#include <stdio.h>
#include <stdlib.h>

#include "functions/buscar_ordenado.c"
#include "functions/inserir_ordenado.c"
#include "functions/inicializar.c"
#include "functions/remover.c"
#include "functions/destruir.c"
#include "functions/imprimir.c"

// gcc -Wall T10.c -o lista && ./lista > output/T10.txt && rm ./lista.exe && cat output/T10.txt

int main(void)
{
  Lista L;
  inicializar(&L);

  int dados[] = {10, 75, 40};
  int n = sizeof(dados) / sizeof(dados[0]);

  printf("== INSERINDO ==\n");
  for (int i = 0; i < n; i++)
  {
    inserir_ordenado(&L, dados[i], true); // TODO: inserir_ordenado(&L, dados[i])
    printf("insere %2d -> ", dados[i]);
    imprimir(&L);
  }

  printf("\n== BUSCANDO ==\n");
  int chaves[] = {60};
  int tamanho_chaves = sizeof(chaves) / sizeof(chaves[0]);
  for (int i = 0; i < tamanho_chaves; i++)
  {
    int comps = 0;
    No *r = buscar_ordenado(&L, chaves[i], &comps);
    printf("busca %3d: %-12s (%d comparacoes)\n",
           chaves[i], r ? "ENCONTRADO" : "ausente", comps);
  }
  destruir(&L);
  printf("\nLista destruida. Tamanho final: %d\n", L.tamanho);
  return 0;
}
