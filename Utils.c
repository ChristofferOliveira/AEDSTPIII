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
