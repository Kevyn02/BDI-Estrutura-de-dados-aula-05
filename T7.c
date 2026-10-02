#include <stdio.h>
#include <stdlib.h>

#include "functions/buscar_ordenado.c"
#include "functions/inserir_ordenado.c"
#include "functions/inicializar.c"
#include "functions/remover.c"
#include "functions/destruir.c"
#include "functions/imprimir.c"

// gcc -Wall T7.c -o lista && ./lista > output/T7.txt && rm ./lista.exe && cat output/T7.txt

int main(void)
{
  Lista L;
  inicializar(&L);

  int dados[] = {5, 4, 3, 2, 1};
  int n = sizeof(dados) / sizeof(dados[0]);

  printf("== INSERINDO ==\n");
  for (int i = 0; i < n; i++)
  {
    inserir_ordenado(&L, dados[i]); // TODO: inserir_ordenado(&L, dados[i])
    printf("insere %2d -> ", dados[i]);
    imprimir(&L);
  }

  destruir(&L);
  printf("\nLista destruida. Tamanho final: %d\n", L.tamanho);
  return 0;
}
