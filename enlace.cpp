#include "enlace.h"

Enlace::Enlace(const string& nombre, const shared_ptr<Elemento>& e): ptr(e){
	Enlace::nombre = nombre;
}

int Enlace::obtenerTamanyo(int i){
	cout << i << endl;
	if (i > 1024){
		cout << "Maximo nivel de recursividad alcanzado jeje" << endl;
		return 0;
	}
	else{
		return (*(ptr.lock())).obtenerTamanyo(i+1);
	}
}

bool Enlace::cambiarTamanyo(const int tam){
	return (*(ptr.lock())).cambiarTamanyo(tam);

}
