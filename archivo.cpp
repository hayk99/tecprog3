#include "archivo.h"

Archivo::Archivo(){
	nombre = "nuevo";
	tamanyo = 1;
}

Archivo::Archivo(const string& nombre){
	Archivo::nombre = nombre;
	tamanyo = 1;
}

Archivo::Archivo(const string& nombre, const int tam){
	Archivo::nombre = nombre;
	tamanyo = tam;
}

int Archivo::obtenerTamanyo(int i) {
	return tamanyo;
}

bool Archivo::cambiarTamanyo(const int tam){
	tamanyo =  tam;
	return true;
}