/*1548 - Fila do Recreio*/
/*Carlos Wagner*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void selection(int *, int);
int trocas;

int main ()
{

	int casos, numAlunos, i;

	scanf("%d", &casos);

	while (casos--)
	{

		scanf("%d", &numAlunos);

		int filaAntes[numAlunos];
		int filaDepois[numAlunos];

		for (i = 0; i < numAlunos; i++)
		{
			scanf("%d", &filaAntes[i]);
			filaDepois[i] = filaAntes[i];
		}

		trocas = 0;
		selection(filaDepois, numAlunos);

		for (i = 0; i < numAlunos; i++)
			if (filaAntes[i] == filaDepois[i])
				trocas++;

		printf("%d\n", trocas);

	}

}

void selection(int *vetor, int tam)
{

	int i, j, maior, temp;

	for (i = 0; i < tam - 1; i++)
	{

		maior = i;
		for (j = i + 1; j < tam; j++)
			if (vetor[j] > vetor[maior])
				maior = j;

		if (i != maior)
		{

			temp = vetor[i];
			vetor[i] = vetor[maior];
			vetor[maior] = temp;

		}

	}

}
