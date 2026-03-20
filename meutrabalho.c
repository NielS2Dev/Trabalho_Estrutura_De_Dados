#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpartela(){
    system("clear");
}   

void mudarcor(int cor) {
    switch(cor) {
        case 0: printf("\033[0m"); break;   
        case 1: printf("\033[31m"); break;  // Vermelho
        case 2: printf("\033[32m"); break;  // Verde
        case 3: printf("\033[33m"); break;  // Amarelo
        case 4: printf("\033[34m"); break;  // Azul
        case 5: printf("\033[35m"); break;  // Magenta
        case 6: printf("\033[36m"); break;  // Ciano
        case 7: printf("\033[37m"); break;  // Branco
        case 8: printf("\033[90m"); break;  // Cinza
        case 9: printf("\033[91m"); break;  // Vermelho claro
    }
}

void cadastro(){
    mudarcor(2);
    printf("==================================================================================================================================================================================================================\n");
    mudarcor(5);
    printf(" ________                  __                  __  __                                      ________  __  __                                            _______   __  __  __                           \n");
    printf("/        |                /  |                /  |/  |                                    /        |/  |/  |                                          /       \\ /  |/  |/  |                          \n");
    printf("$$$$$$$$/______   ______  $$ |____    ______  $$ |$$ |____    ______                      $$$$$$$$/ $$/ $$ |  ______    _______         ______        $$$$$$$  |$$/ $$ |$$ |____    ______    _______ \n");
    printf("   $$ | /      \\ /      \\ $$      \\  /      \\ $$ |$$      \\  /      \\        ______       $$ |__    /  |$$ | /      \\  /       |       /      \\       $$ |__$$ |/  |$$ |$$      \\  /      \\  /       |\n");
    printf("   $$ |/$$$$$$  |$$$$$$  |$$$$$$$  | $$$$$$  |$$ |$$$$$$$  |/$$$$$$  |      /      |      $$    |   $$ |$$ | $$$$$$  |/$$$$$$$/       /$$$$$$  |      $$    $$/ $$ |$$ |$$$$$$$  | $$$$$$  |/$$$$$$$/ \n");
    printf("   $$ |$$ |  $$/ /    $$ |$$ |  $$ | /    $$ |$$ |$$ |  $$ |$$ |  $$ |      $$$$$$/       $$$$$/    $$ |$$ | /    $$ |$$      \\       $$    $$ |      $$$$$$$/  $$ |$$ |$$ |  $$ | /    $$ |$$      \\ \n");
    printf("   $$ |$$ |     /$$$$$$$ |$$ |__$$ |/$$$$$$$ |$$ |$$ |  $$ |$$ \\__$$ |                    $$ |      $$ |$$ |/$$$$$$$ | $$$$$$  |      $$$$$$$$/       $$ |      $$ |$$ |$$ |  $$ |/$$$$$$$ | $$$$$$  |\n");
    printf("   $$ |$$ |     $$    $$ |$$    $$/ $$    $$ |$$ |$$ |  $$ |$$    $$/                     $$ |      $$ |$$ |$$    $$ |/     $$/       $$       |      $$ |      $$ |$$ |$$ |  $$ |$$    $$ |/     $$/ \n");
    printf("   $$/ $$/       $$$$$$$/ $$$$$$$/   $$$$$$$/ $$/ $$/   $$/  $$$$$$/                      $$/       $$/ $$/  $$$$$$$/ $$$$$$$/         $$$$$$$/       $$/       $$/ $$/ $$/   $$/  $$$$$$$/ $$$$$$$/  \n");

    mudarcor(2);
    printf("\n==================================================================================================================================================================================================================\n");
    mudarcor(0);
}


struct No {
    char *nome;
    struct No *prox;
};


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

int main(){
    limpartela();
    cadastro();
    printf("Olá\n");
}