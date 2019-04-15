#include "ruta.h"
#include <memory>
#include <string>
#include <iostream>
#include <list>

using namespace std;

int main(){
	Archivo a("A");
	Archivo b("B");
	Archivo c("C");
	shared_ptr<Archivo> ptrA = make_shared<Archivo>(a);
	shared_ptr<Archivo> ptrB = make_shared<Archivo>(b);
	shared_ptr<Archivo> ptrC = make_shared<Archivo>(c);


	Directorio d1("Dir 1");
	shared_ptr<Directorio> ptrDir1 = make_shared<Directorio>(d1);
	Directorio d2("Dir 2");
	shared_ptr<Directorio> ptrDir2 = make_shared<Directorio>(d2);
	Enlace e1("Enlace a A", ptrA);
	Enlace e2("Enlace a Dir1", ptrDir1);
	d1.anyadir(ptrA);
	d1.anyadir(ptrB);
	d1.anyadir(ptrC);
	d1.anyadir(ptrDir2);
	shared_ptr<Enlace> ptrE1 = make_shared<Enlace>(e1);
	shared_ptr<Enlace> ptrE2 = make_shared<Enlace>(e2);
	d2.anyadir(ptrE1);
	d2.anyadir(ptrE2);
/*
	string lista;
	cout << "Elementos en " << d1.devolverNombre() << endl << "===============" << endl;
	d1.mostrarElementos(lista);
	cout << lista << endl;
	cout << "El tamanyo es de " << d1.obtenerTamanyo() << endl;



	d1.anyadir(ptrDir2);
	cout << "Elementos en " << d2.devolverNombre() << endl << "===============" << endl;
	d2.mostrarElementos(lista);
	cout << lista << endl;
	cout << "El tamanyo es de " << d2.obtenerTamanyo() << endl;
*/
	cout << e1.obtenerTamanyo() << endl;



	return 0;
}