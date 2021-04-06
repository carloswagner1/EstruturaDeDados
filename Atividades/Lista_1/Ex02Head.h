/*Autor: Carlos Wagner Rodrigues da Silva*/

/*Exercício_02*/
/*Interface - lista de funcionários*/


/*Typedef*/
typedef struct{
	int codigo;
	char nome[31];
	float salario;
} RegFunc;

/*Protótipo*/
void IncluirFunc (int, int);
void ImprimeLista(int, char *);
int ExcluiFunc (int, int);

