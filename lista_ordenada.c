#include <stdio.h>
#include <stdlib.h>

/* Nó da lista: guarda a chave de ordenação e o ponteiro para o sucessor. */
typedef struct No
{
  int chave;
  struct No *prox; // TODO: ponteiro para o próximo nó
} No;

/* Descritor da lista: ponto de entrada + metadado de tamanho. */
typedef struct
{
  No *inicio; // TODO: aponta para o MENOR elemento
  int tamanho;
} Lista;

/* Deixa a lista em estado vazio e consistente. */
void inicializar(Lista *L)
{
  L->inicio = NULL; // TODO: lista vazia
  L->tamanho = 0;   // TODO: nenhum elemento
}

/* Insere 'valor' mantendo a ordem crescente. Retorna 1 em sucesso, 0 em falha. */
int inserir_ordenado(Lista *L, int valor)
{
  No *novo = (No *)malloc(sizeof(No));
  if (novo == NULL)
    return 0; /* sempre teste o malloc! */
  novo->chave = valor;
  novo->prox = NULL;

  No *ant = NULL;        /* nó anterior ao ponto de inserção */
  No *atual = L->inicio; /* cursor de varredura              */

  /* Avança enquanto a chave do nó atual for MENOR que o valor. */
  while (atual != NULL && atual->chave < valor)
  { // TODO: atual->chave < valor
    ant = atual;
    atual = atual->prox; // TODO: avançar o cursor
  }

  novo->prox = atual; // TODO: ligar ao sucessor

  if (ant == NULL)
    L->inicio = novo; // TODO: virou o primeiro nó
  else
    ant->prox = novo; // TODO: inserção no meio ou no fim

  L->tamanho++;
  return 1;
}

/* Retorna o nó com a chave procurada, ou NULL.
   Escreve em *comparacoes quantos nós foram efetivamente examinados. */
No *buscar_ordenado(Lista *L, int valor, int *comparacoes)
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

    if (p->chave > valor) // TODO: p->chave > valor
      break;              /* PARADA ANTECIPADA */

    p = p->prox; // TODO: avançar
  }

  if (comparacoes)
    *comparacoes = c;
  return NULL;
}

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

void imprimir(Lista *L)
{
  printf("[");
  for (No *p = L->inicio; p != NULL; p = p->prox)
    printf("%d%s", p->chave, p->prox ? " -> " : "");
  printf("]  (n=%d)\n", L->tamanho);
}

int main(void)
{
  Lista L;
  inicializar(&L);

  int dados[] = {40, 10, 75, 30, 90, 25};
  int n = sizeof(dados) / sizeof(dados[0]);

  printf("== INSERINDO ==\n");
  for (int i = 0; i < n; i++)
  {
    inserir_ordenado(&L, dados[i]); // TODO: inserir_ordenado(&L, dados[i])
    printf("insere %2d -> ", dados[i]);
    imprimir(&L);
  }

  printf("\n== BUSCANDO ==\n");
  int chaves[] = {10, 40, 60, 999};
  for (int i = 0; i < 4; i++)
  {
    int comps = 0;
    No *r = buscar_ordenado(&L, chaves[i], &comps);
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
