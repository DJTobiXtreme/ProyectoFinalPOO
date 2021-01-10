#include "HijaAgregarCliente.h"
#include "string_conv.h"
#include <wx/msgdlg.h>

HijaAgregarCliente::HijaAgregarCliente(wxWindow *parent, Bicicleteria *bicicleteria) 
	: BaseAgregarCliente(parent), m_bicicleteria(bicicleteria) { }

//Guardar y Terminar
void HijaAgregarCliente::ClickBotonGuardar( wxCommandEvent& event )  {
	string nombre = wx_to_std(m_nombre->GetValue());
	string telefono = wx_to_std(m_telefono->GetValue()); 
	string direccion = wx_to_std(m_direccion->GetValue());
	string bici = wx_to_std(m_bicicleta->GetValue());
	Cliente c(nombre,telefono,direccion,bici);
	string svalidar = c.ValidarDatos();
	if (svalidar.empty()) {
		m_bicicleteria->AgregarCliente(c);
		m_bicicleteria->GuardarClientes();
		EndModal(1);
	} else {
		wxMessageBox(std_to_wx(svalidar),"Error",wxOK|wxICON_ERROR,this);
	}
}

void HijaAgregarCliente::ClickBotonTerminar( wxCommandEvent& event )  {
	EndModal(0);
}

void HijaAgregarCliente::AlApretarEnterNom( wxCommandEvent& event )  {
	ClickBotonGuardar(event);
}

void HijaAgregarCliente::AlApretarEnterTel( wxCommandEvent& event )  {
	ClickBotonGuardar(event);
}

void HijaAgregarCliente::AlApretarEnterDireccion( wxCommandEvent& event )  {
	ClickBotonGuardar(event);
}

void HijaAgregarCliente::AlApretarEnterBicicleta( wxCommandEvent& event )  {
	ClickBotonGuardar(event);
}

