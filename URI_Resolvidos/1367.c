/*Ajude!*/
/*Carlos Wagner Rodrigues da Silva*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

#define QTDE_SUB 300


typedef struct{
	char id;
	int tempo;
	char julg[10];
} Submissao;


int compara(const void *, const void *);

int main(){
	int n, i, tempoTotal, aux, acertos;
	Submissao *submit;
	char idQuestao;



	while(scanf("%d", &n) && n){
		submit= (Submissao *) malloc(sizeof(Submissao) * n);

		for(i = 0; i < n; i++)
			scanf(" %c %d %s" , &submit[i].id, &submit[i].tempo, submit[i].julg);

		qsort(submit, n, sizeof(Submissao), compara);

		for(idQuestao = submit[i].id, i = acertos = tempoTotal = 0; i < n; idQuestao = submit[i].id){
			for(aux = 0; i < n && idQuestao == submit[i].id; i++){
					if(!strcmp(submit[i].julg,"correct")){
						tempoTotal += (aux + submit[i].tempo);
						acertos++;
						while(idQuestao == submit[i].id) i++;
						break;
					}

					aux += 20;
			}	
		}

		printf("%d %d\n", acertos, tempoTotal);
	}

	 return 0;

}

int compara(const void *p1, const void *p2){
	Submissao *i = (Submissao *)p1, *j = (Submissao *)p2;

	if(i->id > j->id)
		return 1;
	else if(i->id < j->id)
		return -1;
	else
		return 0;
}
