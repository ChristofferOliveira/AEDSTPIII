//#include"Forcabruta.h"
#ifndef BMH_H
#define BMH_H

#include "Utils.h"
#include "pthread.h"

int ord(char c);

void BMH(char *dicionario, char *padrao, int tamanhoPadrao, int inicio, int tamanhoTexto);

void *thread_BMH(void *arg);

#endif // BMH_H
