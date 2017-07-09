#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>

struct timespec start, finish;
double elapsed;

//Variáveis globais
char *dicionario;
char *padrao;
int tamanhoTexto;
int tamanhoPadrao;
int numerothreads;
int numeroCasamento;
pthread_mutex_t mutex;

char * lerArquivo(FILE *arquivo);

//Verifica se as duas letras equivalem a alguma letra do padrão.
int verificarFinalThread(char letraFinal, char letraInicio);

#endif // UTILS_H
