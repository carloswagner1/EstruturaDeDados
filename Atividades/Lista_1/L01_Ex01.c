//Autor: Carlos Wagner Rodrigues da Silva

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct regFunc {
	int codigo; 
	char nome[30]; 
	double salario;
	struct regFunc *prox;
};

typedef struct regFunc TNo;

typedef struct {
	TNo *inicio, *final; 
	int qtde;
	float somaSalario;
} TDescr;

void InicializaLista(TDescr *);
int Inclusao(TDescr *, int);
int Exclusao(TDescr *, int);
void ImprimeLista(TDescr *, char *);

int main (void){
	int codigo;
	TDescr lista;

	/*inicializando os descritores da lista de funcionários*/
	InicializaLista(&lista);

	printf("\n---- Lista 01 - Exercicio 01 ----\n");

	while (1){
		printf("\nInforme o codigo do funcionario (ou < 0 para encerrar):\n");
		scanf("%d", &codigo);

		if (codigo < 0)
			break;

		if (Inclusao(&lista, codigo) == 0){
			puts("Memória insuficiente.");
			break;
		}
	}
	/*Imprimir lista de funcionários*/
	ImprimeLista(&lista, "----Lista de funcionarios---");

	while (1)
	{	printf("\nInforme o codigo do funcionario a excluir:\n");
		scanf("%d", &codigo);

		if (codigo < 0)
			break;
		
		if(Exclusao(&lista, codigo) == 0)
			puts("Valor nao existe na lista");
		else
			ImprimeLista(&lista, "----Lista de funcionário atualizada----\n");		
	}

	printf("Encerrando a aplicacao...\n");

	return 0;	
}

void InicializaLista(TDescr *lista)
{	lista->inicio = NULL;
	lista->final = NULL;
	lista->qtde = 0;
	lista->somaSalario = 0;
}

int Inclusao(TDescr *lista, int numero){
	TNo *aux;
	//char nome[30];
	//float salario;

	aux = (struct regFunc *) malloc(sizeof(struct regFunc));

	if(!aux)
	{	
		return 0;
	}
	else
	{	/* preenchendo os campos da variável criada dinamicamente */
		aux->codigo= numero;
		aux->prox = NULL;
		printf("Informe o nome do funcionario\n");
		scanf("%s", aux->nome);
		printf("Informe o salário do funcionario\n");
		scanf("%lf", &aux->salario);
		/* fazendo o encadeamento do novo nó na lista */
		if (lista->inicio == NULL)
			lista->inicio = aux;
		else
			lista->final->prox = aux;

		lista->qtde = lista->qtde + 1;
		lista->somaSalario = lista->somaSalario + aux->salario;
		lista->final = aux;
		return 1;	
	}
}

int Exclusao(TDescr *lista, int numero){
	TNo *aux;
	
	/* Procurando o código informado na lista */
	aux = lista->inicio;
	lista->final = NULL;
	while (aux != NULL)
	{	if (aux->codigo == numero)
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
		lista->somaSalario = lista->somaSalario - aux->salario;
		return 1;
	}
}

void ImprimeLista(TDescr *lista, char *cabec)
{	TNo *aux;
	//int soma;

	if (lista->inicio == NULL){
		puts("Lista esta vazia");			
	}

	
	else
	{	printf("\n\n%s\n", cabec);

		aux = lista->inicio;
		//menor = aux->valor;
		//maior = aux->valor;
		//soma = 0;

		while (aux != NULL){
			printf("Codigo: %d\nNome: %s\nSalario R$ %.2f\n\n", aux->codigo, aux->nome, aux->salario);
			aux = aux->prox;
		}
		
		printf("\n\nSoma Total dos Salarios R$ %.2f\n", lista->somaSalario);
		printf("Média Salarial R$ %.2f\n", (lista->somaSalario/lista->qtde));
	}			
}

