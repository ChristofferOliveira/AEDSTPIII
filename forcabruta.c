#include "Forcabruta.h"

void forcaBruta(char *dic, char *pad, int m, int n){
	int i, j, k, cas = 0;

	for(i = 0; i <= m-n; i++){/*Até a última posição possível para uma comparação do padrão*/
		k = i;/*Indice de início da comparação no texto*/
		j = 0;/*Indice de comparação do padrão*/

		while(dic[k] == pad[j] && j < n){/*Enquanto o caracter de posição k do texto for igual ao caracter de posição j do padrão e j for menor que o tamanho do padrão, quer dizer que está ocorrendo casamento*/
			k++;/*Comparação é feita sequencialmente*/
			j++;
		}

		if(j == n){/*Quando j é igual ao tamanho do padrão, isso significa que o último caracter verificado do texto é diferente do último caracter verificado do padrão*/
			cas++;
			printf("Casamento na(s) posição(ões): %d\n", i);
		}
	}
	printf("Número de casamentos: %d\n", cas);
}
