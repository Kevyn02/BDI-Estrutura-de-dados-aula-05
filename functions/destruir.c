#include <stdio.h>
#include <stdlib.h>
#include "types/no.h"

/* Libera todos os nós e devolve a lista ao estado vazio. */
void destruir(Lista *L)
{
  No *p = L->inicio;
  while (p != NULL)
  {
    No *proximo = p->prox; // TODO: guardar ANTES do free
    free(p);
    p = proximo;
  }
  L->inicio = NULL;
  L->tamanho = 0;
}
