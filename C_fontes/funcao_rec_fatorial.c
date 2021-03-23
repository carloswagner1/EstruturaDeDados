/* programa que le um numero e imprime seu fatorial */
#include <stdio.h>

int fat (int n);

/* Função principal */
int main (){
    int n;
    printf("Informe um número inteiro positivo: ");
    scanf("%d", &n);
    printf("Fatorial de %d = %d\n", n, fat(n));
    return 0;
}
/* Função recursiva para calcular o valor do fatorial */
int fat ( int n ){
    if (n==0)
        return 1;
    else
        return n*fat(n-1);
}