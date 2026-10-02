#include <stdio.h>
#include <stdlib.h>
#include "types/no.h"

/* Remove a primeira ocorrência de 'valor'. Retorna 1 se removeu, 0 caso contrário. */
int remover(Lista *L, int valor)
{
  No *ant = NULL;
  No *atual = L->inicio;

  while (atual != NULL && atual->chave < valor)
  {
    ant = atual;
    atual = atual->prox;
  }

  /* Não achou: fim da lista ou já passou do ponto. */
  if (atual == NULL || atual->chave != valor)
    return 0;

  /* Desliga o nó da corrente. */
  if (ant == NULL)
    L->inicio = atual->prox; // TODO: removendo o primeiro nó
  else
    ant->prox = atual->prox; // TODO: costurar anterior com sucessor

  free(atual); // TODO: devolver a memória
  L->tamanho--;
  return 1;
}
