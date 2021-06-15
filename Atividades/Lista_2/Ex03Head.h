/*Autores:*/
/*Jessica Maria dos Santos*/
/*Carlos Wagner Rodrigues da Silva*/
/*Exercício_03 - Interface*/


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
