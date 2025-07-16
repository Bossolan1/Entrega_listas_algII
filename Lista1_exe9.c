#include<stdio.h>
#include<stdlib.h>

int positivo_ou_negativo(int a)
{
    if(a > 0)
    {
    return 0;
    }
    if(a < 0)
    {
    return 1;
    }
    if(a == 0);
    {
    return 2;
    }
}

int main()
{
    int num = 0;
    printf("Me diga um valor\n");
    scanf("%d", &num);
    if(positivo_ou_negativo(num) == 1)
    {
        printf("Negativo\n");
    }
    if(positivo_ou_negativo(num) == 0)
    {
        printf("Positivo\n");
    }
    if(positivo_ou_negativo(num) == 2)
    {
        printf("0 nao eh nada\n");
    }
}