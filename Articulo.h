#ifndef ARTICULO_H
#define ARTICULO_H
#include <string>
using namespace std;

class Articulo {
public:
	Articulo();
	void RestarStock(int StockARestar);
	Articulo(string nombre, float costo, float porcentaje, int stock, string provedor);
	Articulo(string nombre, float costo, float porcentaje, float precio, int stock, string provedor);
	string VerNombre() const;
	void ModificarNombre(string nombre);
	float VerCosto() const;
	void ModificarCosto(float costo);
	float VerPrecio() const;	
	void ModificarPrecio(float precio);
	int VerStock() const;
	void ModificarStock(int stock);
	string VerProvedor() const;
	void ModificarProvedor(string provedor);
	void AplicarPorcentaje(float porcentaje);
	Articulo& operator=(const Articulo &a);
	string ValidarDatos() const;
	float VerPorcentaje() const;
	float CalcularPrecioConPorcentaje();
private:
	string m_nombre;
	float m_costo;
	float m_porcentaje;
	float m_precio;
	int m_stock;
	string m_provedor;
};

#endif

