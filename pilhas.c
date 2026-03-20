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

// Apenas salvando para me beasear xD
// Pop: Remove um elemento da pilha. O nome removido da pilha deve ser retornado pelo
// parâmetro nome. Caso não seja possível remover um elemento da pilha, o valor NULL é
// retornado através do parâmetro nome. A função retorna um ponteiro para a pilha
// atualizada. Cabe ao usuário da biblioteca liberar a memória utilizada pelo nome retornado.
struct No *pop(struct No *pilha, char **nome){
    if (pilha == NULL) {
        *nome = NULL; // Retorna NULL se a pilha estiver vazia
        return NULL;
    }

    struct No *removido = pilha;
    *nome = removido->nome; 
    pilha = pilha->prox;    

    free(removido); 
    return pilha;
}


// Tamanho: Retorna a quantidade de elementos na pilha.
int tamanho_pilha(struct No *pilha) {
    int cont = 0;
    struct No *atual = pilha;
    while (atual != NULL) {
        cont++;
        atual = atual->prox;
    }
    return cont;
}


// Imprimir: Imprime do topo até a base da pilha. 
// Retorna a quantidade de elementos impressos (pois a assinatura exige 'int').
int imprimir_pilha(struct No *pilha) {
    struct No *atual = pilha;
    int cont = 0;
    printf("\n--- EXIBINDO PILHA (Topo -> Base) ---\n");
    while (atual != NULL) {
        // Formato vertical para parecer uma pilha de verdade
        printf("  [Topo + %d] Nome: %-7s | End: %p | Prox: %p\n", cont, atual->nome, (void*)atual, (void*)atual->prox);
        atual = atual->prox;
        cont++;
    }
    printf("  ------------------ BASE DA PILHA ------------------\n");
    return cont; // Retorna a quantidade de elementos 
}

// Destruir: Libera a memória da pilha e das strings.
void destruir_pilha(struct No *pilha) {
    struct No *atual = pilha;
    struct No *prox_no;
    while (atual != NULL) {
        prox_no = atual->prox;
        free(atual->nome);
        free(atual);
        atual = prox_no;
    }
}