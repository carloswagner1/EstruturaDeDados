/*URI 1195 - Árvore Binária de Busca*/
/*Carlos Wagner Rodrigues da Silva*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*structs e typedefs*/
struct regNo	{
	struct regNo *esq;
	int valor;
	struct regNo *dir;
				};

typedef struct regNo TArvore;


int tipo;

/*protótipo de funções*/
TArvore * AchaPai(TArvore *r, int v);
int ImprimeArvore(TArvore *r);


int main()
{	TArvore *raiz, *pai, *aux;
	int Tam, Ncasos, c, d, no;

	raiz = NULL;
	scanf("%d", &Ncasos);

	for(c=1; c<=Ncasos; c++)
	{
		raiz = NULL;

		scanf("%d", &Tam);
		for(d=0; d<Tam; d++)
		{
			scanf("%d", &no);

			aux = (TArvore *) malloc(sizeof(TArvore));
			aux->valor = no;
			aux->esq = NULL;
			aux->dir = NULL;

			pai = AchaPai(raiz, no);
			if(pai == NULL)
				raiz = aux;
			else
				if(no <= pai->valor)
					pai->esq = aux;
				else
					pai->dir = aux;
		}

		printf("Case %d:", c);

		printf("\nPre.:");
		tipo = 1;
		ImprimeArvore(raiz);

		printf("\nIn..:");
		tipo = 2;
		ImprimeArvore(raiz);

		printf("\nPost:");
		tipo = 3;
		ImprimeArvore(raiz);

		printf("\n\n");

	}

	return 0;
}

/*Funções*/

TArvore * AchaPai(TArvore *r, int v){
	if(r == NULL)
	/* Arvore vazia */
		return NULL;
	else
		if(v <= r->valor)
		/* Novo no deve ficar a esquerda de r */
			if(r->esq == NULL)
				return r;
			else
				return AchaPai(r->esq, v);
		else
		/* Novo no deve ficar a direita de r */
			if(r->dir == NULL)
				return r;
			else
				return AchaPai(r->dir, v);
}

int ImprimeArvore(TArvore *r){
	if(r != NULL)
	{
		if(tipo == 1){
			printf(" %d", r->valor);
			ImprimeArvore(r->esq);
			ImprimeArvore(r->dir);
		}
		if(tipo == 2){
			ImprimeArvore(r->esq);
			printf(" %d", r->valor);
			ImprimeArvore(r->dir);
		}
		if(tipo == 3){
			ImprimeArvore(r->esq);
			ImprimeArvore(r->dir);
			printf(" %d", r->valor);
		}
	}

	return 0;
}