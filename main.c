#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adicionais.h"
#include "filas.h"



// Pop: Remove um elemento do topo da pilha.
struct No *pop(struct No *pilha, char **nome) {
    if (pilha == NULL) {
        *nome = NULL; // Retorna NULL se a pilha estiver vazia
        return NULL;
    }

    struct No *removido = pilha;
    *nome = removido->nome; // Passa o ponteiro da string para o usuário
    pilha = pilha->prox;    // Atualiza o topo da pilha

    free(removido); // Libera o nó
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

// ==========================================
// FUNÇÃO MAIN PARA TESTAR O CÓDIGO
// ==========================================
int main() {
    limpartela();
    cadastro();

    // --- TESTE AMPLIADO DE FILA ---
    struct No *fila = NULL;
    char *nome_f;

    printf("--- ADICIONANDO 5 PESSOAS NA FILA ---\n");
    fila = inserir(fila, "Alice");
    fila = inserir(fila, "Bruno");
    fila = inserir(fila, "Carlos");
    fila = inserir(fila, "Daniel");
    fila = inserir(fila, "Elena");
    
    imprimir_fila(fila);

    printf("\n--- REMOVENDO 2 PESSOAS DA FILA ---\n");
    for(int i = 0; i < 2; i++) {
        fila = remover(fila, &nome_f);
        if (nome_f) {
            printf("Saindo da fila: %s\n", nome_f);
            free(nome_f); // Liberando conforme o PDF [cite: 15]
        }
    }
    imprimir_fila(fila);
    destruir_fila(fila); // [cite: 20]


    // --- TESTE AMPLIADO DE PILHA ---
    struct No *pilha = NULL;
    char *nome_p;

    printf("\n\n--- EMPILHANDO 5 NOMES ---\n");
    push(pilha, "Zico"); // Você pode testar assim ou:
    pilha = push(pilha, "Xuxa");
    pilha = push(pilha, "Yuri");
    pilha = push(pilha, "Zico");
    pilha = push(pilha, "Neymar");
    pilha = push(pilha, "Marta");

    imprimir_pilha(pilha);

    printf("\n--- FAZENDO 3 POPS (REMOCOES) ---\n");
    for(int i = 0; i < 3; i++) {
        pilha = pop(pilha, &nome_p);
        if (nome_p) {
            printf("Removido do topo (POP): %s\n", nome_p);
            free(nome_p); // Liberando conforme o PDF [cite: 35]
        }
    }
    imprimir_pilha(pilha);
    destruir_pilha(pilha); // [cite: 42]

    return 0;
}