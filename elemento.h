#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <list>

using namespace std;

class Elemento {
protected:
	string nombre;
public:
	Elemento();
	~Elemento();
	string devolverNombre();
	void renombrar(const string& nombre);

	virtual int obtenerTamanyo(int i = 0) = 0;
	virtual bool cambiarTamanyo(const int tam) = 0; // Devuelve true si ha cambiado el tamaño, false si no (es un directorio)
};
