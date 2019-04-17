#include "directorio.h"

Directorio::Directorio(){
	nombre = "nuevo dir";
}

Directorio::Directorio(const string& nombreDir){
	nombre = nombreDir;
}

Directorio::~Directorio() {}

void Directorio::anyadir(const shared_ptr<Elemento>& elemento){
	elementos.push_back(elemento);
}

bool Directorio::borrar(const string& fichero){
	bool encontrado = false;
	for(list<shared_ptr<Elemento>>::iterator i = elementos.begin(); !encontrado && i != elementos.end(); i++){
		if((*(*i)).devolverNombre() == fichero){
			encontrado = true;
			elementos.erase(i);
		}
	}
	return encontrado;
}

string Directorio::mostrarElementos(){
	string salida;
	for(auto& e:elementos){
		salida += (*e).devolverNombre();
		salida += "\n";
	}
	salida.pop_back();
	return salida;
}

int Directorio::obtenerTamanyo(int i){
	int total = 0;
	for(auto& e:elementos){
		total += (*e).obtenerTamanyo(i);
	}
	return total;
}

bool Directorio::devolverElemento(const string& fichero, shared_ptr<Elemento>& elemento){
	bool encontrado = false;
	for(list<shared_ptr<Elemento>>::iterator i = elementos.begin(); !encontrado && i != elementos.end(); i++){
		if((*(*i)).devolverNombre() == fichero){
			encontrado = true;
			elemento = (*i);
		}
	}
	return encontrado;
}

bool Directorio::cambiarTamanyo(const int tam){
	throw CambioTamanyoDirectorio();
	return false;
}
