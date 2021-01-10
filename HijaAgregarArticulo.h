#ifndef HIJAAGREGARARTICULO_H
#define HIJAAGREGARARTICULO_H
#include "wxfb_project.h"
#include "Bicicleteria.h"

class HijaAgregarArticulo : public BaseAgregarArticulo {
	
private:
	Bicicleteria *m_bicicleteria;
protected:
	void AlApretarEnterNombre( wxCommandEvent& event )  override;
	void AlAlpretarEnterCosto( wxCommandEvent& event )  override;
	void AlApretarEnterPrecio( wxCommandEvent& event )  override;
	void AlApretarEnterStock( wxCommandEvent& event )  override;
	void AlApretarEnterProveedor( wxCommandEvent& event )  override;
	void ClickBotonGuardar( wxCommandEvent& event )  override;
	void ClickBotonTerminar( wxCommandEvent& event )  override;
	
public:
	HijaAgregarArticulo(wxWindow *parent, Bicicleteria *bicicleteria);
};

#endif

