#include "pthread.h"
#include "Utils.h"
#include "Forcabruta.h"

void forcaBrutaPthread(){
    int i, tamanhoThread, resto;

    pthread_t threads[numerothreads];
    Pthread argumentos[numerothreads];

    tamanhoThread = tamanhoTexto / numerothreads;
    resto = tamanhoTexto % numerothreads;

    for(i = 0; i < numerothreads; i++){

        argumentos[i].id = i;
        argumentos[i].thread_tamanho = tamanhoThread;
        argumentos[i].thread_inicio = i * tamanhoThread;

        if(i > 0){
            if(verificarFinalThread(dicionario[i * tamanhoThread], argumentos[i - 1].thread_tamanho)){
                argumentos[i].thread_inicio = (i * tamanhoThread) - tamanhoPadrao;
            }
        }
        if(i == (numerothreads - 1)){
            argumentos[i].thread_tamanho += resto;
        }

        pthread_create(&(threads[i]), NULL, thread_forcaBruta, &(argumentos[i]));
    }
    for(i = 0; i < numerothreads; i++){
        pthread_join(threads[i], NULL);
    }
    printf("\nNumero de Casamentos: %d\n\n", numeroCasamento);
}
