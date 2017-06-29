#include "BMH.h"
#include "Utils.h"
#include "Forcabruta.h"

int main(int argc, char *argv[]){

    int tamanhoTexto, tamanhoPadrao, opcao;
    char *dicionario, *padrao;

	FILE *arqTex, *arqPadrao;

	arqTex = fopen(argv[1], "r");
    arqPadrao = fopen(argv[2], "r");

	if(arqTex == NULL || arqPadrao == NULL){
		printf("Algum dos arquivos está vazio.\n");
        return 0;
	}else{

		dicionario = lerArquivo(arqTex);
		printf("dicionario = %s\n", dicionario);

        padrao = lerArquivo(arqPadrao);
        printf("padrao = %s\n", padrao);
	}
	fclose(arqTex);
	fclose(arqPadrao);

	tamanhoTexto = strlen(dicionario);
	tamanhoPadrao = strlen(padrao);/*m tamanho do texto, n tamanho do padraorão*/

	while(opcao != 3){
		printf("1.Força bruta\n2.Heurística\n3.Sair\n");
		scanf("%d", &opcao);
        switch(opcao){
         case 1:
            forcaBruta(dicionario, padrao, tamanhoTexto, tamanhoPadrao);
            break;
         case 2:
            BMH(dicionario, padrao, tamanhoTexto, tamanhoPadrao);
            break;
         case 3:
            break;
         default:
            printf("Comando Incorreto");
            break;
        }
	}

	free(dicionario);
	free(padrao);

	return 0;
}
