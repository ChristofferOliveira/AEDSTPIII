#include"BMH.h"

void BMH(char *dic, char *pad, int m, int n){
	int i, j, k, cas = 0, tabelad[256];/*Vocabulário*/

	for(i = 0; i < 256; i++){
		tabelad[i] = n;
	}

	for(i = 0; i < n; i++){
		tabelad[(int)pad[i]] = n-i;/*Posição no vocabulário onde os caracteres do padrão se encontram*/
	}

	j = n;

	while(j <= m){
		k = j;/*Indice de início de comparação no texto(note que ele se inicia com o valor correspondente ao tamanho do padrão)*/
		i = n;/*Indice de comparação do padrão*/

		while(dic[k-1] == pad[i-1] && i > 0){/*Enquanto o caracter de posição k-1 do texto for igual ao caracter de posição i-1 do padrão e i for menor que o tamanho do padrão, quer dizer que está ocorrendo casamento*/
			k--;/*Nesse caso a comparação é feita da direita para a esquerda*/
			i--;
		}

		if(i == 0){/*Quando i é igual a zero, isso significa que o último caracter verificado do texto é igual ao primeiro caracter verificado do padrão, logo ocorreu um casamento*/
			cas++;
			printf("Casamento na(s) posição(ões): %d\n", k);
		}

		j += tabelad[(int)dic[j]];
	}
	printf("Número de casamentos: %d\n", cas);
}
