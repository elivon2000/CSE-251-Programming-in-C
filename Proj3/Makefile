all:
	@echo "Type 'make scheduler' to build project 3."
	@echo "Type './scheduler'   to run it."

scheduler:	scheduler.o io.o strptime_diy.o
	g++ -o scheduler scheduler.o io.o strptime_diy.o

scheduler.o:	scheduler.c io.h strptime_diy.h
	gcc -c -o scheduler.o scheduler.c

io.o:	io.c io.h strptime_diy.h
	gcc -c -o io.o io.c

strptime_diy.o:	strptime_diy.c strptime_diy.h
	gcc -c -o strptime_diy.o strptime_diy.c

clean:
	rm *.o scheduler

all:
	gcc *.c -o scheduler

