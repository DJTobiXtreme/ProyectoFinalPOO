#ifndef FECHA_H
#define FECHA_H

bool tiene31(int mes);
	
bool tiene30(int mes);

struct Fecha{
	int dia,mes,anio;
	Fecha &operator++(){
		if (this->mes==12 and this->dia == 31){
			++this->anio;
			this->mes = 1;
			this->dia = 1;
		} else if (tiene31(this->mes) and this->dia==31) {
			++this->mes;
			this->dia = 1;
		} else if (tiene30(this->mes) and this->dia==30) {
			++this->mes;
			this->dia = 1;
		} else if (this->mes==2 and this->anio%4==0 and this->dia==29) {
			++this->mes;
			this->dia = 1;
		} else if (this->mes==2 and !this->anio%4==0 and this->dia==28){
			++this->mes;
			this->dia = 1;
		} else {
			++this->dia;
		}
		return *this;
	}
	
	bool operator==(const Fecha &f){
		return(this->dia==f.dia and this->mes == f.mes and this->anio == f.anio);
	}
	
	bool operator<(const Fecha &f){
		if(this->anio < f.anio) return true;
		else if(this->anio == f.anio and this->mes < f.mes) return true;
		else if(this->anio == f.anio and this->mes == f.mes and this->dia < f.dia) return true;
		else return false;
	}
};

#endif
