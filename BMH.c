#include "BMH.h"

void BMH(char *dic, char *pad, int n, int inicio, int m){
	int i, j, k, cas = 0;
	int tabelad[256];//Vocabulário

	for(i = 0; i < 256; i++){
		tabelad[i] = n;
	}

	for(i = 0; i < n; i++){
		tabelad[(int)pad[i]] = n-i; //Posição no vocabulário onde os caracteres do padrão se encontram
	}

	j = inicio + n;

	while(j <= m){
		k = j;      //Indice de início de comparação no texto(note que ele se inicia com o valor correspondente ao tamanho do padrão)*/
		i = n;      //Indice de comparação do padrão*/

		/*Enquanto o caracter de posição k-1 do texto for igual ao caracter de posição i-1 do padrão
        e i for menor que o tamanho do padrão, quer dizer que está ocorrendo casamento*/
		while(dic[k-1] == pad[i-1] && i > 0){
			k--;/*Nesse caso a comparação é feita da direita para a esquerda*/
			i--;
		}

		/*Quando i é igual a zero, isso significa que o último caracter verificado do texto é igual
        ao primeiro caracter verificado do padrão, logo ocorreu um casamento*/
		if(i == 0){
			#pragma omp critical
			{
                numeroCasamento++;
			}
			printf("Casamento na(s) posição(ões): %d\n", k);
		}

		//Tratando caracteres que não esteja na tabela ascIII das letras.
        if(tabelad[(int)dicionario[j]] > tamanhoPadrao){
            j += tamanhoPadrao;
        }else{
            j += tabelad[(int)dicionario[j]];
        }
	}
}

void *thread_BMH(void *arg){
    ptr_Pthread argumento = (ptr_Pthread)arg;

    int i, j, k, cas = 0, fimThread = 0,tabelad[256];

	for(i = 0; i < 256; i++){
		tabelad[i] = tamanhoPadrao;
	}

	for(i = 0; i < tamanhoPadrao; i++){
		tabelad[(int)padrao[i]] = tamanhoPadrao - i;
	}

    fimThread = argumento->thread_inicio + argumento->thread_tamanho;

    j = argumento->thread_inicio + tamanhoPadrao;

	while(j <= fimThread){
		k = j;
		i = tamanhoPadrao;

		while(dicionario[k-1] == padrao[i-1] && i > 0){
			k--;
			i--;
		}

		if(i == 0){ //Se houve casamento
			pthread_mutex_lock(&mutex);
            numeroCasamento = numeroCasamento + 1;
            pthread_mutex_unlock(&mutex);
			printf("Casamento na(s) posição(ões): %d com thread %d\n", k, argumento->id);
		}

		//Tratando caracteres que não esteja na tabela ascIII das letras.
        if(tabelad[(int)dicionario[j]] > tamanhoPadrao){
            j += tamanhoPadrao;
        }else{
            j += tabelad[(int)dicionario[j]];
        }
	}

}
