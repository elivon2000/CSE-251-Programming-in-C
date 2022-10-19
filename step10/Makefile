all:
	@echo "Type 'make garage32' to build on 32-bit systems and "
	@echo "'make garage64' to build on 64-bit systems"
	@echo "If you encounter any error messages switching between "
	@echo "machines, try typing 'make clean' to remove old files"
    
garage.o:	garage.c
	gcc -c -o garage.o garage.c
   
garage32: garage.o
	g++ -o garage garage.o -lm libGarageLib.a `wx-config --libs` -lX11

garage64: garage.o
	g++ -o garage garage.o -lm libGarageLib64.a `wx-config --libs` -lX11

clean:
	rm -f garage.o garage
