#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

/*Structs-Typedefs*/
struct regList {
	char cidade[31];
	int populacao;
	float area; 
	float PIB;
	float IDH;
	struct regList *ant;
	struct regList *prox;
};

typedef struct regList TNo;

typedef struct {
	TNo *inicio, *final; 
} TDescr;

/*Prototipos de Funcoes*/
void inicializaLista(TDescr *);
int IncluiItem(TDescr *, float);

int main({

	return 0;
}

/*Funções*/

/*função inicializaliza*/
void inicializaLista(TDescr *lista){
	lista->inicio = NULL;
	lista->final = NULL;	
}

