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
#define QTDE_FUNC 5000

int main(){
	//RegFunc *listafunc;
	int codigo, final, opcao;

	/*inicializando a variável de controle do fim da lista*/
	final = -1;

	/*looping Menu Inicial*/
	do{
		printf("\n---- LISTA 01 - EXERCICIO 02 ----\n\n");
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

					if (final == QTDE_FUNC)
						puts("Lista esta cheia");
					else
					IncluirFunc(++final, codigo);		
				}
			break;

			case 2:
				/*exclui funcionario*/
				while (TRUE){
					printf("\nInforme o codigo do funcionario a excluir (ou < 0 para encerrar):\n");
					scanf("%d", &codigo);

					if (codigo < 0)
					break;
		
					if(ExcluiFunc(final, codigo)== FALSE)
						puts ("Codigo informado nao existe na lista.");
					else{
						final--;
						printf("Lista de funcionarios atualizada.\n");
					}
				}
			break;

			case 3:
				/*Imprimir lista de funcionários*/
				ImprimeLista(final, "----Lista de funcionarios----");
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