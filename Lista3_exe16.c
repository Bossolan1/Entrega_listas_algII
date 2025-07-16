#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main();
int *gera_produto_vetor(int tamanho, int *matriz,int *vetor);

int *gera_produto_vetor(int tamanho, int *matriz, int *vetor)
{
    int *produto = malloc(sizeof(int) * tamanho);
    
    for(int i =0; i < tamanho; i++)
    {
            
    }
    for(int i = 0; i < tamanho; i++)
    {
        produto[i] = 0;
        for(int j = 0; j < tamanho; j++)
        {            
            produto[i] += matriz[i*tamanho+j] * vetor[j];
        }
    }
    return produto;
}

int main()
{
    int numero = 0, *matriz, *produto_vetor;
     
    srand(time(NULL));
    printf("Me diga um valor inteiro\n");
    do
    {
        scanf(" %d", &numero);
    }while(numero <= 0);


    matriz = malloc(sizeof(int) * numero * numero);
    
    
    int linha = numero, coluna = numero;
    for(int i =0; i < linha; i++)
    {
        for(int j =0; j < coluna; j++)
        {
            matriz[i * coluna + j] = rand() % 11;
            printf("[%2d]", matriz[i* coluna + j]);
        }
        printf("\n");
    }
    printf("matriz gerada:\n");

    printf("vetor atual:\n");
    int vetor[numero]; 
    for(int i = 0; i < numero; i++)
    {   
        vetor[i] = rand() % 11;
        printf("[%d]", vetor[i]);
    }
    printf("\nNovo vetor baseado no produto dos dois\n");
    produto_vetor = gera_produto_vetor(numero,matriz,vetor);
    for(int i =0; i < numero; i++)
    {
        printf("[%d]",produto_vetor[i]);
    }
    printf("\n");
    free(matriz);
    free(produto_vetor);
}