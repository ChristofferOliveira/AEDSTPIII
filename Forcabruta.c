#include "Forcabruta.h"

void forcaBruta(char *dic, char *pad, int n, int inicio, int m){
	int i, j, k;

	for(i = inicio; i <= m-n; i++){     //Até a última posição possível para uma comparação do padrão
		k = i;      //Indice de início da comparação no texto
		j = 0;      //Indice de comparação do padrão

		/*Enquanto o caracter de posição k do texto for igual ao caracter de posição j do padrão
		 e j for menor que o tamanho do padrão, quer dizer que está ocorrendo casamento*/
		while(dic[k] == pad[j] && j < n){
			k++;    //Comparação é feita sequencialmente*/
			j++;
		}

        /*Quando j é igual ao tamanho do padrão, isso significa que o último caracter verificado
        do texto é diferente do último caracter verificado do padrão*/
		if(j == n){
			#pragma omp critical
			{
                numeroCasamento++;
			}
			printf("Casamento na(s) posição(ões): %d\n", i);
		}
	}
}

void *thread_forcaBruta(void *arg){
    ptr_Pthread argumento = (ptr_Pthread)arg;

    int i, j, k, fimThread = 0;

    fimThread = argumento->thread_inicio + argumento->thread_tamanho;

    for(i = argumento->thread_inicio; i <= fimThread; i++){

        k = i;
        j = 0;

        //Fazendo casamentos para verificar se há ocorrência.
        while(dicionario[k] == padrao[j] && j < tamanhoPadrao && k <= fimThread){
            k++;
            j++;
        }

        if(j == tamanhoPadrao){     //Se houve casamento
            pthread_mutex_lock(&mutex);
            numeroCasamento = numeroCasamento + 1;
            pthread_mutex_unlock(&mutex);
            printf("Casamento na(s) posição(ões): %d com thread %d\n", i, argumento->id);
        }
    }
}
