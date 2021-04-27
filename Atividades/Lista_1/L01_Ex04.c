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
void inicializalizaPilha(DPilha *);
int Empilha(DPilha *, char);
int ListaVazia(DPilha *);
int ComparaElem(DPilha *, char);
int Desempilha(DPilha *);


int main(){
	char expr[21];
	DPilha descr;

	
	/*Inicilizando o descritor da pilha*/
	inicializalizaPilha(&descr);

	printf("Informe a expressão matemática: \n");
	scanf("%s", expr);

	/*Varrendo a Expressao*/
	/*Empilhando os delimitadores de abertura*/
	for(int i=0; i <= strlen(expr); i++){
		if(expr[i]=='(' || expr[i]=='[' || expr[i]== '{'){
			Empilha(&descr, expr[i]);
		}

		/*Testando delimitadores de fechamento*/
		if(ListaVazia(&descr)){
			if(expr[i] == ')' || expr[i] == ']' || expr[i] == '}'){
				descr.qtde = 1;
				break;
			}	
			
		}else{
			if(ComparaElem(&descr, expr[i])==TRUE)
				Desempilha(&descr);
		}
	}


	if(descr.qtde == 0)
		printf("Expressao valida. Balanceamento ok.\n");
	else
		printf("Erro!!Expressao invalida\n");

	return 0;
}

void inicializalizaPilha(DPilha * descr){
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

int ListaVazia(DPilha *descr){
	if(descr->topo == NULL)
		return TRUE;
	else
		return FALSE;
}

int ComparaElem(DPilha *descr, char c){
	TLista *aux;

	aux = descr->topo;

	if(c ==')' && aux->delimitador == '(')
		return TRUE;
	else if(c == ']' && aux->delimitador == '[')
		return TRUE;
	else if(c == '}' && aux->delimitador == '{')
		return TRUE;
	else
		return FALSE;
}

int Desempilha(DPilha *descr){
	TLista *aux;

	aux = descr->topo;
	descr->topo = descr->topo->prox;
	descr->qtde--;

	free(aux);
	return TRUE;	
}

