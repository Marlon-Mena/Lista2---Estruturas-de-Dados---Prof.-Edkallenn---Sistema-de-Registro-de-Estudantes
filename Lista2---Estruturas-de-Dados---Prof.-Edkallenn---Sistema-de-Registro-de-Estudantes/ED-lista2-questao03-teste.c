/*
** Função : Teste do sistema de estudantes
** Autor : Marlon Mena Monteiro Alves - Ciência da Computação - Estruturas de Dados I - Terceiro Periodo
** Data : 19/06/2025
** Observações: Demonstra cadastro, histórico, fila e deque
*/

#include <stdio.h>
#include "ED-lista2-questao03-estudante.h"

#include "ED-lista2-questao03-lista.c"
#include "ED-lista2-questao03-pilha.c"
#include "ED-lista2-questao03-fila.c"
#include "ED-lista2-questao03-deque.c"

int main() {
    NoLista *lista = NULL;
    NoPilha *pilha = NULL;
    Fila fila;
    Deque deque;
    inicializarFila(&fila);
    inicializarDeque(&deque);

   
    Estudante e1 = {"Lucas", 101, {7.5, 8.0, 9.0}};
    lista = adicionarEstudante(lista, e1);
    enfileirar(&fila, e1);
    inserirFim(&deque, e1);

    Estudante *pe = buscarEstudante(lista, 101);
    if (pe) {
        pilha = empilhar(pilha, pe->matricula, pe->notas);
        pe->notas[0] = 10.0; 
    }

        imprimirLista(lista);

    return 0;
}
