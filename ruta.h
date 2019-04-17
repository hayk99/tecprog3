#pragma once

#include "elemento.h"
#include "directorio.h"
#include "enlace.h"
#include "archivo.h"
#include <memory>
#include <string>
#include <iostream>
#include <list>
#include <sstream>

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
	void cd(string path);
	void stat(const string& path);
	void vim(string vim,const int size);
	void mkdir(string dir);
	void ln(string orig, string dest);
	void rm(const string& path);
	bool addList (string& path, shared_ptr<Elemento>& ptr, string& dir);
};
