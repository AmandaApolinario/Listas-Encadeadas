#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz{
    int **numeros;
    int qtdLinhas;
    int qtdColunas;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    Matriz *mat = (Matriz*)malloc(sizeof(Matriz));
    
    mat->numeros = (int**)malloc(nlinhas * sizeof(int*));
    for(int i=0;i<nlinhas;i++){
        mat->numeros[i] = (int*)malloc(ncolunas * sizeof(int));
    }
    
    mat->qtdColunas = ncolunas;
    mat->qtdLinhas = nlinhas;

    return mat;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    mat->numeros[linha][coluna] = elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna){
    return mat->numeros[linha][coluna];
}

int recuperaNColunas (Matriz* mat){
    return mat->qtdColunas;
}

int recuperaNLinhas (Matriz* mat){
    return mat->qtdLinhas;
}

Matriz* transposta (Matriz* mat){
    Matriz *transp;
    transp = inicializaMatriz(mat->qtdColunas,mat->qtdLinhas);

    for(int i=0;i<mat->qtdLinhas;i++){
        for(int j=0;j<mat->qtdColunas;j++){
            transp->numeros[j][i]= mat->numeros[i][j];
        }
    }
    return transp;
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    Matriz *multp;
    multp = inicializaMatriz(mat1->qtdLinhas,mat2->qtdColunas);

    for (int i = 0; i < mat1->qtdLinhas; i++){
        for (int j = 0; j < mat2->qtdColunas; j++){
            multp->numeros[i][j] = 0;
            for (int x = 0; x < mat1->qtdColunas; x++){
                multp->numeros[i][j] += mat1->numeros[i][x]* mat2->numeros[x][j];
            }
        }
    }
    return multp;
}

void imprimeMatriz(Matriz* mat){
    for(int i=0;i<mat->qtdLinhas;i++){
        for(int j=0;j<mat->qtdColunas;j++){
            printf("%d ",mat->numeros[i][j]);
        }
        printf("\n");
    }
}

void destroiMatriz(Matriz* mat){
    for(int i=0;i<mat->qtdLinhas;i++){
        free(mat->numeros[i]);
    }

    free(mat->numeros);
    free(mat);
}