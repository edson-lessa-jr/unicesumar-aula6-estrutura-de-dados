#include "02_fila_lista_dinamica.h"


// Função para criar uma nova fila
Fila* criaFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    if (!fila) {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }
    fila->frente = fila->tras = NULL;
    return fila;
}

// Função para criar um novo nó
NoF* criaNoF(int dado) {
    NoF* novoNo = (NoF*)malloc(sizeof(NoF));
    if (!novoNo) {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }
    novoNo->dado = dado;
    novoNo->proximo = NULL;
    return novoNo;
}

// Função para adicionar (enqueue) um elemento à fila
void enqueue(Fila* fila, int dado) {
    NoF* novoNo = criaNoF(dado);
    if (fila->tras == NULL) {
        fila->frente = fila->tras = novoNo;
        return;
    }
    fila->tras->proximo = novoNo;
    fila->tras = novoNo;
    printf("Adicionado: %d\n", dado);
}

// Função para remover (dequeue) um elemento da fila
int dequeue(Fila* fila) {
    if (fila->frente == NULL) {
        printf("Fila vazia.\n");
        return -1; // Indica erro
    }
    NoF* temp = fila->frente;
    int dado = temp->dado;
    fila->frente = fila->frente->proximo;
    if (fila->frente == NULL) {
        fila->tras = NULL;
    }
    free(temp);
    return dado;
}

// Função para ver o elemento na frente da fila sem removê-lo (peek)
int peek(Fila* fila) {
    if (fila->frente == NULL) {
        printf("Fila vazia.\n");
        return -1; // Indica erro
    }
    return fila->frente->dado;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila* fila) {
    return fila->frente == NULL;
}

// Função para exibir todos os elementos da fila
void exibirFila(Fila* fila) {
    NoF* temp = fila->frente;
    while (temp != NULL) {
        printf("%d -> ", temp->dado);
        temp = temp->proximo;
    }
    printf("NULL\n");
}

// Função para inserir um elemento no meio da fila
void inserirNoMeioFila(Fila* fila, int dado, int posicao) {
    if (posicao < 0) {
        printf("Posicao invalida.\n");
        return;
    }

    NoF* novoNo = criaNoF(dado);
    if (posicao == 0) {
        novoNo->proximo = fila->frente;
        fila->frente = novoNo;
        if (fila->tras == NULL) {
            fila->tras = novoNo;
        }
        return;
    }

    NoF* temp = fila->frente;
    for (int i = 0; temp != NULL && i < posicao - 1; i++) {
        temp = temp->proximo;
    }

    if (temp == NULL) {
        printf("Posicao invalida.\n");
        free(novoNo);
    } else {
        novoNo->proximo = temp->proximo;
        temp->proximo = novoNo;
        if (novoNo->proximo == NULL) {
            fila->tras = novoNo;
        }
        printf("Inserido: %d na posicao %d\n", dado, posicao);
    }
}

// Função para remover um elemento do meio da fila
int removerDoMeioFila(Fila* fila, int posicao) {
    if (fila->frente == NULL || posicao < 0) {
        printf("Fila vazia ou posição inválida.\n");
        return -1; // Indica erro
    }

    NoF* temp = fila->frente;
    if (posicao == 0) {
        return dequeue(fila);
    }

    for (int i = 0; temp != NULL && i < posicao - 1; i++) {
        temp = temp->proximo;
    }

    if (temp == NULL || temp->proximo == NULL) {
        printf("Posição inválida.\n");
        return -1; // Indica erro
    }

    NoF* noRemovido = temp->proximo;
    int dado = noRemovido->dado;
    temp->proximo = noRemovido->proximo;
    if (temp->proximo == NULL) {
        fila->tras = temp;
    }
    free(noRemovido);
    return dado;
}

int fila(){
    Fila* fila = criaFila();
    int opcao, valor, posicao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar elemento à fila\n");
        printf("2. Remover elemento da fila\n");
        printf("3. Ver elemento na frente da fila\n");
        printf("4. Verificar se a fila está vazia\n");
        printf("5. Exibir todos os elementos da fila\n");
        printf("6. Inserir elemento no meio da fila\n");
        printf("7. Remover elemento do meio da fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser adicionado: ");
                scanf("%d", &valor);
                enqueue(fila, valor);
                break;
            case 2:
                valor = dequeue(fila);
                if (valor != -1) {
                    printf("Elemento removido: %d\n", valor);
                }
                break;
            case 3:
                valor = peek(fila);
                if (valor != -1) {
                    printf("Elemento na frente da fila: %d\n", valor);
                }
                break;
            case 4:
                if (filaVazia(fila)) {
                    printf("A fila esta vazia.\n");
                } else {
                    printf("A fila nao esta vazia.\n");
                }
                break;
            case 5:
                printf("Elementos da fila: ");
                exibirFila(fila);
                break;
            case 6:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                printf("Digite a posicao em que deseja inserir: ");
                scanf("%d", &posicao);
                inserirNoMeioFila(fila, valor, posicao);
                break;
            case 7:
                printf("Digite a posicao do elemento a ser removido: ");
                scanf("%d", &posicao);
                valor = removerDoMeioFila(fila, posicao);
                if (valor != -1) {
                    printf("Elemento removido da posicao %d: %d\n", posicao, valor);
                }
                break;
            case 0:
                while (!filaVazia(fila)) {
                    dequeue(fila);
                }
                free(fila);
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}