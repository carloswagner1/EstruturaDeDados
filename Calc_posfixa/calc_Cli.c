
/* Calc - Cliente */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "calc.h"

int main (void){
	char c;
	float v;
	Calc* calc;

	/* cria calculadora com precisão de impressão de duas casas decimais*/
	calc = cria_calc("%.2f\n");

	do {
		/* le proximo caractere nao branco */
		scanf(" %c",&c);
		/* verifica se e' operador valido */
		if (c=='+' || c=='-' || c=='*' || c=='/') {
			operador(calc,c);
		}
		/* devolve caractere lido e tenta ler número */
		else {
			ungetc(c,stdin);
			if (scanf("%f",&v) == 1)
				operando(calc,v);
		}
	} while (c != 'q');

	libera_calc(calc);

	return 0;

}
