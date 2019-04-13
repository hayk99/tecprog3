//Esto al .h

class Ruta {
	string ruta;
	std::list<std::shared_ptr<Directorio>> rutaActual;
	std::shared_ptr <Directorio> dirActual;

public:
	Ruta();
	~Ruta();
	string pwd();
	void ls();
	void cd(string path);
	void stat(string element);
};

//Esto al cc

Ruta::Ruta(const Directorio& root_)rutaActual("/"), dirActual(dirActual) {};

Ruta::~Ruta() {};

string Ruta::pwd() { 
	return rutaActual;
}

void Ruta::ls() {
	Directorio::mostrarELementos(p);
}

void cd(string path) {
	rutaActual<Directorio>::iterator iter;
	iter = rutaActual.begin();
	//find 
	// if . no hago na
	// else substr and erase
	if (path!=".") {
		if (path="/") {
			//destruir
			rutaActual.erase(next(begin(rutaActual)), end(rutaActual));
		}
		else if (path=".."){
			//quito un elemento
			rutaActual.pop_back();
		}
		else {
			int pos = path.find("/",0);
			if (pos == -1) {
				string dir = path.substr(0);
				shared_ptr<Directorio> ptr;
				bool existe = *dirActual.existe(dir, ptr);
				shared_ptr<Directorio> meDevuelve = dynamic_cast<Directorio>(ptr)
				if ( ptr != null && existe )
					rutaActual.push_back(meDevuelve);
			}
			else if (pos == 0) {
				string newPath = path.erase(0);
				cd (newPath);
			}
		}
	}

}

void stat(string element) {
	string elemento;
	if ( elemtn[0]='/') {
		elemento=strtok(path, "/");
		cout << "  " <<elemento;
		while( ( (elemento=strtok(NULL, "/")) != NULL) && existe) {
			cout << "  " << elemento;
			bool existe = Directorio::existe(elemento);
		}
	}
	else elemento=element;
	elemento.obtenerTamanyo()

}