#include "HijaCambioMasivo.h"
#include "string_conv.h"

HijaCambioMasivo::HijaCambioMasivo(wxWindow *parent, Bicicleteria *bicicleteria) 
	: BaseCambioMasivo(parent), m_bicicleteria(bicicleteria)
{
	
}

void HijaCambioMasivo::ClickBotonAceptar( wxCommandEvent& event )  {
	float porcentaje = stof(wx_to_std(BarraPorcentaje->GetValue()))/100;
	string proveedor = wx_to_std(BarraProveedor->GetValue());
	for(int i=0;i<m_bicicleteria->CantidadArticulos();i++) { 
		if (m_bicicleteria->VerArticulo(i).VerProvedor()==proveedor)
			m_bicicleteria->VerArticulo(i).AplicarPorcentaje(porcentaje);
	}
	m_bicicleteria->GuardarArticulos();
	EndModal(1);
}

void HijaCambioMasivo::ClickBotonCancelar( wxCommandEvent& event )  {
	EndModal(0);
}

void HijaCambioMasivo::AlApretarEnterPorcentaje( wxCommandEvent& event )  {
	ClickBotonAceptar(event);
}

void HijaCambioMasivo::AlApretarEnterProveedor( wxCommandEvent& event )  {
	ClickBotonAceptar(event);
}

