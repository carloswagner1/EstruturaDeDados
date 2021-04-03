/*Autor: Carlos Wagner Rodrigues da Silva*/

/*Lista_01 - Exercicio_04*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

struct regLista{
	char delimitador;
	struct regLista *prox;
};
typedef struct regLista TLista;

typedef struct{
	TLista *topo;
	int qtde;
} DPilha;

/*Prototipos de Funcoes*/
void InicializaPilha(DPilha *);
int Empilha(DPilha *, char);
int Desempilha(DPilha *);

int main(){
	char expr[21];
	DPilha descr;
	
	/*Inicilizando o descritor da pilha*/
	InicializaPilha(&descr);

	printf("Informe a expressão matemática (ou X para sair): \n");
	scanf("%s", expr);

	/*if(expr[0] == 'X')
		break;*/

	for(int i=0; i < strlen(expr); i++){
			if(expr[i]=='(')
				Empilha(&descr, expr[i]);
			else if(expr[i]==')')
				Desempilha(&descr);
	}


	if(descr.topo == NULL)
		printf("Expressao balanceada\n");
	else
		printf("Expressao nao balanceada\n");

	return 0;
}

void InicializaPilha(DPilha * descr){
	descr->topo = NULL;
	descr->qtde = 0;
}

int Empilha(DPilha *descr,char s){
	TLista *aux;

	/* criando uma variável struct TLista dinamicamente*/
	aux = (struct regLista *) malloc(sizeof(struct regLista));

	if(aux == NULL)
		return FALSE;
	
	else{
		/*preenchendo os campos da variável*/
		aux->delimitador = s;
		aux->prox = descr->topo;

		descr->topo=aux;
		descr->qtde++;
		return TRUE;
	}
	
}

int Desempilha(DPilha *descr){
	TLista *aux;

	if(descr->topo != NULL){
		aux = descr->topo;
		descr->topo = descr->topo->prox;
		descr->qtde--;

		free(aux);
		return TRUE;
	}else{
		return FALSE;
	}

	
	
}