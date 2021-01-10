#include "HijaClientes.h"
#include "HijaModificarCliente.h"
#include "string_conv.h"
#include "HijaAgregarCliente.h"
#include "Utils.h"
#include <wx/msgdlg.h>

HijaClientes::HijaClientes(wxWindow *parent, Bicicleteria *bicicleteria) 
	: BaseClientes(parent), m_bicicleteria(bicicleteria) 
{
	m_grilla->DisableDragColSize();
	m_grilla->SetSelectionMode(wxGrid::wxGridSelectRows);
	RefrescarGrilla();
}

void HijaClientes::OnCambiaSize( wxSizeEvent& event )  {
	AcomodarGrilla(this,m_grilla,m_grilla->GetNumberCols());	
}

void HijaClientes::AlIngresarTexto( wxCommandEvent& event )  {
	string txt = wx_to_std(BarraBusqueda->GetValue());
	RefrescarGrillaBuscador(txt);
}

void HijaClientes::AlPresionarEnter( wxCommandEvent& event )  {
	event.Skip();
}

void HijaClientes::DobleClickGrilla( wxGridEvent& event )  {
	int fila_actual = BuscarFilaActual();
	HijaModificarCliente win(this, m_bicicleteria, fila_actual); 
	if(win.ShowModal() == 1){
		RefrescarGrilla();
	}
}

void HijaClientes::ClickBotonAgregar( wxCommandEvent& event )  {
	HijaAgregarCliente win(this, m_bicicleteria); wxCommandEvent e;
	if(win.ShowModal() == 1){
		RefrescarGrilla();
		this->ClickBotonAgregar(e);
	}
}

void HijaClientes::ClickBotonModificar( wxCommandEvent& event )  {
	int fila_actual = BuscarFilaActual();
	HijaModificarCliente win(this, m_bicicleteria,fila_actual); 
	if(win.ShowModal() == 1){
		RefrescarGrilla();
	}
}

void HijaClientes::ClickBotonEliminar( wxCommandEvent& event )  {
	int fila_actual = BuscarFilaActual();
	int desicion = wxMessageBox(std_to_wx("¿Esta seguro que desea eliminar el cliente?"),m_grilla->GetCellValue(fila_actual,0),wxYES_NO);
	if (desicion == wxNO){
		return;
	}
	m_bicicleteria->EliminarCliente(fila_actual);
	m_bicicleteria->GuardarClientes();
	RefrescarGrilla();
}


int HijaClientes::BuscarPorNombre (string nombre) const {
	for(int i=0;i<m_bicicleteria->CantidadClientes();i++) { 
		if(m_bicicleteria->VerCliente(i).VerNombre() == nombre){
			return i;
		}
	}
	return 0;
}

void HijaClientes::RefrescarGrilla ( ) {
	if(m_grilla->GetNumberRows() != 0)
		m_grilla->DeleteRows(0,m_grilla->GetNumberRows());
	
	for(int i=0;i<m_bicicleteria->CantidadClientes();i++) { 
		const Cliente &a = m_bicicleteria->VerCliente(i);
		m_grilla->AppendRows();
		m_grilla->SetCellValue(i,0,std_to_wx(a.VerNombre()));
		m_grilla->SetCellValue(i,1,std_to_wx(a.VerTelefono()));
		m_grilla->SetCellValue(i,2,std_to_wx(a.VerDireccion()));
		m_grilla->SetCellValue(i,3,std_to_wx(a.VerBici()));
	}
}

void HijaClientes::RefrescarGrillaBuscador (string m_txt) {
	vector<Cliente> v;
	pasar_a_minusculas(m_txt);
	string aux;
	for(int i=0;i<m_bicicleteria->CantidadClientes();i++) { 
		const Cliente &a = m_bicicleteria->VerCliente(i);
		aux = a.VerNombre();
		pasar_a_minusculas(aux);
		if(aux.find(m_txt,0)!=string::npos) v.push_back(a);
	}	 
	
	m_buscados = v;
	
	if(m_grilla->GetNumberRows() != 0)
		m_grilla->DeleteRows(0,m_grilla->GetNumberRows());
	for(size_t i=0;i<m_buscados.size();i++) { 
		const Cliente &a = m_buscados[i];
		m_grilla->AppendRows();
		m_grilla->SetCellValue(i,0,std_to_wx(a.VerNombre()));
		m_grilla->SetCellValue(i,1,std_to_wx(a.VerTelefono()));
		m_grilla->SetCellValue(i,2,std_to_wx(a.VerDireccion()));
		m_grilla->SetCellValue(i,3,std_to_wx(a.VerBici()));
	}
}

int HijaClientes::BuscarFilaActual ( ) const {
	int fila_actual = m_grilla->GetGridCursorRow();
	string nombre = wx_to_std(m_grilla->GetCellValue(fila_actual,0));
	fila_actual = BuscarPorNombre(nombre);
	return fila_actual;
}

