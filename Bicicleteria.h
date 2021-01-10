#ifndef BICICLETERIA_H
#define BICICLETERIA_H
#include <vector>
#include "Articulo.h"
#include "Cliente.h"
#include "Venta.h"
using namespace std;

class Bicicleteria {
public:
	//El constructor carga los archivos
	Bicicleteria(string archiArticulos, string archiClientes, string archiVentas, string archiDetalleVentas);
	
	// Metodos articulo
	void CargarArticulosArchi(string nombreArchi);
	void AgregarArticulo(Articulo a);
	Articulo &VerArticulo(int indice);
	void EliminarArticulo(int indice);
	void GuardarArticulos();
	int CantidadArticulos() const;
	
	// Metodos Cliente
	void CargarClientesArchi(string nombreArchi);
	void AgregarCliente(Cliente c);
	Cliente VerCliente(int indice) const;
	void GuardarClientes();
	int CantidadClientes() const;
	void EliminarCliente(int indice);
	
	// Metodos Ventas
	void CargarVentasArchi(string nombreArchi);
	void AgregarVenta(Venta v);
	Venta VerVenta(int indice) const;
	void GuardarVentas();
	void AgregarDetalle(vector<ArticuloEnVenta>v);
	int CantidadVentas() const;
	void EliminarVenta(int indice);
	vector<ArticuloEnVenta>BuscarDetalleVenta(int indice) const;
	
private:
	vector<Articulo> m_articulos;
	vector<Cliente> m_clientes;
	vector<Venta> m_ventas;
	vector<ArticuloEnVenta>m_Detalles;
	string m_archiArticulos;
	string m_archiClientes;
	string m_archiVentas;
	string m_archiDetalleVentas;
};

#endif

