#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estruturas.h"
#include "funcoes.h"

int main() {
    ListaCarros lista;
    inicializar(&lista);

    int opcao;
    
    do {
        printf("\n===== MENU =====\n");
        printf("1. Inserir carro\n");
        printf("2. Listar carros\n");
        printf("3. Remover carro\n");
        printf("4. Consultar carro\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: {
                Carro c;

                printf("ID: ");
                scanf("%d", &c.id);

                printf("Marca: ");
                scanf(" %[^\n]", c.marca);

                printf("Modelo: ");
                scanf(" %[^\n]", c.modelo);

                printf("Ano: ");
                scanf("%d", &c.ano);

                printf("Preco: ");
                scanf("%f", &c.preco);

                printf("Matricula: ");
                scanf(" %[^\n]", c.matricula);

                inserirCarro(&lista, c);
                break;
            }

            case 2:
                listar(&lista);
                break;

            case 3: {
                int id;
                printf("Digite o ID do carro a remover: ");
                scanf("%d", &id);
                removerCarro(&lista, id);
                break;
            }

            case 4: {
                char matricula[20];
                printf("Digite a matricula: ");
                scanf(" %[^\n]", matricula);
                consultar(&lista, matricula);
                break;
            }

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    liberar(&lista);
    return 0;
}
