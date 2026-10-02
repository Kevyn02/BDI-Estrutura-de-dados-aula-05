#include <stdio.h>
#include <stdlib.h>

#include "functions/buscar_ordenado.c"
#include "functions/inserir_ordenado.c"
#include "functions/inicializar.c"
#include "functions/remover.c"
#include "functions/destruir.c"
#include "functions/imprimir.c"

// gcc -Wall T13.c -o lista && ./lista > output/T13.txt && rm ./lista.exe && cat output/T13.txt

int main(void)
{
  Lista L;
  inicializar(&L);

  int dados[] = {10, 75, 40, 90};
  int n = sizeof(dados) / sizeof(dados[0]);

  printf("== INSERINDO ==\n");
  for (int i = 0; i < n; i++)
  {
    inserir_ordenado(&L, dados[i]); // TODO: inserir_ordenado(&L, dados[i])
    printf("insere %2d -> ", dados[i]);
    imprimir(&L);
  }

  printf("\n== REMOVENDO ==\n");
  int alvos[] = {90}; /* 1o, meio, inexistente */
  int tamanho_alvos = sizeof(alvos) / sizeof(alvos[0]);
  for (int i = 0; i < tamanho_alvos; i++)
  {
    int ok = remover(&L, alvos[i]); // TODO: remover(&L, alvos[i])
    printf("remove %3d [%s] -> ", alvos[i], ok ? "ok" : "--");
    imprimir(&L);
  }

  destruir(&L);
  printf("\nLista destruida. Tamanho final: %d\n", L.tamanho);
  return 0;
}
