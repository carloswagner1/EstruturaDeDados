/* 	Autores:
	Jessica Maria dos Santos
	Carlos Wagner Rodrigues da Silva*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct regNo{	struct regNo *esq;
				int valor;
				struct regNo *dir;
			};
typedef struct regNo TNo;

TNo *AchaPai(TNo *, int);
void em_ordem(TNo *);

int main(void)
{	TNo *raiz = NULL, *aux, *pai;
	int numero;
	
	while (1)
	{	printf("\nInforme o valor ou -1 para encerrar:\n"); 
		scanf("%d", &numero);
		
		if (numero < 0) break;
		
		aux = (TNo *) malloc(sizeof(TNo));
		aux->valor = numero;
		aux->dir = NULL;
		aux->esq = NULL;
		
		/* Fazendo o encadeamento do novo noh */
		pai = AchaPai(raiz, numero);
		if (pai == NULL)
			raiz = aux;
		else
			if (numero <= pai->valor)
				pai->esq = aux;
			else
				pai->dir = aux;
	}
	/*imprime em ordem*/
	em_ordem(raiz);
	printf("\n");

	return 0;
}

TNo *AchaPai(TNo *r, int n)
{	if (r == NULL)
		return NULL;
	else
		if (n <= r->valor)
		/* n é descendente do lado esquerdo de r */
			if (r->esq == NULL)
				return r;
			else
				return AchaPai(r->esq, n);
		else
		/* n é descendente do lado direito de r */
			if (r->dir == NULL)
				return r;
			else
				return AchaPai(r->dir, n);
}

void em_ordem(TNo *r)
{
	printf("<");/*abre a árvore*/
	if (r != NULL){
		em_ordem(r->esq);
		printf("%d", r->valor);
		em_ordem(r->dir);
	}
	printf(">");/*fecha a árvore*/

}

