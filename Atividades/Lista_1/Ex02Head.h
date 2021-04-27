/*Autor: Carlos Wagner Rodrigues da Silva*/

/*Exercício_02*/
/*Interface - Lista de funcionários*/

#define TRUE 1
#define FALSE 0

#define QTDE_FUNC 5000

/*Structs-Typedefs*/
typedef struct{
	int codigo;
	char nome[31];
	float salario;
} regFunc;

typedef struct{
	int final;
	regFunc lista[QTDE_FUNC];
}TDescr;

/*Protótipo de Funcoes*/
void inicializalizaLista(TDescr *);
int IncluiFuncionario(TDescr *, int);
void ImprimeLista(TDescr *, char *);
int ExcluiFuncionario(TDescr *, int);
