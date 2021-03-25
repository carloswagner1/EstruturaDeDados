/*
	Interface lista linear de inteiros por encadeamento.

*/

struct regLista {int valor; struct regLista *prox;};
typedef struct regLista TNo;

typedef struct {TNo *inicio, *final; int qtde;} TDescr;

void InicializaLista(TDescr *);
int IncluiItem(TDescr *, int);
void ImprimeLista(TDescr *, char *);
int ExcluiItem(TDescr *, int);

