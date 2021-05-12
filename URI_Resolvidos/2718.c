/*2718 - Luzes de Natal*/
/*Carlos Wagner*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main() {
    long long n, v, acum, maior, resto;

    scanf("%lld", &n);
    
    while (n--) {
        scanf("%lld", &v);
        acum = 0;
        maior = 0;
        
        while (v) {
            resto = v % 2;
            if (resto) {
                acum++;
                if (acum > maior)
                    maior = acum;
            }
            else
                acum = 0;
            v -= v/2 + resto;
        }
        printf("%lld\n", maior);
    }
    return 0;
}