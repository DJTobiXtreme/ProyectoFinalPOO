#ifndef HIJAPRINCIPAL_H
#define HIJAPRINCIPAL_H
#include "wxfb_project.h"
#include "Bicicleteria.h"

class HijaPrincipal : public BasePrincipal {
	
private:
	
protected:
	void ClickBotonAgregarVenta( wxCommandEvent& event )  override;
	void ClickBotonClientes( wxCommandEvent& event )  override;
	void ClickBotonVentas( wxCommandEvent& event )  override;
	void ClickBotonArticulos( wxCommandEvent& event )  override;
	Bicicleteria *m_bicicleteria;
public:
	HijaPrincipal(Bicicleteria *bicicleteria);
};

#endif

