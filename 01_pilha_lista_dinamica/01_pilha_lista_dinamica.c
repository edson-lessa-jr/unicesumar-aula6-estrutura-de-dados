#include "01_pilha_lista_dinamica.h"

// Função para criar um novo nó
NoP* criaNo(int dado) {
    NoP* novoNo = (NoP*)malloc(sizeof(NoP));
    if (!novoNo) {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }
    novoNo->dado = dado;
    novoNo->proximo = NULL;
    return novoNo;
}

// Função para empilhar (push) um elemento
void push(NoP** topo, int dado) {
    NoP* novoNo = criaNo(dado);
    novoNo->proximo = *topo;
    *topo = novoNo;
    printf("Empilhado: %d\n", dado);
}

// Função para desempilhar (pop) um elemento
int pop(NoP** topo) {
    if (*topo == NULL) {
        printf("Pilha vazia.\n");
        return -1; // Indica erro
    }
    NoP* temp = *topo;
    int dado = temp->dado;
    *topo = (*topo)->proximo;
    free(temp);
    return dado;
}

// Função para ver o elemento no topo da pilha sem removê-lo (top)
int top(NoP* topo) {
    if (topo == NULL) {
        printf("Pilha vazia.\n");
        return -1; // Indica erro
    }
    return topo->dado;
}

// Função para verificar se a pilha está vazia
int isEmpty(NoP* topo) {
    return topo == NULL;
}

// Função para exibir todos os elementos da pilha
void exibirPilha(NoP* topo) {
    NoP* temp = topo;
    while (temp != NULL) {
        printf("%d -> ", temp->dado);
        temp = temp->proximo;
    }
    printf("NULL\n");
}

// Função para inserir um elemento em uma posição específica da pilha
void inserirNoMeio(NoP** topo, int dado, int posicao) {
    if (posicao < 0) {
        printf("Posicao invalida.\n");
        return;
    }
    if (posicao == 0) {
        push(topo, dado);
        return;
    }
    NoP* novoNo = criaNo(dado);
    NoP* temp = *topo;
    for (int i = 0; temp != NULL && i < posicao - 1; i++) {
        temp = temp->proximo;
    }
    if (temp == NULL) {
        printf("Posicao invalida.\n");
        free(novoNo);
    } else {
        novoNo->proximo = temp->proximo;
        temp->proximo = novoNo;
        printf("Inserido: %d na posicao %d\n", dado, posicao);
    }
}

int pilha() {
    NoP* topo = NULL;
    int opcao, valor, posicao;

    do {
        printf("\nMenu:\n");
        printf("1. Empilhar elemento\n");
        printf("2. Desempilhar elemento\n");
        printf("3. Ver elemento no topo\n");
        printf("4. Verificar se a pilha esta vazia\n");
        printf("5. Exibir todos os elementos da pilha\n");
        printf("6. Inserir elemento no meio da pilha\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser empilhado: ");
                scanf("%d", &valor);
                push(&topo, valor);
                break;
            case 2:
                valor = pop(&topo);
                if (valor != -1) {
                    printf("Elemento desempilhado: %d\n", valor);
                }
                break;
            case 3:
                valor = top(topo);
                if (valor != -1) {
                    printf("Elemento no topo: %d\n", valor);
                }
                break;
            case 4:
                if (isEmpty(topo)) {
                    printf("A pilha esta vazia.\n");
                } else {
                    printf("A pilha nao esta vazia.\n");
                }
                break;
            case 5:
                printf("Elementos da pilha: ");
                exibirPilha(topo);
                break;
            case 6:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                printf("Digite a posicao em que deseja inserir: ");
                scanf("%d", &posicao);
                inserirNoMeio(&topo, valor, posicao);
                break;
            case 0:
                while (!isEmpty(topo)) {
                    pop(&topo);
                }
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}