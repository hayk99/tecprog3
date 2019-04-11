#include "ruta.h"

Elemento::Elemento();

Elemento::~Elemento();

virtual int Elemento::obtenerTamanyo(int i = 0) = 0 const;

string devolverNombre(){
	return nombre;
}

void Elemento::renombrar(const string& nombre) Elemento::nombre(nombre);

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

Archivo::~Archivo();

int Archivo::obtenerTamanyo(int i = 0){
	return tamanyo;
};

void Archivo::cambiarTamaño(const int tam) tamanyo(tam) {};



Directorio::Directorio();

Directorio::~Directorio();

void Directorio::añadir(const Elemento& fichero){
	
};

bool Directorio::borrar(const string& fichero){

};

int Directorio::obtenerTamanyo(int i = 0){
	int total = 0;
	for(const auto& e::elementos){
		total = e.obtenerTamanyo();
	}
	return total;
};

Enlace::Enlace(const string& nombre, const Elemento& fichero){
	Enlace::nombre = nombre;
	ptr = &fichero;
}

Enlace::~Enlace();

int Enlace::obtenerTamanyo(int i = 0){
	if (i > 1024){
		cout "Maximo nivel de recursividad alcanzado jeje" << endl;
		return 0;
	}
	else{
		return *ptr.obtenerTamanyo(i+1);
	}
};






