all: main_chano

main_chano: main_chano.o elemento.o directorio.o enlace.o archivo.o ruta.o
	g++ -o main_chano main_chano.o elemento.o directorio.o enlace.o archivo.o ruta.o

main_chano.o: main_chano.cpp
	g++ -c main_chano.cpp

ruta.o:	ruta.cpp ruta.h
	g++ -c ruta.cpp

elemento.o: elemento.h elemento.cpp
	g++ -c elemento.cpp

archivo.o: archivo.h archivo.cpp
	g++ -c archivo.cpp

enlace.o: enlace.h enlace.cpp
	g++ -c enlace.cpp

directorio.o: directorio.h directorio.cpp
	g++ -c directorio.cpp

clean:
	rm *.o main_chano
