/*Figurinhas*/
/*Carlos Wagner Rodrigues da Silva*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//int mdc(int, int);

int main(){
	int N, F1, F2, aux;

	scanf("%d", &N);
	
	for(int i = 0; i < N; i++){
		scanf("%d %d", &F1, &F2);

		if(F1 > F2){
			aux = F1;
			F1 = F2;
			F2 = aux;
		}

		while(F2 % F1 != 0){
			aux = F1;
			F1 = F2 % F1;
			F2 = aux;
		}

		printf("%d\n", F1);
	}

}

/*int mdc(int x, int y){
	int resto = 0;
	while(y % x != 0){
			resto = x;
			x = y % x;
			y = resto;
	}
	return x;
}*/