/*Autor: Carlos Wagner Rodrigues da Silva*/

/*Exercicio_02*/
/*Implementação - Lista de Funcionarios*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Ex02Head.h"

void InicializaLista(TDescr *lst){
	lst->final = -1;
}

int IncluiFuncionario (TDescr *lst, int num){
	if (lst->final == QTDE_FUNC)
		return FALSE;
	else{
		lst->lista[++(lst->final)].codigo = num;
	
		printf("Informe o nome do funcionario\n");
		scanf("%s", lst->lista[(lst->final)].nome);

		printf("Informe o salario do funcionario\n");
		scanf("%f", &lst->lista[(lst->final)].salario);
	return TRUE;
	}
}

void ImprimeLista(TDescr *lst, char *cabec){
	int p = 0;
	float soma = 0;

	if (lst->final == -1)
		puts("Lista esta vazia.");
	else{
		printf("\n\n%s\n", cabec);

		while (p <= lst->final){
			printf("Codigo: %d\nNome: %s\nSalario R$ %.2f\n\n", 
			lst->lista[p].codigo,
			lst->lista[p].nome,
			lst->lista[p].salario);
 
			soma = soma + lst->lista[p].salario; 
			p++;	
		}
		printf("Soma Total dos Salarios R$ %.2f\n", soma);
		printf("Média Salarial R$ %.2f\n", soma/p);
	}

}

int ExcluiFuncionario(TDescr *lst, int num){
	int p = 0;

	while (p <= lst->final && lst->lista[p].codigo != num){
		p = p + 1;
	}

	if (p > lst->final)
		return FALSE;
	else{
		while (p < lst->final){
			lst->lista[p] = lst->lista[p + 1];
			p++;
		}
		lst->final = lst->final -1;
		return TRUE;
	}
}