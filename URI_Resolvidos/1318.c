#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main (){

	int contador = 0, i, j, k;
	int numBilhetes, numPessoas;
	
	while (1)
	{		
		scanf("%d %d", &numBilhetes, &numPessoas);

		if (numBilhetes == 0 && numPessoas == 0)
			break;

		int codBilhete[numPessoas], codBilheteCpy[numPessoas];

		for (i = 0; i < numPessoas; i++)
			scanf("%d", &codBilhete[i]);

		//Cria uma cópia do vetor codBilhete para fazer modificações futuras;
		for (i = 0; i < numPessoas; i++)
			codBilheteCpy[i] = codBilhete[i];

		//Percorre o vetor codBilhete;
		for (i = 0; i < numPessoas; i++)
		{	
			
			for (j = 0; j < numPessoas; j++)
			{	
				//É preciso que a posição do codBilhete seja diferente do codBilheteCpy
				//Para não contar repetições;
				if (i != j)
					if (codBilhete[i] == codBilheteCpy[j])
					{
						contador++;
						codBilheteCpy[j] = 0;
						//Se pelo menos um valor igual for constatado
						//É preciso escrever 0 em todas as posições que têm o mesmo valor
						//Para não contar na próxima iteração;
						for (k = j; k < numPessoas; k++)
							if (codBilhete[i] == codBilheteCpy[k])
								codBilheteCpy[k] = 0;

						//Para o laço for 'j' logo em seguida;
						break;

					}
				//Por fim, escreve 0 na posição que estava sendo avaliada com i;
				codBilheteCpy[i] = 0;
			
			}
		}

		printf("%d\n", contador);
		contador = 0;
	}
}