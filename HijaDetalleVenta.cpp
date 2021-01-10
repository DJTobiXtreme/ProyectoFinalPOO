#include "HijaDetalleVenta.h"
#include "string_conv.h"
#include "Utils.h"

HijaDetalleVenta::HijaDetalleVenta (wxWindow * parent, Bicicleteria * bicicleteria, int indice) 
	: BaseDetalleVenta(parent), m_bicicleteria(bicicleteria), m_indice(indice)
{
	vector<ArticuloEnVenta>Detalle = m_bicicleteria->BuscarDetalleVenta(m_indice);
	for(size_t i=0;i<Detalle.size();i++){
		const Articulo &a = Detalle[i].articulo;
		m_grillaDetalle->AppendRows();
		m_grillaDetalle->SetCellValue(i,0,std_to_wx(a.VerNombre()));
		m_grillaDetalle->SetCellValue(i,1,std_to_wx(to_string(Detalle[i].cantidad)));
		m_grillaDetalle->SetCellValue(i,2,std_to_wx(to_string(a.VerPrecio())));
		m_grillaDetalle->SetCellValue(i,3,std_to_wx(to_string(Detalle[i].cantidad*a.VerPrecio())));
	}
}

void HijaDetalleVenta::OnCambiaSize( wxSizeEvent& event )  {
	AcomodarGrilla(this,m_grillaDetalle,m_grillaDetalle->GetNumberCols());
}

