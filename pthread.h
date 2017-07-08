#ifndef PTHREAD_H
#define PTHREAD_H

#include "Utils.h"
#include <pthread.h>
#include "Forcabruta.h"
#include "BMH.h"

typedef struct pthread{
    int thread_inicio, thread_tamanho, id;
}Pthread, *ptr_Pthread;

void forcaBrutaPthread();

void BMHPthread();

#endif // PTHREAD_H
