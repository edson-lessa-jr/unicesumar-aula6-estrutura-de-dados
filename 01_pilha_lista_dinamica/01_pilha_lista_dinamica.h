#ifndef PILHA_LISTA_DINAMICA_H
#define PILHA_LISTA_DINAMICA_H

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da pilha
typedef struct NoP {
    int dado;
    struct NoP* proximo;
} NoP;

// Funções para manipulação da pilha
NoP* criaNo(int dado);
void push(NoP** topo, int dado);
int pop(NoP** topo);
int top(NoP* topo);
int isEmpty(NoP* topo);
void exibirPilha(NoP* topo);
void inserirNoMeio(NoP** topo, int dado, int posicao);
int pilha();

#endif // PILHA_LISTA_DINAMICA_H