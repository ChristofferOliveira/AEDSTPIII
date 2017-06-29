all: Forcabruta.o BMH.o Utils.o
	gcc Forcabruta.o BMH.o Utils.o main.c -o main.exe
	./main.exe texto.txt padrao.txt
Forcabruta.o: Forcabruta.c Forcabruta.h
	gcc -c Forcabruta.c -o Forcabruta.o
BMH.o: BMH.c BMH.h
	gcc -c BMH.c -o BMH.o
Utils.o: Utils.c Utils.h
	gcc -c Utils.c -o Utils.o
clar: rm *.o