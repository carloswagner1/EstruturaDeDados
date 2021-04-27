/*Autor: Carlos Wagner Rodrigues da Silva*/
/*Lista_01 - Exercicio_01*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

/*Structs-Typedefs*/
struct regFunc {
	int codigo; 
	char nome[31]; 
	float salario;
	struct regFunc *prox;
};

typedef struct regFunc TNo;

typedef struct {
	TNo *inicio, *final; 
	int qtde;
	float totalSalario;
} TDescr;

/*Prototipos de Funcoes*/
void inicializalizaLista(TDescr *);
int IncluiFuncionario(TDescr *, int);
void ImprimeLista(TDescr *, char *);
int ExcluiFuncionario(TDescr *, int);

int main (void){
	int codigo;
	TDescr lista;

	/*inicializalizando os descritores da lista de funcionários*/
	inicializalizaLista(&lista);

	printf("\n---- LISTA 01 - EXERCICIO 01 ----\n");

	/*inclui funcionarios*/
	while (TRUE){
		printf("\nInforme o codigo do funcionario (ou < 0 para encerrar):\n");
		scanf("%d", &codigo);

		if (codigo < 0)
			break;

		if (IncluiFuncionario(&lista, codigo) == FALSE){
			puts("Memoria insuficiente para a operacao.");
			return 3;
		}
	}

	/*Imprimir lista de funcionários*/
	ImprimeLista(&lista, "----Lista de funcionarios----");

	/*exclui funcionario*/
	while (TRUE)
	{	printf("\nInforme o codigo do funcionario a excluir:\n");
		scanf("%d", &codigo);

		if (codigo < 0)
			break;
		
		if(ExcluiFuncionario(&lista, codigo) == FALSE)
			puts("Codigo informado nao existe na lista.");
		else
			ImprimeLista(&lista, "----Lista de funcionarios atualizada----");		
	}

	printf("Encerrando a aplicacao...\n");

	return 0;	
}

void inicializalizaLista(TDescr *lista)
{	lista->inicio = NULL;
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
