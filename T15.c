#include <stdio.h>
#include <stdlib.h>

#include "functions/buscar_ordenado.c"
#include "functions/inserir_ordenado.c"
#include "functions/inicializar.c"
#include "functions/remover.c"
#include "functions/destruir.c"
#include "functions/imprimir.c"

// gcc -Wall T15.c -o lista && ./lista > output/T15.txt && rm ./lista.exe && cat output/T15.txt

int main(void)
{
  Lista L;
  inicializar(&L);

  int dados[] = {10, 75, 40};
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

  int novo_dados[] = {7};
  int novo_n = sizeof(novo_dados) / sizeof(novo_dados[0]);

  printf("== INSERINDO ==\n");
  for (int i = 0; i < novo_n; i++)
  {
    inserir_ordenado(&L, novo_dados[i]); // TODO: inserir_ordenado(&L, novo_dados[i])
    printf("insere %2d -> ", novo_dados[i]);
    imprimir(&L);
  }
  return 0;
}
