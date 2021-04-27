/*Autor: Carlos Wagner Rodrigues da Silva*/
/*Exercicio_01*/
/*Interface - Lista de funcionários*/

#define TRUE 1
#define FALSE 0

/*Structs-Typedefs*/
struct regFunc {
	int codigo; 
	char nome[31]; 
	float salario;
	struct regFunc *prox;
};

typedef struct regFunc TNo;

typedef struct {
	TNo *inicio, *final; 
	int qtde;
	float totalSalario;
} TDescr;

/*Prototipos de Funcoes*/
void inicializalizaLista(TDescr *);
int IncluiFuncionario(TDescr *, int);
void ImprimeLista(TDescr *, char *);
int ExcluiFuncionario(TDescr *, int);