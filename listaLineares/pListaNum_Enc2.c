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
{	int numero, qtde, menor, maior;
	float med = 0;
	TNo *inicio, *final, *aux, *ant;

	/* inicializando a variável inicio com um endereco vazio */
	inicio = NULL;
	final = NULL;
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
		if (inicio == NULL){
			inicio = aux;
			final = aux;
			med = aux->valor;			
		}
			
		else{
            final = aux;
            ant->prox = aux;
            med += aux->valor;           
			
        }			
		qtde = qtde + 1;
		ant = aux;
	}

	/* imprimindo os valores da lista */
	if (inicio == NULL)
		puts("Lista esta vazia");
	else
	{	printf("\n\n\nConteudo da lista:\n");
		aux = inicio;
		menor = inicio->valor;
		maior = inicio->valor;
		while (aux != NULL)
		{	printf("%d\n", aux->valor);
			if (aux->valor < menor)
				menor = aux->valor;
			if (aux->valor > maior)
				maior = aux->valor;
			aux = aux->prox;
		}
		printf("A lista possui %d itens\n", qtde);
		printf("Valor do inicio = %d\n", inicio->valor);
		printf("Valor do final = %d\n", final->valor);
		printf("Menor valor = %d\n", menor);
		printf("Maior valor = %d\n", maior);
		printf("Media = %.2f\n", med/qtde);
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
		med -= numero;		
		qtde = qtde - 1;
	}

	/* imprimindo os valores da lista */
	if (inicio == NULL)
		puts("Lista esta vazia");
	else
	{	printf("\n\n\nNovo conteudo da lista:\n");
		aux = inicio;
		menor = inicio->valor;
		maior = inicio->valor;
		while (aux != NULL)
		{	printf("%d\n", aux->valor);
			if (aux->valor < menor)
				menor = aux->valor;
			if (aux->valor > maior)
				maior = aux->valor;
			aux = aux->prox;
		}
		printf("A lista possui %d itens\n", qtde);
		printf("Valor do inicio = %d\n", inicio->valor);
		printf("Valor do final = %d\n", final->valor);
		printf("Menor valor = %d\n", menor);
		printf("Maior valor = %d\n", maior);
		printf("Media = %.2f\n", med/qtde);
	}
	
	return 0;
}
