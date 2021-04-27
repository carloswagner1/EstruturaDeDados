/*Autor: Carlos Wagner Rodrigues da Silva*/

/*Lista_01 - Exercicio_04*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

struct regPilha{
	char delimitador;
	struct regPilha *prox;
};

typedef struct regPilha TPilha;

typedef struct{
	TPilha *topo;
	int qtde;
}DPilha;

/*Prototipos de Funcoes*/
void inicializalizaPilha(DPilha *);
int Empilha(DPilha *, char);
int ListaVazia(DPilha *);
int ComparaElem(char, char);
int Desempilha(DPilha *);


int main(){
	char expr[21];
	DPilha descr;
	int i=0;
	
	/*Inicilizando o descritor da pilha*/
	inicializalizaPilha(&descr);

	printf("Informe a expressão matemática: \n");
	scanf("%s", expr);

	/*Varrendo a Expressao*/
	/*Empilhando os delimitadores de abertura*/
	while(i <= strlen(expr)){
		if(expr[i]=='(' || expr[i]=='[' || expr[i]== '{'){
			Empilha(&descr, expr[i]);
		}

		if(expr[i] == ')' || expr[i] == ']' || expr[i] == '}'){
			ComparaElem((Desempilha(&descr), expr[i])==TRUE);
			descr.qtde=1;
		}
		i++;
	}

	if(descr.qtde == 0)
		printf("\nExpressao valida.\nBalanceamento ok.\n");
	else
		printf("\nErro!!!\nExpressao invalida.\n");

	return 0;
}

void inicializalizaPilha(DPilha * descr){
	descr->topo = NULL;
	descr->qtde = 0;
}

int Empilha(DPilha *descr,char s){
	TPilha *aux;

	/* criando uma variável struct TPilha dinamicamente*/
	aux = (struct regPilha *) malloc(sizeof(struct regPilha));

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

int ListaVazia(DPilha *descr){
	return(descr->topo == NULL);
}

int ComparaElem(char a, char c){
	
	if(c ==')' && a == '(')
		return TRUE;
	else if(c == ']' && a == '[')
		return TRUE;
	else if(c == '}' && a == '{')
		return TRUE;
	else
		return FALSE;
}

int Desempilha(DPilha *descr){
	char a;
	if(ListaVazia(descr)){
		descr->qtde = 1;
		exit(1);
	}

	a = descr->topo->delimitador;
	descr->topo = descr->topo->prox;
	descr->qtde--;

	return a;	
}

