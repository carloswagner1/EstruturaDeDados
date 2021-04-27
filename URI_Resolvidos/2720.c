/*Presentes Grandes*/
/*Carlos Wagner Rodrigues da Silva*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define TAM 100000

typedef struct presente{unsigned _id; unsigned _volume;}presente;

int compara(presente *, presente *);
int compara2(unsigned *, unsigned *);

presente presentes[TAM] = { 0 };
unsigned ids[TAM];

int main ()
{

	unsigned i;
	unsigned short numCasos;
	unsigned short altura, largura, comprimento;
	unsigned numPresentesNoel, numPresentesBruno;

	scanf("%hu", &numCasos);

	while (numCasos--)
	{

		scanf("%u %u", &numPresentesNoel, &numPresentesBruno);

		for (i = 0; i < numPresentesNoel; ++i)
		{

			scanf("%u %hu %hu %hu", &presentes[i]._id, &altura, &largura, &comprimento);
			presentes[i]._volume = altura * largura * comprimento;

		}

		qsort(presentes, numPresentesNoel, sizeof(presente), compara);

		for (i = 0; i < numPresentesBruno; ++i)
			ids[i] = presentes[i]._id;

		qsort(ids, numPresentesBruno, sizeof(unsigned), compara2);

		for (i = 0; i < numPresentesBruno; ++i)
		{

			if (i != 0 && i != numPresentesBruno)
				printf(" ");

			printf("%u", ids[i]);

		}

		printf("\n");

	}
	return 0;
}

int compara(presente *a, presente *b)
{

	if (a->_volume == b->_volume)
	{

		if (a->_id > b->_id)
			return 1;
		else
			return -1;

	}
	else if (a->_volume > b->_volume)
		return -1;
	else
		return 1;

}

int compara2(unsigned *a, unsigned *b)
{

	if (*a > *b)
		return 1;
	else
		return -1;

}