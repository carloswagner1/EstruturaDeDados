/*Autor: Carlos Wagner Rodrigues da Silva*/

/*Exercicio_01*/
/*Implementação - Lista de Funcionarios*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Ex01Head.h"

void inicializalizaLista(TDescr *lista){	lista->inicio = NULL;
	lista->final = NULL;
	lista->qtde = 0;
	lista->totalSalario = 0;
}

int IncluiFuncionario(TDescr *lista, int num){
	TNo *aux;

	/* criando uma variável struct regFunc dinamicamente */
	aux = (struct regFunc *) malloc(sizeof(struct regFunc));

	if(aux == NULL)
		return FALSE;
	
	else{	
		/* preenchendo os campos da variável criada dinamicamente */
		aux->codigo= num;
		aux->prox = NULL;
		
		printf("Informe o nome do funcionario\n");
		scanf("%s", aux->nome);

		printf("Informe o salario do funcionario\n");
		scanf("%f", &aux->salario);

		/* fazendo o encadeamento do novo nó na lista */
		if (lista->inicio == NULL)
			lista->inicio = aux;
		else
			lista->final->prox = aux;

		lista->qtde = lista->qtde + 1;
		lista->totalSalario = lista->totalSalario + aux->salario;
		lista->final = aux;
		return TRUE;	
	}
}

void ImprimeLista(TDescr *lista, char *cabec){	
	TNo *aux;

	if (lista->inicio == NULL)
		puts("Lista esta vazia");			
	else{	
		printf("\n\n%s\n", cabec);

		aux = lista->inicio;

		while (aux != NULL){
			printf("Codigo: %d\nNome: %s\nSalario R$ %.2f\n\n", aux->codigo, aux->nome, aux->salario);
			aux = aux->prox;
		}
		
		printf("Soma Total dos Salarios R$ %.2f\n", lista->totalSalario);
		printf("Média Salarial R$ %.2f\n", (lista->totalSalario/lista->qtde));
	}			
}

int ExcluiFuncionario(TDescr *lista, int num){
	TNo *aux, *ant;
	
	/* Procurando o código informado na lista */
	aux = lista->inicio;
	ant = NULL;
	while (aux != NULL){	
		if (aux->codigo == num)
			break;
		
		ant = aux;
		aux = aux->prox;
	}
	
	if (aux == NULL)
		return FALSE;
	else{
		if (ant == NULL)
			lista->inicio = aux->prox;
		else
			ant->prox = aux->prox;
		
		if (aux == lista->final)
			lista->final = ant;
		
		free(aux);
		
		lista->qtde = lista->qtde - 1;
		lista->totalSalario = lista->totalSalario - aux->salario;
	}
	return TRUE;
}