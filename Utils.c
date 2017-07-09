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
    for(int i = 0; i < tamanhoPadrao; i++){
        if(ocorrenciaFinal != 1){
            if(padrao[i] == letraFinal){    //Se alguma letra do padrão é igual a letra do final da tread.
                ocorrenciaFinal = 1;
            }
        }
        if(ocorrenciaInicio != 1){          //Se alguma letra do padrão é igual a letra do inicio da thread.
            if(padrao[i] == letraInicio){
                ocorrenciaInicio = 1;
            }
        }
        if((ocorrenciaFinal == 1) && (ocorrenciaInicio == 1)){  //Possivel ocorrência entre as threads
            return 1;
        }
    }
    return 0;
}
