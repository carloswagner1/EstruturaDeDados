/*Escala de Cinza*/
/*Carlos Wagner Rodrigues da Silva*/


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))

int main(void){
    int T, t;

    scanf("%d", &T);

    for (t = 1; t <= T; ++t) {
        char conversion[5];
        int r, g, b, p;

        scanf("%s", conversion);
        scanf("%d%d%d", &r, &g, &b);

        if (!strcmp(conversion, "eye")) {
            p = 0.3 * r + 0.59 * g + 0.11 * b;
        } else if (!strcmp(conversion, "mean")) {
            p = (r + g + b) / 3;
        } else if (!strcmp(conversion, "max")) {
            p = max(r, max(g, b));
        } else /*if (!strcmp(conversion, "min"))*/ {
            p = min(r, min(g, b));
        }

        printf("Caso #%d: %d\n", t, p);
    }

    return 0;
}