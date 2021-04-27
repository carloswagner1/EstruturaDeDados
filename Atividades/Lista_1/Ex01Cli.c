/*Autor: Carlos Wagner Rodrigues da Silva*/

/*Exercicio_01*/
/*Cliente - Lista de Funcionarios*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Ex01Head.h"

/*Funcao main*/
int main (void){
	int codigo, opcao;
	TDescr lista;

	/*inicializalizando os descritores da lista de funcionários*/
	inicializalizaLista(&lista);

	/*lopping do Menu inicializal*/
	do{
		printf("\n---- LISTA 01 - EXERCICIO 01 ----\n\n");
		printf("Informe a opcao desejada\n");
		printf("1 - Incluir funcionario\n");
		printf("2 - Excluir funcionario\n");
		printf("3 - Listar funcionarios cadastrados\n");
		printf("0 - Encerrar o programa\n\n");
		printf("Opcao: ");

		scanf("%d", &opcao);

		switch(opcao){
			case 1:
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
			break;

			case 2:
				/*exclui funcionario*/
				while (TRUE){
					printf("\nInforme o codigo do funcionario a excluir:\n");
					scanf("%d", &codigo);

					if (codigo < 0)
					break;
		
					if(ExcluiFuncionario(&lista, codigo) == FALSE)
						puts("Codigo informado nao existe na lista.");
					else
						printf("Lista de funcionarios atualizada.\n");
				}
			break;

			case 3:
				/*Imprimir lista de funcionários*/
				ImprimeLista(&lista, "----Lista de funcionarios----");
			break;

			case 0:
				printf("Encerrando a aplicacao...\n");
			break;

			default:
				printf("Digite uma opcao valida!!!\n");
		}
			
	}while(opcao!=0);

	return 0;	
}