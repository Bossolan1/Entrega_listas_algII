#include<stdio.h>

void imprime(int *vet, int posicao)
{
    while(posicao != 0)
    {
        posicao--;
        printf("[%d]",*vet);
        vet++;
    }
    printf("\n");
}

int main()
{
    int vetor[5];
    for(int i =0; i < 5; i++)
    {
        printf("Me fale o %d° valor\n", i+1);
        scanf(" %d", &vetor[i]);
    }
    imprime(vetor,5);
    return 0;
}