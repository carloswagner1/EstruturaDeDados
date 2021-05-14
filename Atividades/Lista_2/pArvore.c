#include <stdio.h>
#include <stdlib.h>

struct regNo{	struct regNo *esq;
				int valor;
				struct regNo *dir;
			};
typedef struct regNo TNo;

TNo *AchaPai(TNo *, int);
void ImprimeArvore(TNo *, int);
int ContaNos(TNo *);
int SomaNos(TNo *);
int ContaPares(TNo *);
void ImprimeMaior(TNo *r, int);
void ImprimeMenor(TNo *r, int);
int ContaFolhas(TNo *);
int Altura(TNo *);

int main(void)
{	TNo *raiz = NULL, *aux, *pai;
	int numero;
	
	while (1)
	{	printf("\nInforme o valor:\n"); 
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
	
	printf("\n\nA arvore possui %d elementos:\n", ContaNos(raiz));
	ImprimeArvore(raiz, 0);
	printf("\n");
	ImprimeMaior(raiz, 0);
	ImprimeMenor(raiz, 0);
	printf("A arvore possui %d folhas.\n", ContaFolhas(raiz));
	printf("Altura da arvore: %d\n", Altura(raiz));
	
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

int ContaNos(TNo *r)
{	if (r == NULL)
		return 0;
	else
		return 1 + ContaNos(r->esq) + ContaNos(r->dir);
}

void ImprimeArvore(TNo *r, int n)
{	int c;
	
	if (r != NULL)
	{	for (c = 0; c < n; c++) 
			printf("    ");
		printf("%d\n", r->valor);	

		ImprimeArvore(r->esq, n + 1);
		ImprimeArvore(r->dir, n + 1);
	}
}

void ImprimeMaior(TNo *r, int n)
{	if (r != NULL){
		if (r->dir == NULL)
			printf("Maior valor contido na arvore: %d\n", r->valor);
		else
			ImprimeMaior(r->dir, n + 1);
	}
}

void ImprimeMenor(TNo *r, int n)
{	if (r != NULL){
		if (r->esq == NULL)
			printf("Menor valor contido na arvore: %d\n", r->valor);
		else
			ImprimeMenor(r->esq, n + 1);
	}
}

int ContaFolhas(TNo *r)
{	int folha = 0;
	if(r != NULL){
		if(r->esq == NULL && r->dir == NULL)
			folha += 1;
		else
		  folha = folha + ContaFolhas(r->esq) + ContaFolhas(r->dir);
	}
	return folha;
}

int Altura(TNo *r){
	if(r == NULL)
		return -1;
	else{
		int sae = Altura(r->esq);
		int sad = Altura(r->dir);
		if (sae < sad)
			return sad + 1;
		else
			return sae + 1;
	}
}
