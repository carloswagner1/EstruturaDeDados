/*Arquivo Fonte Cliente - Lista de Funcionarios*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Ex01Head.h"


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