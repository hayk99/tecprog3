//Esto al .h

class Ruta {
	string ruta;
	list<Directorio*> rutaActual;
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
	dir=strtok(path, "/");
	cout << "  " <<dir;
	while( ( (dir=strtok(NULL, "/")) != NULL) && existe) {
		cout << "  " << dir;
		bool existe = existe(dir);
	}
	if (!existe) cout << path << "No such file or directory \n";
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