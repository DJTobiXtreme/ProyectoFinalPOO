#ifndef HIJACAMBIOMASIVO_H
#define HIJACAMBIOMASIVO_H
#include "wxfb_project.h"
#include "HijaCambioMasivo.h"
#include "Bicicleteria.h"

class HijaCambioMasivo : public BaseCambioMasivo {
	
private:
	Bicicleteria *m_bicicleteria;
protected:
	void AlApretarEnterPorcentaje( wxCommandEvent& event )  override;
	void AlApretarEnterProveedor( wxCommandEvent& event )  override;
	void ClickBotonAceptar( wxCommandEvent& event )  override;
	void ClickBotonCancelar( wxCommandEvent& event )  override;
	
public:
	HijaCambioMasivo(wxWindow *parent, Bicicleteria *bicicleteria);
};

#endif

