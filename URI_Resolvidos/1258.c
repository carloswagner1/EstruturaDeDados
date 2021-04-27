/*Camisetas*/
/*Carlos Wagner Rodrigues da Silva*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{char nome[100];char cor[10];char tam;}TAluno;
int Compara(const void *, const void *);

int main(){
	
	TAluno Turma[60];
	int n, i, j = 0;
	
	while(scanf("%d ", &n) && n != 0){
		for(i = 0 ;i < n; i++){
			gets(Turma[i].nome);
			scanf("%s %c ", Turma[i].cor, &Turma[i].tam);
		}
		qsort(Turma, n, sizeof(TAluno), Compara);
		if(j)
			printf("\n");
		else
			j++;
		for(i=0;i<n;i++)
			printf("%s %c %s\n", Turma[i].cor, Turma[i].tam, Turma[i].nome);
	}
	
	return 0;
}

int Compara(const void *p1, const void *p2){
	TAluno *i = (TAluno *)p1, *j = (TAluno *)p2;
	
	if(strcmp(i->cor, j->cor) == 0)
		if(i->tam > j->tam)
			return -1;
		else
			if(i->tam < j->tam)
				return 1;
			else
				return strcmp(i->nome, j->nome);
	else
		return strcmp(i->cor, j->cor);
}