#include "02_fila_lista_dinamica.h" // Inclui o cabeçalho da fila dinâmica

// Função para criar uma nova fila
Fila *criaFila() {
    // Aloca memória para uma nova estrutura Fila
    Fila *fila = (Fila *) malloc(sizeof(Fila));

    // Verifica se a alocação de memória foi bem sucedida
    if (!fila) {
        printf("Erro de alocacao de memoria.\n"); // Exibe mensagem de erro
        exit(1); // Encerra o programa com código de erro 1
    }

    // Inicializa os ponteiros 'frente' e 'tras' da fila como nulos (fila vazia)
    fila->frente = fila->tras = NULL;

    // Retorna o ponteiro para a nova fila criada
    return fila;
}

// Função para criar um novo nó
NoF *criaNoF(int dado) {
    // Aloca memória para um novo nó da fila
    NoF *novoNo = (NoF *) malloc(sizeof(NoF));

    // Verifica se a alocação de memória foi bem sucedida
    if (!novoNo) {
        printf("Erro de alocacao de memoria.\n"); // Exibe mensagem de erro
        exit(1); // Encerra o programa com código de erro 1
    }

    // Inicializa os dados do novo nó
    novoNo->dado = dado; // Armazena o dado no nó
    novoNo->proximo = NULL; // Define o próximo nó como nulo

    // Retorna o ponteiro para o novo nó criado
    return novoNo;
}

// Função para adicionar (incluirFila) um elemento à fila
void incluirFila(Fila *fila, int dado) {
    // Cria um novo nó com o dado a ser adicionado à fila
    NoF *novoNo = criaNoF(dado);

    // Caso a fila esteja vazia (frente e tras são nulos)
    if (fila->tras == NULL) {
        // Atualiza tanto 'frente' quanto 'tras' para o novo nó, pois é o único elemento
        fila->frente = fila->tras = novoNo;
    } else {
        // Conecta o 'proximo' do nó 'tras' atual ao novo nó
        fila->tras->proximo = novoNo;

        // Atualiza o ponteiro 'tras' para o novo nó, que agora é o último da fila
        fila->tras = novoNo;
    }

    // Exibe mensagem de sucesso
    printf("Adicionado: %d\n", dado);
}

// Função para remover (removerFila) um elemento da fila
int removerFila(Fila *fila) {
    // Verifica se a fila está vazia
    if (fila->frente == NULL) {
        printf("Fila vazia.\n"); // Exibe mensagem de erro
        return -1; // Indica erro
    }

    // Armazena o nó atual do 'frente' da fila em uma variável temporária
    NoF *temp = fila->frente;

    // Extrai o dado do nó do 'frente' da fila
    int dado = temp->dado;

    // Atualiza o ponteiro 'frente' para o próximo nó da fila
    fila->frente = fila->frente->proximo;

    // Se a fila ficou vazia após a remoção, atualiza 'tras' para nulo
    if (fila->frente == NULL) {
        fila->tras = NULL;
    }

    // Libera a memória do nó removido
    free(temp);

    // Retorna o dado removido da fila
    return dado;
}

// Função para ver o elemento na frente da fila sem removê-lo (inicioFila)
int inicioFila(Fila *fila) {
    // Verifica se a fila está vazia
    if (fila->frente == NULL) {
        printf("Fila vazia.\n"); // Exibe mensagem de erro
        return -1; // Indica erro
    }

    // Retorna o dado do elemento na 'frente' da fila
    return fila->frente->dado;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila *fila) {
    // Retorna verdadeiro se a fila estiver vazia ('frente' nulo)
    return fila->frente == NULL;
}

// Função para exibir todos os elementos da fila
void exibirFila(Fila *fila) {
    // Variável temporária para percorrer a fila
    NoF *temp = fila->frente;

    // Percorre a fila enquanto o próximo nó não for nulo
    while (temp != NULL) {
        // Exibe o dado do nó atual
        printf("%d -> ", temp->dado);

        // Avança para o próximo nó
        temp = temp->proximo;
    }

    // Exibe mensagem de fim da fila
    printf("NULL\n");
}

