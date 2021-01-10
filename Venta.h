#ifndef VENTA_H
#define VENTA_H
#include <vector>
#include "ArticuloEnVenta.h"
#include "Fecha.h"
#include "Cliente.h"
using namespace std;

class Venta {
public:
	Venta(Fecha f, string cliente, float precio_venta, float ganancia_venta, vector<ArticuloEnVenta>v, int indice);
	Venta();
	Fecha VerFecha() const;
	int VerDia() const;
	int VerMes() const;
	int VerAnio() const;
	int VerCantVendida() const;
	float VerPrecioACobrar() const;
	float VerGanacia() const;
	void CalcularDatos();
	void AgregarArticulo(ArticuloEnVenta articulo);
	void EliminarArticulo(int indice);
	ArticuloEnVenta VerArticulo(int indice) const;
	string VerCliente() const;
	void CargarCliente(string cliente);
	int size() const;
	int VerIndice()const;
private:
	Fecha m_fecha;
	string m_cliente;
	float m_precio_venta;
	float m_ganacia_venta;
	vector<ArticuloEnVenta> m_articulos_venta;
	int m_indice;
};

#endif

