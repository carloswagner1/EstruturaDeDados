/*Autor: Carlos Wagner Rodrigues da Silva*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

#define QTDE_FUNC 5001

/*Prototipos de Funcoes*/
void InicializaLista(TDescr *);
int IncluiFuncionario(TDescr *, int);
void ImprimeLista(int, char *);
int ExcluiFuncionario(TDescr *, int);

int listaFunc[QTDE_FUNC];

int main (void){
	int codigo;
	TDescr lista;

	/*inicializando os descritores da lista de funcionários*/
	InicializaLista(&lista);

	printf("\n---- Lista 01 - Exercicio 01 ----\n");

	/*inclui funcionarios*/
	while (1){
		printf("\nInforme o codigo do funcionario (ou < 0 para encerrar):\n");
		scanf("%d", &codigo);

		if (codigo < 0)
			break;

		if (IncluiFuncionario(&lista, codigo) == FALSE){
			puts("Memória insuficiente para a operacao.");
			return 3;
		}
	}

	/*Imprimir lista de funcionários*/
	ImprimeLista(&lista, "----Lista de funcionarios---");

	/*exclui funcionarios*/
	while (1)
	{	printf("\nInforme o codigo do funcionario a excluir:\n");
		scanf("%d", &codigo);

		if (codigo < 0)
			break;
		
		if(ExcluiFuncionario(&lista, codigo) == FALSE)
			puts("Valor nao existe na lista");
		else
			ImprimeLista(&lista, "----Lista de funcionário atualizada----");		
	}

	printf("Encerrando a aplicacao...\n");

	return 0;	
}

void InicializaLista(TDescr *lista)
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

		printf("Informe o salário do funcionario\n");
		scanf("%lf", &aux->salario);

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

void ImprimeLista(int, char *cabec){	
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