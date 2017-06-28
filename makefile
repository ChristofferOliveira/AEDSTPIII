#MAKEFILE#
all: tp3
tp3: main.o forcabruta.o BMH.o 
	gcc -o tp3 main.o forcabruta.o BMH.o
main.o: main.c forcabruta.h BMH.h
	gcc -o main.o -c main.c
BMH.o: BMH.c BMH.h
	gcc -o BMH.o -c BMH.c
forcabruta.o: forcabruta.c forcabruta.h
	gcc -o forcabruta.o -c forcabruta.c
clean:
	rm -rf *.o
mrproper: clean
	rm -rf tp3
