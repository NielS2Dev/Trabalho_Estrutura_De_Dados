#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adicionais.h"
#include "filas.h"
#include "pilhas.h"


// Push serve para inserir  um nome no topo da pilha.
struct No *push(struct No *pilha, char *nome) {
    struct No *novo = (struct No *)malloc(sizeof(struct No));
    if (novo == NULL) return pilha;

    novo->nome = strdup(nome);
    novo->prox = pilha; // Esse novo nó aponta para o topo da pilha anterior no caso antigo

    return novo; // O Que passará a ser o novo topo da pilha
}
