#include "HijaModificarCliente.h"
#include "string_conv.h"
#include <wx/msgdlg.h>

HijaModificarCliente::HijaModificarCliente(wxWindow *parent, Bicicleteria *bicicleteria, int fila) 
	: BaseModificarCliente(parent), m_bicicleteria(bicicleteria), m_fila(fila) 
{
	Cliente a = m_bicicleteria->VerCliente(m_fila);
	m_nombre->SetValue(std_to_wx(a.VerNombre()));
	m_telefono->SetValue(std_to_wx(a.VerTelefono()));
	m_direccion->SetValue(std_to_wx(a.VerDireccion()));
	m_bicicleta->SetValue(std_to_wx(a.VerBici()));
}

void HijaModificarCliente::AlApretarEnterNom( wxCommandEvent& event )  {
	ClickBotonGuardar(event);
}

void HijaModificarCliente::AlApretarEnterCost( wxCommandEvent& event )  {
	ClickBotonGuardar(event);
}

void HijaModificarCliente::AlApretarEnterPrecio( wxCommandEvent& event )  {
	ClickBotonGuardar(event);
}

void HijaModificarCliente::AlApretarEnterStock( wxCommandEvent& event )  {
	ClickBotonGuardar(event);
}

void HijaModificarCliente::ClickBotonGuardar( wxCommandEvent& event )  {
	string nombre = wx_to_std(m_nombre->GetValue());
	string telefono = wx_to_std(m_telefono->GetValue()); 
	string direccion = wx_to_std(m_direccion->GetValue());
	string bici = wx_to_std(m_bicicleta->GetValue());
	Cliente c(nombre,telefono,direccion,bici);
	string svalidar = c.ValidarDatos();
	if (svalidar.empty()) {
		m_bicicleteria->AgregarCliente(c);
		m_bicicleteria->EliminarCliente(m_fila);
		m_bicicleteria->GuardarClientes();
		EndModal(1);
	} else {
		wxMessageBox(std_to_wx(svalidar),"Error",wxOK|wxICON_ERROR,this);
	}
}

void HijaModificarCliente::ClickBotonTerminar( wxCommandEvent& event )  {
	EndModal(0);
}

