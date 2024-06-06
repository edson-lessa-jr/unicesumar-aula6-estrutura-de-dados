#include <stdio.h>
#include "01_pilha_lista_dinamica/01_pilha_lista_dinamica.h"
#include "02_fila_lista_dinamica/02_fila_lista_dinamica.h"


int main(void) {
    int opcao;

    printf("Iniciando o programa\n");

    do {
        // Exibindo o menu de opções
        printf("\nMenu:\n");
        printf("1. Exemplo Pilha com Lista Dinamica\n");
        printf("2. Exemplo Fila com Lista Dinamica\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // Verificando a opção escolhida e chamando a função correspondente
        switch (opcao) {
            case 1:
                pilha();
                break;
            case 2:
                fila();
                break;
            case 0:
                printf("Saindo do programa. Obrigado!\n");
                break;
            default:
                printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
        }
    } while (opcao != 0);

    return 0;
}
