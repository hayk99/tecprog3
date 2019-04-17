#include "ruta.h"

Ruta::Ruta(Directorio& root){
	dirActual = make_shared<Directorio>(root);
	ruta = "/";
	rutaActual.push_back(dirActual);
}

Ruta::~Ruta() {};

string Ruta::pwd() { 
	cout << ruta  << endl;
	return ruta;
}

void Ruta::ls() {
	string e = (*dirActual).mostrarElementos();
	cout <<  e.c_str() << endl;
}


bool Ruta::addList(string& path, shared_ptr<Elemento>& ptr, string& dir){
	shared_ptr<Directorio> dado = dynamic_pointer_cast<Directorio>(ptr);
	if (dado != nullptr){
		rutaActual.push_back(dado);
		dirActual = dado;
		ruta += '/';
		ruta += dir;
		return true;
	}
	else return false;
}

void Ruta::cd(string path) {
	if (path!=".") {
		if (path=="/") {  //quiere ir a raiz
			//destruir
			rutaActual.erase(next(rutaActual.begin()), rutaActual.end());
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
			for (iter = rutaActual.begin(); iter != rutaActual.end(); iter++) {
				shared_ptr<Directorio> aux = *iter;
				if ( ((**iter).devolverNombre() == "home") )
					rutaActual.push_back(aux);
				else rutaActual.pop_back();
				iter++;
				aux=(*iter);
			}
		}
		else {
			shared_ptr<Elemento> aux = nullptr;
			if (path[0] != '/') { //entonces hago cd a un nodo hijo
				int pos = path.find('/'); //busco la barra
				if (pos > 0){ //path contiene varios nodos
					string dir = "";
					while (pos > 0) { // o sea hay una '/' al menos
						dir = path.substr (0, pos); //cojo la primera parte
						if ((*dirActual).devolverElemento(dir, aux) && addList(path,aux,dir)) {
							//si existe ese directorio y el ptr dado por Directorio no es null, es decir es un tipo Directorio
							//lo que he leido del path lo añado
							/*shared_ptr<Directorio> dado = dynamic_pointer_cast<Directorio>(aux);
							if (*dado != nullptr){
								rutaActual.push_back(aux);
								dirActual = dado;
								ruta += '/';
								ruta += dir;
								path.erase (0,pos+1) //borro ese parte del path
								pos = path.find('/');
							}
							else pos = -1;*/
						}
						//sino termino bucle porque la ruta es incompleta
						else pos = -1;
					}
					//hago esta iteracion por si el user introduce dir1/dir2 en vez de dir1/dir2/
					dir = path.substr(0, path.length());
					if ((*dirActual).devolverElemento(dir, aux)) {
						bool kk = addList (path, aux, dir);
						/*shared_ptr<Directorio> dado = dynamic_pointer_cast<Directorio>(aux);
						if (*dado != nullptr){
							rutaActual.push_back(aux);
							dirActual = dado;
							ruta += '/';
							ruta += dir;
						}*/
					}

				}
				//hace cd a un solo directorio
				else if ((*dirActual).devolverElemento(path, aux)) { //path esta compuesto solo por un hijo
					shared_ptr<Directorio> dado = dynamic_pointer_cast<Directorio>(aux);
					if (dado != nullptr) {
						rutaActual.push_back(dado);
						dirActual = dado;
						ruta += '/';
						ruta += path;
					}
				}
			}
			else if (path[0] == '/') {//es una ruta completa desde raiz
				path.erase(0,1);//borro la barra
				int pos = path.find('/');
				string dir = path.substr(0,pos); //saco el primer directorio
				if (dir == "home") {//esta bien introducida la ruta completa, puedo seguir
					list<std::shared_ptr<Directorio>>::iterator iter;
					//busco en mi Lista de dirs dónde tengo el home
					for (iter = rutaActual.begin(); iter != rutaActual.end(); iter++) {
							if ( ((**iter).devolverNombre() != "home") ) {
								iter++;
								pos = -1;
							}
							else  {
								//no es ruta completa válida
								iter = rutaActual.end();
							}
					}
				}/*
				pos = path.find('/');
				while (pos > 0 ){ 
					path.erase(0,pos+1);
					dir = path.substr(0,pos);
					if ((**iter).devolverNombre() == dir) {
						iter++;
					}
					else { //ahora tengo que añadir a mi path{

					}
					pos = path.find('/');
				}// o sea hay una '/' al menos
				*/
			}
		}
	}
}

