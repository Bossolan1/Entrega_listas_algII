#include<stdio.h>
#include<stdlib.h>

int main();
int *gera_vetor(int valor);

int main()
{
    int valor = 0, *vetor;
    printf("Me diga um valor\n");
    scanf(" %d", &valor);
    vetor = gera_vetor(valor);
    for(int i =0; i < valor; i++)
    {
        vetor[i] = i+1;
        printf("[%d] ", vetor[i]);
    }
    if(vetor == NULL)
    {
        printf("Vetor nulo ele é igual a %s\n", vetor);
    }
    else
        printf("\n");
    
    free(vetor);
}

int *gera_vetor(int valor)
{
    if(valor > 0)
    {
        int *vetor_gerado = malloc(valor * sizeof(int));
        return vetor_gerado;
    }
    else
    {
        return NULL;
    }
}