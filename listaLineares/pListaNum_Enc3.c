/*
	Opera sobre lista linear de inteiros por encadeamento, 
	com exclusao de item informado pelo usuario, descritor 
	estruturado e subrotinas.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct regLista {int valor; struct regLista *prox;};
typedef struct regLista TNo;

typedef struct {TNo *inicio, *final; int qtde;} TDescr;

void InicializaLista(TDescr *);
void ImprimeLista(TDescr *, char *);
int Inclusao(TDescr *, int);
int Exclusao(TDescr *, int);

int main(void)
{	int numero;
	TDescr lista;

	/* inicializando os descritores da lista */
	InicializaLista(&lista);
	
	while (1)
	{	printf("Informe o numero (ou < 0 para encerrar):\n");
		scanf("%d", &numero);

		if (numero < 0)
			break;

		if(Inclusao(&lista, numero) == 0)
		{	puts("Erro de alocação.");
			break;
		}

	}
	
	/* imprimindo os valores da lista */
	ImprimeLista(&lista, "Conteudo da lista:");

	while (1)
	{	printf("\nInforme o valor a excluir:\n");
		scanf("%d", &numero);

		if (numero < 0)
			break;
		
		if(Exclusao(&lista, numero) == 0)
			puts("Valor nao existe na lista");
		else
			ImprimeLista(&lista, "Novo conteudo da lista:");		
	}
	
	return 0;
}

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

int Inclusao(TDescr *lista, int numero)
{	TNo *aux;

	aux = (struct regLista *) malloc(sizeof(struct regLista));

	if(!aux)
	{	
		return 0;
	}
	else
	{	/* preenchendo os campos da variável criada dinamicamente */
		aux->valor = numero;
		aux->prox = NULL;
	
		/* fazendo o encadeamento do novo nó na lista */
		if (lista->inicio == NULL)
			lista->inicio = aux;
		else
			lista->final->prox = aux;

		lista->qtde = lista->qtde + 1;
		lista->final = aux;
		return 1;
	}
}

int Exclusao(TDescr *lista, int numero)
{	TNo *aux;
	
	/* Procurando o valor informado na lista */
	aux = lista->inicio;
	lista->final = NULL;
	while (aux != NULL)
	{	if (aux->valor == numero)
			break;
		
		lista->final = aux;
		aux = aux->prox;
	}
	
	if (aux == NULL)
		return 0;
	else
	{	if (lista->final == NULL)
			lista->inicio = aux->prox;
		else
			lista->final->prox = aux->prox;
		
		if (aux == lista->final)
			lista->final = lista->final;
		
		free(aux);
		
		lista->qtde = lista->qtde - 1;
		return 1;
	}
}