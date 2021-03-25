/*Autor: Carlos Wagner Rodrigues da Silva*/

/*Arquivo Fonte Cliente - Lista de Funcionarios*/

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