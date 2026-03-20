#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"


// Push serve para inserir  um nome no topo da pilha.
struct No *push(struct No *pilha, char *nome) {
    if(nome == NULL) return pilha; // Se o nome for NULL a pilha contina a mesma coisa sem alterações
    
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
        if (nome != NULL) *nome = NULL;
        return NULL;
    }

    if (nome == NULL) {
        return pilha;
    }

    struct No *removido = pilha;
    struct No *nova_pilha = pilha->prox;

    *nome = removido->nome;     

    // REMOVER NÃO LIBERA DO NOME E SIM DO NÓ
    // ANOTAÇÃO DA AULA
    free(removido); 
    return nova_pilha;
}



// retorna a quantidade de elementos na pilha.
int tamanho(struct No *pilha) {
    int cont = 0;
    struct No *atual = pilha;
    while (atual != NULL) {
        cont++;
        atual = atual->prox;
    }
    return cont;
}


// mprime do topo até a base da pilha. 
// Retorna a quantidade de elementos impressos
int imprimir(struct No *pilha) {
    struct No *atual = pilha;
    int cont = 0;
    while (atual != NULL) {
        printf("[%s] -> ", atual->nome);
        atual = atual->prox;
        cont++;
    }
    printf("NULL\n");
    return cont; 
}

// libera a memória da pilha e das strings.
void destruir(struct No *pilha) {
    struct No *atual = pilha;
    struct No *prox_no;
    while (atual != NULL) {
        prox_no = atual->prox;
        free(atual->nome);
        free(atual);
        atual = prox_no;
    }
}