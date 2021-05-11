/*Huaauhahhuahau*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

struct regLista{
	char vogal;
	struct regLista *prox;
};
typedef struct regLista TLista;

struct descrPilha{
	TLista *topo;	
};

typedef struct descrPilha DPilha;

/*Prototipos de Funcoes*/
void inicializalizaPilha(DPilha *);
int Empilha(DPilha *, char);
int Desempilha(DPilha *);

int main(){
    char str1[51];
    DPilha descr;
    int i, qtde=0;
    

	/*Inicilizando o descritor da pilha*/
	inicializalizaPilha(&descr);

	/*passando a string*/
    scanf("%s", str1);

    /*varrendo a expressão*/
    /*empilhando vogais*/

    for(i = 0; i <= 50; i++){
        if(str1[i] == 'a' || str1[i]== 'e' || str1[i]== 'i' ||
            str1[i]== 'o' || str1[i]== 'u'){
                Empilha(&descr, str1[i]);
            	qtde++;
        }        
    }

    for(i = 0; i <= 50; i++){
   	    if(str1[i] == 'a' || str1[i]== 'e' || str1[i]== 'i' || str1[i]== 'o' || str1[i]== 'u'){
   	      	if(str1[i] == Desempilha(&descr)){
   	       		qtde--;
   	       	}else{
   	       		break;
   	       	}       
        }   
    }

    if(qtde == 0){
    	printf("S\n");
    }else{
    	printf("N\n");
    }
    

    return 0;    
}

void inicializalizaPilha(DPilha * descr){
	descr->topo = NULL;
}

int Empilha(DPilha *descr, char s){
	TLista *aux;

	/* criando uma variável struct TLista dinamicamente*/
	aux = (TLista *) malloc(sizeof(TLista));

	if(aux == NULL)
		return FALSE;	
	else{
		/*preenchendo os campos da variável*/
		aux->vogal = s;
		aux->prox = descr->topo;

		descr->topo=aux;
		return TRUE;
	}	
}


int Desempilha(DPilha *descr){
	TLista *aux;

	if(descr->topo != NULL){
		aux = descr->topo;
		descr->topo = descr->topo->prox;		
		return aux->vogal;	
	}else{
		return FALSE;
	}
	free(aux);
}