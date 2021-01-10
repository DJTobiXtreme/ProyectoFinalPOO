#include "Cliente.h"

Cliente::Cliente() { }


Cliente::Cliente (string nombre, string telefono, string direccion, string bici): m_nombre(nombre), 
	m_direccion(direccion), m_telefono(telefono), m_bici(bici){ }

string Cliente::VerNombre() const {
	return m_nombre;
}

string Cliente::VerDireccion() const {
	return m_direccion;
}

string Cliente::VerTelefono() const {
	return m_telefono;
}

void Cliente::ModificarNombre(string nombre) {
	m_nombre = nombre;
}

void Cliente::ModificarTelefono(string telefono) {
	m_telefono = telefono;
}

void Cliente::ModificarDireccion(string direccion) {
	m_direccion = direccion;
}

string Cliente::VerBici () const {
	return m_bici;
}

string Cliente::ValidarDatos ( ) const {
	string errores;
	if(m_nombre.size()==0) errores+="El nombre no puede estar vacío\n";
	if(m_telefono.size()==0) errores+="El telefono no puede estar vacío\n";
	if(m_direccion.size()==0) errores+="La dirección no puede estarvacía\n";
	if(m_bici.size()==0) errores+="La bicicleta no puede estar vacía\n";
	return errores;
}

void Cliente::ModificarBici (string bici) {
	m_bici = bici;
}

