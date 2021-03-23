/* programa que le um numero e imprime seu fatorial */
#include <stdio.h>

int fat (int n);

/* Função principal */
int main (void){
    int n;
    printf("Informe um número inteiro positivo: ");
    scanf("%d", &n);
    printf("Fatorial = %d\n", fat(n));
    return 0;
}
/* Função para calcular o valor do fatorial */
int fat ( int n ){
    int i;
    int f = 1;
    for (i = 1; i <= n; i++){
        f *= i;
    }
    return f;  
//    printf("Fatorial = %d\n", f);
}