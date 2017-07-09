//#include"Forcabruta.h"
#ifndef BMH_H
#define BMH_H

#include "Utils.h"
#include "pthread.h"

//BMH sequencial.
void BMH(char *dicionario, char *padrao, int tamanhoPadrao, int inicio, int tamanhoTexto);

//BMH com pthreads.
void *thread_BMH(void *arg);

#endif // BMH_H
