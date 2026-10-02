#include <stdio.h>
#include <stdlib.h>
#include "../types/no.h"

/* Retorna o nó com a chave procurada, ou NULL.
   Escreve em *comparacoes quantos nós foram efetivamente examinados. */
No *buscar_ordenado_desc(Lista *L, int valor, int *comparacoes)
{
  No *p = L->inicio;
  int c = 0;

  while (p != NULL)
  {
    c++; /* contabiliza a visita */

    if (p->chave == valor)
    { /* encontrou */
      if (comparacoes)
        *comparacoes = c;
      return p; // TODO: devolver o nó
    }

    if (p->chave < valor) // TODO: p->chave < valor
      break;              /* PARADA ANTECIPADA */

    p = p->prox; // TODO: avançar
  }

  if (comparacoes)
    *comparacoes = c;
  return NULL;
}
