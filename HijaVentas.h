#ifndef HIJAVENTAS_H
#define HIJAVENTAS_H
#include "wxfb_project.h"
#include "Bicicleteria.h"

class HijaVentas : public BaseVentas {
	
private:
	Bicicleteria *m_bicicleteria;
protected:
	void AlApretarEnter( wxCommandEvent& event )  override;
	void ClickBotonAceptar( wxCommandEvent& event )  override;
	int BuscarPorFecha(Fecha f);
	
public:
	HijaVentas(wxWindow *parent, Bicicleteria *bicicleteria);
};

#endif

	
