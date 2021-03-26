/*Autor: Carlos Wagner Rodrigues da Silva*/

/*Exercicio_01*/
/*Cliente - Lista de Funcionarios*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Ex01Head.h"

#define TRUE 1
#define FALSE 0


int main (void){
	int codigo;
	TDescr lista;

	/*inicializando os descritores da lista de funcionários*/
	InicializaLista(&lista);

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
	{	printf("\nInforme o codigo do funcionario a excluir (ou < 0 para encerrar):\n");
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