/*
** Função : Fila de matrícula
** Autor : Marlon Mena Monteiro Alves - Ciência da Computação - Estruturas de Dados I - Terceiro Periodo
** Data : 19/06/2025
** Observações: Fila dinâmica simples com encadeamento
*/

#include <stdlib.h>
#include <string.h>

typedef struct NoFila {
    Estudante aluno;
    struct NoFila *prox;
} NoFila;

typedef struct {
    NoFila *inicio, *fim;
} Fila;

void inicializarFila(Fila *f) {
    f->inicio = f->fim = NULL;
}

void enfileirar(Fila *f, Estudante e) {
    NoFila *novo = (NoFila*) malloc(sizeof(NoFila));
    novo->aluno = e;
    novo->prox = NULL;
    if (f->fim == NULL)
        f->inicio = novo;
    else
        f->fim->prox = novo;
    f->fim = novo;
}

int desenfileirar(Fila *f, Estudante *saida) {
    if (f->inicio == NULL) return 0;
    NoFila *temp = f->inicio;
    *saida = temp->aluno;
    f->inicio = temp->prox;
    if (f->inicio == NULL) f->fim = NULL;
    free(temp);
    return 1;
}
