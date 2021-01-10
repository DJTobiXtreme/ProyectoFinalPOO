#include "HijaModificarArticulo.h"
#include "string_conv.h"
#include <wx/msgdlg.h>
#include "Utils.h"

HijaModificarArticulo::HijaModificarArticulo(wxWindow *parent, Bicicleteria *bicicleteria, int indiceFila, int indiceCol) 
	: BaseModificarArticulo(parent), m_bicicleteria(bicicleteria), m_indice(indiceFila)
{
	Articulo &a = m_bicicleteria->VerArticulo(m_indice);
	m_nombre->SetValue(std_to_wx(a.VerNombre()));
	m_costo->SetValue(std_to_wx(to_string(a.VerCosto())));
	m_precio->SetValue(std_to_wx(to_string(a.VerPorcentaje()*100)));
	m_stock->SetValue(std_to_wx(to_string(a.VerStock())));
	m_proveedor->SetValue(std_to_wx(a.VerProvedor()));
	
	if(indiceCol == 1) {
		m_costo->SetFocus();
		m_costo->Clear();
	}
	else if(indiceCol == 2){
		m_precio->SetFocus();
		m_precio->Clear();
	}
	else if(indiceCol == 3){
		m_stock->SetFocus();
		m_stock->Clear();
	}
}

void HijaModificarArticulo::ClickBotonGuardar( wxCommandEvent& event )  {
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
		m_bicicleteria->EliminarArticulo(m_indice);
		m_bicicleteria->AgregarArticulo(a);
		m_bicicleteria->GuardarArticulos();
		EndModal(1);
	} else {
		wxMessageBox(std_to_wx(svalidar),"Error",wxOK|wxICON_ERROR,this);
	}
}

void HijaModificarArticulo::ClickBotonTerminar( wxCommandEvent& event )  {
	EndModal(0);
}

void HijaModificarArticulo::AlApretarEnterNom( wxCommandEvent& event )  {
	ClickBotonGuardar(event);
}

void HijaModificarArticulo::AlApretarEnterCost( wxCommandEvent& event )  {
	ClickBotonGuardar(event);
}

void HijaModificarArticulo::AlApretarEnterPrecio( wxCommandEvent& event )  {
	ClickBotonGuardar(event);
}

void HijaModificarArticulo::AlApretarEnterStock( wxCommandEvent& event )  {
	ClickBotonGuardar(event);
}

