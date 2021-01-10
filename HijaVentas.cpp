#include "HijaVentas.h"
#include "string_conv.h"
#include "HijaListaVentas.h"
#include <wx/msgdlg.h>
#include "Utils.h"

HijaVentas::HijaVentas(wxWindow *parent, Bicicleteria *bicicleteria)
	: BaseVentas(parent), m_bicicleteria(bicicleteria) 
{
	
}

void HijaVentas::ClickBotonAceptar( wxCommandEvent& event )  {
	Fecha fdesde;
	Fecha fhasta;
	Fecha ultimaVenta = m_bicicleteria->VerVenta(m_bicicleteria->CantidadVentas()-1).VerFecha();
	//Guardamos valores de los cuadros de textos
	if(es_int(wx_to_std(Desde_dia->GetValue())) and es_int(wx_to_std(Desde_mes->GetValue())) 
	   and es_int(wx_to_std(Desde_anio->GetValue())) and es_int(wx_to_std(Hasta_dia->GetValue()))
	   and es_int(wx_to_std(Hasta_mes->GetValue())) and es_int(wx_to_std(Hasta_anio->GetValue())))
	{
		fdesde.dia = stoi(wx_to_std(Desde_dia->GetValue()));
		fdesde.mes = stoi(wx_to_std(Desde_mes->GetValue()));
		fdesde.anio = stoi(wx_to_std(Desde_anio->GetValue()));
		fhasta.dia = stoi(wx_to_std(Hasta_dia->GetValue()));
		fhasta.mes = stoi(wx_to_std(Hasta_mes->GetValue()));
		fhasta.anio = stoi(wx_to_std(Hasta_anio->GetValue()));
	}
	else{
		wxMessageBox("Formato de fecha invalido","Error");
		return;
	}

	int i=0;//Para que la funcion devolver_fecha_hoy sepa que tiene que devolver un fecha y no un string
	if (fhasta<fdesde){ 
		wxMessageBox("Hasta no puede ser menor a desde","Error");
		return;
	}
	
	if (devolver_fecha_hoy(i)<fhasta){
		wxMessageBox("Hasta no puede ser mayor a hoy","Error");
		return;
	}
	
	if (fdesde<m_bicicleteria->VerVenta(0).VerFecha()){
		wxMessageBox("La fecha no puede ser menor a la primer venta: "+fecha_a_string(m_bicicleteria->VerVenta(0).VerFecha()),"Error");
		return;
	}
	
	//Busquedas
	int posh, posd;

	if(ultimaVenta < fdesde){
		posd = m_bicicleteria->CantidadVentas();
	} else {
		posd = BuscarPorFecha(fdesde);
	}
	
	if(ultimaVenta < fhasta or ultimaVenta == fhasta){
		posh = m_bicicleteria->CantidadVentas();
	} else{
		++fhasta;
		posh = BuscarPorFecha(fhasta);
	}
	
	if(posd==posh){
		wxMessageBox("No se encontraron ventas","Error");
		return;
	}
	else{
		HijaListaVentas *win = new HijaListaVentas(this,m_bicicleteria, posd, posh);
		win->Show();
		this->Close();
	}
}

//Buscador por fecha recursivo
int HijaVentas::BuscarPorFecha (Fecha f) {
	for(int i=0;i<m_bicicleteria->CantidadVentas();i++) { 
		if(m_bicicleteria->VerVenta(i).VerFecha() == f) return i;
	}
	BuscarPorFecha(++f);//Si no lo encuentra que se llame de nuevo
}
//La recursividad funciona gracias a las validaciones

//Al apretar enter que guarde 
void HijaVentas::AlApretarEnter( wxCommandEvent& event )  {
	ClickBotonAceptar(event);
}

