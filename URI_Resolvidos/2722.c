#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void main ()
{

	char nome[101], sobrenome[101], nomeCompleto[201];
	unsigned short casos, i, j, k;
	unsigned contador, aux;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf(" %[^\n] %[^\n]", nome, sobrenome);

		contador = 0;
		i = 0;
		k = 0;
		j = 0;

		aux = strlen(sobrenome);

		/*O laço continua até que o tamanho da string acabe.
		Como a a string do 'nome' sempre é iterada primeiro que a 'sobrenome', 
		a string 'sobrenome' vai acabar antes que a 'nome';*/
		while (aux--)
		{

			while (nome[i])
			{	
				/*A string 'nomeCompleto' recebe as letras em 'nome' até que 'contador' seja 2
				'contador' sendo == 2 significa que passei duas letras da string fonte para a string destino;
				 O laço para e o laço da string 'sobrenome' itera da mesma forma*/
				nomeCompleto[k++] = nome[i++];
				contador++;

				if (contador == 2)
					break;
			}

			contador = 0;
			while (sobrenome[j])
			{

				nomeCompleto[k++] = sobrenome[j++];
				contador++;

				if (contador == 2)
					break;


			}

			contador = 0;
		}

		nomeCompleto[k] = '\0';
		printf("%s\n", nomeCompleto);
	}
}
