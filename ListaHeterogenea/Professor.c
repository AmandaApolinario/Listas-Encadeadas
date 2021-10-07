#include "Professor.h"

struct professor{
    int siape;
    char *nome;
    float salario;
};

Professor* InicProfessor(int siape, char *nome,float salario){
    Professor *novo = (Professor*)malloc(sizeof(Professor));
    novo->nome = strdup(nome);
    novo->siape = siape;
    novo->salario = salario;

    return novo;
}

void ImprimeProfessor(Professor *prof){
    printf("Siape: %d, Nome: %s, Salario: %.2f\n",prof->siape,prof->nome,prof->salario);
}

int RetornaSiape(Professor *prof){
    return prof->siape;
}

char *RetornaNomeProfessor(Professor *prof){
    return prof->nome;
}

float RetornaSalario(Professor *prof){
    return prof->salario;
}

void DestroiProfessor(Professor *prof){
    free(prof->nome);
    free(prof);
}