#include<stdlib.h>
#include<stdio.h>

int main()
{
int tamanho = 0;
do
{
    printf("Me diga um valor maior ou igual a 0\n");
    scanf(" %d", &tamanho);
}while(tamanho < 0);

int *vetor = malloc(tamanho * sizeof(int));
for(int i = 0; i < tamanho; i++)
{
    printf("Me diga um valor >= 1 para a posição %d", i + 1);
    do
    {
        scanf(" %d", &vetor[i]);
    }while(vetor[i] < 2);    
}
printf("Vamos escrever esse vetor agora\n");
for(int i =0; i < tamanho; i++)
{
    printf("%d ", vetor[i]);
}
free(vetor);
}