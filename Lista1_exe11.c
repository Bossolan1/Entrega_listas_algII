#include<stdio.h>
#include<stdlib.h>

char calc_conceito(float nota)
{
    if(nota <= 4.9)
    return 'D';
    if(nota >= 5 && nota <= 6.9)
    return 'C';
    if(nota >= 7 && nota <= 8.9)
    return 'B';
    if(nota >= 9 && nota <= 10)
    return 'A';
    if(nota > 10)
    return 'R';
}

int main()
{   
    float media = 0;
    char conceito = 'D';
    printf("Qual foi a sua média final?\n");
    scanf("%f",&media);
    conceito = calc_conceito(media);
    printf("Seu conceito é %c\n", conceito);
    if(conceito == 'R')
    printf("De retardado mental s2\n");
    return 0;
} 