#ifndef ADICIONAIS_H
#define ADICIONAIS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No {
    char *nome;
    struct No *prox;
};

void mudarcor(int cor);
void limpartela();
void exibirfila();
void exibirpilha();
void cadastro();
void antesdafila();



#endif