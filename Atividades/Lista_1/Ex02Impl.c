/*Autor: Carlos Wagner Rodrigues da Silva*/

/*Exercicio_02*/
/*Implementação - Lista de Funcionarios*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Ex02Head.h"

#define TRUE 1
#define FALSE 0
#define QTDE_FUNC 5000

/*variável global*/
RegFunc lista[QTDE_FUNC]; 

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