#ifndef PTHREAD_H
#define PTREAD_H

#include <pthread.h>

typedef struct pthread{
    int thread_inicio, thread_tamanho, id;
}Pthread, *ptr_Pthread;

void forcaBrutaPthread();

#endif // PTHREAD_H
