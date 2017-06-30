#include "pthread.h"
#include "Utils.h"
#include "Forcabruta.h"
#include "BMH.h"

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
                argumentos[i].thread_inicio -= tamanhoPadrao;
                argumentos[i].thread_tamanho += tamanhoPadrao;
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

void BMHPthread(){
    int i, tamanhoThread, resto, restoThread;

    pthread_t threads[numerothreads];
    Pthread argumentos[numerothreads];

    tamanhoThread = tamanhoTexto / numerothreads;
    resto = tamanhoTexto % numerothreads;

    for(i = 0; i < numerothreads; i++){

        argumentos[i].id = i;
        argumentos[i].thread_tamanho = tamanhoThread;
        argumentos[i].thread_inicio = i * tamanhoThread;

        if(i > 0){
            restoThread = argumentos[i - 1].thread_tamanho % tamanhoPadrao;
 /**DEBUG**/printf("Resto da Thread: %d\n", restoThread);
            argumentos[i].thread_inicio -= restoThread;
            argumentos[i].thread_tamanho += restoThread;
/**DEBUg**/printf("Thread: %d -- Inicio: %d - Tamanho: %d\n", argumentos[i].id, argumentos[i].thread_inicio, argumentos[i].thread_tamanho);

            if(argumentos[i].thread_inicio != argumentos[i - 1].thread_tamanho){
                    if(verificarFinalThread(dicionario[argumentos[i].thread_inicio], dicionario[argumentos[i - 1].thread_tamanho])){
            /**DEEBUG**/printf("2Padrao está entre duas Threads.\n");
                            argumentos[i].thread_inicio = argumentos[i].thread_inicio - tamanhoPadrao;
                            argumentos[i].thread_tamanho = argumentos[i].thread_tamanho + tamanhoPadrao;
            /**DEBUg**/printf("2Thread: %d -- Inicio: %d - Tamanho: %d\n", argumentos[i].id, argumentos[i].thread_inicio, argumentos[i].thread_tamanho);
                    }
            }
        }
        if(i == (numerothreads - 1)){
            argumentos[i].thread_tamanho += resto;
        }

        pthread_create(&(threads[i]), NULL, thread_BMH, &(argumentos[i]));
    }
    for(i = 0; i < numerothreads; i++){
        pthread_join(threads[i], NULL);
    }
    printf("\nNumero de Casamentos: %d\n\n", numeroCasamento);
}
