/*
	--
	Implementação lista linear de inteiros por encadeamento.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pListaNum_header.h"

#define TRUE 1
#define FALSE 0


void InicializaLista(TDescr *lista)
{	lista->inicio = NULL;
	lista->final = NULL;
	lista->qtde = 0;
}


void ImprimeLista(TDescr *lista, char *cabec)
{	TNo *aux;
	int soma, maior, menor;

	if (lista->inicio == NULL){
		puts("Lista esta vazia");			
	}

	
	else
	{	printf("\n\n\n%s\n", cabec);

		aux = lista->inicio;
		menor = aux->valor;
		maior = aux->valor;
		soma = 0;

		while (aux != NULL)
		{	printf("%d\n", aux->valor);
	
			if (aux->valor > maior)
				maior = aux->valor;
		
			if (aux->valor < menor)
				menor = aux->valor;
			
			soma = soma + aux->valor;
			
			aux = aux->prox;
		}
		printf("A lista possui %d itens\n", lista->qtde);
		printf("Maior: %d      Menor: %d      Media: %.2f\n", 
			maior, menor, soma / (float) lista->qtde);
	
	}			
/*	printf("Ultimo: %d\n", lista.final->valor); */
}

int IncluiItem(TDescr *lista, int num)
{	TNo *aux;
	/*criando uma variável struct regLista dinamicamnete*/
	aux = (struct regLista *) malloc(sizeof(struct regLista));

	if(aux == NULL)
		return FALSE;
	
	else
	{	/* preenchendo os campos da variável criada dinamicamente */
		aux->valor = num;
		aux->prox = NULL;
	
		/* fazendo o encadeamento do novo nó na lista */
		if (lista->inicio == NULL)
			lista->inicio = aux;
		else
			lista->final->prox = aux;

		lista->qtde = lista->qtde + 1;
		lista->final = aux;
		return TRUE;
	}
}

int ExcluiItem(TDescr *lista, int num)
{	TNo *aux, *ant;
	
	/* Procurando o valor informado na lista */
	aux = lista->inicio;
	ant = NULL;
	while (aux != NULL)
	{	if (aux->valor == num)
			break;
		
		lista->final = aux;
		aux = aux->prox;
	}
	
	if (aux == NULL)
		return FALSE;
	else
	{	if (lista->final == NULL)
			lista->inicio = aux->prox;
		else
			ant->prox = aux->prox;
		
		if (aux == lista->final)
			lista->final = ant;
		
		free(aux);
		
		lista->qtde = lista->qtde - 1;
		
		return TRUE;
	}
}
