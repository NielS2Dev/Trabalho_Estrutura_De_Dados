#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adicionais.h"
#include "filas.h"

// Essa Struct serve para inserir um nome no final da fila e a função tem que retornar um ponteiro para a fila atualizada, ou seja, o início da fila.
struct No *inserir(struct No *fila, char *nome){
    // aloca memória para um novo nó da fila
    struct No *novo = malloc(sizeof(struct No));
    if (novo == NULL){
        printf("Erro ao alocar memória para o novo nó.\n");
        return fila;
    }

    novo->nome = strdup(nome); // Aloca memória para a string e copia o nome
    novo->prox = NULL;

    // Se a fila estiver vazia, o novo nó é o início
    if (fila == NULL) {
        return novo;
    }

    // Agora vamos fazer um loop para encontrar o final da fila e inserir o novo nó lá
    struct No *atual = fila;
    //Em geral aqui é enquanto o próximo nó não for NULL ou seja, enquanto não chegar no final da fila continua avançando, até chegar na condição de atual -> prox ser NULL ou seja o final da fila e aí sim inserir o novo nó.

    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = novo;

    return fila; // Retorna o ponteiro para a fila atualizada
}

struct No *remover(struct No *fila, char **nome){
    // Como no pdf o Sr. colocou "o valor NULL é retornado através do parâmetro nome" creio que seja essa a melhor forma de se fazer passando ponteiro para ponteiro.
    if(fila == NULL){
        *nome = NULL;
        return NULL;
    }

    struct No *removido = fila;
    *nome = removido->nome; // Passa o ponteiro da string para o usuário
    fila = fila->prox; // Atualizando o começinho lá da fila

    free(removido);
    return fila;
}

int tamanho_fila(struct No *fila){
    int cont = 0;

    // Criando essa variável aqui que irá  e guardando o endereço de memória do início da fila para poder percorrer a fila sem perder o endereço do início da fila, porque se eu fizer fila = fila -> prox, aí sim eu perco o endereço do início da fila e não tem como voltar mais, então é melhor criar uma variável auxiliar para percorrer a fila.

    struct No *atual = fila;

    while(atual != NULL){
        cont++;
        atual = atual -> prox;
    }
    return cont;
}

void imprimir_fila(struct No *fila){
    struct No *atual = fila;
    while (atual != NULL) {
        // Mostrando o nome e o endereço do próximo nó para provar a ligação
        printf("[%s | Prox: %p] -> ", atual->nome, (void*)atual->prox);
        atual = atual->prox;
    }
    printf("NULL\n");
}

void destruir_fila(struct No *fila) {
    struct No *atual = fila;
    struct No *prox_no;
    while (atual != NULL) {
        prox_no = atual->prox;
        free(atual->nome); 
        free(atual);       
        atual = prox_no;
    }
}
