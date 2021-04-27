/* Interface da calculadora */

/*Struct-typedefs*/

struct no {
	float info;
	struct no* prox;
}; 

typedef struct no No;

struct pilha {
	No* prim;
};

typedef struct pilha Pilha;

struct calc {
	char f[21]; /*formato de imrpessão*/
	Pilha* p;   /*pilha de operandos*/
};

typedef struct calc Calc;

/* protótipos das funções  */
Pilha* cria (void);
void push (Pilha* p, float v);
Calc* cria_calc (char* f);
void operando (Calc* c, float v);
void operador (Calc* c, char op);
void libera_calc (Calc* c);