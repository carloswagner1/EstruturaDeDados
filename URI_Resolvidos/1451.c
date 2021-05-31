/*1451 - Teclado Quebrado*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


/*typedef*/
typedef struct lista{
	char c;
	struct lista *next;
}TNo;

/*protótipo*/
TNo* novaLista(char c);

int main(){
	int pos;
	TNo *aux, *inicio, *final, *tmp;
	char string[100100];
	
	while(scanf("%s", string) != EOF){
		pos = 0;
		//pula caracter '[' ou ']'
		while(string[pos] != '\0' && (string[pos] == '[' || string[pos] == ']')) pos++;
		
		if(string[pos] != '\0')
			inicio = aux = final = novaLista(string[pos++]);
		
		while(string[pos] != '\0'){
			if(string[pos] == '['){
				aux = NULL;
			}else if(string[pos] == ']'){
				aux = final;
			}else if(aux == NULL){ 
				tmp = novaLista(string[pos]);
				tmp->next = inicio;
				aux = inicio = tmp;
			}else if(aux == final){
				tmp = novaLista(string[pos]);
				final->next = tmp;
				aux = final = tmp;
			}else{ /*aux está no meio da lista*/
				tmp = novaLista(string[pos]);
				tmp->next = aux->next;
				aux->next = tmp;
				aux = tmp;
			}
			pos++;
		}
		
		//output do resultado
		while(inicio != NULL){
			printf("%c", inicio->c);
			tmp = inicio;
			inicio = inicio->next;
			free(tmp);
		}
		printf("\n");
	}
	
	return 0;
}

/*função nova lista*/
TNo* novaLista(char c){
	TNo* tmp = (TNo*) malloc(sizeof(TNo));
	tmp->c = c; tmp->next = NULL;
	return tmp;
}

