all: Forcabruta.o BMH.o Utils.o pthread.o
	gcc Forcabruta.o BMH.o Utils.o pthread.o main.c -o main.exe
	./main.exe 2 texto.txt padrao.txt
Forcabruta.o: Forcabruta.c Forcabruta.h
	gcc -c Forcabruta.c -o Forcabruta.o
BMH.o: BMH.c BMH.h
	gcc -c BMH.c -o BMH.o
Utils.o: Utils.c Utils.h
	gcc -c Utils.c -o Utils.o
pthread.o: pthread.c pthread.h
	gcc -c pthread.c -o pthread.o
clear:
	rm *.o