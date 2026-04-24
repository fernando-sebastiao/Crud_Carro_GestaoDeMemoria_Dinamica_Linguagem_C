#include "Estruturas.h"
#include<stdlib.h>
#include <stdio.h>
#include "funcoes.h"

void inicializar(ListaCarros *lista){
	lista->capacidade = 2;
	lista->tamanho = 0;
	
	lista->dados = malloc(lista->capacidade * sizeof(Carro));
}

void aumentarCapacidade(ListaCarros *lista)
{
	lista->capacidade *=2;
	Carro *temp = realloc(lista->dados, lista->capacidade*sizeof(Carro));
	if(temp == NULL)
		printf("Espaco nao alocado\n");
	else
		lista->dados = temp;
}

void inserirCarro(ListaCarros *lista, Carro c)
{
	if(lista->capacidade == lista->tamanho)
	{
		aumentarCapacidade(lista);
	}
	lista->dados[lista->tamanho] = c;
	lista->tamanho++;
}

void listar(ListaCarros *lista)
{
	int i;
	if(lista->tamanho!=0){
		for(i = 0; i < lista->tamanho; i++){
		printf("Id: %d\n", lista->dados[i].id);
		printf("Marca: %s\n", lista->dados[i].marca);
		printf("Modelo: %s\n", lista->dados[i].modelo);
		printf("Ano: %d\n", lista->dados[i].ano);
		printf("Preco: %f\n", lista->dados[i].preco);
	}
		return;
	}
	printf("Nao tem carros no sistema!\n");
}

void removerCarro(ListaCarros *lista, int id){
	int i, j;
	for(i=0; i < lista->tamanho; i++){
		if(lista->dados[i].id == id){
			for(j = i; j < lista->tamanho-1; j++)
			{
				lista->dados[j] = lista->dados[j+1];
			}
				lista->tamanho--;
				printf("Carro removido com sucesso!\n");
				return;
		}
	}
	printf("Carro nao encontrado\n");
}

void consultar(ListaCarros *lista, char *matricula)
{
	int i,j;
	for(i = 0; i < lista->tamanho; i++)
	{
		if(lista->dados[i].matricula == matricula )
		{
			printf("Encontrado: \n");
			printf("Id: %d\n", lista->dados[i].id);
			printf("Marca: %s\n", lista->dados[i].marca);
			printf("Modelo: %s\n", lista->dados[i].modelo);
			printf("Ano: %d\n", lista->dados[i].ano);
			printf("Preco: %f\n", lista->dados[i].preco);
			return;
		}
	}
	printf("Carro nao encontrado\n");
}

void liberar(ListaCarros *lista){
	free(lista->dados);
}
