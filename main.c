#include"BMH.h"

int main(int argc, char *argv[]){

	char *dic, *pad;
	
	FILE *arqTex = fopen(argv[1], "r"), *arqPad = fopen(argv[2], "r");
	
	if(arqTex == NULL || arqPad == NULL){
		printf("Algum dos arquivos está vazio.\n");
	}else{
		
		fseek(arqTex, 0, SEEK_END);
		int inSizeTex = ftell(arqTex)+1;
		rewind(arqTex);
		dic = malloc(inSizeTex);
		fread(dic, 1, inSizeTex, arqTex);
		
		printf("dic = %s\n", dic);
		
		fseek(arqPad, 0, SEEK_END);
		int inSizePad = ftell(arqPad)+1;
		rewind(arqPad);
		pad = malloc(inSizePad);
		fread(pad, 1, inSizePad, arqPad);
		
		printf("pad = %s\n", pad);
	}
	fclose(arqTex);
	fclose(arqPad);
	
	int m = strlen(dic), n = strlen(pad), oper;/*m tamanho do texto, n tamanho do padrão*/
	while(1){
		printf("1.Força bruta\n2.Heurística\n3.Sair\n");
		scanf("%d", &oper);
		
		if(oper == 1){
			forcabruta(dic, pad, m, n);
		}else if(oper == 2){
			BMH(dic, pad, m, n);
		}else if(oper == 3){
			return 0;
		}
	}
	free(dic);
	free(pad);
}
