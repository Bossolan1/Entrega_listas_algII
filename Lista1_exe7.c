#include<stdio.h>
#include<stdlib.h>

void perfeito(int num)
{
    int cnt = 0, aux = 0, tot_soma = 0;
    for(int i = num - 1; i > 0; i--)
    {
        if(num % i == 0)
        tot_soma += i;
    }
    if(tot_soma == num)
    {
        printf("%d eh um numero perfeito\n");
    }
    else
    {
        printf("%d nao eh um numero perfeito\n");
    }
}
int main()
{
int numero = 0;
    printf("Me diga um numero\n");
    scanf("%d", &numero);
    perfeito(numero);
return 0;
}