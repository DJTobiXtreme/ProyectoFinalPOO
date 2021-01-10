#include "Utils.h"
#include <vector>
#include <algorithm>
#include "Fecha.h"
using namespace std;

string devolver_fecha_hoy ( ){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	
	stringstream ss;
	ss<<ltm->tm_mday<<"/"<<ltm->tm_mon+1<<"/"<<ltm->tm_year%100;
	
	return ss.str();
}

Fecha devolver_fecha_hoy(int) {
	time_t now = time(0);
	tm *ltm = localtime(&now);
	
	Fecha f;
	f.anio=ltm->tm_year%100;
	f.mes=ltm->tm_mon+1;
	f.dia=ltm->tm_mday;
	
	return f;
}
	
string AcomodarParaFloat(string &s){
	auto it = s.find('.',0);
	s = s.substr(0,it+3);
	return s;
}
	
bool es_int (const string & s) {
	auto it = s.begin();
	while(it != s.end() and isdigit(*it)) ++it;
	return !s.empty() and it == s.end();
}


bool es_float (const string &s) {
	int contp = 0;
	for(size_t i=0;i<s.length();){
		if(s[i] == '.' and contp <= 1){
			contp++;
			i++;
			continue;
		}
		else if(isdigit(s[i])) ++i;
		else return false;
	}
	return true;
}

void pasar_a_minusculas(std::string & s) {
	int i,c=s.size();
	for (i=0;i<c;i++)
		s[i]=std::tolower(s[i]);
}

void AcomodarGrilla(wxWindow *w, wxGrid *grilla, int size) {
	w->Layout();
	int ancho_total_viejo=0;
	vector<int>tamanios(size);
	for (int i=0;i<size;i++) { 
		tamanios[i] = grilla->GetColSize(i);
		ancho_total_viejo += tamanios[i];
	}
	int ancho_total_nuevo= grilla->GetSize().GetWidth();
	grilla->BeginBatch();
	for (int i=0;i<size;i++) 
		grilla->SetColSize(i,tamanios[i]*ancho_total_nuevo/ancho_total_viejo);
	grilla->EndBatch();
}

string fecha_a_string(const Fecha & f) {
	string str = to_string(f.dia)+'/'+to_string(f.mes)+'/'+to_string(f.anio);
	return str;
}

