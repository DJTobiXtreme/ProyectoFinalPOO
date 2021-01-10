#include "Venta.h"

Venta::Venta() {
	
}


int Venta::VerCantVendida() const {
	return m_articulos_venta.size();
}
float Venta::VerPrecioACobrar ( ) const {
	return m_precio_venta;
}

float Venta::VerGanacia ( ) const {
	return m_ganacia_venta;
}

void Venta::CalcularDatos ( ) {
	m_precio_venta = 0;
	float sumCosto = 0;
	for(ArticuloEnVenta a:m_articulos_venta){
		m_precio_venta += (a.articulo.VerPrecio()*a.cantidad);
		sumCosto += (a.articulo.VerCosto()*a.cantidad);
	}
	m_ganacia_venta = m_precio_venta-sumCosto;
	
}

void Venta::AgregarArticulo (ArticuloEnVenta articulo) {
	m_articulos_venta.push_back(articulo);
}

void Venta::EliminarArticulo (int indice) {
	m_articulos_venta.erase(m_articulos_venta.begin()+indice);
}

ArticuloEnVenta Venta::VerArticulo (int indice) const{
	return m_articulos_venta[indice];
}

string Venta::VerCliente ( ) const {
	return m_cliente;
}

void Venta::CargarCliente (string cliente) {
	m_cliente = cliente;
}

int Venta::size ( ) const {
	return m_articulos_venta.size();
}

Venta::Venta (Fecha f, string cliente, float precio_venta, float ganancia_venta, vector<ArticuloEnVenta> v, int indice):
	m_fecha(f),m_cliente(cliente), m_precio_venta(precio_venta), m_ganacia_venta(ganancia_venta),m_articulos_venta(v), m_indice(indice){
}

Fecha Venta::VerFecha ( ) const {
	return m_fecha;
}

int Venta::VerDia ( ) const {
	return m_fecha.dia;
}

int Venta::VerMes ( ) const {
	return m_fecha.mes;
}

int Venta::VerAnio ( ) const {
	return m_fecha.anio;
}

int Venta::VerIndice ( ) const {
	return m_indice;
}

