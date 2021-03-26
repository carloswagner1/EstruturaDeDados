/*Autor: Carlos Wagner Rodrigues da Silva*/

/*Exercicio_02*/
/*Cliente - Lista de Funcionarios*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Ex02Head.h"

#define TRUE 1
#define FALSE 0


#define QTDE_FUNC 500

int main(){
	//RegFunc *listafunc;
	int codigo, final;

	/*inicializando a variável de controle do fim da lista*/
	final = -1;

	printf("\n---- Lista 01 - Exercicio 01 ----\n");
	
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
}