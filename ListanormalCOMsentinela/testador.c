#include <stdio.h>
#include <stdlib.h>
#include "listaMat.h"

Matriz * PreencheMatrizAleatoria(Matriz *mat);

int main(){
    srand(9);

    Matriz *mat1,*mat2,*mat3,*mat4;

    mat1 = inicializaMatriz(4,4);
    mat2 = inicializaMatriz(2,5);
    mat3 = inicializaMatriz(3,2);
    mat4 = inicializaMatriz(5,3);

    mat1 = PreencheMatrizAleatoria(mat1);
    mat2 = PreencheMatrizAleatoria(mat2);
    mat3 = PreencheMatrizAleatoria(mat3);
    mat4 = PreencheMatrizAleatoria(mat4);

    Lista *lista = InicLista();
    InsereLista(lista,mat1);
    InsereLista(lista,mat2);
    InsereLista(lista,mat3);
    InsereLista(lista,mat4);

    printf("A lista de matrizes eh:\n");
    ImprimeLista(lista);

    Matriz * transp1 = transposta(mat1);
    Matriz *transp2 = transposta(mat2);
    Matriz *transp3 = transposta(mat3);
    Matriz *transp4 = transposta(mat4);

    Lista *listaTransp = InicLista();
    InsereLista(listaTransp,transp1);
    InsereLista(listaTransp,transp2);
    InsereLista(listaTransp,transp3);
    InsereLista(listaTransp,transp4);

    printf("A lista transposta eh:\n");
    ImprimeLista(listaTransp);

    printf("A lista normal sem a primeira matriz eh:\n");
    RetiraLista(lista,0);
    ImprimeLista(lista);

    printf("A lista normal sem a matriz do meio eh:\n");
    RetiraLista(lista,1);
    ImprimeLista(lista);

    printf("A lista de transpostas sem o ultimo elemento eh:\n");
    RetiraLista(listaTransp,3);
    ImprimeLista(listaTransp);

    printf("Lista normal com as duas matrizes que foram removidas adicionadas:\n");
    InsereLista(lista,mat4);
    InsereLista(lista,mat2);
    ImprimeLista(lista);

    printf("Lista transposta adicionando a matriz removida:\n");
    InsereLista(listaTransp,transp1);
    ImprimeLista(listaTransp);

    DestroiLista(lista);
    DestroiLista(listaTransp);
    
    return 0;
}

Matriz * PreencheMatrizAleatoria(Matriz *mat){
    for(int i=0;i<recuperaNLinhas(mat);i++){
        for(int j=0;j<recuperaNColunas(mat);j++){
            modificaElemento(mat, i, j,rand()%15);
        }
    }

    return mat;
}