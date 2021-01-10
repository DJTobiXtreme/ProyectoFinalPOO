#include "HijaAgregarVenta.h"
#include "string_conv.h"
#include "Utils.h"
#include "ArticuloEnVenta.h"
#include "HijaArticulos.h"
#include <wx/msgdlg.h>

HijaAgregarVenta::HijaAgregarVenta(wxWindow *parent, Bicicleteria *bicicleteria) 
	: BaseAgregarVenta(parent), m_bicicleteria(bicicleteria), m_ultima_fila(0), m_precio_venta(0), m_ganancia_venta(0)
{
	
}


void HijaAgregarVenta::AlEscribir( wxCommandEvent& event )  {
	string txt = wx_to_std(BarraBusqueda->GetValue());
	RefrescarGrillaBuscador(txt);
}

void HijaAgregarVenta::AlApretarEnterBuscar( wxCommandEvent& event ) {
	BarraCantidad->SetFocus();
	BarraCantidad->Clear();
}

void HijaAgregarVenta::AlApretarEnterCantidad( wxCommandEvent& event )  {
	string nombre = wx_to_std(m_grillabuscador->GetCellValue(0,0));
	int fila_actual = BuscarPorNombre(nombre);
	ArticuloEnVenta aEnV;
	aEnV.articulo = m_bicicleteria->VerArticulo(fila_actual);
	if (es_int(wx_to_std(BarraCantidad->GetValue()))){
		aEnV.cantidad = stoi(wx_to_std(BarraCantidad->GetValue()));
	} else {
		wxMessageBox("Ingrese una cantidad valida","Error",wxOK|wxICON_ERROR,this);
		return;
	}
	
	m_grillaVenta->AppendRows();
	m_grillaVenta->SetCellValue(m_ultima_fila,0,std_to_wx(aEnV.articulo.VerNombre()));
	m_grillaVenta->SetCellValue(m_ultima_fila,1,std_to_wx(to_string(aEnV.articulo.VerPrecio())));
	m_grillaVenta->SetCellValue(m_ultima_fila,2,std_to_wx(to_string(aEnV.cantidad)));
	m_grillaVenta->SetCellValue(m_ultima_fila,3,std_to_wx(to_string(aEnV.articulo.VerPrecio()*aEnV.cantidad)));
	
	m_aux_venta.push_back(aEnV);
	
	m_precio_venta += aEnV.articulo.VerPrecio()*aEnV.cantidad;
	m_ganancia_venta += (aEnV.articulo.VerPrecio()-aEnV.articulo.VerCosto())*aEnV.cantidad;
	
	m_bicicleteria->VerArticulo(fila_actual).RestarStock(aEnV.cantidad);
	
	m_PrecioTotal->SetValue(std_to_wx(to_string(m_precio_venta)));
	m_ultima_fila++; 
	BarraBusqueda->Clear();
	BarraBusqueda->SetFocus();
}

void HijaAgregarVenta::ClickBotonGuardarVenta( wxCommandEvent& event )  {
	//Validaciones
	int i=0;
	string cliente = wx_to_std(BarraCliente->GetValue());
	if (cliente.empty()) {
		wxMessageBox("El campo cliente no puede estar vacio","Error",wxOK|wxICON_ERROR,this);
		return;
	} else if (cliente.size()>=256){
		wxMessageBox("El campo cliente es demasiado largo","Error",wxOK|wxICON_ERROR,this);
		return;
	} else if (m_aux_venta.size()==0) {
		wxMessageBox("No ha ingresado ningun articulo","Error",wxOK|wxICON_ERROR,this);
		return;
	}
	
	int indice = m_bicicleteria->CantidadVentas();
	Venta v(devolver_fecha_hoy(i),cliente,m_precio_venta,m_ganancia_venta,m_aux_venta, indice);
	m_bicicleteria->AgregarVenta(v);
	m_bicicleteria->AgregarDetalle(m_aux_venta);
	m_bicicleteria->GuardarArticulos();
	m_bicicleteria->GuardarVentas();
	this->Close();
}



void HijaAgregarVenta::RefrescarGrillaBuscador (string m_txt) {
	if (m_txt.empty()){
		if(m_grillabuscador->GetNumberRows()!=0)
			m_grillabuscador->DeleteRows(0,m_grillabuscador->GetNumberRows());//Si llega algo vacío que muestre la grilla y vuelva
		return;
	}
	pasar_a_minusculas(m_txt); string aux;
	m_buscados.clear();//Limpiamos el vector para agregarle los articulos buscados ahora
	for(int i=0;i<m_bicicleteria->CantidadArticulos();i++) { 
		const Articulo &a = m_bicicleteria->VerArticulo(i);
		aux = a.VerNombre();
		pasar_a_minusculas(aux);
		if(aux.find(m_txt,0)!=string::npos) 
			m_buscados.push_back(a);
	}	
	
	if(m_grillabuscador->GetNumberRows()!=0)
		m_grillabuscador->DeleteRows(0,m_grillabuscador->GetNumberRows());
	//Refrescamos la grilla con los valores buscados
	for(size_t i=0;i<m_buscados.size();i++) { 
		const Articulo &a = m_buscados[i];
		m_grillabuscador->AppendRows();
		m_grillabuscador->SetCellValue(i,0,std_to_wx(a.VerNombre()));
		m_grillabuscador->SetCellValue(i,1,std_to_wx(to_string(a.VerPrecio())));
		m_grillabuscador->SetCellValue(i,2,std_to_wx(a.VerProvedor()));
	}
}

int HijaAgregarVenta::BuscarPorNombre (string nombre) const {
	for(int i=0;i<m_bicicleteria->CantidadArticulos();i++){ 
		if(m_bicicleteria->VerArticulo(i).VerNombre() == nombre) return i;
	}
	return 0;
}

void HijaAgregarVenta::OnCambiarSize( wxSizeEvent& event ) {
	AcomodarGrilla(this, m_grillabuscador,m_grillabuscador->GetNumberCols());
	AcomodarGrilla(this, m_grillaVenta,m_grillaVenta->GetNumberCols());
}


void HijaAgregarVenta::ClickBotonEliminarAI( wxCommandEvent& event )  {
	if (m_aux_venta.empty()) return;
	int fila_a_borrar = m_grillaVenta->GetGridCursorRow();
	int desicion = wxMessageBox(std_to_wx("¿Esta seguro que desea eliminar el articulo?"),m_grillaVenta->GetCellValue(fila_a_borrar,0),wxYES_NO);
	if (desicion == wxNO){
		return;
	}
	m_precio_venta -= m_aux_venta[fila_a_borrar].articulo.VerPrecio()*m_aux_venta[fila_a_borrar].cantidad;
	m_ganancia_venta -= (m_aux_venta[fila_a_borrar].articulo.VerPrecio()-m_aux_venta[fila_a_borrar].articulo.VerCosto())*m_aux_venta[fila_a_borrar].cantidad;
	int fila_modificar_stock = BuscarPorNombre(m_aux_venta[fila_a_borrar].articulo.VerNombre());
	m_bicicleteria->VerArticulo(fila_modificar_stock).RestarStock(-m_aux_venta[fila_a_borrar].cantidad);
	
	
	m_aux_venta.erase(m_aux_venta.begin()+fila_a_borrar);
	m_PrecioTotal->SetValue(std_to_wx(to_string(m_precio_venta)));
	m_ultima_fila--; 
	m_grillaVenta->DeleteRows(fila_a_borrar);
}

