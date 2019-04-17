#include <exception>
#include "excepciones.h"

arbol_ficheros_error::arbol_ficheros_error() noexcept {}

const char* arbol_ficheros_error::what() const noexcept{
	return "Error en el Arbol de ficheros";
}

const char* CambioTamanyoDirectorio::what() const noexcept {
	return "Es un directorio, no se puede cambiar su tamanyo";
}

const char* RutaCorrupta::what() const noexcept {
	return "La ruta introducida no es valida";
}

const char* NombreRepetido::what() const noexcept {
	return "Ya existe un elemento con ese nombre";
}