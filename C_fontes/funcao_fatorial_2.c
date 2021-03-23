/* programa que le um numero e imprime seu fatorial */
#include <stdio.h>

int fat (int n);

/* Função principal */
int main (void){
    int n;
    printf("Informe um número inteiro positivo: ");
    scanf("%d", &n);
    printf("Fatorial de %d = %d\n", n, fat(n));
    return 0;
}
/* Função para calcular o valor do fatorial */
int fat ( int n ){
    int f = 1;
    while (n != 0){
        f *= n;
        n--;
    }
    return f;  

}