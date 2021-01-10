#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
using namespace std;

class Cliente {
public:
	Cliente();
	Cliente(string nombre, string telefono, string direccion, string bici);
	string VerNombre() const;
	string VerDireccion() const;
	string VerTelefono() const;
	void ModificarNombre(string nombre);
	void ModificarTelefono(string telefono);
	void ModificarDireccion(string direccion);
	void ModificarBici(string bici);
	string VerBici() const;	
	string ValidarDatos() const;
private:
	string m_nombre;
	string m_direccion;
	string m_telefono;
	string m_bici;
};

#endif

