#include "ruta.h"

Elemento::Elemento() {}

Elemento::~Elemento() {}


string Elemento::devolverNombre(){
	return nombre;
}

void Elemento::renombrar(const string& nombre){
	Elemento::nombre = nombre;
}



Archivo::Archivo(){
	nombre = "nuevo";
	tamanyo = 1;
}

Archivo::Archivo(const string& nombre){
	Archivo::nombre = nombre;
	tamanyo = 1;
};

Archivo::Archivo(const string& nombre, const int tam){
	Archivo::nombre = nombre;
	tamanyo = tam;
}

Archivo::~Archivo() {}

int Archivo::obtenerTamanyo(int i) {
	return tamanyo;
};

void Archivo::cambiarTamanyo(const int tam){
	tamanyo =  tam;
};

Enlace::Enlace(const string& nombre, const Elemento& fichero){
	Enlace::nombre = nombre;
	*ptr = fichero;
}

Enlace::~Enlace() {}

int Enlace::obtenerTamanyo(int i){
	if (i > 1024){
		cout << "Maximo nivel de recursividad alcanzado jeje" << endl;
		return 0;
	}
	else{
		return (*ptr).obtenerTamanyo(i+1);
	}
};

Directorio::Directorio(){
	nombre = "nuevo dir";
	numElementos = 0;
}

Directorio::Directorio(const string& nombreDir){
	nombre = nombreDir;
	numElementos = 0;
}

Directorio::~Directorio(){}

void Directorio::anyadir(const Elemento& fichero){
	
};

bool Directorio::borrar(const string& fichero){

};

int Directorio::obtenerTamanyo(int i){
	int total = 0;
	for(const auto& e:elementos){
		total += e.obtenerTamanyo(i);
	}
	return total;
}






