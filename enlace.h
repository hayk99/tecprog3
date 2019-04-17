#pragma once

#include "elemento.h"
#include <memory>
#include <string>
#include <iostream>
#include <list>

class Enlace : public Elemento {
	std::weak_ptr<Elemento> ptr;  // No puede ser shared pointer para que no retenga un elemento que ha sido borrado
public:
	Enlace(const string& nombre, const shared_ptr<Elemento>& e);
	~Enlace();
	int obtenerTamanyo(int i = 0) override;
	bool obtenerElemento(shared_ptr<Elemento>& e);
	bool cambiarTamanyo(const int tam) override;
};
