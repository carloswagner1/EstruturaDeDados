/*Biblioteca Pascal*/
/*Carlos Wagner Rodrigues da Silva*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0

int main(void){

	int linhas, colunas, i, j;

	while (scanf("%d %d", &colunas, &linhas), linhas)
	{

		char matriz[linhas][colunas];

		for (i = 0; i < linhas; ++i)
			for (j = 0; j < colunas; ++j)
				scanf("%hhd", &matriz[i][j]);

		int cont;
		_Bool is = false;
		for (j = 0; j < colunas; ++j)
		{

			cont = 0;
			for (i = 0; i < linhas; ++i)
				if (matriz[i][j])
					cont++;
			
			if (cont == linhas)
				is = true;

		}

		printf("%s\n", is ? "yes" : "no");

	}

	return 0;

}