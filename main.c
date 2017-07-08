#include "BMH.h"
#include "Utils.h"
#include "Forcabruta.h"
#include "pthread.h"
#include "openmp.h"

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

    numeroCasamento = 0;
	tamanhoTexto = strlen(dicionario) - 1;
	tamanhoPadrao = strlen(padrao) - 1;

	printf("Tamanho do texto: %d Tamanho do padrão: %d\n", tamanhoTexto, tamanhoPadrao);

	while(opcao != 7){
		printf("1.Força bruta(Sequencial)\n2.BMH(Sequencial)\n3.Força bruta(pthreads)\n4.Força bruta(openmp)\n5.BMH(pthreads)\n6.BMH(openmp)\n7.Sair\n");
		scanf("%d", &opcao);
        switch(opcao){
         case 1:
         	clock_gettime(CLOCK_MONOTONIC, &start);
            forcaBruta(dicionario, padrao, tamanhoPadrao, 0, tamanhoTexto);
            clock_gettime(CLOCK_MONOTONIC, &finish);

			elapsed = (finish.tv_sec - start.tv_sec);
			elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

			printf("Tempo de execução em segundos: %lf\n",elapsed );
            printf("Número de casamentos: %d\n", numeroCasamento);
            numeroCasamento = 0;
            break;
         case 2:
         	clock_gettime(CLOCK_MONOTONIC, &start);
            BMH(dicionario, padrao, tamanhoPadrao, 0, tamanhoTexto);
            printf("Número de casamentos: %d\n", numeroCasamento);
            clock_gettime(CLOCK_MONOTONIC, &finish);

			elapsed = (finish.tv_sec - start.tv_sec);
			elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

			printf("Tempo de execução em segundos: %lf\n",elapsed );
            numeroCasamento = 0;
            break;
         case 3:
            forcaBrutaPthread();
            numeroCasamento = 0;
            break;
         case 4:
			forcaBrutaOPM();
			numeroCasamento = 0;
            break;
         case 5:
            BMHPthread();
            numeroCasamento = 0;
            break;
         case 6:
         	BMHOPM();
         	numeroCasamento = 0;
            break;
         case 7:
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
