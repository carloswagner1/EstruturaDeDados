#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct{int numerador; int denominador;}TRac;
TRac Adicao(TRac, TRac);
TRac Subtracao(TRac, TRac);
TRac Divisao(TRac, TRac);
TRac Multiplicao(TRac, TRac);
TRac Simplificacao(TRac);
int mdc(int, int);

int main(){
	
	TRac f1, f2;
	char sinal;
	int n;
	
	scanf("%d", &n);
	while(n--){
		scanf("%d / %d %c %d / %d", &f1.numerador, &f1.denominador, &sinal, &f2.numerador, &f2.denominador);
		if(sinal == '+')
			f1 = Adicao(f1, f2);
		else
			if(sinal == '-')
				f1 = Subtracao(f1, f2);
			else
				if(sinal == '/')
					f1 = Divisao(f1, f2);
				else
					f1 = Multiplicao(f1, f2);
		f2 = Simplificacao(f1);
		printf("%d/%d = %d/%d\n", f1.numerador, f1.denominador, f2.numerador, f2.denominador);			
	}		
	return 0;
}

TRac Adicao(TRac i, TRac j){
	TRac r;
	/* Soma: (N1*D2 + N2*D1) / (D1*D2) */
	r.numerador = i.numerador * j.denominador + j.numerador * i.denominador;
	r.denominador = i.denominador * j.denominador;
	
	return r;	
}

TRac Subtracao(TRac i, TRac j){
	TRac r;
	/* Subtração: (N1*D2 - N2*D1) / (D1*D2) */
	r.numerador = i.numerador * j.denominador - j.numerador * i.denominador;
	r.denominador = i.denominador * j.denominador;
	
	return r;
}

TRac Multiplicao(TRac i, TRac j){
	TRac r;
	/* Multiplicação: (N1*N2) / (D1*D2) */
	r.numerador = i.numerador * j.numerador;
	r.denominador = i.denominador * j.denominador;
	
	return r; 
}

TRac Divisao(TRac i, TRac j){
	TRac r;
	/* Divisão: (N1/D1) / (N2/D2), ou seja (N1*D2)/(N2*D1) */
	r.numerador = i.numerador * j.denominador;
	r.denominador = j.numerador * i.denominador;
	
	return r;
}

TRac Simplificacao(TRac i){
	int d;
	
	d = mdc(i.numerador, i.denominador);
	i.numerador = i.numerador / d;
	i.denominador = i.denominador / d;
	
	return i;
}

int mdc(int i, int j){
	if(i < 0)	
		i = -i;
	if(j < 0)	
		j = -j;
	if(i % j == 0)
        return j;
    else
        return mdc(j, i % j);
}
