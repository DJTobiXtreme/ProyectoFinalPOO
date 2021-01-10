#include "Articulo.h"

Articulo::Articulo(string nombre, float costo, float porcentaje, int stock, string provedor) : 
	m_nombre(nombre), m_costo(costo), m_porcentaje(porcentaje), m_stock(stock), m_provedor(provedor) {
	m_precio = CalcularPrecioConPorcentaje();
}

Articulo::Articulo(string nombre, float costo, float porcentaje, float precio, int stock, string provedor) : 
	m_nombre(nombre), m_costo(costo), m_porcentaje(porcentaje), m_precio(precio), m_stock(stock), m_provedor(provedor) {
}

string Articulo::VerNombre ( ) const {
	return m_nombre;
}

void Articulo::ModificarNombre (string nombre) {
	m_nombre = nombre;
}

float Articulo::VerCosto ( ) const {
	return m_costo;
}

void Articulo::ModificarCosto (float costo) {
	m_costo = costo;
}

float Articulo::VerPrecio ( ) const {
	return m_precio;
}

void Articulo::ModificarPrecio (float precio) {
	m_precio = precio;
}

int Articulo::VerStock ( ) const {
	return m_stock;
}

void Articulo::ModificarStock (int stock) {
	m_stock = stock;
}

string Articulo::VerProvedor ( ) const {
	return m_provedor;
}

void Articulo::ModificarProvedor (string provedor) {
	m_provedor = provedor;
}

Articulo& Articulo::operator= (const Articulo & a) {
	this->m_nombre = a.m_nombre;
	this->m_costo = a.m_costo;
	this->m_precio = a.m_precio;
	this->m_stock = a.m_stock;
	this->m_porcentaje = a.m_porcentaje;
	this->m_provedor = a.m_provedor;
	return *this;
}

string Articulo::ValidarDatos ( ) const {
	string errores;	
	if (m_nombre.size()==0) errores+="El nombre no puede estar vacio\n";
	if (m_costo<0) errores+="El costo no puede ser negativo vacio\n";
	if (m_costo>m_precio) errores+="El costo no puede ser mayor al precio\n";
	if (m_precio<0) errores+="El precio no puede ser negativo\n";
	if (m_stock<0) errores+="El stock es invalido\n";
	if (m_provedor.size()==0) errores+="El provedor no puede estar vacio\n";
	return errores;
}

Articulo::Articulo ( ) {
	
}

void Articulo::RestarStock (int StockARestar) {
	m_stock -= StockARestar;
}

void Articulo::AplicarPorcentaje (float porcentaje) {
	porcentaje += 1;
	m_precio *= porcentaje;
	m_costo *= porcentaje;
}

float Articulo::VerPorcentaje ( ) const {
	return m_porcentaje;
}

float Articulo::CalcularPrecioConPorcentaje ( ) {
	return m_costo*(m_porcentaje+1);
}

