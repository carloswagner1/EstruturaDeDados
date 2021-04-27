
/* Calc - Implementação*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "calc.h"


Pilha* cria (void){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

void push (Pilha* p, float v){
	if (p->n == MAX) {
	/* capacidade esgotada */
		printf("Capacidade da pilha estourou.\n");
		exit(1);/* aborta programa */
	}

	/* insere elemento na próxima posição livre */
	p->vet[p->n] = v;
	p->n++;
}

Calc* cria_calc (char* formato){
	Calc* c = (Calc*) malloc(sizeof(Calc));
	strcpy(c->f,formato);
	c->p = cria();/* cria pilha vazia */
	return c;
}

void operando (Calc* c, float v){
	/* empilha operando */
	push(c->p,v);

	/* imprime topo da pilha */
	printf(c->f,v);
}

void operador (Calc* c, char op){
	float v1, v2, v;
	
	/* desempilha operandos */
	if (vazia(c->p))
		v2 = 0.0;
	else
		v2 = pop(c->p);

	if (vazia(c->p))
		v1 = 0.0;
	else
		v1 = pop(c->p);

	/* faz operação*/
	switch (op) {
		case '+': 
			v = v1 + v2;
		break;

		case '-':
			v = v1 - v2;
		break;

		case '*':
			v = v1 * v2;
		break;

		case '/':
			v = v1 / v2;
		break;
	}

	/* empilha resultado */
	push(c->p,v);

	/* imprime topo da pilha */
	printf(c->f,v);
}

void libera_calc (Calc* c){
	libera(c->p);
	free(c);
}