#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main();
int *produto_matriz(int *matrizA, int *matrizB, int tamanho);

int main()
{
    int *matrizA, *matrizB, *matrizC, numero = 0;
    printf("Me fale um número maior que 0\n");
    do
    {
        scanf(" %d", &numero);
    }while(numero <= 0);
    matrizA = malloc(numero*numero*sizeof(int)), matrizB = malloc(numero*numero*sizeof(int));
    printf("Matriz A e B:\n");
    for(int i = 0; i < numero; i++)
    {
        for(int j =0; j < numero; j++)
        {
            matrizA[i*numero+j] = rand()%11;
            printf("[%2d]",matrizA[i*numero+j]);
        }
        printf("               ");
        for(int j =0; j < numero; j++)
        {
            matrizB[i*numero+j] = rand()%11;
             printf("[%2d]",matrizB[i*numero+j]);
        }
        printf("\n");
    } 
    printf("Nova matriz C:\n");
    matrizC = produto_matriz(matrizA,matrizB,numero);
    
    for(int i =0; i < numero; i++)
    {
        for(int j =0; j < numero; j++)
        {
            printf("[%3d]",matrizC[i*numero+j]);
        }
        printf("\n");
    }
    free(matrizA);
    free(matrizB);
    free(matrizC);
}  

int *produto_matriz(int *matrizA, int *matrizB, int tamanho)
{
    int *matrizC = malloc(tamanho*tamanho*sizeof(int));
    for(int i =0; i < tamanho; i++)
    {
        for(int j =0;j < tamanho; j++)
        {
         matrizC[i * tamanho + j] = 0; 
            for(int k =0; k < tamanho; k++)
            {
                 matrizC[i * tamanho + j] += matrizA[i * tamanho + k] * matrizB[k * tamanho + j]; 
            }
        }
    }
    return matrizC;
}