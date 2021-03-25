/*
	Enunciado 6 da Atividade 2

	Lista por contiguidade

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TAM 100

struct regLista {int vet[TAM];};
typedef struct regLista TLista;

typedef struct {TLista* inicio, final; int qtde;} TDescr;

int InicializaLista(TDescr *);
void ImprimeLista(TDescr *, char *);
int Inclusao(TDescr *, int);
int Exclusao(TDescr *, int);

int main()
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

int InicializaLista(TDescr *lista)
{	lista.inicio = NULL;
	lista.final = NULL;
	lista->qtde = 0;
	return lista;
}


void ImprimeLista(TDescr *lista, char *cabec)
{	TLista *aux;
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
{	TLista *aux;

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
{	TLista *aux;
	
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



typedef struct{
	int vet[TAM];
	int fim;
}RegLista;

/*struct tDescr {RegList Item[TAM]; Posicao Inicio; Posicao Final;};
typedef struct tDescr TDescr; //TipoLista = TDescr*/


//protótipos

void InicializaLista(RegLista*);
void Inclusao(RegLista*, int, int);

void ImprimeLista(RegLista, char*);
/*TDescr* InicializaLista();*/
/*void Inclusao(RegList* x, TDescr* Lista);*/
/*RegList* Exclusao(Posicao, TDescr *);*/

int main(void)
{	RegLista lista;
	int numero, aux;

	/* inicializando a lista */
	InicializaLista(&lista);
	
	while (1)
	{	
		printf("Informe o numero (ou < 0 para encerrar):\n");
		scanf("%d", &numero);

		if (numero < 0)
			break;

		Inclusao(&lista, numero, aux);	
		aux++;
	}
	printf("%d", lista.vet[0]);
	ImprimeLista(lista, "Conteudo da lista:");
	/* imprimindo os valores da lista */
	//ImprimeLista(&lista, "Conteudo da lista:");


	/*while (1)
	{	printf("\nInforme o valor a excluir:\n");
		scanf("%d", &numero);

		if (numero < 0)
			break;
		
		if(Exclusao(&lista, numero) == 0)
			puts("Valor nao existe na lista");
		else
			ImprimeLista(&lista, "Novo conteudo da lista:");		
	}
	*/
	return 0;
}

void InicializaLista(RegLista *lista){
	lista->fim = 0;
}

/*int ListaCheia (RegLista lista){
	if(lista->fim == TAM)
		return 1;
	return 0;
}

int ListaVazia (RegLista lista){
	if (lista->fim == 0)
		return 1;
	return 0;

}*/

void Inclusao(RegLista *lista, int numero, int aux){

	/*valida se há espaço*/
	if(lista->fim == TAM){
		printf("Espaço insuficiente\n");
		return;
	}

	/*insere o valor*/
	lista->vet[aux] = numero;
	printf("%d", lista->vet[aux]);
	lista->fim++;
}

void ImprimeLista(RegLista lista, char *cabec)
{	//RegLista *aux;
	int soma, maior, menor, i;

	if (&lista.vet[0] == NULL){
		puts("Lista esta vazia");			
	}

	
	//else
	{	printf("\n\n\n%s\n", cabec);

		//aux = lista;
		menor = lista.vet[0];
		maior = lista.vet[0];
		soma = 0;

		for (i = 0; i < lista.fim; i++){
			printf("%d\n", lista.vet[i]);

			if (lista.vet[i] > maior)
				maior = lista.vet[i];
		
			if (lista.vet[i] < menor)
				menor = lista.vet[i];
			
			soma = soma + lista.vet[i];
		}
		printf("A lista possui %d itens\n", lista.fim);
		printf("Maior: %d      Menor: %d      Media: %.2f\n", 
			maior, menor, soma / (float) lista.fim);
	
	}			
/*	printf("Ultimo: %d\n", lista.final->valor); */
}