#ifndef HIJAAGREGARCLIENTE_H
#define HIJAAGREGARCLIENTE_H
#include "wxfb_project.h"
#include "Bicicleteria.h"

class HijaAgregarCliente : public BaseAgregarCliente {
	
private:
	Bicicleteria *m_bicicleteria;
protected:
	void AlApretarEnterNom( wxCommandEvent& event )  override;
	void AlApretarEnterTel( wxCommandEvent& event )  override;
	void AlApretarEnterDireccion( wxCommandEvent& event )  override;
	void AlApretarEnterBicicleta( wxCommandEvent& event )  override;
	void ClickBotonGuardar( wxCommandEvent& event )  override;
	void ClickBotonTerminar( wxCommandEvent& event )  override;
	
public:
	HijaAgregarCliente(wxWindow *parent, Bicicleteria *bicicleteria);
};

#endif