// Função para inserir um elemento no meio da fila
void inserirNoMeioFila(Fila *fila, int dado, int posicao) {
    // Verifica se a posição é válida (maior ou igual a zero)
    if (posicao < 0) {
        printf("Posicao invalida.\n"); // Exibe mensagem de erro
        return; // Retorna da função sem realizar nenhuma ação
    }

    // Caso especial: inserir no início da fila (posição 0)
    if (posicao == 0) {
        // Cria um novo nó com o dado a ser inserido
        NoF *novoNo = criaNoF(dado);

        // Faz o novo nó apontar para o atual 'frente' da fila
        novoNo->proximo = fila->frente;

        // Atualiza o 'frente' da fila para o novo nó
        fila->frente = novoNo;

        // Se a fila estava vazia, atualiza também o 'tras'
        if (fila->tras == NULL) {
            fila->tras = novoNo;
        }

        // Exibe mensagem de sucesso
        printf("Inserido: %d na posicao %d\n", dado, posicao);

        // Retorna da função sem realizar outras ações
        return;
    }

    // Cria um novo nó com o dado a ser inserido
    NoF *novoNo = criaNoF(dado);

    // Variável temporária para percorrer a fila até a posição anterior à desejada
    NoF *temp = fila->frente;

    // Busca o nó na posição 'posicao - 1' (nó anterior à desejada)
    for (int i = 0; temp != NULL && i < posicao - 1; i++) {
        temp = temp->proximo;
    }

    // Verifica se a posição é válida (atingiu o fim da fila)
    if (temp == NULL) {
        printf("Posicao invalida.\n"); // Exibe mensagem de erro
        free(novoNo); // Libera a memória do novo nó alocado
    } else {
        // Insere o novo nó na fila após o nó 'temp'
        novoNo->proximo = temp->proximo;
        temp->proximo = novoNo;

        // Se o novo nó foi inserido no final da fila, atualiza o 'tras'
        if (novoNo->proximo == NULL) {
            fila->tras = novoNo;
        }

        // Exibe mensagem de sucesso
        printf("Inserido: %d na posicao %d\n", dado, posicao);
    }
}


// Função para remover um elemento do meio da fila
int removerDoMeioFila(Fila *fila, int posicao) {
    // Verifica se a fila está vazia ou a posição é inválida
    if (fila->frente == NULL || posicao < 0) {
        printf("Fila vazia ou posição inválida.\n"); // Exibe mensagem de erro
        return -1; // Indica erro
    }

    // Caso especial: remover do início da fila (posição 0)
    if (posicao == 0) {
        // Retorna o valor removido com a função removerFila
        return removerFila(fila);
    }

    // Variável temporária para percorrer a fila até a posição anterior à desejada
    NoF *temp = fila->frente;

    // Busca o nó na posição 'posicao - 1' (nó anterior à desejada)
    for (int i = 0; temp != NULL && i < posicao - 1; i++) {
        temp = temp->proximo;
    }

    // Verifica se a posição é válida (atingiu o fim da fila ou o nó anterior é nulo)
    if (temp == NULL || temp->proximo == NULL) {
        printf("Posição inválida.\n"); // Exibe mensagem de erro
        return -1; // Indica erro
    }

    // Armazena o nó a ser removido na variável 'noRemovido'
    NoF *noRemovido = temp->proximo;

    // Extrai o dado do nó a ser removido
    int dado = noRemovido->dado;

    // Faz o nó 'temp' apontar para o próximo nó após o removido
    temp->proximo = noRemovido->proximo;

    // Atualiza o 'tras' da fila se o nó removido era o último
    if (temp->proximo == NULL) {
        fila->tras = temp;
    }

    // Libera a memória do nó removido
    free(noRemovido);

    // Retorna o dado removido da fila
    return dado;
}

int fila() {
    // Cria uma fila vazia
    Fila *fila = criaFila();

    // Variáveis para armazenar opções, valores e posições
    int opcao, valor, posicao;

    // Loop principal do menu
    do {
        // Exibe o menu de opções
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

        // Lê a opção escolhida pelo usuário
        scanf("%d", &opcao);

        // Switch para tratar as diferentes opções do menu
        switch (opcao) {
            case 1:
                // Adiciona um elemento à fila
                printf("Digite o valor a ser adicionado: ");
                scanf("%d", &valor);
                incluirFila(fila, valor);
                break;

            case 2:
                // Remove um elemento da fila
                valor = removerFila(fila);
                if (valor != -1) {
                    printf("Elemento removido: %d\n", valor);
                }
                break;

            case 3:
                // Mostra o elemento na frente da fila
                valor = inicioFila(fila);
                if (valor != -1) {
                    printf("Elemento na frente da fila: %d\n", valor);
                }
                break;

            case 4:
                // Verifica se a fila está vazia
                if (filaVazia(fila)) {
                    printf("A fila esta vazia.\n");
                } else {
                    printf("A fila nao esta vazia.\n");
                }
                break;

            case 5:
                // Exibe todos os elementos da fila
                printf("Elementos da fila: ");
                exibirFila(fila);
                break;

            case 6:
                // Insere um elemento no meio da fila
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                printf("Digite a posicao em que deseja inserir: ");
                scanf("%d", &posicao);
                inserirNoMeioFila(fila, valor, posicao);
                break;

            case 7:
                // Remove um elemento do meio da fila
                printf("Digite a posicao do elemento a ser removido: ");
                scanf("%d", &posicao);
                valor = removerDoMeioFila(fila, posicao);
                if (valor != -1) {
                    printf("Elemento removido da posicao %d: %d\n", posicao, valor);
                }
                break;

            case 0:
                // Sai do menu e libera a memória da fila
                while (!filaVazia(fila)) {
                    removerFila(fila);
                }
                free(fila);
                printf("Saindo...\n");
                break;

            default:
                // Opção inválida, exibe mensagem de erro
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0); // Sai do loop quando a opção 0 for escolhida

    return 0; // Retorna sucesso
}
