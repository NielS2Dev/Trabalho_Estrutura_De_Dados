#ifndef ADICIONAIS_H
#define ADICIONAIS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No {
    char *nome;
    struct No *prox;
};

void mudarCor(int cor);
void limpartela();
void exibirfila();
void cadastro();




#endif