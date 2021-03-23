/*
	Opera sobre lista linear de inteiros por encadeamento, com exclusao
	de item informado pelo usuario.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct regLista {int valor; struct regLista *prox;};
typedef struct regLista TNo;

int main(void)
{	int numero, qtde;
	TNo *inicio, *aux, *ant;

	/* inicializando a variável inicio com um endereco vazio */
	inicio = NULL;
	qtde = 0;
	
	while (1)
	{	printf("Informe o numero (ou < 0 para encerrar):\n");
		scanf("%d", &numero);

		if (numero < 0)
			break;
		
		/* criando uma variável struct regLista dinamicamente */
		aux = (struct regLista *) malloc(sizeof(struct regLista));

		/* preenchendo os campos da variável criada dinamicamente */
		aux->valor = numero;
		aux->prox = NULL;
	
		/* fazendo o encadeamento do novo nó na lista */
		if (inicio == NULL)
			inicio = aux;
		else
			ant->prox = aux;

		qtde = qtde + 1;
		ant = aux;
	}
	
	/* imprimindo os valores da lista */
	if (inicio == NULL)
		puts("Lista esta vazia");
	else
	{	printf("\n\n\nConteudo da lista:\n");
		aux = inicio;
		while (aux != NULL)
		{	printf("%d\n", aux->valor);
			aux = aux->prox;
		}
		printf("A lista possui %d itens\n", qtde);
	}
	
	printf("\nInforme o valor a excluir:\n");
	scanf("%d", &numero);

	/* Procurando o valor informado na lista */
	aux = inicio;
	ant = NULL;
	while (aux != NULL)
	{	if (aux->valor == numero)
			break;
		
		ant = aux;
		aux = aux->prox;
	}
	
	if (aux == NULL)
		puts("Valor nao existe na lista");
	else
	{	if (ant == NULL)
			inicio = aux->prox;
		else
			ant->prox = aux->prox;
		
		free(aux);
		
		qtde = qtde - 1;
	}

	/* imprimindo os valores da lista */
	if (inicio == NULL)
		puts("Lista esta vazia");
	else
	{	printf("\n\n\nNovo conteudo da lista:\n");
		aux = inicio;
		while (aux != NULL)
		{	printf("%d\n", aux->valor);
			aux = aux->prox;
		}
		printf("A lista possui %d itens\n", qtde);
	}
	
	return 0;
}
