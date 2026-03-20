#ifndef PILHAS_H
#define PILHAS_H

#include "adicionais.h"

struct No *push(struct No *pilha, char *nome);
struct No *pop(struct No *pilha, char **nome);
int tamanho_pilha(struct No *pilha);
int imprimir_pilha(struct No *pilha);
void destruir(struct No *pilha);


#endif