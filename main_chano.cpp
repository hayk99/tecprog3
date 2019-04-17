#include "ruta.h"
#include <memory>
#include <string>
#include <iostream>
#include <list>

using namespace std;

int main(){
	shared_ptr<Archivo> ptrA = make_shared<Archivo>("A");
	(*ptrA).cambiarTamanyo(21);
	shared_ptr<Archivo> ptrB = make_shared<Archivo>("B");
	shared_ptr<Archivo> ptrC = make_shared<Archivo>("C");
	shared_ptr<Archivo> ptrD = make_shared<Archivo>();
	(*ptrD).cambiarTamanyo(3);
	shared_ptr<Directorio> ptrRoot = make_shared<Directorio>("/");
	shared_ptr<Directorio> ptrDir1 = make_shared<Directorio>("Dir 1");
	shared_ptr<Directorio> ptrDir2 = make_shared<Directorio>("Dir 2");
	shared_ptr<Enlace> ptrE = make_shared<Enlace>("eA", ptrA);



	(*ptrRoot).anyadir(ptrA);
	(*ptrRoot).anyadir(ptrB);
	(*ptrRoot).anyadir(ptrDir1);
	(*ptrDir1).anyadir(ptrC);
	(*ptrDir1).anyadir(ptrDir2);
	(*ptrDir2).anyadir(ptrD);
	(*ptrDir2).anyadir(ptrE);
	Ruta r((*ptrRoot));
	r.stat("Dir 1/Dir 2/eA");
/*
	cout << (*ptrDir1).mostrarElementos() << endl;
	cout << (*ptrDir1).obtenerTamanyo() << endl;
	cout << "=========================="<< endl;
	cout << (*ptrDir2).mostrarElementos() << endl;
	cout << (*ptrDir2).obtenerTamanyo() << endl;
	cout << "=========================="<< endl;
*/


	return 0;
}