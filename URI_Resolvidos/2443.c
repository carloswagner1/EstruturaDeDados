#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int mdc(int a, int b)
{
	if(a<0)
		a = -a;
	if(b<0)
		b = -b;
	if(a%b == 0)
		return b;
	else
		return mdc(b,a%b);
}

int main() {
    int n1, d1, n2, d2, num, den, div;
    
    scanf("%d %d %d %d", &n1, &d1, &n2, &d2);

	num = (n1*d2 + n2*d1);
	den = (d1*d2);
	
	div = mdc(num,den);

	printf("%d %d\n", num/div, den/div);

    return 0;
}