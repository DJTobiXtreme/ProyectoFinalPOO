#ifndef HIJAAGREGARVENTA_H
#define HIJAAGREGARVENTA_H
#include "wxfb_project.h"
#include "Bicicleteria.h"
#include "ArticuloEnVenta.h"

class HijaAgregarVenta : public BaseAgregarVenta {
	
private:
	Bicicleteria *m_bicicleteria;
	string m_txt;
	vector<Articulo> m_buscados;
	int m_ultima_fila;
	vector<ArticuloEnVenta> m_aux_venta;
	float m_precio_venta;
	float m_ganancia_venta;
protected:
	void ClickBotonEliminarAI( wxCommandEvent& event )  override;
	void OnCambiarSize( wxSizeEvent& event )  override;
	void AlEscribir( wxCommandEvent& event )  override;
	void AlApretarEnterBuscar( wxCommandEvent& event )  override;
	void AlApretarEnterCantidad( wxCommandEvent& event )  override;
	void ClickBotonGuardarVenta( wxCommandEvent& event )  override;
	void RefrescarGrillaBuscador(string m_txt);
	int BuscarPorNombre(string nombre) const;
public:
	HijaAgregarVenta(wxWindow *parent, Bicicleteria *bicicleteria);
};

#endif


