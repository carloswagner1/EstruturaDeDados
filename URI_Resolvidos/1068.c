/*1068 - Balanço de Parênteses I*/
/*Carlos Wagner Rodrigues da Silva*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct regLista{
	char paranteses;
	struct regLista *prox;
};

typedef struct regLista TLista;

struct descrPilha{
	TLista *topo;
	int qtde;
};

typedef struct descrPilha DPilha;

int main(){
	char expr[3000] = "";
	DPilha descritor;
	TLista *aux;
	int c, sai;

	
	while(scanf("%s", expr) != EOF){
		descritor.topo = NULL;
		descritor.qtde = c = sai = 0;
	
		
		do{
			if(expr[c] == '('){
				aux = (TLista *) malloc(sizeof( TLista ));

				if(aux == NULL)
					break;

				aux->paranteses = expr[c];
				aux->prox = descritor.topo;

				descritor.topo = aux;
				descritor.qtde++;


			}

			if(expr[c] == ')'){

				if(descritor.topo == NULL){
					sai = 1;
					break;
				}

				else{
					aux = descritor.topo;
					descritor.topo = aux->prox;
					descritor.qtde--;
					free(aux);
				}
			}
			c++;
			
		}while (c < strlen(expr));


		if(sai == 1 || descritor.qtde != 0)
			printf("incorrect\n");
		else
			printf("correct\n");
	}
	
	return 0;
}