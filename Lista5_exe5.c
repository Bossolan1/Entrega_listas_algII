#include<stdio.h>
#include<stdlib.h>

int main()
{
    int vetor[5], *p = vetor;
    for(int i =0; i < 5; i++)
    {
        printf("Me fale um valor\n");
        scanf(" %d", p + i);
    }
    for(int i = 0; i < 5; i++)
    {  
        printf("Valor da %d° casa dobrado é de: %d\n", i+1, *(p+i)*2);
    }