#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct professor Professor;

Professor* InicProfessor(int siape, char *nome,float salario);

void ImprimeProfessor(Professor *prof);

int RetornaSiape(Professor *prof);

char *RetornaNomeProfessor(Professor *prof);

float RetornaSalario(Professor *prof);

void DestroiProfessor(Professor *prof);

#endif