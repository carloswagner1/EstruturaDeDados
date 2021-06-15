/*Autores:*/
/*Jessica Maria dos Santos*/
/*Carlos Wagner Rodrigues da Silva*/
/*Exercício_03 - Cliente*/


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "Ex03Head.h"



/*programa main*/
int main(){
	char city[31];
	char aux[] = "FIM";
	TDescr lista;
	float idh;

  /* inicializando os descritores da lista */
	inicializaLista(&lista);

	while (1){
		printf("Informe o nome da cidade ou FIM para encerrar:\n");
		scanf(" %[^\n]", city);

		if(strcmp(aux, city) == 0)
			break;

		if (IncluiItem(&lista, city) == FALSE)
			{ puts("Memoria insuficiente para esta operacao");

		return 3;
		}

	}	

	/*Impressão cidades cadastradas em ordem e ao contrário*/
	ImprimeLista(&lista);


	while(1){
		printf("\nInforme o IDH limite ou -1 para encerrar: \n");
		scanf("%f", &idh);

		if(idh < 0) 
			break;

		if(lista.inicio == NULL){
			printf("A lista esta vazia.\n");
			break;
		}
		
		if(excluiItem(&lista, idh) == FALSE) 
			puts("Não há cidades com IDH maior que o informado");  
			
		else{
			ImprimeLista(&lista);
		}
	}
	return 0;
}