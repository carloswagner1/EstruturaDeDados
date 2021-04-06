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