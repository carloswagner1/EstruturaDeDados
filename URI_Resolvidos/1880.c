/*Renzo e a Decoração Capicuânica*/
/*Carlos Wagner Rodrigues da Silva*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int palindromo(int n, int b);

int main()
{
	int cases;
	int aux;
	int n, i;

	scanf("%i", &cases);

	while (cases--){
		
		scanf("%i", &n);
		aux = 0;

		for(i = 2; i <= 16; ++i)
		{
			if (palindromo(n, i))
			{
				if (aux)
					printf(" ");				
				printf("%i", i);
				aux = 1;
			}
		}
		if(!aux)
			printf("-1");
		printf("\n");    
	}

	return 0;
}


int palindromo(int n, int b) //numero e base
{
	char string[35];
	int tam = 0;
	int i, k, j;
	i = 0;
	
	while (n)
	{
		int resto = n % b;
		if (resto <= 9)
			string[i++] = resto + '0'; 
		else string[i++] = resto - 10 + 'a';
			n /= b;
		
		tam++;
	}
	
	string[tam] = '\0';

	/*checar o palindromo*/	
	for (k = 0, j = tam - 1; k < j; ++k, --j)
		if (string[j] != string[k])
			return 0;	
	return 1;	
}