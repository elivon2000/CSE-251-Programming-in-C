transistors:	transistors.o io.o
	g++ -o transistors transistors.o io.o

transistors.o:	transistors.c transistors.h
	gcc -c -o transistors.o transistors.c

io.o:	io.c transistors.h
	gcc -c -o io.o io.c

clean:
	rm -f *.o transistors

all:
	gcc -c -o transistors.o transistors.c
	gcc -c -o io.o io.c
	g++ -o transistors transistors.o io.o
	./transistors
