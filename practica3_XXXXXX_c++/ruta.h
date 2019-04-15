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
	virtual int obtenerTamanyo(int i = 0) = 0;
	string devolverNombre();
	void renombrar(const string& nombre);
};


class Archivo:Elemento {
	int tamanyo;
public:
	Archivo();
	Archivo(const string& nombre);
	Archivo(const string& nombre, const int tam);
	~Archivo();
	int obtenerTamanyo(int i = 0) override;
	void cambiarTamanyo(const int tam);
};

class Enlace:Elemento {
	std::shared_ptr<Elemento> ptr;
public:
	Enlace(const string& nombre, const Elemento& fichero);
	~Enlace();
	int obtenerTamanyo(int i = 0) override;
};

class Directorio:Elemento {
	list<shared_ptr<Elemento>> elementos;
	int numElementos;
public:
	Directorio();
	Directorio(const string& nombreDir);
	~Directorio();
	int obtenerTamanyo(int i = 0)  override;
	void anyadir(const shared_ptr<Elemento>& elemento);
	bool borrar(const string& fichero);
	void mostrarElementos(string& salida);
	bool devolverElemento(const string& fichero, shared_ptr<Elemento>& elemento);
};

class Ruta {
	string ruta; // Para sacar por pantalla la ruta
	std::list<std::shared_ptr<Directorio>> rutaActual;  // Lista de punteros a los directorios por los que se ha bajado
	std::shared_ptr <Directorio> dirActual; // Puntero al directorio actual

public:
	Ruta(Directorio& root_);
	~Ruta();
	string pwd();
	void ls();
	//void cd(string path);
	//void stat(string element);
};

