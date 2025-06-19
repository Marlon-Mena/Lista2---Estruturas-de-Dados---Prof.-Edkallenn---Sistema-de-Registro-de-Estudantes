/*
** Função : Deque para atendimento
** Autor : Marlon Mena Monteiro Alves - Ciência da Computação - Estruturas de Dados I - Terceiro Periodo
** Data : 19/06/2025
** Observações: Inserção no início e fim, remoção nos dois também
*/

#include <stdlib.h>

typedef struct NoDeque {
    Estudante aluno;
    struct NoDeque *ant, *prox;
} NoDeque;

typedef struct {
    NoDeque *inicio, *fim;
} Deque;

void inicializarDeque(Deque *d) {
    d->inicio = d->fim = NULL;
}

void inserirInicio(Deque *d, Estudante e) {
    NoDeque *novo = (NoDeque*) malloc(sizeof(NoDeque));
    novo->aluno = e;
    novo->ant = NULL;
    novo->prox = d->inicio;
    if (d->inicio == NULL)
        d->fim = novo;
    else
        d->inicio->ant = novo;
    d->inicio = novo;
}

void inserirFim(Deque *d, Estudante e) {
    NoDeque *novo = (NoDeque*) malloc(sizeof(NoDeque));
    novo->aluno = e;
    novo->prox = NULL;
    novo->ant = d->fim;
    if (d->fim == NULL)
        d->inicio = novo;
    else
        d->fim->prox = novo;
    d->fim = novo;
}
