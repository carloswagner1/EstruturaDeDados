#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct regLista{
	int info;
	struct regLista *prox;
}Lista;

typedef struct pilha{
	Lista *ini;
	Lista *fim;
}Pilha;

Pilha *inicialize();
void *push(Pilha *p, int carta);
int pop(Pilha *p);

int main(){
	int n, i, carta, cont = 0;
	Pilha *pilha;
	pilha = inicialize();

	do{
		scanf("%d", &n);
		if(n){
			cont = n;
			for(i=1;i<=n;i++){
				push(pilha, i);
			}
			printf("Discarded cards:");

			while(cont!=1){
				printf(" %d", pop(pilha));
				push(pilha, pop(pilha));
				if(cont!=2)
					printf(",");
				cont--;
			}

			if(!vazio(pilha))
				printf("\nRemaining card: %d\n", pop(pilha));
		}
	}while(n!=0);

	return 0;
}

Pilha *inicialize(){
	Pilha *prim = (Pilha*)malloc(sizeof(Pilha));
	prim->ini = NULL;
	prim->fim = NULL;

	return prim;
}

void *push(Pilha *p, int carta){
	Lista *novo = (Lista*)malloc(sizeof(Lista));
	novo->info = carta;
	novo->prox = NULL;
	if(p->ini==NULL){
		p->ini = novo;
		p->fim = novo;
	}else{
		p->fim->prox = novo;
		p->fim = novo;
	}

}

int pop(Pilha *p){
	int carta;
	Lista *l;
	l = p->ini;
	carta = l->info;

	p->ini = l->prox;
	if(p->ini==NULL)
		p->fim = NULL;
	
	free(l);
	
	return carta;
}

int vazio(Pilha *p){
	return p->ini==NULL;
}

