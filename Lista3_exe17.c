#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int *gera_vetor_uwu(int *matriz, int tamanho)
{
    int *vetor = malloc(sizeof(int) * tamanho);
    for(int i=0; i < tamanho; i++)
    {
        for(int j= 0; j < tamanho; j++)
        {
            vetor[i] += matriz[j*tamanho+i];
        }
    } 
    return vetor;
}


int main()
{
    int numero = 0, *vetor;
    srand(time(NULL));
    printf("Hammer of justice time!\n");
    printf("Ola usuario gostaria de me mandar um numero?\nnão??? que pena... escreve um então!\n só para te avisar, ele tem que ser maior que 0\n");
    do
    {    
        scanf(" %d", &numero);
    }while(numero <= 0);   
    int *matriz_sexy = malloc(sizeof(int) * numero * numero);
    printf("Vossa matriz\n");
    for(int i = 0; i < numero; i++)
    {
        for(int j = 0; j < numero; j++)
        {
            matriz_sexy[i * numero + j] = rand() % 11;
            printf("[%2d]", matriz_sexy[i * numero +j]);  
        }
        printf("\n");
    }
    vetor = gera_vetor_uwu(matriz_sexy, numero);
    printf("Seu vetor da soma das colunas da matriz\n");
    for(int i =0; i < numero; i++)
    {
        printf("[%d]",vetor[i]);
    }
    free(matriz_sexy);
    free(vetor);
    printf("\n");
} 
