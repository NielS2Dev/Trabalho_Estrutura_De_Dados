#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição do nó da lista simplesmente ligada, conforme o documento
struct No {
    char *nome;
    struct No *prox;
};

// ==========================================
// TRABALHO DE FILAS (Queue)
// ==========================================

// Inserir: Insere um nome no final da fila.
struct No *inserir(struct No *fila, char *nome) {
    struct No *novo = (struct No *)malloc(sizeof(struct No));
    if (novo == NULL) return fila;
    
    // Aloca memória para a string para evitar problemas de escopo
    novo->nome = strdup(nome);
    novo->prox = NULL;

    // Se a fila estiver vazia, o novo nó é o início
    if (fila == NULL) {
        return novo;
    }

    // Caso contrário, percorre até o final e insere
    // Estou criando um ponteiro chamado atual para meio que pecorrer a fila, e quando chegar no final o próximo do último nó vai apontar para o novo nó xD
    
    struct No *atual = fila;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;

    return fila; // Retorna o ponteiro para a fila atualizada
}

// Remover: Remove um elemento do início da fila.
struct No *remover(struct No *fila, char **nome) {
    if (fila == NULL) {
        *nome = NULL; // Retorna NULL se não for possível remover
        return NULL;
    }

    struct No *removido = fila;
    *nome = removido->nome; // Passa o ponteiro da string para o usuário
    fila = fila->prox;      // Atualiza o início da fila

    free(removido); // Libera apenas o nó, o nome será liberado pelo usuário
    return fila;
}

// Tamanho: Retorna a quantidade de elementos na fila.
int tamanho_fila(struct No *fila) {
    int cont = 0;
    struct No *atual = fila;
    while (atual != NULL) {
        cont++;
        atual = atual->prox;
    }
    return cont;
}

// Imprimir: Imprime do início ao fim da fila.
void imprimir_fila(struct No *fila) {
    struct No *atual = fila;
    printf("\n--- EXIBINDO FILA (Inicio -> Fim) ---\n");
    while (atual != NULL) {
        // Mostra o nome e o endereço do próximo nó para provar a ligação
        printf("[%s | Prox: %p] -> ", atual->nome, (void*)atual->prox);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Destruir: Libera a memória da fila e das strings.
void destruir_fila(struct No *fila) {
    struct No *atual = fila;
    struct No *prox_no;
    while (atual != NULL) {
        prox_no = atual->prox;
        free(atual->nome); // Libera a string
        free(atual);       // Libera o nó
        atual = prox_no;
    }
}


// ==========================================
// TRABALHO DE PILHAS (Stack)
// ==========================================

// Push: Insere um nome no topo da pilha.
struct No *push(struct No *pilha, char *nome) {
    struct No *novo = (struct No *)malloc(sizeof(struct No));
    if (novo == NULL) return pilha;

    novo->nome = strdup(nome);
    novo->prox = pilha; // O novo nó aponta para o antigo topo

    return novo; // O novo nó passa a ser o topo da pilha
}

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