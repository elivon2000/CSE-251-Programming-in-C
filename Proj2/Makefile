all:
	@echo "Type 'make elevator_a' to build part a"
	@echo "Type 'make elevator'   to build part b"

elevator:	elevator.o
	g++ -o elevator elevator.o -lm libElevatorLib64.a `wx-config --libs` -lX11

elevator_a:	elevator_a.o
	g++ -o elevator_a elevator_a.o -lm libElevatorLib64.a `wx-config --libs` -lX11

elevator.o:	elevator.c
	gcc -c -o elevator.o elevator.c

elevator_a.o:	elevator_a.c
	gcc -c -o elevator_a.o elevator_a.c 

clean:
	rm -f *.o elevator elevator_a

