#include "Bicicleteria.h"
#include <fstream>
#include <string>
#include <iostream>
#include "Utils.h"
#include <cstring>
using namespace std;

Bicicleteria::Bicicleteria(string archiArticulos, string archiClientes, string archiVentas, string archiDetalleVentas)
	: m_archiArticulos(archiArticulos), m_archiClientes(archiClientes), m_archiVentas(archiVentas), m_archiDetalleVentas(archiDetalleVentas) {
	
	CargarClientesArchi(m_archiClientes);
	CargarArticulosArchi(m_archiArticulos);
	CargarVentasArchi(m_archiVentas);
}

struct AuxCliente{
	char nombre[256];
	char direccion[256];
	char telefono[256];
	char bici[256];
};

void Bicicleteria::AgregarArticulo (Articulo a) {
	m_articulos.push_back(a);
}

void Bicicleteria::CargarArticulosArchi (string nombreArchi) {
	ifstream fin(m_archiArticulos);
	string nombre; float costo; float porcentaje; float precio; int stock; string provedor;
	
	while(getline(fin,nombre)){
		fin>>costo>>porcentaje>>precio>>stock;
		fin.ignore();
		getline(fin,provedor);
		m_articulos.push_back({nombre,costo,porcentaje,precio,stock,provedor});
	}
}

Articulo & Bicicleteria::VerArticulo (int indice) {
	return m_articulos[indice];
}

void Bicicleteria::EliminarArticulo (int indice) {
	m_articulos.erase(m_articulos.begin()+indice);
}

void Bicicleteria::GuardarArticulos () {
	ofstream fout(m_archiArticulos);
	for(Articulo a : m_articulos) { 
		fout << a.VerNombre() << endl;
		fout << a.VerCosto() << endl;
		fout << a.VerPorcentaje() << endl;
		fout << a.VerPrecio() << endl;
		fout << a.VerStock() << endl;
		fout << a.VerProvedor() << endl;
	}
}

void Bicicleteria::CargarClientesArchi (string nombreArchi) {
	ifstream fin(m_archiClientes,ios::binary|ios::ate);
	int tamanio = fin.tellg()/sizeof(AuxCliente);
	fin.seekg(0);
	AuxCliente auxcliente;
	Cliente c;
	for(int i=0;i<tamanio;++i) { 
		fin.read(reinterpret_cast<char*>(&auxcliente),sizeof(auxcliente));
		c.ModificarNombre(auxcliente.nombre);
		c.ModificarDireccion(auxcliente.direccion);
		c.ModificarTelefono(auxcliente.telefono);
		c.ModificarBici(auxcliente.bici);
		m_clientes.push_back(c);
	}
}

void Bicicleteria::AgregarCliente (Cliente c) {
	m_clientes.push_back(c);
}

Cliente Bicicleteria::VerCliente (int indice) const {
	return m_clientes[indice];
}

void Bicicleteria::GuardarClientes ( ) {
	ofstream fout(m_archiClientes,ios::binary);
	AuxCliente auxcliente;
	for(Cliente c : m_clientes){
		strcpy(auxcliente.nombre,c.VerNombre().c_str());
		strcpy(auxcliente.direccion,c.VerDireccion().c_str());
		strcpy(auxcliente.telefono,c.VerTelefono().c_str());
		strcpy(auxcliente.bici,c.VerBici().c_str());
		fout.write(reinterpret_cast<char*>(&auxcliente),sizeof(auxcliente));
	}
}

void Bicicleteria::CargarVentasArchi (string nombreArchi) {
	ifstream fin(m_archiVentas);
	int dia, mes, anio, indice;
	Fecha fecha;
	float precio_venta;
	float ganancia_venta;
	string nombre_cliente;
	vector<ArticuloEnVenta>v_articulos;
	while(fin>>dia>>mes>>anio){
		fecha={dia,mes,anio};
		fin >> precio_venta;
		fin >> ganancia_venta;
		fin >> nombre_cliente;
		fin >> indice;
		Venta aux(fecha,nombre_cliente,precio_venta,ganancia_venta,v_articulos,indice);
		m_ventas.push_back(aux);
	}
	
}

void Bicicleteria::AgregarVenta (Venta v) {
	m_ventas.push_back(v);
}

Venta Bicicleteria::VerVenta (int indice) const {
	return m_ventas[indice];
	
}

void Bicicleteria::GuardarVentas ( ) {
	ofstream fout(m_archiVentas);
	for(Venta v : m_ventas){
		fout << v.VerDia() << " " << v.VerMes() << " " << v.VerAnio() << endl;
		fout << v.VerPrecioACobrar()<< endl;
		fout << v.VerGanacia()<< endl;
		fout << v.VerCliente() << endl;
		fout << v.VerIndice() << endl;
	}
	ofstream foutD(m_archiDetalleVentas,ios::in|ios::ate);
	foutD << "NUEVA VENTA" << endl;
	foutD << m_ventas.size()-1 << endl;
	foutD << m_Detalles.size() << endl;
	for(size_t i=0;i<m_Detalles.size();i++) { 
		const ArticuloEnVenta &a = m_Detalles[i];
		foutD << a.articulo.VerNombre() << endl;
		foutD << a.articulo.VerCosto() << endl;
		foutD << a.articulo.VerPorcentaje() << endl;
		foutD << a.articulo.VerPrecio() << endl;
		foutD << a.articulo.VerStock() << endl;
		foutD << a.articulo.VerProvedor() << endl;
		foutD << a.cantidad << endl;
	}
	
}

int Bicicleteria::CantidadArticulos ( ) const {
	return m_articulos.size();
}

int Bicicleteria::CantidadClientes ( ) const {
	return m_clientes.size();
}

int Bicicleteria::CantidadVentas ( ) const {
	return m_ventas.size();
}

void Bicicleteria::EliminarCliente (int indice ) {
	m_clientes.erase(m_clientes.begin()+indice);
}

void Bicicleteria::EliminarVenta (int indice ) {
	m_ventas.erase( m_ventas.begin()+indice);
}

vector<ArticuloEnVenta> Bicicleteria::BuscarDetalleVenta (int indice) const {
	ifstream fin(m_archiDetalleVentas);
	//Declaraciones
	string aux, size;
	string nombre_articulo;
	float costo, porcentaje, precio;
	int stock;
	string provedor;
	int cantidad_articulo;
	vector<ArticuloEnVenta>v_articulos;
	//Busqueda
	while(getline(fin,aux)){
		if(aux == "NUEVA VENTA"){
			getline(fin,aux);
			if(aux == to_string(indice)){
				getline(fin,size);
				int s = stoi(size);
				for(int i=0;i<s;i++){
					getline(fin,nombre_articulo);			
					fin>>costo>>porcentaje>>precio>>stock;
					fin.ignore();
					getline(fin, provedor);
					fin >> cantidad_articulo;
					fin.ignore();
					Articulo a(nombre_articulo,costo,porcentaje,precio,stock,provedor);
					v_articulos.push_back({a,cantidad_articulo});
				}
			}
		}
	}
	return v_articulos;
}

void Bicicleteria::AgregarDetalle (vector<ArticuloEnVenta> v) {
	m_Detalles = v;
}
