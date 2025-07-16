#include<stdio.h>
#include<stdlib.h>

int potencia(int n, int exp)
{
    int aux = n;
    for(int i = exp; i > 1; i--)
    {
        aux *= n ;
    }
    return aux;
}


int main()
{
int numero = 0, expoente = 0;
    printf("me fale um valor para ser elevadoz\n");
    scanf("%d", &numero);
    printf("Me fale um expoente para ele\n");
    scanf("%d", &expoente);
    numero = potencia(numero , expoente);
    printf("A sua potencia eh de: %d\n",numero);
return 0;
}