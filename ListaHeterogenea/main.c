#include "Professor.h"
#include "Aluno.h"
#include "ListaHet.h"

int main(){
    Aluno* amanda = InicAluno(111,"Amanda",5);
    Aluno* paula = InicAluno(222, "Paula", 9);
    Aluno* matheus = InicAluno(333,"Matheus", 8);
    Aluno* lorenzo = InicAluno(444,"Lorenzo",7);

    Professor* vinicius = InicProfessor(12345,"Vinicius",8000.00);
    Professor* patricia = InicProfessor(54321,"Patricia",9000.00);

    ListaHet* churrasco = InicLista();

    InsereAluno(churrasco,amanda);
    InsereAluno(churrasco,paula);
    InsereProfessor(churrasco,vinicius);
    InsereAluno(churrasco,matheus);
    InsereAluno(churrasco,lorenzo);
    InsereProfessor(churrasco,patricia);

    printf("Lista de pessoas:\n");
    ImprimeListaHet(churrasco);

    float valor = 0;
    valor = ValorChurrasco(churrasco);
    printf("Valor: %.2f",valor);

    DestroiLista(churrasco);

    DestroiAluno(amanda);
    DestroiAluno(paula);
    DestroiAluno(matheus);
    DestroiAluno(lorenzo);

    DestroiProfessor(vinicius);
    DestroiProfessor(patricia);

    return 0;
}