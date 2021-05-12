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
void ImprimeMaior(TNo *r);
void ImprimeMenor(TNo *r);
int ContaFolhas(TNo *);

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
	//aux = AchaMaior(raiz);
	//printf("\n\n%d\n", AchaMaior(raiz));
	ImprimeMaior(raiz);
	ImprimeMenor(raiz);
	printf("\n\nA arvore possui %d folhas.\n", ContaFolhas(raiz));


	
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

void ImprimeMaior(TNo *r)
{	if (r != NULL){
		r=r->dir;
		if (r->dir == NULL)
			printf("Maior valor contido na arvore: %d\n", r->valor);
		else
			ImprimeMaior(r);
	}
}

void ImprimeMenor(TNo *r)
{	if (r != NULL){
		r=r->esq;
		if (r->esq == NULL)
			printf("Menor valor contido na arvore: %d\n", r->valor);
		else
			ImprimeMenor(r);
	}
}

int ContaFolhas(TNo *r)
{	int soma = 0;
	if (r == NULL)
		return 0;
	else{
		if(r->esq == NULL && r->dir == NULL)
			soma = soma +1;					
		else{
			ContaFolhas(r->esq);
			ContaFolhas(r->dir);
		}

	}

	return soma;		
}
