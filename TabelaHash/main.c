#include "hash.h"
#include  <ctype.h> 

#define TAMPAL 67
#define TAMTAB 127


int lePalavra(FILE* fp, char* s){
    int i=0,c;

    while((c = fgetc(fp)) != EOF){
        if(isalpha(c)){
            break;
        }
    }

    if(c == EOF){
        return 0;
    }
    else{
        s[i++] = c;
    }

    while((i<TAMPAL-1) && (c = fgetc(fp)) != EOF && isalpha(c)){
        s[i++] = c;
    }

    s[i] = '\0';

    return i;
}

int main(int argc,char** argv){
    FILE* fp;
    Hash* tab;
    char s[TAMPAL];

    if(argc != 2){
        printf("arquivo nao encontrado\n");
        return 0;
    }

    fp = fopen(argv[1],"rt");

    if(fp == NULL){
        printf("Erro na abertura do arquivo\n");
        return 0;
    }

    //comeco da utilizacao da tabela hash
    tab = inicHash(TAMTAB);

    while(lePalavra(fp,s)){
        Palavra* p = acessa(tab,s);

        atualizaOcorrencias(p);
    }

    imprimeHash(tab);

    liberaHash(tab);
    fclose(fp);

    return 0;
}