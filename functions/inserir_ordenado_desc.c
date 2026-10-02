#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../types/no.h"

/* Insere 'valor' mantendo a ordem decrescente. Retorna 1 em sucesso, 0 em falha. */
int inserir_ordenado_desc(Lista *L, int valor, bool permitir_duplicatas)
{
  No *novo = (No *)malloc(sizeof(No));
  if (novo == NULL)
    return 0; /* sempre teste o malloc! */
  novo->chave = valor;
  novo->prox = NULL;

  No *ant = NULL;        /* nó anterior ao ponto de inserção */
  No *atual = L->inicio; /* cursor de varredura              */

  /* Avança enquanto a chave do nó atual for MAIOR que o valor. */
  while (atual != NULL && atual->chave > valor)
  {
    if (atual->chave == valor && !permitir_duplicatas)
      return 0; // TODO: não permitir duplicatas

    // TODO: atual->chave > valor
    ant = atual;
    atual = atual->prox; // TODO: avançar o cursor
  }

  novo->prox = atual; // TODO: ligar ao sucessor

  if (ant == NULL)
    L->inicio = novo; // TODO: virou o primeiro nó
  else
    ant->prox = novo; // TODO: inserção no meio ou no fim

  L->tamanho++;
  return 1;
}
