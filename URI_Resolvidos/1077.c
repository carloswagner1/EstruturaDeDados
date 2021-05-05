/*Infixa para Posfixa*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define EXP_MAX_SIZE 1024


int prec(char operator);

void paraPosfixa(const char *exp, char *out);


int main (void) {
	int N;
	char infixa[EXP_MAX_SIZE], posfixa[EXP_MAX_SIZE];

	scanf("%d\n", &N);

	while (N-- > 0) {
		fgets(infixa, EXP_MAX_SIZE, stdin);
		paraPosfixa(infixa, posfixa);
		printf("%s\n", posfixa);
	}
	return 0;

}


void paraPosfixa(const char *exp, char *out) {
	char p[EXP_MAX_SIZE];
	int i, o = 0, t = -1;
	char c;

	for (i = 0; exp[i] != '\n' && exp[i] != '\0'; i++) {
		c = exp[i];
		if (c == ' ') 
			continue;
		if (c == '('){
			p[++t] = c;
		}else if (c == ')'){
			while (t > -1 && p[t] != '(') {
				out[o++] = p[t--];
			}
			t--;
		}else if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			out[o++] = c;
		}else{
			while (t > -1 && p[t] != '(' && prec(p[t]) >= prec(c)) {
				out[o++] = p[t--];
			}
			p[++t] = c;
		}
	}
	while (t > -1) out[o++] = p[t--];
	out[o++] = '\0';

}




int prec(char operator) {
	switch (operator) {
		case '^':
			return 3;
		break;

		case '*':
			return 2;
		break;

		case '/':
			return 2;
		break;

		case '+':
			return 1;
		break;

		case '-':
			return 1;
		break;

		default:
			return 0;

	}

}