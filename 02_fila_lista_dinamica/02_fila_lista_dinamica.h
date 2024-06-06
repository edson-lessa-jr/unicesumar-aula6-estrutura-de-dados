#ifndef FILA_LISTA_DINAMICA_H
#define FILA_LISTA_DINAMICA_H

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da fila
typedef struct NoF {
    int dado;
    struct NoF* proximo;
} NoF;

// Estrutura da fila
typedef struct {
    NoF* frente;
    NoF* tras;
} Fila;

// Funções para manipulação da fila
Fila* criaFila();
NoF* criaNoF(int dado);
void incluirFila(Fila* fila, int dado);
int removerFila(Fila* fila);
int inicioFila(Fila* fila);
int filaVazia(Fila* fila);
void exibirFila(Fila* fila);
void inserirNoMeioFila(Fila* fila, int dado, int posicao);
int removerDoMeioFila(Fila* fila, int posicao);
int fila();

#endif // FILA_H
