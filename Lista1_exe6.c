#include<stdio.h>
#include<stdlib.h>

void em_dias(int a, int m, int d)
{
    printf("Sua idade expressa em dias eh: %.0f\n",(((float)a * 365) + ((float)m * 30,4167) + (float)d));
}

int main()
{
int ano = 0, meses = 0, dias = 0;
    printf("Me diga quantos anos voce tem\n");
    scanf("%d", &ano);
    printf("Quantos meses voce tem?\n");
    scanf("%d", &meses);
    printf("Me diga quantos dias voce tem\n");
    scanf("%d", &dias);
    em_dias(ano, meses, dias);
return (0);
}