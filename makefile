all: Forcabruta.o BMH.o Utils.o pthread.o openmp.o
	gcc Forcabruta.o BMH.o Utils.o pthread.o openmp.o main.c -o main.exe -D_REENTRANT -lpthread -fopenmp
Forcabruta.o: Forcabruta.c Forcabruta.h
	gcc -c Forcabruta.c -o Forcabruta.o
BMH.o: BMH.c BMH.h
	gcc -c BMH.c -o BMH.o
Utils.o: Utils.c Utils.h
	gcc -c Utils.c -o Utils.o
pthread.o: pthread.c pthread.h
	gcc -c pthread.c -o pthread.o
openmp.o: openmp.c openmp.h
	gcc -c openmp.c -o openmp.o
clear:
	rm *.o
	rm *main.exe
