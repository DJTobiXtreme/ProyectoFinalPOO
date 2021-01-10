#ifndef HIJACLIENTES_H
#define HIJACLIENTES_H
#include "wxfb_project.h"
#include "Bicicleteria.h"

class HijaClientes : public BaseClientes {
	
private:
	Bicicleteria *m_bicicleteria;
	string m_txt;
	vector<Cliente> m_buscados;
protected:
	void OnCambiaSize( wxSizeEvent& event )  override;
	void AlIngresarTexto( wxCommandEvent& event )  override;
	void AlPresionarEnter( wxCommandEvent& event )  override;
	void DobleClickGrilla( wxGridEvent& event )  override;
	void ClickBotonAgregar( wxCommandEvent& event )  override;
	void ClickBotonModificar( wxCommandEvent& event )  override;
	void ClickBotonEliminar( wxCommandEvent& event )  override;
	void RefrescarGrilla();
	void RefrescarGrillaBuscador(string m_txt);
	int BuscarPorNombre(string nombre) const;
	int BuscarFilaActual() const;
public:
	HijaClientes(wxWindow *parent, Bicicleteria *bicicleteria);
};

#endif

