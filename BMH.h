//#include"Forcabruta.h"
#ifndef BMH_H
#define BMH_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void BMH(char *dicionario, char *padrao, int tamanhoPadrao, int inicio, int tamanhoTexto);

void *thread_BMH(void *arg);

#endif // BMH_H
