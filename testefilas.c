#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main() {
	printf("AAAAAAAAAAAAAAAAAAAAA");
	char nome[100];
	char *nome_antes, *nome_devolvido;
	struct No *fila = NULL;

	printf("======= Fila vazia =======\n");
	fila = inserir(fila, NULL);
	assert(fila == NULL);
	assert(tamanho(fila) == 0);
	imprimir(fila);
	printf("===========================\n\n");

	printf("========== Andre ==========\n");
	strcpy(nome, "Andre");
	fila = inserir(fila, nome);
	assert(fila != NULL);
	assert(strcmp(fila->nome, "Andre") == 0);
	assert(fila->nome != nome);
	assert(fila->prox == NULL);
	assert(tamanho(fila) == 1);
	imprimir(fila);
	printf("===========================\n\n");

	printf("========== Andre ==========\n");
	assert(inserir(fila, NULL) == fila);
	assert(tamanho(fila) == 1);
	imprimir(fila);
	printf("===========================\n\n");

	printf("========= Bartira->Andre =========\n");
	strcpy(nome, "Bartira");
	fila = inserir(fila, nome);
	assert(fila != NULL);
	assert(strcmp(fila->nome, "Bartira") == 0);
	assert(fila->nome != nome);
	assert(strcmp(fila->prox->nome, "Andre") == 0);
	assert(fila->nome != fila->prox->nome);
	assert(fila->prox->prox == NULL);
	assert(tamanho(fila) == 2);
	imprimir(fila);
	printf("===========================\n\n");

	printf("========= Camila->Bartira->Andre =========\n");
	strcpy(nome, "Camila");
	fila = inserir(fila, nome);
	assert(fila != NULL);
	assert(strcmp(fila->nome, "Camila") == 0);
	assert(fila->nome != nome);
	assert(strcmp(fila->prox->nome, "Bartira") == 0);
	assert(fila->nome != fila->prox->nome);
	assert(strcmp(fila->prox->prox->nome, "Andre") == 0);
	assert(fila->prox->nome != fila->prox->prox->nome);
	assert(fila->prox->prox->prox == NULL);
	assert(tamanho(fila) == 3);
	imprimir(fila);
	printf("===========================\n\n");

	printf("========= Chico->Camila->Bartira->Andre =========\n");
	strcpy(nome, "Chico");
	fila = inserir(fila, nome);
	assert(fila != NULL);
	assert(strcmp(fila->nome, "Chico") == 0);
	assert(fila->nome != nome);
	assert(strcmp(fila->prox->nome, "Camila") == 0);
	assert(fila->nome != fila->prox->nome);
	assert(strcmp(fila->prox->prox->nome, "Bartira") == 0);
	assert(fila->prox->nome != fila->prox->prox->nome);
	assert(strcmp(fila->prox->prox->prox->nome, "Andre") == 0);
	assert(fila->prox->prox->nome != fila->prox->prox->prox->nome);
	assert(fila->prox->prox->prox->prox == NULL);
	assert(tamanho(fila) == 4);
	imprimir(fila);
	printf("===========================\n\n");

	printf("========= Chico->Camila->Bartira =========\n");
	fila = remover(fila, &nome_devolvido);
	assert(fila != NULL);
	assert(strcmp(nome_devolvido, "Andre") == 0);
	free(nome_devolvido);
	assert(strcmp(fila->nome, "Chico") == 0);
	assert(fila->nome != nome);
	assert(strcmp(fila->prox->nome, "Camila") == 0);
	assert(fila->nome != fila->prox->nome);
	assert(strcmp(fila->prox->prox->nome, "Bartira") == 0);
	assert(fila->prox->nome != fila->prox->prox->nome);
	assert(fila->prox->prox->prox == NULL);
	assert(tamanho(fila) == 3);
	imprimir(fila);
	printf("===========================\n\n");

	printf("========= Chico->Camila =========\n");
	fila = remover(fila, &nome_devolvido);
	assert(fila != NULL);
	assert(strcmp(nome_devolvido, "Bartira") == 0);
	free(nome_devolvido);
	assert(strcmp(fila->nome, "Chico") == 0);
	assert(fila->nome != nome);
	assert(strcmp(fila->prox->nome, "Camila") == 0);
	assert(fila->nome != fila->prox->nome);
	assert(fila->prox->prox == NULL);
	assert(tamanho(fila) == 2);
	imprimir(fila);
	printf("===========================\n\n");

	printf("========== Chico ==========\n");
	fila = remover(fila, &nome_devolvido);
	assert(fila != NULL);
	assert(strcmp(nome_devolvido, "Camila") == 0);
	free(nome_devolvido);
	assert(strcmp(fila->nome, "Chico") == 0);
	assert(fila->nome != nome);
	assert(fila->prox == NULL);
	assert(tamanho(fila) == 1);
	imprimir(fila);
	printf("===========================\n\n");

	printf("========== Chico ==========\n");
	assert(remover(fila, NULL) == fila);
	assert(tamanho(fila) == 1);
	imprimir(fila);
	printf("===========================\n\n");

	printf("======= fila vazia =======\n");
	nome_antes = fila->nome;
	fila = remover(fila, &nome_devolvido);
	assert(strcmp(nome_devolvido, "Chico") == 0);
	free(nome_devolvido);
	assert(nome_antes == nome_devolvido);
	assert(fila == NULL);
	assert(tamanho(fila) == 0);
	imprimir(fila);
	printf("===========================\n\n");

	destruir(fila);
	printf("Fim do teste\n");
	return 0;
}