#include <stdio.h>
#include <stdlib.h>
#include "types/no.h"

void imprimir(Lista *L)
{
  printf("[");
  for (No *p = L->inicio; p != NULL; p = p->prox)
    printf("%d%s", p->chave, p->prox ? " -> " : "");
  printf("]  (n=%d)\n", L->tamanho);
}
