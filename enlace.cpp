#include "enlace.h"

Enlace::Enlace(const string& nombre, const shared_ptr<Elemento>& e){
	Enlace::nombre = nombre;
	ptr = e;
}
Enlace::~Enlace(){}

int Enlace::obtenerTamanyo(int i){
	if (i > 1024){
		throw recursividadInfinita();
		return 0;
	}
	else{
		return (*ptr).obtenerTamanyo(i+1);
	}
}

bool Enlace::cambiarTamanyo(const int tam){
	return (*ptr).cambiarTamanyo(tam);

}
