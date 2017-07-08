#include "openmp.h"

void forcaBrutaOPM(){
	int *inicioThreads, *fimThreads, i, tamanhoThreads, resto;
	
	inicioThreads = malloc(numerothreads * sizeof(int));
	fimThreads = malloc(numerothreads * sizeof(int));
	
	tamanhoThreads = tamanhoTexto/numerothreads;
	
	resto = tamanhoTexto%numerothreads;
	
	inicioThreads[0] = 0;
	
	fimThreads[0] = tamanhoThreads;
	
	for(i = 1; i < numerothreads; i++){
		
		inicioThreads[i] = tamanhoThreads * i;
		
		fimThreads[i] = inicioThreads[i] + tamanhoThreads;
	
		if(verificarFinalThread(dicionario[inicioThreads[i]], dicionario[fimThreads[i-1]])){
			inicioThreads[i] -= tamanhoPadrao;
			//fimThreads[i] += tamanhoPadrao;
		}
		if(i == numerothreads - 1){
			fimThreads[i] += resto;
		}
	}
	
	#pragma paralel for num_threads(numerothreads)
	clock_gettime(CLOCK_MONOTONIC, &start);
	for(i = 0; i < numerothreads; i++){
		printf("inicio: %d fim: %d thread: %d tamanhoTexto: %d\n", inicioThreads[i], fimThreads[i], i, tamanhoTexto);
		forcaBruta(dicionario, padrao, tamanhoPadrao, inicioThreads[i], fimThreads[i]);
	}
	
	clock_gettime(CLOCK_MONOTONIC, &finish);

	elapsed = (finish.tv_sec - start.tv_sec);
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

	printf("Tempo de execução em segundos: %lf\n",elapsed );
	
	printf("Número de casamentos: %d\n", numeroCasamento);
}

void BMHOPM(){
	int *inicioThreads, *fimThreads, i, tamanhoThreads, resto;
	
	inicioThreads = malloc(numerothreads * sizeof(int));
	fimThreads = malloc(numerothreads * sizeof(int));
	
	tamanhoThreads = tamanhoTexto/numerothreads;
	
	resto = tamanhoTexto%numerothreads;
	
	inicioThreads[0] = 0;
	
	fimThreads[0] = tamanhoThreads;
	
	for(i = 1; i < numerothreads; i++){
		
		inicioThreads[i] = tamanhoThreads * i;
		
		fimThreads[i] = inicioThreads[i] + tamanhoThreads;
	
		if(verificarFinalThread(dicionario[inicioThreads[i]], dicionario[fimThreads[i-1]])){
			inicioThreads[i] -= tamanhoPadrao;
			//fimThreads[i] += tamanhoPadrao;
		}
		if(i == numerothreads - 1){
			fimThreads[i] += resto;
		}
	}
	
	#pragma paralel for num_threads(numerothreads)
	clock_gettime(CLOCK_MONOTONIC, &start);
	for(i = 0; i < numerothreads; i++){
		printf("inicio: %d fim: %d thread: %d tamanhoTexto: %d\n", inicioThreads[i], fimThreads[i], i, tamanhoTexto);
		BMH(dicionario, padrao, tamanhoPadrao, inicioThreads[i], fimThreads[i]);
	}
	
	clock_gettime(CLOCK_MONOTONIC, &finish);

	elapsed = (finish.tv_sec - start.tv_sec);
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

	printf("Tempo de execução em segundos: %lf\n",elapsed );
	
	printf("Número de casamentos: %d\n", numeroCasamento);
}
