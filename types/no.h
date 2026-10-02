#ifndef NO_H
#define NO_H

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

#endif
