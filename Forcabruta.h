#ifndef FORCABRUTA_H
#define FORCABRUTA_H

#include "pthread.h"
#include "Utils.h"

//Forca bruta sequencial
void forcaBruta(char *dic, char *pad, int n, int inicio, int m);

//Força bruta com pthreads
void *thread_forcaBruta(void *arg);

#endif // FORCABRUTA_H
