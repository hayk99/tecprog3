#pragma once

#include <memory>

class Elemento {
	string nombre;

public:
	Elemento();
	~Elemento();
	int obtenerTamanyo(int i = 0);
	string devolverNombre();
	void renombrar(const string& nombre);
};

class Archivo:Elemento {
	int tamanto;
public:
	Archivo();
	Archivo(const string& nombre);
	Archivo(const string& nombre, const int tam);
	~Archivo();
	int obtenerTamanyo(int i = 0);
	void cambiarTamaño(const int tam);
};

class Directorio:Elemento {
	std::List<Elemento> elementos;
	int numElementos;
public:
	Directorio();
	~Directorio();
	int obtenerTamanyo(int i = 0);
	void añadir(const Elemento& fichero);
	bool borrar(const string& fichero);
};

class Enlace:Elemento {
	std::shared_ptr<Elemento> ptr;
public:
	Enlace(const string& nombre, const Elemento& fichero);
	~Enlace();
	int obtenerTamanyo(int i = 0);
};