#include "Fila.h"

int main(){

    Filmes * f1 = InicFilmes("Um lugar silencioso",9);
    Filmes * f2 = InicFilmes("Esquadrao suicida",3);
    Filmes * f3 = InicFilmes("Clube da luta",10);
    Filmes * f4 = InicFilmes("O jogo da imitacao",8);
    Filmes * f5 = InicFilmes("Fallen Angels",7);


    Fila* fila = inicFila();

    insereFila(fila,f1);
    insereFila(fila,f2);
    insereFila(fila,f3);
    insereFila(fila,f4);
    insereFila(fila,f5);

    printf("imprime fila\n");
    imprimeFila(fila);

    retiraFila(fila);
    retiraFila(fila);
    retiraFila(fila);
    retiraFila(fila);
    retiraFila(fila);

    printf("\nimprime fila vazia\n");
    imprimeFila(fila);

    insereFila(fila,f1);
    insereFila(fila,f2);
    insereFila(fila,f3);
    insereFila(fila,f4);
    insereFila(fila,f5);

    printf("\nimprime fila readicionando filmes\n");
    imprimeFila(fila);

    destroiFila(fila);
    return 0;
}
