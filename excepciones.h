#pragma once

#include <exception>
#include <iostream>

using namespace std;

class ExcepcionArbolFicheros {
public:
	ExcepcionArbolFicheros() noexcept;
	virtual const char* what() const noexcept;
};

class CambioTamanyoDirectorio : public ExcepcionArbolFicheros {
public:
	const char* what() const noexcept;
};

class RutaCorrupta : public ExcepcionArbolFicheros {
public:
	const char* what() const noexcept;
};

class NombreRepetido : public ExcepcionArbolFicheros {
public:
	const char* what() const noexcept;
};



