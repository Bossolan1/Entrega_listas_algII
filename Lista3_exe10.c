#include<stdio.h>
#include<stdlib.h>

int main();
int *gera_vetor(int num);

int main()
{
    int tamanho = 0, *vetor;
    printf("Qual é o tamanho do vetor?\n");
    scanf(" %d", &tamanho);
    vetor = gera_vetor(tamanho);
    for(int i = 0; i < tamanho; i++)
    {
        printf("Me fale o %d° valor\n", i + 1);
        scanf(" %d", &vetor[i]);
    }
    printf("Seu vetor é:");
    for(int i = 0; i < tamanho; i++)
    {
        printf("[%d]", vetor[i]);
    }
    printf("\n");
    
    free(vetor);
}

int *gera_vetor(int num)
{
    if(num <= 0)
    {
        return NULL;
    }
    else
    {
        int *vetor = malloc(num * sizeof(int));
        return vetor;
    }

}