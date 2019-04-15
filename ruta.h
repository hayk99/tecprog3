#pragma once

#include "elemento.h"
#include "directorio.h"
#include "enlace.h"
#include "archivo.h"
#include <memory>
#include <string>
#include <iostream>
#include <list>

using namespace std;

class Ruta {
	string ruta; // Para sacar por pantalla la ruta
	std::shared_ptr <Directorio> dirActual; // Puntero al directorio actual
	std::list<std::shared_ptr<Directorio>> rutaActual;  // Lista de punteros a los directorios por los que se ha bajado
public:
	Ruta(Directorio& root);
	~Ruta();
	string pwd();
	void ls();
	//void cd(string path);
	//void stat(string element);
};
