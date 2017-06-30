#include "BMH.h"
#include "Utils.h"
#include "Forcabruta.h"
#include "pthread.h"

int main(int argc, char *argv[]){
    if(argc < 4){//Condição para verificar se o arquivo foi passado como argumeto antes de excutar o programa
        printf("Falha ao executar(falta de argumento)\n");
        return 0;
    }

    int opcao;
	FILE *arqTex, *arqPadrao;

    numerothreads = atoi(argv[1]);
	arqTex = fopen(argv[2], "r");
    arqPadrao = fopen(argv[3], "r");

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

	tamanhoTexto = strlen(dicionario) - 1;
	tamanhoPadrao = strlen(padrao) - 1;

	while(opcao != 3){
		printf("1.Força bruta(Sequencial)\n2.BMH(Sequencial)\n3.Força bruta(pthreads)\n4.Força bruta(openmp)\n5.Sair\n");
		scanf("%d", &opcao);
        switch(opcao){
         case 1:
            forcaBruta(dicionario, padrao, tamanhoTexto, tamanhoPadrao);
            break;
         case 2:
            BMH(dicionario, padrao, tamanhoTexto, tamanhoPadrao);
            break;
         case 3:
            forcaBrutaPthread();
            break;
         case 4:

            break;
         case 5:

            break;
         default:
            printf("Comando Incorreto\n");
            break;
        }
	}

	free(dicionario);
	free(padrao);

	return 0;
}
