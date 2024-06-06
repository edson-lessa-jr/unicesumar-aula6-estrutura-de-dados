#include "01_pilha_lista_dinamica.h" // Inclui o cabeçalho da pilha dinâmica

// Função para criar um novo nó
NoP* criaNo(int dado) {
    // Aloca memória para um novo nó na pilha
    NoP* novoNo = (NoP*)malloc(sizeof(NoP));

    // Verifica se a alocação de memória foi bem sucedida
    if (!novoNo) {
        printf("Erro de alocacao de memoria.\n"); // Exibe mensagem de erro
        exit(1); // Encerra o programa com código de erro 1
    }

    // Inicializa os dados do novo nó
    novoNo->dado = dado; // Armazena o dado no nó
    novoNo->proximo = NULL; // Define o próximo nó como nulo

    // Retorna o ponteiro para o novo nó
    return novoNo;
}

// Função para empilhar (empilhar) um elemento
void empilhar(NoP** topo, int dado) {
    // Cria um novo nó com o dado a ser empilhado
    NoP* novoNo = criaNo(dado);

    // Faz o novo nó apontar para o topo da pilha
    novoNo->proximo = *topo;

    // Atualiza o topo da pilha para o novo nó
    *topo = novoNo;

    // Exibe mensagem de sucesso
    printf("Empilhado: %d\n", dado);
}

// Função para desempilhar (desempilhar) um elemento
int desempilhar(NoP** topo) {
    // Verifica se a pilha está vazia
    if (*topo == NULL) {
        printf("Pilha vazia.\n"); // Exibe mensagem de erro
        return -1; // Indica erro
    }

    // Armazena o nó atual do topo da pilha em uma variável temporária
    NoP* temp = *topo;

    // Extrai o dado do nó do topo da pilha
    int dado = temp->dado;

    // Atualiza o topo da pilha para o próximo nó
    *topo = (*topo)->proximo;

    // Libera a memória do nó desempilhado
    free(temp);

    // Retorna o dado desempilhado
    return dado;
}

// Função para ver o elemento no topo da pilha sem removê-lo (topoPilha)
int topoPilha(NoP* topo) {
    // Verifica se a pilha está vazia
    if (topo == NULL) {
        printf("Pilha vazia.\n"); // Exibe mensagem de erro
        return -1; // Indica erro
    }

    // Retorna o dado do elemento no topo da pilha
    return topo->dado;
}

// Função para verificar se a pilha está vazia
int pilhaVazia(NoP* topo) {
    // Retorna verdadeiro se a pilha estiver vazia (topo nulo)
    return topo == NULL;
}

// Função para exibir todos os elementos da pilha
void exibirPilha(NoP* topo) {
    // Variável temporária para percorrer a pilha
    NoP* temp = topo;

    // Percorre a pilha enquanto o próximo nó não for nulo
    while (temp != NULL) {
        // Exibe o dado do nó atual
        printf("%d -> ", temp->dado);

        // Avança para o próximo nó
        temp = temp->proximo;
    }

    // Exibe mensagem de fim da pilha
    printf("NULL\n");
}

// Função para inserir um elemento em uma posição específica da pilha
void inserirNoMeioPilha(NoP** topo, int dado, int posicao) {
    // Verifica se a posição é válida (maior ou igual a zero)
    if (posicao < 0) {
        printf("Posicao invalida.\n"); // Exibe mensagem de erro
        return;
    }

    // Caso especial: inserir no topo da pilha (posição 0)
    if (posicao == 0) {
        empilhar(topo, dado); // Utiliza a função empilhar para empilhar o elemento
        return;
    }

    // Cria um novo nó com o dado a ser inserido
    NoP* novoNo = criaNo(dado);

    // Variável temporária para percorrer a pilha até a posição desejada
    NoP* temp = *topo;
    // Procura a posição anterior à desejada ( nó na posição posicao-1 )
    for (int i = 0; temp != NULL && i < posicao - 1; i++) {
        temp = temp->proximo;
    }

    // Verifica se a posição é válida (atingiu o fim da pilha)
    if (temp == NULL) {
        printf("Posicao invalida.\n"); // Exibe mensagem de erro
        free(novoNo); // Libera a memória do novo nó alocado
    } else {
        // Insere o novo nó na pilha
        novoNo->proximo = temp->proximo;
        temp->proximo = novoNo;

        // Exibe mensagem de sucesso
        printf("Inserido: %d na posicao %d\n", dado, posicao);
    }
}

int pilha() {
    // Cria um ponteiro para o topo da pilha inicializado como nulo (pilha vazia)
    NoP* topo = NULL;

    int opcao, valor, posicao;

    do {
        // Exibe o menu de opções
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
                empilhar(&topo, valor);
                break;
            case 2:
                valor = desempilhar(&topo);
                if (valor != -1) {
                    printf("Elemento desempilhado: %d\n", valor);
                }
                break;
            case 3:
                valor = topoPilha(topo);
                if (valor != -1) {
                    printf("Elemento no topo: %d\n", valor);
                }
                break;
            case 4:
                if (pilhaVazia(topo)) {
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
                inserirNoMeioPilha(&topo, valor, posicao);
                break;
            case 0:
                // Desempilha todos os elementos restantes antes de sair
                while (!pilhaVazia(topo)) {
                    desempilhar(&topo);
                }
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}