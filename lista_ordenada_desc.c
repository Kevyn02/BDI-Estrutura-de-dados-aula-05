#include <stdio.h>
#include <stdlib.h>

#include "functions/buscar_ordenado_desc.c"
#include "functions/inserir_ordenado_desc.c"
#include "functions/inicializar.c"
#include "functions/remover.c"
#include "functions/destruir.c"
#include "functions/imprimir.c"

// gcc -Wall lista_ordenada_desc.c -o lista && ./lista > output/lista_ordenada_desc.txt && rm ./lista.exe && cat output/lista_ordenada_desc.txt

int main(void)
{
  Lista L;
  inicializar(&L);

  int dados[] = {40, 10, 75, 30, 90, 25};
  int n = sizeof(dados) / sizeof(dados[0]);

  printf("== INSERINDO ==\n");
  for (int i = 0; i < n; i++)
  {
    inserir_ordenado_desc(&L, dados[i], true); // TODO: inserir_ordenado(&L, dados[i])
    printf("insere %2d -> ", dados[i]);
    imprimir(&L);
  }

  printf("\n== BUSCANDO ==\n");
  int chaves[] = {10, 40, 60, 999};
  for (int i = 0; i < 4; i++)
  {
    int comps = 0;
    No *r = buscar_ordenado_desc(&L, chaves[i], &comps);
    printf("busca %3d: %-12s (%d comparacoes)\n",
           chaves[i], r ? "ENCONTRADO" : "ausente", comps);
  }

  printf("\n== REMOVENDO ==\n");
  int alvos[] = {10, 40, 999}; /* 1o, meio, inexistente */
  for (int i = 0; i < 3; i++)
  {
    int ok = remover(&L, alvos[i]); // TODO: remover(&L, alvos[i])
    printf("remove %3d [%s] -> ", alvos[i], ok ? "ok" : "--");
    imprimir(&L);
  }

  destruir(&L);
  printf("\nLista destruida. Tamanho final: %d\n", L.tamanho);
  return 0;
}
