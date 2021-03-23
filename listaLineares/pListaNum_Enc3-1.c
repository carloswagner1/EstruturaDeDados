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

void ImprimeLista(TDescr, char *);

//TDescr Inicializa(TDescr);
void Inicializa(TDescr*);

int main(void)
{	int numero;
	TDescr lista;
	TNo *aux, *ant;

	/* inicializando a variável inicio com um endereco vazio */
	Inicializa(&lista);
	/*lista.inicio = NULL;
	lista.final = NULL;
	lista.qtde = 0;*/
	
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
		if (lista.inicio == NULL)
			lista.inicio = aux;
		else
			ant->prox = aux;

		lista.qtde = lista.qtde + 1;
		lista.final = aux;
		ant = aux;
	}
	
	/* imprimindo os valores da lista */
	if (lista.inicio == NULL)
		puts("Lista esta vazia");
	else
		ImprimeLista(lista, "Conteudo da lista:");

	while (1)
	{	printf("\nInforme o valor a excluir:\n");
		scanf("%d", &numero);

		if (numero < 0)
			break;
		
		/* Procurando o valor informado na lista */
		aux = lista.inicio;
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
				lista.inicio = aux->prox;
			else
				ant->prox = aux->prox;
		
			if (aux == lista.final)
				lista.final = ant;
		
			free(aux);
		
			lista.qtde = lista.qtde - 1;

			/* imprimindo os valores da lista */
			if (lista.inicio == NULL)
				puts("Lista esta vazia");
			else
				ImprimeLista(lista, "Novo conteudo da lista:");
		}
	}
	
	return 0;
}

void ImprimeLista(TDescr lista, char *cabec)
{	TNo *aux;
	int soma, maior, menor;
	
	printf("\n\n\n%s\n", cabec);

	aux = lista.inicio;
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
	printf("A lista possui %d itens\n", lista.qtde);
	printf("Maior: %d      Menor: %d      Media: %.2f\n", 
			maior, menor, soma / (float) lista.qtde);
				
/*	printf("Ultimo: %d\n", lista.final->valor); */
}

/*TDescr Inicializa(TDescr lista){
	lista.inicio = NULL;
	lista.final = NULL;
	lista.qtde = 0;
	return lista;
}*/

void Inicializa(TDescr *lista){
	lista->inicio = NULL;
	lista->final = NULL;
	lista->qtde = 0;	
}