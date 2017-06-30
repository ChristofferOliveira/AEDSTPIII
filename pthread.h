#ifndef PTHREAD_H
#define PTHREAD_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct pthread{
    int thread_inicio, thread_tamanho, id;
}Pthread, *ptr_Pthread;

void forcaBrutaPthread();

void BMHPthread();

#endif // PTHREAD_H
