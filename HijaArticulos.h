#ifndef HIJAARTICULOS_H
#define HIJAARTICULOS_H
#include "wxfb_project.h"
#include "Bicicleteria.h"

class HijaArticulos : public BaseArticulos {
	
private:
	Bicicleteria *m_bicicleteria;
	string m_txt;
	vector<Articulo> m_buscados;
protected:
	void ClickBotonCambiarPrecio( wxCommandEvent& event )  override;
	void OnCambiaSize( wxSizeEvent& event )  override;
	void AlIngresarTexto( wxCommandEvent& event )  override;
	void DobleClickGrilla( wxGridEvent& event )  override;
	void ClickBotonAgregar( wxCommandEvent& event )  override;
	void ClickBotonModificar( wxCommandEvent& event )  override;
	void ClickBotonEliminar( wxCommandEvent& event )  override;
	void RefrescarGrilla();
	void RefrescarGrillaBuscador(string m_txt);
	int BuscarPorNombre(string nombre) const;
	int BuscarFilaActual() const;
public:
	HijaArticulos(wxWindow *parent, Bicicleteria *bicicleteria);
};

#endif

