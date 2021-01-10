#ifndef HIJADETALLEVENTA_H
#define HIJADETALLEVENTA_H
#include "wxfb_project.h"
#include "Bicicleteria.h"

class HijaDetalleVenta : public BaseDetalleVenta {
	
private:
	Bicicleteria *m_bicicleteria;
	int m_indice;
protected:
	void OnCambiaSize( wxSizeEvent& event )  override;
public:
	HijaDetalleVenta(wxWindow *parent, Bicicleteria *bicicleteria, int indice);
};

#endif

