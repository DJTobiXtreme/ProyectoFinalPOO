#ifndef HIJAMODIFICARARTICULO_H
#define HIJAMODIFICARARTICULO_H
#include "wxfb_project.h"
#include "Bicicleteria.h"

class HijaModificarArticulo : public BaseModificarArticulo {
	
private:
	Bicicleteria *m_bicicleteria;
	int m_indice;
protected:
	void AlApretarEnterNom( wxCommandEvent& event )  override;
	void AlApretarEnterCost( wxCommandEvent& event )  override;
	void AlApretarEnterPrecio( wxCommandEvent& event )  override;
	void AlApretarEnterStock( wxCommandEvent& event )  override;
	void ClickBotonGuardar( wxCommandEvent& event )  override;
	void ClickBotonTerminar( wxCommandEvent& event )  override;
public:
	HijaModificarArticulo(wxWindow *parent, Bicicleteria *bicicleteria, int indiceFila, int indiceCol=0);
};

#endif

