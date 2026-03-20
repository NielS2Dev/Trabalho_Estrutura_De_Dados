#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

// Aqui estamos basicamente inserindo um nome no final da fila e a função tem que retonar um ponteiro para a fila atualizado
struct No *inserir(struct No *fila, char *nome) {
    if (nome == NULL){
        return fila;
    }
    // aloca memoria para o nó ;-;
    struct No *novo = malloc(sizeof(struct No));
    if (novo == NULL){
        return fila;
    }

    novo->nome = strdup(nome);
    novo->prox = fila; 
    return novo; 
}
struct No *remover(struct No *fila, char **nome) {
    // Como no pdf o Sr. colocou "o valor NULL é retornado através do parâmetro nome" creio que seja essa a melhor forma de se fazer passando ponteiro para ponteiro.
    if (fila == NULL) {
        if (nome != NULL) *nome = NULL;
        return NULL;
    }

    if (nome == NULL){
        return fila;
    } 

    // e só tiver 1 elemento na fila
    if (fila->prox == NULL) {
        *nome = fila->nome;
        free(fila);
        return NULL;
    }

    // buscando o penultimo no para remover o ultimo
    struct No *anterior = NULL;
    struct No *atual = fila;

    while (atual->prox != NULL) {
        anterior = atual;
        atual = atual->prox;
    }

    // meio que o atual agora é o utilmo e o anteriro e oq vem antes do ultimo o penultimo então  
    *nome = atual->nome;
    free(atual);
    anterior->prox = NULL; //aqui que transformaos o peunulto em ultimo

    return fila;
}


int tamanho(struct No *fila){
    int cont = 0;

    // Criando essa variável aqui que irá  e guardando o endereço de memória do início da fila para poder percorrer a fila sem perder o endereço do início da fila, porque se eu fizer fila = fila -> prox, aí sim eu perco o endereço do início da fila e não tem como voltar mais, então é melhor criar uma variável auxiliar para percorrer a fila.

    struct No *atual = fila;

    while(atual != NULL){
        cont++;
        atual = atual -> prox;
    }
    return cont;
}

void imprimir(struct No *fila){
    struct No *atual = fila;
    while (atual != NULL) {
        // Mostrando o nome e o endereço do próximo nó para mostrar que tem uma ligação
        printf("[%s | Prox: %p] -> ", atual->nome, (void*)atual->prox);
        atual = atual->prox;
    }
    printf("NULL\n");
}

void destruir(struct No *fila) {
    struct No *atual = fila;
    struct No *prox_no;
    while (atual != NULL) {
        prox_no = atual->prox;
        free(atual->nome); 
        free(atual);       
        atual = prox_no;
    }
}
