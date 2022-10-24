all:
	@echo "Type 'make robot32' to build on 32-bit systems and "
	@echo "'make robot64' to build on 64-bit systems"
	@echo "If you encounter any error messages switching between "
	@echo "machines, try typing 'make clean' to remove old files"

robot.o:	robot.c
	gcc -c -o robot.o robot.c
   
robot32: robot.o
	g++ -o robot robot.o -lm libRobotLib.a `wx-config --libs` -lX11

robot64: robot.o
	g++ -o robot robot.o -lm libRobotLib64.a `wx-config --libs` -lX11

clean:	
	rm -f robot *.o

