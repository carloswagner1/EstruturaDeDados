/*A Fila de Desempregados*/
/*Carlos Wagner Rodrigues da Silva*/


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct regFila {
    int valor;
    int ant;
    int prox;
};

int main()
{
    int N, k, m;

    while (1) {
        struct regFila candidatos[21];
        int i, j1, j2;
        int restante;

        scanf("%d%d%d", &N, &k, &m);

        if (!(N || k || m))
            break;

        for (i = 1; i <= N; ++i) {
            candidatos[i].valor = i;
            candidatos[i].ant = (i == 1) ? N : i - 1;
            candidatos[i].prox = (i == N) ? 1 : i + 1;
        }
        candidatos[0].prox = 1;
        candidatos[N + 1].ant = N;

        restante = N;
        j1 = 0;
        j2 = N + 1;

        while (1) {
            for (i = 0; i < k; ++i)
                j1 = candidatos[j1].prox;
            for (i = 0; i < m; ++i)
                j2 = candidatos[j2].ant;

            printf("%3d", candidatos[j1].valor);
            --restante;
            if (j1 != j2) {
                printf("%3d", candidatos[j2].valor);
                --restante;
            }

            if (candidatos[j1].ant == j2 || candidatos[j1].prox == j2) {
                if (candidatos[j1].ant == j2) {
                    candidatos[j1].ant = candidatos[j2].ant;
                    candidatos[j2].prox = candidatos[j1].prox;
                }
                if (candidatos[j1].prox == j2) {
                    candidatos[j1].prox = candidatos[j2].prox;
                    candidatos[j2].ant = candidatos[j1].ant;
                }
            }

            candidatos[candidatos[j1].ant].prox = candidatos[j1].prox;
            candidatos[candidatos[j1].prox].ant = candidatos[j1].ant;
            if (j1 != j2) {
                candidatos[candidatos[j2].ant].prox = candidatos[j2].prox;
                candidatos[candidatos[j2].prox].ant = candidatos[j2].ant;
            }

            if (restante > 0)
                putchar(',');
            else {
                putchar('\n');
                break;
            }
        }
    }

    return 0;
}
