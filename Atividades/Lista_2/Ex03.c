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
void ImprimeLista(TDescr *, char *);
void ImprimeListaContrario(TDescr *, char *);

/*programa main*/
int main(){
  char city[31];
  char aux[] = "FIM";
  TDescr lista;

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

  ImprimeLista(&lista, "Cidades Cadastradas");
  ImprimeListaContrario(&lista, "Contrário");

  return 0;
}

/* função iniciliza a lista*/
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

void ImprimeLista(TDescr *lista, char *cabec){  
  TNo *aux;

  if (lista->inicio == NULL)
    puts("Lista esta vazia");     
  else{ 
    printf("\n\n%s\n", cabec);

    aux = lista->inicio;

    while (aux != NULL){
      printf("Cidade: %s Populacao: %d Area %.2f PIB: %.2f IDH: %.2f\n",
       aux->cidade, aux->populacao, aux->area, aux->PIB, aux->IDH);
      aux = aux->prox;
    } 
  }     
}

void ImprimeListaContrario(TDescr *lista, char *cabec){  
  TNo *aux;

  if (lista->inicio == NULL)
    puts("Lista esta vazia");     
  else{ 
    printf("\n\n%s\n", cabec);

    aux = lista->final;

    while (aux != NULL){
      printf("Cidade: %s Populacao: %d Area %.2f PIB: %.2f IDH: %.2f\n",
       aux->cidade, aux->populacao, aux->area, aux->PIB, aux->IDH);
      aux = aux->ant;
    } 
  }     
}