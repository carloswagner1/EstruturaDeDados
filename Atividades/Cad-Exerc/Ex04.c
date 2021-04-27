/*caderno atividades*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct ponto{
	float x;
	float y;
	struct ponto *prox;
};

typedef struct ponto Ponto;

typedef struct {
	Ponto *inicio, *final; 
	int qtde;
} TDescr;

/*Prototipos de Funcoes*/
void InicializaLista(TDescr *);
int IncluiPonto(TDescr *, float, float);
void ImprimeLista(TDescr *, char *);
int ExcluiPonto(TDescr *, int);


int main (void)
{
struct ponto p;
}

void InicializaLista(TDescr *lista){	
	lista->inicio = NULL;
	lista->final = NULL;
	lista->qtde = 0;	
}

int IncluiPonto(TDescr *lista, float num){
	Ponto *aux;

	/* criando uma variável struct ponto dinamicamente */
	aux = (struct ponto *) malloc(sizeof(struct ponto));

	if(aux == NULL)
		return FALSE;
	
	else{	
		/* preenchendo os campos da variável criada dinamicamente */
		aux->codigo= num;
		aux->prox = NULL;
		
		printf("Informe o nome do funcionario\n");
		scanf("%s", aux->nome);

		printf("Informe o salario do funcionario\n");
		scanf("%f", &aux->salario);

		/* fazendo o encadeamento do novo nó na lista */
		if (lista->inicio == NULL)
			lista->inicio = aux;
		else
			lista->final->prox = aux;

		lista->qtde = lista->qtde + 1;
		lista->totalSalario = lista->totalSalario + aux->salario;
		lista->final = aux;
		return TRUE;	
	}
}