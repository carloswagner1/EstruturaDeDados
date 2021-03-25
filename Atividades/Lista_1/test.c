#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

#define QTDE_FUNC 500

typedef struct{
	int codigo;
	char nome[31];
	float salario;
} RegFunc;

void IncluirFunc (int, int);
void ImprimeLista(int, char *);
void ExcluiFunc (int, int);

RegFunc lista[QTDE_FUNC];

int main(){
	//RegFunc *listafunc;
	int codigo, final, p;

	/*inicializando a variável de controle do fim da lista*/
	final = -1;

	printf("\n---- Lista 01 - Exercicio 01 ----\n");
	
	while (TRUE){
		printf("\nInforme o codigo do funcionario (ou < 0 para encerrar):\n");
		scanf("%d", &codigo);

		if (codigo < 0)
			break;

		if (final == QTDE_FUNC)
			puts("Lista estah cheia");
		else
			IncluirFunc(++final, codigo);		
	}

	/*imprimindo valores da lista*/	
	if (final < 0)
		puts("Lista esta vazia.");
	else
		ImprimeLista(final, "----Lista de funcionarios----");

	/*exlui funcionarios*/
	while (TRUE){
		printf("\nInforme o codigo do funcionario a excluir:\n");
		scanf("%d", &codigo);

		if (codigo < 0)
			break;

		ImprimeLista(final, "----Lista de funcionário atualizada----");
	}

	printf("Encerrando a aplicacao...\n");

	return 0;
}

void IncluirFunc (int final, int cod){
	lista[final].codigo = cod;

	printf("Informe o nome do funcionario\n");
	scanf("%s", lista[final].nome);

	printf("Informe o salário do funcionario\n");
	scanf("%f", &lista[final].salario);
	
}

void ImprimeLista(int final, char *cabec){
	int p = 0;
	float soma= 0;

	printf("\n\n%s\n", cabec);

	while (p <= final){
		printf("Codigo: %d\nNome: %s\nSalario R$ %.2f\n\n", 
		lista[p].codigo, lista[p].nome, lista[p].salario);
		soma = soma + lista[p].salario;
		p++;	
	}
	printf("Soma Total dos Salarios R$ %.2f\n", soma);
	printf("Média Salarial R$ %.2f\n", soma/p);
	
}

void ExcluiFunc (int final, int cod){
	int p = 0;
}