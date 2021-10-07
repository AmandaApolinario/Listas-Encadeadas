#include "arv.h"

void SimOuNao(int num);

int main(){
    Aluno *amanda = InicAluno(121,"Amanda",7.1);
    Aluno *pedro = InicAluno(915,"Pedro",5.9);
    Aluno *ana = InicAluno(342,"Ana",8.2);
    Aluno *filipe = InicAluno(111,"Filipe",4.5);
    Aluno *paula = InicAluno(615,"Paula",9.0);
    Aluno *carlos = InicAluno(713,"Carlos",6.5);

    Arv* arvore = criaArv(amanda,
    criaArv(ana,criaArv(filipe,criaArvVazia(),criaArv(filipe,criaArvVazia(),criaArvVazia())),criaArv(paula,criaArvVazia(),criaArvVazia())),
    criaArv(pedro,criaArvVazia(),criaArv(carlos,criaArvVazia(),criaArv(filipe,criaArvVazia(),criaArvVazia()))));

    arvImprime(arvore);

    printf("\nAmanda esta na lista?\n");
    SimOuNao(arvPertence(arvore,"Amanda"));

    printf("Carlos esta na lista?\n");
    SimOuNao(arvPertence(arvore,"Carlos"));

    printf("Aline esta na lista?\n");
    SimOuNao(arvPertence(arvore,"Aline"));

    int folhas = qtdFolhasArv(arvore);
    printf("A quantidade de folhas da arvore eh: %d\n",folhas);

    int ocorrencias = qtdOcorrenciasArv(arvore,"Filipe");
    printf("A quantidade de ocorrencias do nome %s na arvore eh %d\n","Filipe",ocorrencias);

    int altura = alturaArv(arvore);
    printf("A altura da arvore eh: %d\n",altura);

    arvore = arvLibera(arvore);
    DestroiAluno(amanda);
    DestroiAluno(pedro);
    DestroiAluno(ana);
    DestroiAluno(filipe);
    DestroiAluno(paula);
    DestroiAluno(carlos);

    return 0;
}

void SimOuNao(int num){
    if(num == 1){
        printf("Sim!\n");
    }
    else{
        printf("Nao!\n");
    }
}