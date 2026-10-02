#include <stdio.h>
#include <stdlib.h>

#include "functions/buscar_ordenado.c"
#include "functions/inserir_ordenado.c"
#include "functions/inicializar.c"
#include "functions/remover.c"
#include "functions/destruir.c"
#include "functions/imprimir.c"

// gcc -Wall T1.c -o lista && ./lista > output/T1.txt && rm ./lista.exe && cat output/T1.txt

int main(void)
{
  Lista L;
  inicializar(&L);
  imprimir(&L);

  destruir(&L);
  printf("\nLista destruida. Tamanho final: %d\n", L.tamanho);
  return 0;
}
