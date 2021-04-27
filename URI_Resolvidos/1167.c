#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 35
#define MAX_CRIANCA 100
#define TRUE 1
#define FALSE 0

typedef struct no{struct no *horario, *antiHorario; char nome[MAX_NOME]; int num;}TNo;
typedef struct{TNo *inicio, *final; int num;}TDesc;

void inicializa(TDesc *);
void addNo(TDesc*, char *, int);
void conectaExtremos(TDesc *);
void descobreVencedor(TDesc *, int);

int main(){
	
	TDesc d;
	char nome[MAX_NOME];
	int n, i, num;
	
	while(scanf("%d", &n) && n){
		
		inicializa(&d);
		
		for(i=0; i<n; i++){
			scanf("%s %d", nome, &num);
			addNo(&d, nome, num);
		}
		conectaExtremos(&d);
		
		descobreVencedor(&d, n);
			
		printf("Vencedor(a): %s\n", d.inicio->nome);
	}
	
	return 0;
}

void inicializa(TDesc *d){
	d->inicio = NULL;
	d->final = NULL;
}

void addNo(TDesc *d, char nome[], int num){
	TNo *aux = (TNo *)malloc(sizeof(TNo));
	aux->num = num;
	strcpy(aux->nome, nome);
	
	if(d->inicio == NULL){
		aux->horario = NULL;
		d->inicio = aux;
		d->num = num;
	}else{
		aux->horario = d->final;
		d->final->antiHorario = aux;
	}
	d->final = aux;
}


void conectaExtremos(TDesc *d){
	d->inicio->horario = d->final;
	d->final->antiHorario = d->inicio;
}

void descobreVencedor(TDesc *d, int n){
	TNo *aux = d->inicio; 
	int i, j, num;
	
	for(i=0, n-=1; i<n; i++){
		//printf("Inicio na: %d %s\n", aux->num, aux->nome);
		num = aux->num;
		if(num%2)
			for(j=0; j<num; j++)
				aux = aux->antiHorario;			
		else
			for(j=0; j<num; j++)
				aux = aux->horario;
				
		aux->horario->antiHorario = aux->antiHorario;
		aux->antiHorario->horario = aux->horario;		
		//printf("Termino na: %s %d mov %d\n\n", aux->nome, aux->num, i);		
	}
	d->inicio = aux->antiHorario;
}
