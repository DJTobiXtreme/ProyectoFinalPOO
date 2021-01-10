#include "HijaListaVentas.h"
#include "string_conv.h"
#include "Utils.h"
#include "HijaDetalleVenta.h"

HijaListaVentas::HijaListaVentas(wxWindow *parent, Bicicleteria *bicicleteria, int desde, int hasta) 
	: BaseListaVentas(parent), m_bicicleteria(bicicleteria), m_desde(desde), m_hasta(hasta) 
{
	Venta v;
	float gananciaTotal = 0;
	float precioTotal = 0;
	int row_c = 0;
	for(int i=m_desde;i<m_hasta;i++){
		v = m_bicicleteria->VerVenta(i);
		m_grilla->AppendRows();
		m_grilla->SetCellValue(row_c,0,std_to_wx(fecha_a_string(v.VerFecha())));
		m_grilla->SetCellValue(row_c,1,std_to_wx(to_string(v.VerPrecioACobrar())));
		m_grilla->SetCellValue(row_c,2,std_to_wx(to_string(v.VerGanacia())));
		m_grilla->SetCellValue(row_c,3,std_to_wx(v.VerCliente()));
		row_c++;
		gananciaTotal += v.VerGanacia();
		precioTotal += v.VerPrecioACobrar();
		m_indices.push_back(v.VerIndice());
	}
	BarraGanaciaTotal->SetValue(std_to_wx(to_string(gananciaTotal)));
	BarraCantidadVendida->SetValue(std_to_wx(to_string(precioTotal)));
	BarraTotalVendido->SetValue(std_to_wx(to_string(m_hasta-m_desde)));
}


void HijaListaVentas::OnCambiaSize( wxSizeEvent& event )  {
	AcomodarGrilla(this,m_grilla,m_grilla->GetNumberCols());
}

void HijaListaVentas::OnDobleClickGrilla( wxGridEvent& event )  {
	int indice = m_indices[m_grilla->GetGridCursorRow()];
	HijaDetalleVenta *win = new HijaDetalleVenta(this,m_bicicleteria,indice);
	win->Show();
}

