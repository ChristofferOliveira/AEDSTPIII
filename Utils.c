#include "Utils.h"

String lerArquivo(FILE *arquivo, char *conteudo){

    fseek(arquivo, 0, SEEK_END);
    int inSizeTex = ftell(arqTex)+1;
    rewind(arquivo);
    conteudo = malloc(inSizeTex);
    fread(conteudo, 1, inSizeTex, arquivo);
    return conteudo;
}
