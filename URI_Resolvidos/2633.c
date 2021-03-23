#include <stdio.h>


typedef struct{char carne[21];int validade;} TCarnes;

void ordena(TCarnes *, int tam);

int main (){

	int qtdCarnes, i;

	
	while (scanf("%d", &qtdCarnes) != EOF){

		TCarnes churrasco[qtdCarnes];

		for (i = 0; i < qtdCarnes; i++)
			scanf("%s %d", churrasco[i].carne, &churrasco[i].validade);

		ordena(churrasco, qtdCarnes);

		for (i = 0; i < qtdCarnes; i++){
			if (i != 0 && i != qtdCarnes)
				printf(" ");

			printf("%s", churrasco[i].carne);
		}
		printf("\n");
	}
	return 0;
}

void ordena(TCarnes *churrasco, int tam){

	int i = 1, j;
	TCarnes aux;

	while (i < tam){

		j = i - 1;
		aux = churrasco[i];

		while (j >= 0 && churrasco[j].validade > aux.validade){

			churrasco[j + 1] = churrasco[j];
			j--;
		}
		churrasco[j + 1] = aux;
		i++;
	}
}