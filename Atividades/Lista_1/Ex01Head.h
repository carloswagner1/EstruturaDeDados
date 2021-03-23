/*Arquivo Fonte Header - lista de funcionários*/


/*Structs*/
struct regFunc {
	int codigo; 
	char nome[30]; 
	double salario;
	struct regFunc *prox;
};

typedef struct regFunc TNo;

/*Descritores*/
typedef struct {
	TNo *inicio, *final; 
	int qtde;
	float somaSalario;
} TDescr;

/*Funções*/
void InicializaLista(TDescr *);
int Inclusao(TDescr *, int);
int Exclusao(TDescr *, int);
void ImprimeLista(TDescr *, char *);