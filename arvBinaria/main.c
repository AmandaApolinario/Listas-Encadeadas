#include "ArvBinBusca.h"

int main(){
    Aluno *amanda = InicAluno(121,"Amanda",7.1);
    Aluno *pedro = InicAluno(915,"Pedro",5.9);
    Aluno *ana = InicAluno(342,"Ana",8.2);
    Aluno *filipe = InicAluno(111,"Filipe",4.5);
    Aluno *paula = InicAluno(615,"Paula",9.0);
    Aluno *carlos = InicAluno(713,"Carlos",6.5);

    Arv* arv = arvBinCria(arv);

    arv = arvBinInsere(arv,amanda);
    arv = arvBinInsere(arv,pedro);
    arv = arvBinInsere(arv,ana);
    arv = arvBinInsere(arv,filipe);
    arv = arvBinInsere(arv,paula);
    arv = arvBinInsere(arv,carlos);

    arvBinImprime(arv);

    printf("busca o aluno de matricula 111:\n");
    Arv* t;
    t = arvBinBusca(arv, 111);
    if(t != NULL){
        printf("%s %d\n",RetornaNomeAluno(retornaAluno(t)),RetornaMat(retornaAluno(t)));
    }
    else{
        printf("nao existe\n");
    }

    printf("busca o aluno de matricula 2:\n");
    t = arvBinBusca(arv, 2);
    if(t != NULL){
        printf("%s %d\n",RetornaNomeAluno(retornaAluno(t)),RetornaMat(retornaAluno(t)));
    }
    else{
        printf("nao existe\n");
    }

    arvBinRetira(arv, 121);//retira um no com dois filhos;
    arvBinImprime(arv);
    printf("\n");

    arvBinRetira(arv, 713);//retira uma folha;
    arvBinImprime(arv);
    printf("\n");

    arvBinRetira(arv,915);//retira um no com um filho;
    arvBinImprime(arv);
    printf("\n");

    arvBinRetira(arv, 1);//tenta retirar um que nao existe;
    arvBinImprime(arv);
    printf("\n");

    //reinsere na arvore para liberar a memoria de todos juntos
    arvBinInsere(arv,amanda);
    arvBinInsere(arv,carlos);
    arvBinInsere(arv,pedro);

    arv = arvBinLibera(arv);

    return 0;
}