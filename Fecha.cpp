bool tiene31(int mes) {
	return(mes == 1 or mes == 3 or mes == 5 or mes == 7 or mes == 8 or mes == 10 or mes == 12);
}

bool tiene30(int mes) {
	return(mes != 2 and not tiene31(mes));
}

