#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

/*structs-typedefs*/
struct regList{
	char cidade[31];
	int populacao;
	float area;
	float PIB;
	float IDH;
	struct regList *ant;
	struct regList *prox;
};

typedef struct regList TNo;

typedef struct{
	TNo *inicio;
	TNo *final;
}TDescr;

/*protótipo das funções*/
void inicializaLista(TDescr *);
int IncluiItem(TDescr *, char *);
void ImprimeLista(TDescr *);
int excluiItem(TDescr *, float n); 

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

/* função inicializa a lista*/
void inicializaLista(TDescr *lista){
	lista->inicio = NULL;
	lista->final = NULL;
}

/* função para incluir itens*/
int IncluiItem(TDescr *lista, char *cid){
	TNo *aux;

  /*criando uma variável struct regList dinamicamente*/
	aux = (struct regList *) malloc(sizeof(struct regList));


	if(aux == NULL)
		return FALSE;
	else{ 
    /*preenchendo os campos da variável criada dinamicamente*/
		strcpy(aux->cidade, cid); 

		printf("\nInforme os seguintes dados da cidade:\n");
		printf("Populacao Area PIB IDH:\n");
		scanf("%d %f %f %f", &aux->populacao, &aux->area, &aux->PIB, &aux->IDH);
		printf("\n");

		aux->prox = NULL; 

    /*fazendo o encadeamento do novo nó na lista*/
		if(lista->inicio == NULL){ 
			aux->ant = NULL; 
			lista->inicio = aux; 
		}
		else{     
			lista->final->prox = aux; 
			aux->ant = lista->final;  
		}

		lista->final = aux; 

		return TRUE;

	}

}

void ImprimeLista(TDescr *lista){ 
	TNo *aux;

	if (lista->inicio == NULL) 
		puts("Lista esta vazia");     
	else{ 
		printf("\nCidades cadastradas em ordem\n");

		aux = lista->inicio;

		while (aux != NULL){
			printf("Cidade: %s Populacao: %d Area %.2f PIB: %.2f IDH: %.3f\n",
				aux->cidade, aux->populacao, aux->area, aux->PIB, aux->IDH);
			aux = aux->prox;
		}
   
    printf("\nCidades cadastradas em ordem contrária\n"); 

		aux = lista->final;

		while (aux != NULL){
			printf("Cidade: %s Populacao: %d Area %.2f PIB: %.2f IDH: %.3f\n",
				aux->cidade, aux->populacao, aux->area, aux->PIB, aux->IDH);
			aux = aux->ant; 
		}    
	}     
}


int excluiItem(TDescr *lista, float num){ 
	TNo *aux, *ant;

	aux = lista->inicio; 
	ant=NULL; 
	
  //busca elemento
	while (aux != NULL){ 

		if (aux->IDH >= num) 
			break; 

		ant = aux; 
		aux = aux->prox; 
	}

   /*fazendo a exclusão*/
	if (aux == NULL)
		return FALSE; 
	else{
		if (ant == NULL)
			lista->inicio = aux->prox;
		else{
			ant->prox = aux->prox;      
		}
			
		if (aux->prox != NULL){ 
			aux->prox->ant = aux->ant; 
		}else
			lista->final = aux->ant;  
		free(aux); 
	}
	excluiItem(lista, num); 
	return TRUE;
};