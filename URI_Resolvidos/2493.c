/*Jogo do Operador*/
/*Carlos Wagner Rodrigues da Silva*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int X[50], Y[50], Z[50], E[50];
char N[50][51], R[50];

int compare(const void *a, const void *b);

int main()
{
    int T;

    while (scanf("%d", &T) != EOF) {
        int naoContinua[50];
        int tam = 0;
        int i;

        for (i = 0; i < T; ++i)
            scanf("%d %d=%d", &X[i], &Y[i], &Z[i]);

        for (i = 0; i < T; ++i)
            scanf("%s %d %c", &N[i], &E[i], &R[i]);

        for (i = 0; i < T; ++i) {
            switch (R[i]) {
                case '+':
                    if (X[E[i] - 1] + Y[E[i] - 1] != Z[E[i] - 1])
                        naoContinua[tam++] = i;
                    break;
                case '-':
                    if (X[E[i] - 1] - Y[E[i] - 1] != Z[E[i] - 1])
                        naoContinua[tam++] = i;
                    break;
                case '*':
                    if (X[E[i] - 1] * Y[E[i] - 1] != Z[E[i] - 1])
                        naoContinua[tam++] = i;
                    break;
                case 'I':
                    if (X[E[i] - 1] + Y[E[i] - 1] == Z[E[i] - 1] ||
                        X[E[i] - 1] - Y[E[i] - 1] == Z[E[i] - 1] ||
                        X[E[i] - 1] * Y[E[i] - 1] == Z[E[i] - 1])
                        naoContinua[tam++] = i;
                    break;
            }
        }

        if (tam == 0)
            printf("You Shall All Pass!\n");
        else if (tam == T)
            printf("None Shall Pass!\n");
        else {
            qsort(naoContinua, tam, sizeof(int), compare);
            for (i = 0; i < tam - 1; ++i)
                printf("%s ", N[naoContinua[i]]);
            printf("%s\n", N[naoContinua[i]]);
        }
    }

    return 0;
}

int compare(const void *a, const void *b)
{
    const int *p1 = (const int *) a;
    const int *p2 = (const int *) b;

    return strcmp(N[*p1], N[*p2]);
}