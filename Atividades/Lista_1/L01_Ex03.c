/*Autor: Carlos Wagner Rodrigues da Silva*/
/*Lista_01 - Exercicio_03*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

/*Structs-Typedefs*/
struct regList {
	float valor; 
	struct regList *prox;
};

typedef struct regList TNo;

typedef struct {
	TNo *inicio, *final; 
} TDescr;

/*Prototipos de Funcoes*/
void inicializalizaLista(TDescr *);
int IncluiItem(TDescr *, float);
void ImprimeLista(TDescr *, char *);
void SomaListas(TDescr *, TDescr *, TDescr *);

/*programa main*/
int main (void){
	float numero;
	TDescr lista1;
	TDescr lista2;
	TDescr lista3;


	printf("\n---- EXERCICIO 03 ----\n\n");

	/*inicializalizando os descritores da lista1*/
	inicializalizaLista(&lista1);
	/*incluindo os itens da lista1*/
	printf("Lista 1\n");
	while(1){
		printf("Informe um valor ( ou < 0 para encerrar):\n");
		scanf("%f", &numero);

		if (numero < 0)
			break;

		if (IncluiItem(&lista1, numero) == FALSE){
			puts("Memoria insuficiente para esta operacao");
			return 3;
		}
	}

	/*inicializalizando os descritores da lista1*/
	inicializalizaLista(&lista2);
	/*incluindo os itens da lista1*/
	printf("\nLista 2\n");
	while(1){
		printf("Informe um valor( ou < 0 para encerrar):\n");
		scanf("%f", &numero);

		if (numero < 0)
			break;

		if (IncluiItem(&lista2, numero) == FALSE){
			puts("Memoria insuficiente para esta operacao");
			return 3;
		}
	}
	ImprimeLista(&lista1, "Lista 1");
	ImprimeLista(&lista2, "Lista 2");

	inicializalizaLista(&lista3);

	SomaListas(&lista1, &lista2, &lista3);

	ImprimeLista(&lista3, "Lista 3");

	return 0;
}


/*fuinção inicializaliza*/
void inicializalizaLista(TDescr *lista){
	lista->inicio = NULL;
	lista->final = NULL;	
}

/*função para incluir numeros na lista*/
int IncluiItem(TDescr *lista, float num){
	TNo *aux;

	/*criando uma variável struct regList dinamicamente*/
	aux = (struct regList *) malloc(sizeof(struct regList));

	if(aux == NULL)
		return FALSE;

	/*preenchendo os campos da variável criada dinamicamente*/
	aux->valor = num;
	aux->prox = NULL;

	/*fazendo o encadeamento do novo nó na lista*/
	if(lista->inicio ==  NULL)
		lista->inicio = aux;
	else
		lista->final->prox = aux;

	lista->final = aux;

	return TRUE;
}

void ImprimeLista(TDescr *lista, char *cabec){
	TNo *aux;
	
	printf("\n");

	if (lista->inicio == NULL)
		puts("Lista vazia");
	else{
		printf("%s:   ", cabec);

		aux = lista->inicio;
		while (aux != NULL){
			if(aux->valor < 10)
				printf(" %.2f   ", aux->valor);
			else
				printf("%.2f   ", aux->valor);

			aux = aux->prox;
		}
	}
}

void SomaListas(TDescr *lt1, TDescr *lt2, TDescr *lt3){
	float soma = 0;
	TNo *aux1;
	TNo *aux2;
	aux1 = lt1->inicio;
	aux2 = lt2->inicio;

	/*somando os n-esimos numeros*/
	while(aux1 != NULL && aux2 != NULL){
		soma = aux1->valor + aux2->valor;
		IncluiItem(lt3, soma);

		aux1=aux1->prox;
		aux2=aux2->prox;	
		}
		
	while(aux1 !=NULL && aux2 == NULL){
		soma = aux1->valor;
		IncluiItem(lt3, soma);

		aux1=aux1->prox;
	}

	while(aux1 ==NULL && aux2 != NULL){
		soma = aux2->valor;
		IncluiItem(lt3, soma);

		aux2=aux2->prox;
	}

}