#include "ruta.h"
#include <memory>
#include <string>
#include <iostream>
#include <list>

using namespace std;

int main(){
	/*shared_ptr<Archivo> ptrA = make_shared<Archivo>("A");
	(*ptrA).cambiarTamanyo(21);
	shared_ptr<Archivo> ptrB = make_shared<Archivo>("B");
	shared_ptr<Archivo> ptrC = make_shared<Archivo>("C");
	shared_ptr<Archivo> ptrD = make_shared<Archivo>("D");
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
	Ruta r((*ptrDir1));
	cout << "del main: voy a eliminar \n";

	cout << endl <<endl;
	cout << (*ptrRoot).mostrarElementos() << endl;
	//cout << (*ptrDir1).obtenerTamanyo() << endl;
	cout << "=========================="<< endl;
	cout << (*ptrDir1).mostrarElementos() << endl;
	//cout << (*ptrDir1).obtenerTamanyo() << endl;
	cout << "=========================="<< endl;
	cout << (*ptrDir2).mostrarElementos() << endl;
	//cout << (*ptrDir2).obtenerTamanyo() << endl;
	cout << "=========================="<< endl;

	r.rm("Dir 1/Dir 2/D");
	r.rm("C");

	cout << endl <<endl;
	cout << (*ptrRoot).mostrarElementos() << endl;
	//cout << (*ptrDir1).obtenerTamanyo() << endl;
	cout << "=========================="<< endl;
	cout << (*ptrDir1).mostrarElementos() << endl;
	//cout << (*ptrDir1).obtenerTamanyo() << endl;
	cout << "=========================="<< endl;
	cout << (*ptrDir2).mostrarElementos() << endl;
	//cout << (*ptrDir2).obtenerTamanyo() << endl;
	cout << "=========================="<< endl;


	*/
	Directorio nuevo("");
	Ruta ruta(nuevo);
	//cout << nuevo.mostrarElementos() << endl;
	//ruta.ls();
	ruta.pwd();	

	ruta.mkdir("hey");
	ruta.pwd();	
	ruta.mkdir("hey2");
	ruta.pwd();	

	cout << "==================================="<<endl;
	ruta.ls();
	cout << "==================================="<<endl;

	ruta.
	return 0;
}