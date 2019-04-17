#include "ruta.h"
#include <memory>
#include <string>
#include <iostream>
#include <list>

using namespace std;

int main(){
	Directorio root("");
	Ruta r(root);
	r.mkdir("home");
	r.mkdir("home");
	r.mkdir("bin");
	r.mkdir("etc");
	cout << "llego"<<endl;
	r.cd("home");
	r.mkdir("desk");
	r.mkdir("docs");
	r.vim("text.txt", 500);
	r.cd("docs");
	r.mkdir("gifs");
	r.mkdir("imagenes");
	r.cd("gifs");
	r.vim("ficheroGif.gif", 5000);
	r.cd("..");
	r.cd("..");
	r.pwd();
	r.cd("desk");
	r.mkdir("aoc");
	r.mkdir("tecprog");
	r.mkdir("unamas");
	r.cd("aoc");
	r.mkdir("p1");
	r.mkdir("p2");
	r.cd("p2");
	r.vim("fich1", 100);
	r.vim("fich2", 100);
	r.cd("..");
	r.cd("..");
	r.cd("tecprog");
	r.vim("hey",0);
	r.pwd();
	r.ls();
	
	r.cd("/");
	r.pwd();
	r.ls();
	r.cd("/home/desk/aoc/p22/");
	r.pwd();
	r.ls();/*
	r.rm("/home/desk/aoc/p2");
	r.cd("/home/desk/aoc");
	r.ls();
	r.cd("/");
	r.stat("/home/docs/gifs");
	r.cd("home");
	r.pwd();
	r.cd("/home/docs");
	r.ls();
	cout << endl << endl;
	r.pwd();
	
	r.ln("/home/desk/aoc/p1", "linkaoc");

	r.cd("linkaoc");
	r.pwd();
	r.ls();

//	r.ls();








	



	r.mkdir();
	r.mkdir();
	r.mkdir();
	r.mkdir();
*/
	return 0;
}