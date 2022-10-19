hanoi:	hanoi.o display.o
	gcc -o hanoi hanoi.o display.o

hanoi.o:	hanoi.c hanoi.h
	gcc -c hanoi.c

display.o:	display.c hanoi.h
	gcc -c display.c