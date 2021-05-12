/*1069 - Diamantes e Areia*/
/*Carlos Wagner Rodrigues da Silva*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



struct regLista{
	char simbolo;
	struct regLista *prox;
};

typedef struct regLista TLista;

struct descrPilha{
	TLista *topo;
};

typedef struct descrPilha DPilha;

int main(){
	char expr[1010] = "";
	DPilha descritor;
	TLista *aux1, *aux2;
	int n=0, c=0, qtdDiamante = 0, d=0;

	scanf("%d", &n);

	while(c < n){

		scanf("%s", expr);

		descritor.topo = NULL;
		d = 0;
		qtdDiamante = 0;

		while(d < strlen(expr)){

			if(expr[d] == '<'){
				aux1 = (TLista *) malloc(sizeof(TLista));

				if(aux1 == NULL)
					break;

				aux1->simbolo = expr[d];
				aux1->prox = descritor.topo;

				descritor.topo = aux1;
			}

			else if(expr[d] == '>'){
				aux2 = (TLista *) malloc(sizeof(TLista));

				if(descritor.topo != NULL){					
					aux2 = descritor.topo;
					descritor.topo = aux2->prox;
					free(aux2);
					qtdDiamante++;
				}
			}
			d++;
			
		}

		printf("%d\n", qtdDiamante);
		c++;
	}
	
	return 0;
}