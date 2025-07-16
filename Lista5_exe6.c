#include<stdio.h>
#include<stdlib.h>

int main()
{
    int vetor[5];
    for(int i =0; i < 5; i++)
    {
        printf("Me fale o %d° valor:\n",i+1);
        scanf(" %d", &vetor[i]);
    }
    for(int i =0; i < 5; i++)
    {
        if(vetor[i] % 2 == 1)
        {
            printf("Posição com valor par, endereço %p\n", vetor[i]);
        }
    }
}