void Ruta::stat(const string& path) {
	string copia = path, elemento_a_busc;
	shared_ptr<Directorio> copia_dir = dirActual;
	if(path[0] == '/'){ // es una ruta completa, subir hasta raiz sin modificarlo
		copia.erase(0,1);
		copia_dir = rutaActual.front();
	}
	stringstream f(copia);
	shared_ptr<Elemento> aux;   // Puntero al elemento a buscar
	getline(f,elemento_a_busc,'/');
	bool salir = false, esta = true;
	do {
		if(!(*copia_dir).devolverElemento(elemento_a_busc, aux)){   // No está lo que se buscaba
			esta = false;
			salir = true;
		}
		else{
			copia_dir = dynamic_pointer_cast<Directorio>(aux);
			if(copia_dir.get() == nullptr){                      // No es directorio lo que se buscaba y hay que salir
				salir = true;
			}
			else if(f.eof()){
				salir = true;
			}
			else{
				getline(f,elemento_a_busc,'/');
				if(elemento_a_busc == "\0"){
					salir = true;
				}		
			}
		}
	} while(!salir);
	if(esta && f.eof()){
		cout << (*aux).obtenerTamanyo() << endl;
	}
}


void Ruta::vim (string file, int size) {
	shared_ptr<Elemento> ptr = nullptr;
	if (!(*dirActual).devolverElemento(file, ptr)) { //no existe
		ptr = make_shared<Archivo>(file);
		(*dirActual).anyadir(ptr);
	}
	(*ptr).cambiarTamanyo(size);
}


void Ruta::mkdir (string dir) {
	Directorio nuevo (dir);
	cout << "dir actual es: "<< (*dirActual).devolverNombre()<<endl;
	shared_ptr<Directorio> ptrNew = make_shared<Directorio>(dir);
	(*dirActual).anyadir (ptrNew);
	cout << "creado dir con nombre: "<< dir << endl;
}


void Ruta::ln (const string& orig, const string& dest) {
	string copia = orig, elemento_a_busc;
	shared_ptr<Directorio> copia_dir = dirActual;
	if(orig[0] == '/'){ // es una ruta completa, subir hasta raiz sin modificarlo
		copia.erase(0,1);
		copia_dir = rutaActual.front();
	}
	stringstream f(copia);
	shared_ptr<Elemento> aux;   // Puntero al elemento a buscar
	getline(f,elemento_a_busc,'/');
	bool salir = false, esta = true;
	do {
		if(!(*copia_dir).devolverElemento(elemento_a_busc, aux)){   // No está lo que se buscaba
			esta = false;
			salir = true;
		}
		else{
			copia_dir = dynamic_pointer_cast<Directorio>(aux);
			if(copia_dir.get() == nullptr){                      // No es directorio lo que se buscaba y hay que salir
				salir = true;
			}
			else if(f.eof()){
				salir = true;
			}
			else{
				getline(f,elemento_a_busc,'/');
				if(elemento_a_busc == "\0"){
					salir = true;
				}		
			}
		}
	} while(!salir);
	if(esta && f.eof()){
		shared_ptr<Enlace> ptr = make_shared<Enlace>(dest, aux);
		(*dirActual).anyadir(ptr);
	}
}

void Ruta::rm (const string& path) {
	string copia = path, elemento_a_busc;
	shared_ptr<Directorio> copia_dir = dirActual;
	shared_ptr<Directorio> padre_elemento = dirActual; 
	if(path[0] == '/'){ // es una ruta completa, subir hasta raiz sin modificarlo
		copia.erase(0,1);
		copia_dir = rutaActual.front();
	}
	stringstream f(copia);
	shared_ptr<Elemento> aux;   // Puntero al elemento a buscar
	getline(f,elemento_a_busc,'/');
	bool salir = false, esta = true;
	do {
		if(!(*copia_dir).devolverElemento(elemento_a_busc, aux)){   // No está lo que se buscaba
			esta = false;
			salir = true;
		}
		else{
			copia_dir = dynamic_pointer_cast<Directorio>(aux);
			if(copia_dir.get() == nullptr){                      // No es directorio lo que se buscaba y hay que salir
				salir = true;
			}
			else if(f.eof()){
				salir = true;
			}
			else{
				getline(f,elemento_a_busc,'/');
				if(elemento_a_busc == "\0"){
					salir = true;
				}		
			}      // El elemento a buscar era un directorio, salir = false si hay que seguir buscando
			if(!salir){  // va a buscar el elemento siguiente, actualizar padre a elemento
				padre_elemento = copia_dir;
			}
		}
	} while(!salir);
	if(esta && f.eof()){
		cout << "borrando: " << (*aux).devolverNombre() << " cuyo padre es " << (*padre_elemento).devolverNombre() << endl;
		(*padre_elemento).borrar((*aux).devolverNombre());
		
	}
}