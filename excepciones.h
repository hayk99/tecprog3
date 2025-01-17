#pragma once

#include <exception>
#include <iostream>

using namespace std;

class arbol_ficheros_error {
public:
	arbol_ficheros_error() noexcept;
	virtual const char* what() const noexcept;
};

class CambioTamanyoDirectorio : public arbol_ficheros_error {
public:
	const char* what() const noexcept;
};

class RutaCorrupta : public arbol_ficheros_error {
public:
	const char* what() const noexcept;
};

class NombreRepetido : public arbol_ficheros_error {
public:
	const char* what() const noexcept;
};

class cdErroneo : public arbol_ficheros_error {
public:
	const char* what() const noexcept;
};

class noSalirse : public arbol_ficheros_error {
public:
	const char* what() const noexcept;
};

class recursividadInfinita : public arbol_ficheros_error {
public:
	const char* what() const noexcept;
};

class cdArchivo : public arbol_ficheros_error {
	const char* what() const noexcept ;
};



