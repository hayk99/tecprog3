#include "ruta.h"

Ruta::Ruta(Directorio& root){
	dirActual = make_shared<Directorio>(root);
	rutaActual.push_back(dirActual);
}

Ruta::~Ruta() {};

string Ruta::pwd() { 
	return ruta;
}

void Ruta::ls() {
	string e = (*dirActual).mostrarElementos();
	cout <<  e << endl;
}


void Ruta::cd(string path) {
	if (path!=".") {
		if (path=="/") {  //quiere ir a raiz
			//destruir
			*rutaActual.erase(next(rutaActual.begin()), rutaActual.end());
			//actualizo string de ruta
			ruta = "/";
			//cojo ptr
			dirActual = rutaActual.front();
		}
		else if (path==".."){
			//quito un elemento
			rutaActual.pop_back();
			//cambio ptr a dir actual
			dirActual = rutaActual.back();
			//modifico string del nombre de la ruta actual 
			int lastSlash = ruta.rfind('/');
			int lastElement = ruta.length();
			ruta.erase(lastSlash, lastElement);

		}
		else if (path=="~"){ //va a home del usuario
			list<std::shared_ptr<Directorio>>::iterator iter;
			for (iter = rutaActual.begin(); rutaActual.end(); iter++) {
				shared_ptr<Directorio> aux = *iter;
				if ( (*iter).devolverNombre() = "home" )
					rutaActual.push_back(aux);
				else rutaActual.pop_back();
				iter++;
				aux=(*iter);
			}
		}
		else {
			shared_ptr<Directorio> aux = nullptr;
			if (path[0] != '/') { //entonces hago cd a un nodo hijo
				int pos = path.find('/'); //busco la barra
				if (pos > 0){ //path contiene varios nodos
					while (pos > 0) { // o sea hay una '/' al menos
						string dir = path.substr (0, pos); //cojo la primera parte
						if (devolverElemento(dir, aux)) {
							shared_ptr<Directorio> dado = dynamic_pointer_cast<Directorio>(aux);
							if (*dado != nullptr){
								rutaActual.push_back(aux);
								dirActual = dado;
								ruta += path;
								path.erase (0,pos+1) //borro ese parte del path
								pos = path.find('/');
							}
						}
					}
				}
				else if (devolverElemento(path, aux)) { //path esta compuesto solo por un hijo
					shared_ptr<Directorio> dado = dynamic_pointer_cast<Directorio>(aux);
					if (*dado != nullptr) {
						rutaActual.push_back(aux);
						dirActual = dado;
						ruta += path;
					}
				}
			}
			else if (path[0] == '/') {//es una ruta completa desde raiz
				path.erase(0,1);//borro la barra
				int pos = path.find('/');
				string dir = path.substr(0,pos); //saco el primer directorio
				if (dir == "home") {//esta bien introducida la ruta completa, puedo seguir
					int pos = path.find('/'); //busco la barra
					while (pos > 0) { // o sea hay una '/' al menos
						dir = path.substr (0, pos); //cojo la primera parte
						if (devolverElemento(dir, aux)) {
							shared_ptr<Directorio> dado = dynamic_pointer_cast<Directorio>(aux);
							if (*dado != nullptr){
									rutaActual.push_back(aux);
									dirActual = dado;
									ruta += path;
									path.erase (0,pos+1); //borro ese parte del path
									pos = path.find('/');
							}
						}
					}
				}
			}
		}
	}

}
/*
void Ruta::stat(string path) {
	shared_ptr<Elemento> item = nullptr;
	if (path[0]!='/') { //no es un path completo
		dirActual.devolverElemento(path, item);
		int peso = *item.obtenerTamanyo(0);
		cout << path << " tiene un peso de: "<<peso <<endl;
	}
	else { //es una ruta completa
		/*path.erase (0);
		int pos = path.find('/');
		if (pos > 0) {	// es una ruta con varios '/', tipo : /dir1/dir2/file
			while (pos > 0) {
				dir = path.substr (0, pos); //cojo la primera parte
				if (devolverElemento(dir, item)) {
					shared_ptr<Directorio> dado = dynamic_pointer_cast<Directorio>(item);
					if (*dado != nullptr){
							rutaActual.push_back(item);
							dirActual = dado;
							ruta += path;
							path.erase (0,pos+1); //borro ese parte del path
							pos = path.find('/');
					}
				}
			}
		}
		else { // path de tipo: /dir/file
			list<std::shared_ptr<Directorio>>::iterator iter;
			iter = rutaActual.begin();
			string dir = path.substr(0,pos);
			int peso = 0;
			while ( iter != rutaActual.end() ){
				if ( *iter.devolverNombre==dir ) {
					path.erase(0); //elimino ultima barra
					dir = path.substr(0,ruta.length()); //extraigo nombre
					*iter.devolverElemento(path, item);
					peso = *item.obtenerTamanyo(0);
					cout << path << " tiene un peso de: "<<peso <<endl;
					iter = rutaActual.end();
				}
				else iter++;
			}
		}	
	}
}
*/

void Ruta::vim (string file, int size) {
	shared_ptr<Elemento> ptr = nullptr;
	if ((*dirActual).devolverElemento(file, ptr)) {
		(*ptr).cambiarTamanyo(size);
	}
	else {//no existe
		ptr = make_shared<Archivo>(file);
		(*dirActual).anyadir(ptr);
	}
	(*ptr).cambiarTamanyo(size);
}


void Ruta::mkdir (string dir) {
	Directorio nuevo (dir);
	shared_ptr<Directorio> ptrNew = make_shared<Directorio>(dir);
	nuevo.anyadir (ptrNew);
	rutaActual.push_back(ptrNew);
	dirActual=ptrNew;
	ruta+= "/";
	ruta+= dir;
}

void Ruta::ln(string orig, string dest) {

	if (orig[0]!='/'); // es un enlace inter
}

void Ruta::rm (string e) {

}