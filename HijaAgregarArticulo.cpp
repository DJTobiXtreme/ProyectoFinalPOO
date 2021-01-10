#include "HijaAgregarArticulo.h"
#include "string_conv.h"
#include "Articulo.h"
#include <string>
#include <wx/msgdlg.h>
#include "Utils.h"
using namespace std;

HijaAgregarArticulo::HijaAgregarArticulo(wxWindow *parent, Bicicleteria *bicicleteria)
	: BaseAgregarArticulo(parent), m_bicicleteria(bicicleteria)
{
	
}

void HijaAgregarArticulo::ClickBotonGuardar( wxCommandEvent& event )  {
	float costo, porcentaje;int stock;
	string nombre = wx_to_std(m_nombre->GetValue());
	string scosto = wx_to_std(m_costo->GetValue()); 
	if(scosto.empty() or (not es_float(scosto))) costo = -1;
	else costo = stof(scosto);
	string sporcentaje= wx_to_std(m_precio->GetValue()); 
	if(sporcentaje.empty() or (not es_float(sporcentaje))) porcentaje = -1;
	else porcentaje = (stof(sporcentaje))/100;
	string sstock = wx_to_std(m_stock->GetValue());
	if(sstock.empty() or not(es_int(sstock))) stock = -1;
	else stock = stoi(sstock);
	string provedor = wx_to_std(m_proveedor->GetValue());
	Articulo a(nombre,costo,porcentaje,stock,provedor);
	string svalidar = a.ValidarDatos();
	if (svalidar.empty()) {
		m_bicicleteria->AgregarArticulo(a);
		m_bicicleteria->GuardarArticulos();
		EndModal(1);
	} else {
		wxMessageBox(std_to_wx(svalidar),"Error",wxOK|wxICON_ERROR,this);
	}
}

void HijaAgregarArticulo::ClickBotonTerminar( wxCommandEvent& event )  {
	EndModal(0);
}

void HijaAgregarArticulo::AlApretarEnterNombre( wxCommandEvent& event )  {
	ClickBotonGuardar(event);
}

void HijaAgregarArticulo::AlAlpretarEnterCosto( wxCommandEvent& event )  {
	ClickBotonGuardar(event);
}

void HijaAgregarArticulo::AlApretarEnterPrecio( wxCommandEvent& event )  {
	ClickBotonGuardar(event);
}

void HijaAgregarArticulo::AlApretarEnterStock( wxCommandEvent& event )  {
	ClickBotonGuardar(event);
}

void HijaAgregarArticulo::AlApretarEnterProveedor( wxCommandEvent& event )  {
	ClickBotonGuardar(event);
}

