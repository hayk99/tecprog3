#include "ruta.h"
#include <memory>
#include <string>
#include <iostream>
#include <list>

using namespace std;

int main(){
	Directorio root("");
	Ruta r(root);
	r.vim("A", 10);
	r.mkdir("Dir 1");
	r.ln("Dir 1", "Enlace");
	r.ls();
	r.stat("/Enlace");

	return 0;
}