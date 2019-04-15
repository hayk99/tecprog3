#include "elemento.h"

Elemento::Elemento() {}

string Elemento::devolverNombre(){
	return nombre;
}

void Elemento::renombrar(const string& nombre){
	Elemento::nombre = nombre;
}
