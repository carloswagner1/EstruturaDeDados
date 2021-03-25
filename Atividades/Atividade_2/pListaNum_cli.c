/*
	--
	Programa Cliente que Opera lista linear de inteiros por encadeamento.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pListaNum_header.h"

#define TRUE 1
#define FALSE 0

int main(void)
{	int numero;
	TDescr lista;

	/* inicializando os descritores da lista */
	InicializaLista(&lista);
	
	while (1)
	{	printf("Informe o numero (ou < 0 para encerrar):\n");
		scanf("%d", &numero);

		if (numero < 0)
			break;

		if(IncluiItem(&lista, numero) == FALSE)
		{	puts("Memoria insuficiente para a operacao.");
			return 3;
		}

	}
	
	/* imprimindo os valores da lista */
	ImprimeLista(&lista, "Conteudo da lista:");

	while (1)
	{	printf("\nInforme o valor a excluir:\n");
		scanf("%d", &numero);

		if (numero < 0)
			break;
		
		if(ExcluiItem(&lista, numero) == FALSE)
			puts("Valor nao existe na lista");
		else
			ImprimeLista(&lista, "Novo conteudo da lista:");		
	}
	
	return 0;
}
