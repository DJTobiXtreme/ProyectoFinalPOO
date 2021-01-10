#include "HijaPrincipal.h"
#include "string_conv.h"
#include "HijaArticulos.h"
#include "Utils.h"
#include "HijaClientes.h"
#include "HijaAgregarVenta.h"
#include "HijaVentas.h"
#include "HijaListaVentas.h"
using namespace std;

HijaPrincipal::HijaPrincipal(Bicicleteria *bicicleteria) 
	: BasePrincipal(nullptr), m_bicicleteria(bicicleteria) 
{
	string fecha = wx_to_std(devolver_fecha_hoy());
	if( fecha[1] == '/') fecha = '0'+fecha;
	m_fecha->SetValue(fecha);
}

void HijaPrincipal::ClickBotonArticulos( wxCommandEvent& event )  {
	HijaArticulos *win = new HijaArticulos(this,m_bicicleteria);
	win->Show();
}

void HijaPrincipal::ClickBotonVentas( wxCommandEvent& event )  {
	HijaVentas *win = new HijaVentas(this,m_bicicleteria);
	win->Show();
}

void HijaPrincipal::ClickBotonClientes( wxCommandEvent& event )  {
	HijaClientes *win = new HijaClientes(this,m_bicicleteria);
	win->Show();
}

void HijaPrincipal::ClickBotonAgregarVenta( wxCommandEvent& event )  {
	HijaAgregarVenta *win = new HijaAgregarVenta(this,m_bicicleteria);
	win->Show();
}

