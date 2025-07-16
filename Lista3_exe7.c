#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int *Gera_vetor(int valor);
int main();

int main()
{
    int tamanho = 69, *vetor;
    srand(time(NULL));
    do
    {
        if(tamanho <= 0 )
        {
            printf("Caro usuário, ele deve ser maior que 0!\n");
        }
        else
        printf("Me diga um valor para o vetor\n");
        scanf(" %d", &tamanho);   
    }while(tamanho <= 0);
//dont kick the baby!
    vetor = Gera_vetor(tamanho);
    printf("Seu vetor:\n");
    for(int i =0; i < tamanho; i++)
    {
        printf("[%d] ", vetor[i]);
        
    }
    printf("\n");

    free(vetor);
    return 0;
}

int* Gera_vetor(int valor)
{
    int *vetor = malloc(valor * sizeof(int));
    for(int i =0; i < valor; i++)
    {
        vetor[i] = rand() % valor;
    }
    return (vetor); 
}
