#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <list>

class Elemento {
protected:
	string nombre;
public:
	Elemento();
	virtual int obtenerTamanyo(int i = 0) = 0;
	string devolverNombre();
	void renombrar(const string& nombre);
};
