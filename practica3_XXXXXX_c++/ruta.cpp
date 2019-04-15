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

void Directorio::anyadir(const shared_ptr<Elemento>& elemento){
	elementos.push_back(elemento);
};


bool Directorio::borrar(const string& fichero){
	bool encontrado = false; // Por que no se pueden declarar variables de distinto tipo en un for
	for(list<shared_ptr<Elemento>>::iterator i = elementos.begin(); !encontrado && i != elementos.end(); i++){
		if((*(*i)).devolverNombre() == fichero){
			encontrado = true;
			elementos.erase(i);
		}
	}
	return encontrado;
}

void Directorio::mostrarElementos(string& salida){
	salida = "";
	for(auto& e:elementos){
		salida += (*e).devolverNombre();
	}
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

Ruta::Ruta(Directorio& root_): ruta("/"), dirActual(dirActual) {
	shared_ptr<Directorio> ptr(&root_);
	rutaActual.push_back(ptr);
};

Ruta::~Ruta() {};

string Ruta::pwd() { 
	return ruta;
}

void Ruta::ls() {
	string e;
	(*dirActual).mostrarElementos(e);
	cout <<  e << endl;
}






