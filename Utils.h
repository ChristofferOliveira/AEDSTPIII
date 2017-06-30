#ifndef UTILS_H
#define UTILS_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *dicionario;
char *padrao;
int tamanhoTexto;
int tamanhoPadrao;
int numerothreads;

char * lerArquivo(FILE *arquivo);
int verificarFinalThread(char letraFinal, char letraInicio);

#endif // UTILS_H
