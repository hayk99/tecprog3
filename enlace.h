#pragma once

#include "elemento.h"
#include <memory>
#include <string>
#include <iostream>
#include <list>
#include "excepciones.h"

class Enlace : public Elemento {
	std::shared_ptr<Elemento> ptr;  // No puede ser shared pointer para que no retenga un elemento que ha sido borrado
public:
	Enlace(const string& nombre, const shared_ptr<Elemento>& e);
	~Enlace();
	int obtenerTamanyo(int i = 0) override;
	bool obtenerElemento(shared_ptr<Elemento>& e);
	bool cambiarTamanyo(const int tam) override;
};
