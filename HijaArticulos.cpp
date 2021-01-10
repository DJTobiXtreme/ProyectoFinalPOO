#include "HijaArticulos.h"
#include "string_conv.h"
#include "HijaAgregarArticulo.h"
#include "HijaModificarArticulo.h"
#include <algorithm>
#include "Utils.h"
#include "HijaCambioMasivo.h"
#include <wx/msgdlg.h>
using namespace std;

HijaArticulos::HijaArticulos(wxWindow *parent, Bicicleteria *bicicleteria) 
	: BaseArticulos(parent), m_bicicleteria(bicicleteria) 
{
	m_grilla->DisableDragColSize();//Desactivamos el arrastre de columnas
	m_grilla->SetSelectionMode(wxGrid::wxGridSelectRows);//Desactivamos que puedan seleccionar las seldas
	RefrescarGrilla();//Mostramos la grilla al inicializar la ventana
}

//Creamos la ventana agregar para agregar un nuevo artículo
void HijaArticulos::ClickBotonAgregar( wxCommandEvent& event ) {
	HijaAgregarArticulo win(this, m_bicicleteria); wxCommandEvent e;
	if(win.ShowModal() == 1){
		RefrescarGrilla();
		this->ClickBotonAgregar(e);
	}
}

//Creamos la ventana modificar para modificar artículo
void HijaArticulos::ClickBotonModificar( wxCommandEvent& event ) {
	int fila_actual = BuscarFilaActual();
	HijaModificarArticulo win(this, m_bicicleteria,fila_actual); 
	if(win.ShowModal() == 1){
		RefrescarGrilla();
	}
}

void HijaArticulos::ClickBotonEliminar( wxCommandEvent& event )  {
	int f = BuscarFilaActual();
	int desicion = wxMessageBox(std_to_wx("¿Esta seguro que desea eliminar el articulo?"),m_grilla->GetCellValue(f,0),wxYES_NO);
	if (desicion == wxNO){
		return;
	}
	m_bicicleteria->EliminarArticulo(f);
	m_bicicleteria->GuardarArticulos();
	RefrescarGrilla();
}


void HijaArticulos::RefrescarGrilla () {
	if(m_grilla->GetNumberRows() != 0)
		m_grilla->DeleteRows(0,m_grilla->GetNumberRows());
	//Mostramos los valores guardados
	for(int i=0;i<m_bicicleteria->CantidadArticulos();i++) { 
		const Articulo &a = m_bicicleteria->VerArticulo(i);
		m_grilla->AppendRows();
		m_grilla->SetCellValue(i,0,std_to_wx(a.VerNombre()));
		m_grilla->SetCellValue(i,1,std_to_wx(to_string(a.VerCosto())));
		m_grilla->SetCellValue(i,2,std_to_wx(to_string(a.VerPorcentaje()*100)));
		m_grilla->SetCellValue(i,3,std_to_wx(to_string(a.VerPrecio())));
		m_grilla->SetCellValue(i,4,std_to_wx(to_string(a.VerStock())));
		m_grilla->SetCellValue(i,5,std_to_wx(a.VerProvedor()));
	}
}

void HijaArticulos::DobleClickGrilla( wxGridEvent& event )  {
	int fila_actual = BuscarFilaActual();
	int col_actual = m_grilla->GetGridCursorCol();
	HijaModificarArticulo win(this, m_bicicleteria, fila_actual, col_actual); 
	if(win.ShowModal() == 1){
		RefrescarGrilla();
	}
}

//Buscar
void HijaArticulos::AlIngresarTexto( wxCommandEvent& event )  {
	string txt = wx_to_std(BarraBusqueda->GetValue());//Por cada letra ingresada toma el valor
	RefrescarGrillaBuscador(txt);//LLama a refrescar la grilla
}

//Refresca la grilla al realizar la busqueda
void HijaArticulos::RefrescarGrillaBuscador (string m_txt) {
	if (m_txt.empty()){
		RefrescarGrilla();//Si llega algo vacío que muestre la grilla y vuelva
		return;
	}
	pasar_a_minusculas(m_txt); string aux;
	m_buscados.clear();//Limpiamos el vector para agregarle los articulos buscados ahora
	for(int i=0;i<m_bicicleteria->CantidadArticulos();i++) { 
		const Articulo &a = m_bicicleteria->VerArticulo(i);
		aux = a.VerNombre();
		pasar_a_minusculas(aux);
		if(aux.find(m_txt,0)!=string::npos) 
			m_buscados.push_back(a);//Si lo encuentra, se lo guarda
	}	
	
	if(m_grilla->GetNumberRows()!=0)
		m_grilla->DeleteRows(0,m_grilla->GetNumberRows());
	//Refrescamos la grilla con los valores buscados
	for(size_t i=0;i<m_buscados.size();i++) { 
		const Articulo &a = m_buscados[i];
		m_grilla->AppendRows();
		m_grilla->SetCellValue(i,0,std_to_wx(a.VerNombre()));
		m_grilla->SetCellValue(i,1,std_to_wx(to_string(a.VerCosto())));
		m_grilla->SetCellValue(i,2,std_to_wx(to_string(a.VerPorcentaje()*100)));
		m_grilla->SetCellValue(i,3,std_to_wx(to_string(a.VerPrecio())));
		m_grilla->SetCellValue(i,4,std_to_wx(to_string(a.VerStock())));
		m_grilla->SetCellValue(i,5,std_to_wx(a.VerProvedor()));
	}
}

//Busqueda por nombre para los metodos eliminar y modificar
int HijaArticulos::BuscarPorNombre (string nombre) const {
	for(int i=0;i<m_bicicleteria->CantidadArticulos();i++) { 
		if(m_bicicleteria->VerArticulo(i).VerNombre() == nombre){
			return i;
		}
	}
	return 0;
}

//Escala tamaño de la ventana con lo que hay adentro
void HijaArticulos::OnCambiaSize( wxSizeEvent& event )  {
	AcomodarGrilla(this,m_grilla,m_grilla->GetNumberCols());
}

//Busca y retorna la fila actual para la grilla del buscaador
int HijaArticulos::BuscarFilaActual () const {
	int fila_actual = m_grilla->GetGridCursorRow();
	string nombre = wx_to_std(m_grilla->GetCellValue(fila_actual,0));
	fila_actual = BuscarPorNombre(nombre);
	return fila_actual;
}

void HijaArticulos::ClickBotonCambiarPrecio( wxCommandEvent& event )  {
	HijaCambioMasivo win(this,m_bicicleteria);
	if( win.ShowModal()==1){
		RefrescarGrilla();
	}
}

