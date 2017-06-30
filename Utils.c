#include "Utils.h"

char * lerArquivo(FILE *arquivo){

    char *conteudo;
    fseek(arquivo, 0, SEEK_END);
    int inSizeTex = ftell(arquivo)+1;
    rewind(arquivo);
    conteudo = malloc(inSizeTex);
    fread(conteudo, 1, inSizeTex, arquivo);

    return conteudo;
}

int verificarFinalThread(char letraFinal, char letraInicio){
    int ocorrenciaFinal = 0, ocorrenciaInicio = 0;
/**DEBUG**/printf("Letra inicio: %c - Letra final: %c\n", letraInicio, letraFinal);
    for(int i = 0; i < tamanhoPadrao; i++){
        if(ocorrenciaFinal != 1){
            if(padrao[i] == letraFinal){
/**DEBUG**/printf("Houve ocorrencia da letra do padrao com o final da thread anterior\n");
                ocorrenciaFinal = 1;
            }
        }
        if(ocorrenciaInicio != 1){
            if(padrao[i] == letraInicio){
/**DEBUG**/printf("Houve ocorrencia da letra do padrao com o inicio dessa thread\n");
                ocorrenciaInicio = 1;
            }
        }
        if((ocorrenciaFinal == 1) && (ocorrenciaInicio == 1)){
            return 1;
        }
    }
    return 0;
}
