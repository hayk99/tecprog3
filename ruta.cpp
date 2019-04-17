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

void Ruta::cd(const string& path) {
	string copia = path, elem;
	shared_ptr<Directorio> dir = dirActual;
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
			ruta.erase(ruta.length()-1);
			ruta.erase(ruta.rfind('/')+1, ruta.length());
		}
		else {
			//creo una copia de la lista actual
			std::list<std::shared_ptr<Directorio>> rutaNueva;
			rutaNueva = rutaActual;
			std::shared_ptr<Directorio> salvado = dirActual;	
			string salvar = ruta;	
			if (path[0] == '/') {
				copia.erase(0,1);
				ruta = '/';
				dir = rutaActual.front();
				//borro lista de dirs y añado solo a raiz
				rutaNueva.erase(rutaNueva.begin(), rutaNueva.end());
				rutaNueva.push_back(dir);
			}
			shared_ptr<Elemento> aux;   // Puntero al elemento a buscar
			int pos = copia.find('/');
			elem = copia.substr(0,pos);
			bool seguir = true, pathCorrecto = true;
			if ( pos > 0 ) {
				while ( pos > 0 && seguir) {
					if ((*dir).devolverElemento(elem, aux)) {
						dir = dynamic_pointer_cast<Directorio>(aux);
						if (dir != nullptr) {
							rutaNueva.push_back(dir);
							ruta+= elem;
							ruta+= '/';
							copia.erase (0,pos+1);
							pos = copia.find ('/');
							if (pos > 0) elem = copia.substr (0,pos);		
						} 	
						else {
							seguir = false;
							pathCorrecto = false;
						}
					}
					else  {
						seguir = false;
						pathCorrecto = false;
					}
				}
			}
			if (copia.length() > 0) elem = copia.substr (0, copia.length());
			if ((*dir).devolverElemento(elem, aux)){
				dir = dynamic_pointer_cast<Directorio>(aux);
				if (dir != nullptr) {			
					rutaNueva.push_back(dir);
					ruta+= elem;
					ruta+= '/';
				}
			}
			if (!pathCorrecto) { 
				cout << "Directorio \""<< path << "\" no existe\n";
				dirActual = salvado;
				ruta = salvar;
			}
			else {
				rutaActual = rutaNueva;
				dirActual = rutaActual.back();
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
		cout << "Tamaño es: " << (*aux).obtenerTamanyo() << endl;
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
	shared_ptr<Directorio> ptrNew = make_shared<Directorio>(dir);
	(*dirActual).anyadir (ptrNew);
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