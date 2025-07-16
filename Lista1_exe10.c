#include<stdio.h>
#include<stdlib.h>

int par_ou_impar(int a)
{
    if(a % 2 == 0)
    return 0;
    else
    return 1;
}

int main()
{
    int n = 0;
    printf("Me diga um numero\n");
    scanf("%d", &n);
    if(par_ou_impar(n) == 0)
    printf("Ele é Par\n");
    else
    printf("Ele é impar\n");
}