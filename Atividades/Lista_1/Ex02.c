/*Autor: Carlos Wagner Rodrigues da Silva*/
/*Lista_01 - Exercicio_02*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

#define QTDE_FUNC 5000

/*Structs-Typedefs*/
typedef struct{
	int codigo;
	char nome[31];
	float salario;
} regFunc;

typedef struct{
	int final;
	regFunc lista[QTDE_FUNC];
}TDescr;

/*Protótipo de Funcoes*/
void inicializalizaLista(TDescr *);
int IncluiFuncionario(TDescr *, int);
void ImprimeLista(TDescr *, char *);
int ExcluiFuncionario(TDescr *, int);

/*Funcao main*/
int main(){
	int codigo, opcao;
	TDescr lista;

	/*inicializalizando os descritores da lista de funcionários*/
	inicializalizaLista(&lista);

	/*looping Menu inicializal*/
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

					if (IncluiFuncionario(&lista, codigo) == FALSE){
						puts("Memoria insuficiente para a operacao.");
						return 3;
					}		
				}
			break;

			case 2:
				/*exclui funcionario*/
				while (TRUE){
					printf("\nInforme o codigo do funcionario a excluir (ou < 0 para encerrar):\n");
					scanf("%d", &codigo);

					if (codigo < 0)
					break;
		
					if(ExcluiFuncionario(&lista, codigo)== FALSE)
						puts ("Codigo informado nao existe na lista.");
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

void inicializalizaLista(TDescr *lst){
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