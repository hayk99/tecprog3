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