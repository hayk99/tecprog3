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



