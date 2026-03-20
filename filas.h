#ifndef FILAS_H
#define FILAS_H

#include "adicionais.h"


struct No *inserir(struct No *fila, char *nome);
struct No *remover(struct No *fila, char **nome);
int tamanho_fiila(struct No *fila);
void imprimir_fila(struct No *fila);
void destruir_fila(struct No *fila);

#endif