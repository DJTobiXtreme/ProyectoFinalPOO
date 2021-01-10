#ifndef UTILS_H
#define UTILS_H
#include <ctime>
#include <sstream>
#include <cctype>
#include "Fecha.h"
#include <wx/grid.h>
using namespace std;
	
string devolver_fecha_hoy ();

Fecha devolver_fecha_hoy (int);

void AcomodarGrilla(wxWindow *w, wxGrid *grilla, int size);

Fecha string_a_fecha(const string &str);

string fecha_a_string(const Fecha &f);

string AcomodarParaFloat(string &s);
	
bool es_int (const string & s);

bool es_float (const string &s);

void pasar_a_minusculas(std::string &s);



#endif
