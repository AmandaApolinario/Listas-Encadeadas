#include "hash.h"

struct hash{
    Palavra** vet;
    int tamanho;
};

//nao faz parte do tad por isso usa 'static int'
//vai calcular a pos q vai colocar na tabela hash
static int hash(char* string,int tam){
    int i;
    int total = 0;
    for(i=0;string[i]!= '\0';i++){
        total+= string[i];
    }

    return (total%tam);
}

Hash* inicHash(int tam){
    int i;

    Hash* h = (Hash*)malloc(sizeof(Hash));
    h->tamanho = tam;

    h->vet = (Palavra**)malloc(tam*sizeof(Palavra*));

    //iniciar a tabela com NULL Pq usa na busca
    for(i=0;i<tam;i++){
        h->vet[i] = NULL;
    }
    return h;
}

//insere a palavra ou incrementa se ela ja estiver la
Palavra* acessa(Hash* h, char* string){
    Palavra* p;

    //aplica a funcao de hash e acha o indice q a palavra devia ta na tabela
    int indice = hash(string,h->tamanho);

    //se a palavra ja ta na lista,atualiza 
    //se a busca retornar diferente de null, a palavra existe
    p = buscaPalavra(h->vet[indice],string);

    if(p){
        return p;
    }

    //se p for null, adiciona a palavra
    p = inicPalavra(string);

    h->vet[indice] = inserePalavraLista(h->vet[indice],p);

    return p;
}

int contaPalavras(Hash* h);

void imprimeHash(Hash* h){
    int i;

    for(i=0;i<h->tamanho;i++){
        printf("\nPos vet[%d]: \n",i);
        imprimeLista(h->vet[i]);
    }
}

void liberaHash(Hash* h){
    int i;

    for(i=0;i<h->tamanho;i++){
        liberaListaPalavra(h->vet[i]);
    }

    free(h->vet);
    free(h);
}