#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

#define QTDE_CID 5001

/*structs-typedefs*/
typedef struct{
	char cidade[31];
	int populacao;
	float area;
	float PIB;
	float IDH;
}regList;

typedef struct{
	int final;
	regList lista[QTDE_CID];
}TDescr;

/*protótipo das funções*/
void inicializaLista(TDescr *);
int IncluiItem(TDescr *, char *);
void constroiHeap (int , TDescr *);
void peneira(int , TDescr *);
void heapsort(int , TDescr *);
void ImprimeLista(int , TDescr *);

/*programa main*/
int main(){
	char city[31];
	char aux[] = "FIM";
	TDescr lista;
  	int N;

  /* inicializando os descritores da lista */
	inicializaLista(&lista);

	while (1){
		printf("Informe o nome da cidade ou FIM para encerrar:\n");
		scanf(" %[^\n]", city);

		if(strcmp(aux, city) == 0)
			break;

		if (IncluiItem(&lista, city) == FALSE)
			{ puts("Memoria insuficiente para esta operacao.\n");

		return 3;
		}
	}

	//minHeap  
	constroiHeap(lista.final, &lista);  

	//odena o heap
	heapsort(lista.final, &lista);

	printf("\nInforme a quantidade de cidades beneficiadas:\n");
	scanf("%d", &N); 

	ImprimeLista(N, &lista);

	return 0;
}

void inicializaLista(TDescr *lst){
	lst->final = 0;
}

int IncluiItem (TDescr *lst, char *cid){
	if (lst->final == QTDE_CID)
		return FALSE;
	else{
		strcpy(lst->lista[++(lst->final)].cidade, cid);

		printf("\nInforme os seguintes dados da cidade:\n");
		printf("Populacao Area PIB IDH:\n");
		scanf("%d %f %f %f", &lst->lista[(lst->final)].populacao, 
				&lst->lista[(lst->final)].area, 
				&lst->lista[(lst->final)].PIB, 
				&lst->lista[(lst->final)].IDH);
		printf("\n");
	
		return TRUE;
	}
}

void constroiHeap (int m, TDescr *lst)
{
	TDescr aux;
	for (int k = 1; k < m; ++k){
		int f = k+1;
		while (f > 1 && lst->lista[f/2].IDH < lst->lista[f].IDH) {
	        aux.lista[f] = lst->lista[f / 2];
			lst->lista[f / 2] = lst->lista[f]; 
			lst->lista[f] = aux.lista[f];          
        	f /= 2;                        
      	}
   	}
}

void peneira(int m, TDescr *lst){ 
  	TDescr aux;
  	int f = 2;
  	while (f <= m){
   	   	if (f < m && lst->lista[f].IDH < lst->lista[f+1].IDH)
   	   		++f;
       	if (lst->lista[f/2].IDH >= lst->lista[f].IDH)
        	break;
       	aux.lista[0] = lst->lista[f];    
       	lst->lista[f] = lst->lista[f/2];
       	lst->lista[f/2] = aux.lista[0];
       	f *= 2;
   }   
}

void heapsort(int n, TDescr *lst){
	int i;
	TDescr aux;
	
	for(i = n; i >= 2; --i){
    	aux.lista[0] = lst->lista[1];
    	lst->lista[1] = lst->lista[i]; 
		lst->lista[i] = aux.lista[0];		
		peneira(i-1, lst);			
	}
}


void ImprimeLista(int n, TDescr *lst){
	int i;

	if (lst->final == 0)
		puts("Não há cidades cadastradas.");
	else{
		if(n > lst->final){
	 	  	printf("So existem %d cidades cadastradas.\n", lst->final);
	 	  	n = lst->final;
	 	}  	
	  	else
     		printf("As %d cidades beneficiadas:\n", n);
    	for (i = 1; i <= n; i++){
    	printf("Cidade %d: %s Populacao: %d Area %.2f PIB: %.2f IDH: %.3f\n",
			i, lst->lista[i].cidade, lst->lista[i].populacao, 
			lst->lista[i].area, lst->lista[i].PIB, lst->lista[i].IDH);
    	}
	}
}