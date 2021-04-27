/*Figurinhas*/
/*Carlos Wagner Rodrigues da Silva*/

#include <stdio.h>

int main(void){
	int n, f1, f2, aux=0;

	scanf("%d", &n);
	
	while (n--){
		scanf("%d %d", &f1, &f2);

		while(f2 != 0){
			aux = f1 % f2;
			f1 = f2;
			f2 = aux;
		}

		printf("%d\n", f1);
	}

}


