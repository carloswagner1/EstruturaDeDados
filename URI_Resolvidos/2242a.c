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
	int qtde;	
};

typedef struct descrPilha DPilha;

int main(){
    char str1[51];
    DPilha descr;
    TLista *aux;
    int i;

    descr.topo = NULL;
    descr.qtde = 0;

    scanf("%s", str1);
    
    for(i = 0; i <= 50; i++){
        if(str1[i] == 'a' || str1[i]== 'e' || str1[i]== 'i' ||
            str1[i]== 'o' || str1[i]== 'u'){
                aux = (TLista *) malloc(sizeof( TLista ));
            	aux->vogal = str1[i];
            	aux->prox = descr.topo;

            	descr.topo = aux;
            	descr.qtde++;
        }        
    }

    for(i = 0; i <= 50; i++){
   	    if(str1[i] == 'a' || str1[i]== 'e' || str1[i]== 'i' || str1[i]== 'o' || str1[i]== 'u'){
   	      	if(descr.topo != NULL){
   	      		aux = descr.topo;
   	      		descr.topo = descr.topo->prox;

	  	      	if(str1[i] == aux->vogal){
   	       			descr.qtde--;
   	       			free(aux);
   	       		}else{
   	       			break;
   	       		}       
        	}   
    	}
    }

    if(descr.qtde == 0){
    	printf("S\n");
    }else{
    	printf("N\n");
    }
    
    return 0;
}