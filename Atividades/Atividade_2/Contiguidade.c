/*
	Enunciado 6 da Atividade 2

	Opera sobre lista linear de inteiros por encadeamento, 
	com exclusao de item informado pelo usuario, descritor 
	estruturado e subrotinas.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define InicioVetor 0
#define TAM 100

typedef int Posicao;

struct regLista {int valor; struct regLista *prox;};
typedef struct regLista RegList; //reglist = tipoitem

struct tDescr {RegList Item[TAM]; Posicao Inicio; Posicao Final;};
typedef struct tDescr TDescr; //TipoLista = TDescr


//protótipos
TDescr* InicializaLista();
void Inclusao(RegList* x, TDescr* Lista);
void ImprimeLista(TDescr *, char *);
RegList* Exclusao(Posicao, TDescr *);

int main()
{	
	int numero;
	int lista [];
	//TDescr lista;

	/* inicializando os descritores da lista */
	lista = InicializaLista();

	
	while (1)
	{	
		printf("Informe o numero (ou < 0 para encerrar):\n");
		scanf("%d", &numero);

		if (numero < 0)
			break;

		Inclusao(&lista, numero);	
	}
	
	/* imprimindo os valores da lista */
	ImprimeLista(&lista, "Conteudo da lista:");
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

TDescr* InicializaLista()
{	
	TDescr* lista = (TDescr*)malloc(sizeof(TDescr));
	if(!lista)
	{	printf("Erro: Memoria insuficiente");
	return lista;
}


void ImprimeLista(TDescr* Lista, char *cabec)
{	
	int	aux;
	int soma, maior, menor;

	if (Lista->Inicio == NULL){
		puts("Lista esta vazia");			
	}
	else
	{	printf("\n\n\n%s\n", cabec);
		menor = Lista->valor;
		maior = Lista->valor;
		soma = 0;

		for(aux = Lista->Inicio; aux < Lista->Final, aux ++)
		{
			printf("%d\n", Lista->Item[aux].valor);

			if (Lista->Item[aux].valor > maior)
				maior = Lista->Item[aux].valor;
		
			if (Lista->Item[aux].valor < menor)
				menor = Lista->Item[aux].valor;
			
			soma = soma + Lista->Item[aux].valor;
		}

		printf("A lista possui %d itens\n", Lista->Final);
		printf("Maior: %d      Menor: %d      Media: %.2f\n", 
			maior, menor, soma / (float) aux);
	
	}			
	/*printf("Ultimo: %d\n", lista.final->valor); */
}

void Inclusao(RegList* x, TDescr* Lista)
{	
	if(Lista->Final >= TAM)
	{	
		printf("A lista esta cheia");
	}
	else
	{	/* preenchendo a lista*/
		Lista->Item[Lista->|Final] = *x;
		Lista->Final++;
	}
}

/*RegList* Exclusao(Posicao p, TDescr * Lista)
{	int aux;
	RegList * item;
	item = (RegList*)malloc(sizeof(RegList));*/


	
	/* Procurando o valor informado na lista */
/*	aux = lista->inicio;
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