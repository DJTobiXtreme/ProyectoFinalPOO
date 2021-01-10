#ifndef HIJALISTAVENTAS_H
#define HIJALISTAVENTAS_H
#include "wxfb_project.h"
#include "Bicicleteria.h"

class HijaListaVentas : public BaseListaVentas {
	
private:
	Bicicleteria *m_bicicleteria;
	int m_desde;
	int m_hasta;
	vector<int>m_indices;
protected:
	void OnDobleClickGrilla( wxGridEvent& event )  override;
	void OnCambiaSize( wxSizeEvent& event )  override;
public:
	HijaListaVentas(wxWindow *parent, Bicicleteria *bicicleteria, int desde, int hasta);
};

#endif

