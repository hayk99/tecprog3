#include "ruta.h"

Ruta::Ruta(Directorio& root){
	dirActual = make_shared<Directorio>(root);
	rutaActual.push_back(dirActual);
}

Ruta::~Ruta() {};

string Ruta::pwd() { 
	return ruta;
}

void Ruta::ls() {
	string e;
	(*dirActual).mostrarElementos(e);
	cout <<  e << endl;
}
