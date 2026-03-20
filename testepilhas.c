#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main() {
	char nome[100];
	char *nome_antes, *nome_devolvido;
	struct No *pilha = NULL;

	printf("======= Pilha vazia =======\n");
	pilha = push(pilha, NULL);
	assert(pilha == NULL);
	assert(tamanho(pilha) == 0);
	imprimir(pilha);
	printf("===========================\n\n");

	printf("========== Andre ==========\n");
	strcpy(nome, "Andre");
	pilha = push(pilha, nome);
	assert(pilha != NULL);
	assert(strcmp(pilha->nome, "Andre") == 0);
	assert(pilha->nome != nome);
	assert(pilha->prox == NULL);
	assert(tamanho(pilha) == 1);
	imprimir(pilha);
	printf("===========================\n\n");

	printf("========== Andre ==========\n");
	assert(push(pilha, NULL) == pilha);
	assert(tamanho(pilha) == 1);
	imprimir(pilha);
	printf("===========================\n\n");

	printf("========= Bartira->Andre =========\n");
	strcpy(nome, "Bartira");
	pilha = push(pilha, nome);
	assert(pilha != NULL);
	assert(strcmp(pilha->nome, "Bartira") == 0);
	assert(pilha->nome != nome);
	assert(strcmp(pilha->prox->nome, "Andre") == 0);
	assert(pilha->nome != pilha->prox->nome);
	assert(pilha->prox->prox == NULL);
	assert(tamanho(pilha) == 2);
	imprimir(pilha);
	printf("===========================\n\n");

	printf("========= Camila->Bartira->Andre =========\n");
	strcpy(nome, "Camila");
	pilha = push(pilha, nome);
	assert(pilha != NULL);
	assert(strcmp(pilha->nome, "Camila") == 0);
	assert(pilha->nome != nome);
	assert(strcmp(pilha->prox->nome, "Bartira") == 0);
	assert(pilha->nome != pilha->prox->nome);
	assert(strcmp(pilha->prox->prox->nome, "Andre") == 0);
	assert(pilha->prox->nome != pilha->prox->prox->nome);
	assert(pilha->prox->prox->prox == NULL);
	assert(tamanho(pilha) == 3);
	imprimir(pilha);
	printf("===========================\n\n");

	printf("========= Chico->Camila->Bartira->Andre =========\n");
	strcpy(nome, "Chico");
	pilha = push(pilha, nome);
	assert(pilha != NULL);
	assert(strcmp(pilha->nome, "Chico") == 0);
	assert(pilha->nome != nome);
	assert(strcmp(pilha->prox->nome, "Camila") == 0);
	assert(pilha->nome != pilha->prox->nome);
	assert(strcmp(pilha->prox->prox->nome, "Bartira") == 0);
	assert(pilha->prox->nome != pilha->prox->prox->nome);
	assert(strcmp(pilha->prox->prox->prox->nome, "Andre") == 0);
	assert(pilha->prox->prox->nome != pilha->prox->prox->prox->nome);
	assert(pilha->prox->prox->prox->prox == NULL);
	assert(tamanho(pilha) == 4);
	imprimir(pilha);
	printf("===========================\n\n");

	printf("========= Camila->Bartira->Andre =========\n");
	nome_antes = pilha->nome;
	pilha = pop(pilha, &nome_devolvido);
	assert(pilha != NULL);
	assert(strcmp(nome_devolvido, "Chico") == 0);
	assert(nome_antes == nome_devolvido);
	assert(strcmp(pilha->nome, "Camila") == 0);
	assert(pilha->nome != nome);
	assert(strcmp(pilha->prox->nome, "Bartira") == 0);
	assert(pilha->nome != pilha->prox->nome);
	assert(strcmp(pilha->prox->prox->nome, "Andre") == 0);
	assert(pilha->prox->nome != pilha->prox->prox->nome);
	assert(pilha->prox->prox->prox == NULL);
	assert(tamanho(pilha) == 3);
	imprimir(pilha);
	printf("===========================\n\n");

	printf("========= Bartira->Andre =========\n");
	nome_antes = pilha->nome;
	pilha = pop(pilha, &nome_devolvido);
	assert(pilha != NULL);
	assert(strcmp(nome_devolvido, "Camila") == 0);
	assert(nome_antes == nome_devolvido);
	assert(strcmp(pilha->nome, "Bartira") == 0);
	assert(pilha->nome != nome);
	assert(strcmp(pilha->prox->nome, "Andre") == 0);
	assert(pilha->nome != pilha->prox->nome);
	assert(pilha->prox->prox == NULL);
	assert(tamanho(pilha) == 2);
	imprimir(pilha);
	printf("===========================\n\n");

	printf("========== Andre ==========\n");
	nome_antes = pilha->nome;
	pilha = pop(pilha, &nome_devolvido);
	assert(pilha != NULL);
	assert(strcmp(nome_devolvido, "Bartira") == 0);
	assert(nome_antes == nome_devolvido);
	assert(strcmp(pilha->nome, "Andre") == 0);
	assert(pilha->nome != nome);
	assert(pilha->prox == NULL);
	assert(tamanho(pilha) == 1);
	imprimir(pilha);
	printf("===========================\n\n");

	printf("========== Andre ==========\n");
	assert(pop(pilha, NULL) == pilha);
	assert(tamanho(pilha) == 1);
	imprimir(pilha);
	printf("===========================\n\n");

	printf("======= Pilha vazia =======\n");
	nome_antes = pilha->nome;
	pilha = pop(pilha, &nome_devolvido);
	assert(strcmp(nome_devolvido, "Andre") == 0);
	assert(nome_antes == nome_devolvido);
	assert(pilha == NULL);
	assert(tamanho(pilha) == 0);
	imprimir(pilha);
	printf("===========================\n\n");

	destruir(pilha);
	printf("Fim do teste\n");
	return 0;
}