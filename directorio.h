#pragma once

#include "elemento.h"
#include <memory>
#include <string>
#include <iostream>
#include <list>

class Directorio : public Elemento {
	list<shared_ptr<Elemento>> elementos;
public:
	Directorio();
	Directorio(const string& nombreDir);
	int obtenerTamanyo(int i = 0)  override;
	bool cambiarTamanyo(const int tam) override;
	void anyadir(const shared_ptr<Elemento>& elemento);
	bool borrar(const string& fichero);
	void mostrarElementos(string& salida);
	bool devolverElemento(const string& fichero, shared_ptr<Elemento>& elemento);
};
