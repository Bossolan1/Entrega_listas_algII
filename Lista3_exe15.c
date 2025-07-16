#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main();
int *gera_vetores(int num);

int main()
{
    int valor = 0, *vetor;
    printf("Me diga um tamanho para os vetores:\n");
    scanf(" %d", &valor); 
    vetor = gera_vetores(valor);
    printf("Vetor C:\n");
    for(int i = 0; i < valor; i++)
    {
        printf("[%d]",vetor[i]);
    }
    printf("\n");
    free(vetor);
}

int *gera_vetores(int num)
{
    int vetor_A[num], vetor_B[num], *vetor_C = malloc(sizeof(int) * num);
    srand(time(NULL));
    for(int i = 0; i < num; i++)
    {
        vetor_A[i] = rand() % 11;
        vetor_B[i] = rand() % 11;
        vetor_C[i] = vetor_A[i] *vetor_B[i];
    }
    printf("Vetor A:\n");
    for(int i = 0; i < num; i++)
    {
        printf("[%d]",vetor_A[i]);
    }
    printf("\nVetor B:\n");
    for(int i = 0; i < num; i++)
    {
        printf("[%d]",vetor_B[i]);
    }
    printf("\n");
    return vetor_C;
}

