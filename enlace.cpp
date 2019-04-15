#include "enlace.h"

Enlace::Enlace(const string& nombre, const shared_ptr<Elemento>& e): ptr(e) {}

int Enlace::obtenerTamanyo(int i){
	if (i > 1024){
		cout << "Maximo nivel de recursividad alcanzado jeje" << endl;
		return 0;
	}
	else{
		return (*(ptr.lock())).obtenerTamanyo(i+1);
	}
}
