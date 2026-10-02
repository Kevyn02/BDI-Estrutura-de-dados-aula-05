# Listas Ordenadas em C — Estrutura de Dados (Aula 05)

![C](https://img.shields.io/badge/Language-C-blue.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen.svg)

Repositório dedicado à implementação, testes e documentação da **Atividade Prática 05 (Listas Ordenadas em C)** da disciplina de **Estrutura de Dados** (Curso Superior de Tecnologia em Big Data para Indústria — Fatec São Carlos).

---

## 📌 Descrição do Projeto

O objetivo deste projeto é estruturar uma **Lista Simplesmente Encadeada Ordenada** que mantém seus elementos dispostos em ordem crescente no momento exato da inserção, garantindo o invariante de ordenação em todas as operações:

```c
p->chave <= p->prox->chave
```

A manutenção dessa ordem permite explorar a **busca com parada antecipada**, interrompendo o percurso assim que a chave do nó atual ultrapassa o valor procurado. Isso permite comprovar a ausência do elemento sem a necessidade de percorrer toda a lista.

---

## 📁 Estrutura do Repositório

O repositório foi organizado de forma modular para facilitar a compilação, o reuso de código e a automação das baterias de testes:

```text
.
├── .vscode/                 # Configurações do ambiente de desenvolvimento
├── functions/               # Implementação modular das funções da lista
├── output/                  # Binários compilados e arquivos de saída
├── types/                   # Definições de estruturas de dados (struct No, Lista)
├── T1.c ... T15.c           # Programas individuais para cada caso de teste (T1 a T15)
├── lista_ordenada.c         # Implementação principal (ordem crescente)
├── lista_ordenada_desc.c    # Desafio A: Implementação em ordem decrescente
├── main.c                   # Programa principal com inserções, buscas e remoções
└── .gitignore
```

---

## 🛠️ Estruturas de Dados (`types/`)

```c
/* Nó da lista encadeada */
typedef struct No {
    int chave;
    struct No *prox;
} No;

/* Descritor da lista */
typedef struct {
    No *inicio;
    int tamanho;
} Lista;
```

---

## 🎯 Funcionalidades & Operações

- **Inicialização (`inicializar`):** Configura o descritor da lista em estado consistente e vazio (`O(1)`).
- **Inserção Ordenada (`inserir_ordenado`):** Insere o novo elemento na posição correta tratando quatro cenários (lista vazia, início, meio e fim) com um único laço (`O(n)`).
- **Busca com Parada Antecipada (`buscar_ordenado`):** Varre a lista contabilizando o número de comparações e encerra antecipadamente ao encontrar um valor maior que o buscado (`O(n)` no pior caso, otimizado para o caso médio).
- **Remoção de Elementos (`remover`):** Localiza e desconecta a primeira ocorrência da chave, liberando a memória alocada (`O(n)`).
- **Destruição da Lista (`destruir`):** Percorre e libera todos os nós da memória de forma segura, garantindo a ausência de *memory leaks* (`O(n)`).
- **Exibição (`imprimir`):** Imprime o estado atual da lista e o número total de nós.

---

## 📊 Análise de Complexidade

| Operação | Lista Não Ordenada | Lista Ordenada | Observação |
| :--- | :---: | :---: | :--- |
| **Inserção** | `O(1)` (no início) | `O(n)` | Custo pago para manter o invariante de ordem |
| **Busca com Sucesso** | `O(n)` | `O(n)` | Melhor caso `O(1)` se for o primeiro nó |
| **Busca Sem Sucesso** | `O(n)` | **Parada Antecipada** | Economiza comparações sem percorrer o resto da lista |
| **Menor Elemento** | `O(n)` | `O(1)` | Apontado diretamente por `inicio` |
| **Listagem em Ordem** | `O(n log n)` | `O(n)` | Percurso linear simples |

---

## 🧪 Bateria de Testes (`T1.c` a `T15.c`)

Cada arquivo `TX.c` na raiz representa um cenário de validação especificado no roteiro prático da disciplina:

| Arquivo | Cenário de Teste | Descrição / Saída Esperada |
| :--- | :--- | :--- |
| **`T1.c`** | Lista Vazia | Impressão de lista sem inserções `[] (n=0)` |
| **`T2.c`** | Primeira Inserção | Inserção do primeiro nó `[40] (n=1)` |
| **`T3.c`** | Inserção no Início | Inserção de valor menor que o início `[10 -> 40]` |
| **`T4.c`** | Inserção no Fim | Inserção de valor maior que o fim `[10 -> 40 -> 75]` |
| **`T5.c`** | Inserção no Meio | Inserção intermediária mantendo a ordem `[10 -> 40 -> 75]` |
| **`T6.c`** | Entrada Já Ordenada | Pior caso de inserção (`O(n)` por nó) |
| **`T7.c`** | Entrada Invertida | Melhor caso de inserção (`O(1)` por nó) |
| **`T8.c`** | Chaves Duplicadas | Validação do comportamento com duplicatas (rejeição no Desafio B) |
| **`T9.c`** | Busca no Início | Sucesso na primeira comparação (1 comparação) |
| **`T10.c`** | Busca Ausente (Meio) | Validação da **Parada Antecipada** ao passar da chave |
| **`T11.c`** | Busca Ausente (> Max) | Percorre toda a lista até o final |
| **`T12.c`** | Remoção do Início | Remoção do primeiro elemento com atualização de `L->inicio` |
| **`T13.c`** | Remoção do Fim | Remoção do último elemento garantindo ponteiro para `NULL` |
| **`T14.c`** | Remoção Inexistente | Retorno `0` e integridade do tamanho `n` mantida |
| **`T15.c`** | Esvaziar e Reinserir | Execução de `destruir()` seguida de nova inserção válida |

---

## 🚀 Desafios Avançados Resolvidos

### 1. ★ Desafio A — Lista em Ordem Decrescente (`lista_ordenada_desc.c`)
- **Descrição:** Alteração dos operadores de comparação nas funções de inserção e busca para manter a lista estritamente em ordem decrescente.
- **Impacto:** Apenas os operadores relacionais (`<` para `>`) foram modificados, demonstrando o baixo acoplamento entre o critério de ordenação e a estrutura de ponteiros.

### 2. ★★ Desafio B — Proibir Duplicatas (`functions/` & `T8.c`)
- **Descrição:** Modificação em `inserir_ordenado()` para verificar se a chave já existe durante a varredura e interromper/rejeitar a inserção antes de alocar memória via `malloc()`.
- **Complexidade:** `O(1)` adicional durante o laço existente de busca de posição, sem alocação desnecessária de memória.

---

## 🛠️ Compilação e Execução

### Pré-requisitos
- Compilador C (`gcc` ou `clang`)
- Terminal de comando (`bash`)

### Compilar e rodar o programa principal:
```bash
gcc -Wall main.c -o output/main
./output/main
```

### Compilar e rodar um caso de teste específico (ex: T10):
```bash
gcc -Wall T10.c -o output/T10
./output/T10
```

### Verificação de Vazamento de Memória (*Memory Leaks*):
```bash
valgrind --leak-check=full ./output/main
```

---

## 👨‍💻 Autor
Desenvolvido por **Kevyn** como atividade prática da disciplina de **Estrutura de Dados** (Fatec São Carlos).
