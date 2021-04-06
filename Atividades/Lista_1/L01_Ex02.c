/*Autor: Carlos Wagner Rodrigues da Silva*/

/*Lista_01 - Exercicio_02*/

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
int ExcluiFunc (int, int);

RegFunc lista[QTDE_FUNC];

int main(){
	//RegFunc *listafunc;
	int codigo, final;

	/*inicializando a variável de controle do fim da lista*/
	final = -1;

	printf("\n---- Lista 01 - Exercicio 02 ----\n");
	
	while (TRUE){
		printf("\nInforme o codigo do funcionario (ou < 0 para encerrar):\n");
		scanf("%d", &codigo);

		if (codigo < 0)
			break;

		if (final == QTDE_FUNC)
			puts("Lista esta cheia");
		else
			IncluirFunc(++final, codigo);		
	}

	/*imprimindo valores da lista*/	
	ImprimeLista(final, "----Lista de funcionarios----");

	/*exlui funcionarios*/
	while (TRUE){
		printf("\nInforme o codigo do funcionario a excluir (ou < 0 para encerrar):\n");
		scanf("%d", &codigo);

		if (codigo < 0)
			break;
		
		if(ExcluiFunc(final, codigo)== FALSE)
			puts ("Codigo informado nao existe na lista.");
		else{
			final--;
			ImprimeLista(final, "----Lista de funcionarios atualizada----");
		}
	}

	printf("Encerrando a aplicacao...\n");

	return 0;
}

void IncluirFunc (int final, int cod){
	lista[final].codigo = cod;

	printf("Informe o nome do funcionario\n");
	scanf("%s", lista[final].nome);

	printf("Informe o salario do funcionario\n");
	scanf("%f", &lista[final].salario);
	
}

void ImprimeLista(int final, char *cabec){
	int p = 0;
	float soma= 0;

	if (final < 0)
		puts("Lista esta vazia.");
	else{
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

}

int ExcluiFunc (int final, int cod){
	int p = 0;

	while (p <= final){
		if (lista[p].codigo == cod)
			break;
		p = p + 1;
	}

	if (p > final)
		return FALSE;
	else{
		while (p < final){
			lista[p] = lista[p + 1];
			p++;
		}
	}
	return TRUE;
}