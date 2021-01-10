#ifndef HIJAMODIFICARCLIENTE_H
#define HIJAMODIFICARCLIENTE_H
#include "wxfb_project.h"
#include "Bicicleteria.h"

class HijaModificarCliente : public BaseModificarCliente {
	
private:
	Bicicleteria *m_bicicleteria;
	int m_fila;
protected:
	void AlApretarEnterNom( wxCommandEvent& event )  override;
	void AlApretarEnterCost( wxCommandEvent& event )  override;
	void AlApretarEnterPrecio( wxCommandEvent& event )  override;
	void AlApretarEnterStock( wxCommandEvent& event )  override;
	void ClickBotonGuardar( wxCommandEvent& event )  override;
	void ClickBotonTerminar( wxCommandEvent& event )  override;
	
public:
	HijaModificarCliente(wxWindow *parent, Bicicleteria *bicicleteria, int fila);
};

#endif

