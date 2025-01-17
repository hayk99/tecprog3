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

const char* cdErroneo::what() const noexcept {
	return "Parámetro de cd erroneo";
}

const char* noSalirse::what() const noexcept {
	return "No hay mas cd";
};

const char* recursividadInfinita::what() const noexcept {
	return "No se puede calcular el tamanyo debido a que hay un enlace a un directorio superior";
};

const char* cdArchivo::what() const noexcept {
	return "No se puede cd a un archivo";
};