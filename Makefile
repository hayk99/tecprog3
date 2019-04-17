#all: main_chano
#
#main_chano: main_chano.o elemento.o directorio.o enlace.o archivo.o ruta.o excepciones.o
	#g++ -std=c++11 -O3 -o main_chano main_chano.o elemento.o directorio.o enlace.o archivo.o ruta.o excepciones.o 
#
#main_chano.o: main_chano.cpp
	#g++ -std=c++11 -c main_chano.cpp
#
#excepciones.o:	excepciones.cpp excepciones.h
	#g++ -std=c++11 -c excepciones.cpp
#
#ruta.o:	ruta.cpp ruta.h
	#g++ -std=c++11 -c ruta.cpp
#
#elemento.o: elemento.h elemento.cpp
	#g++ -std=c++11 -c elemento.cpp
#
#archivo.o: archivo.h archivo.cpp
	#g++ -std=c++11 -c archivo.cpp
#
#enlace.o: enlace.h enlace.cpp
	#g++ -std=c++11 -c enlace.cpp
#
#directorio.o: directorio.h directorio.cpp
	#g++ -std=c++11 -c directorio.cpp
#
#clean:
	#rm *.o main_chano


#all: main
#
#main_chano: main.o elemento.o directorio.o enlace.o archivo.o ruta.o excepciones.o
	#g++ -std=c++11 -O3 -o main main.o elemento.o directorio.o enlace.o archivo.o ruta.o excepciones.o 
#
#main_chano.o: main.cpp
	#g++ -std=c++11 -c main.cpp
#
#excepciones.o:	excepciones.cpp excepciones.h
	#g++ -std=c++11 -c excepciones.cpp
#
#ruta.o:	ruta.cpp ruta.h
	#g++ -std=c++11 -c ruta.cpp
#
#elemento.o: elemento.h elemento.cpp
	#g++ -std=c++11 -c elemento.cpp
#
#archivo.o: archivo.h archivo.cpp
	#g++ -std=c++11 -c archivo.cpp
#
#enlace.o: enlace.h enlace.cpp
	#g++ -std=c++11 -c enlace.cpp
#
#directorio.o: directorio.h directorio.cpp
	#g++ -std=c++11 -c directorio.cpp
#
#clean:
	#rm *.o main

PROG=main
SRCS=main.cc

CC=g++ -std=c++11
#CC=clang++ -std=c++11

CFLAGS:=-O3

OBJS=$(SRCS:.cc=.o)

all: $(PROG)

$(PROG): $(OBJS) ruta.o directorio.o archivo.o enlace.o excepciones.o elemento.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cc
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(PROG) $(OBJS) core *.o

dep:
	@makedepend -Y -- $(CFLAGS) -- $(SRCS) 2> /dev/null
	@rm -f Makefile.bak

# DO NOT DELETE