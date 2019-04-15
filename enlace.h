#pragma once

#include "elemento.h"

class Enlace : public Elemento {
	std::weak_ptr<Elemento> ptr;  // No puede ser shared pointer para que no retenga un elemento que ha sido borrado
public:
	Enlace(const string& nombre, const shared_ptr<Elemento>& e);
	int obtenerTamanyo(int i = 0) override;
};
