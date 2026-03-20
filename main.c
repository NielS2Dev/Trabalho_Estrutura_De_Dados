#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adicionais.h"
#include "filas.h"
#include "pilhas.h"


int main() {
    limpartela();

    struct No *fila = NULL;
    char *nome_f;

    cadastro();
    fila = inserir(fila, "Alice");
    fila = inserir(fila, "Bruno");
    fila = inserir(fila, "Carlos");
    fila = inserir(fila, "Daniel");
    fila = inserir(fila, "Elena");
    
    exibirfila();
    imprimir_fila(fila);

    printf("\n--- REMOVENDO 2 PESSOAS DA FILA ---\n");
    for(int i = 0; i < 2; i++) {
        fila = remover(fila, &nome_f);
        if (nome_f) {
            printf("Saindo da fila: %s\n", nome_f);
            free(nome_f); 
        }
    }
    imprimir_fila(fila);
    destruir_fila(fila); 


  
    struct No *pilha = NULL;
    char *nome_p;

    printf("\n\n--- EMPILHANDO 5 NOMES ---\n");
    push(pilha, "Zico"); 
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
            free(nome_p); 
        }
    }
    imprimir_pilha(pilha);
    destruir_pilha(pilha); 

    return 0;
}