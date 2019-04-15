#pragma once

#include "elemento.h"
#include <memory>
#include <string>
#include <iostream>
#include <list>

class Archivo : public Elemento {
	int tamanyo;
public:
	Archivo();
	Archivo(const string& nombre);
	Archivo(const string& nombre, const int tam);
	int obtenerTamanyo(int i = 0) override;
	bool cambiarTamanyo(const int tam);
};