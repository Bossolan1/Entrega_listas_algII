#include<stdio.h>
#include<stdlib.h>

int main()
{
int tamanho = 0;

printf("Qual é o tamanho do vetor?\n");
scanf(" %d", &tamanho);
int *vetor = malloc(tamanho * sizeof(int));


for(int i = 0; i < tamanho; i++)
{
    printf("Me fale o %d° valor:\n",i+1);
    scanf(" %d", &vetor[i]);
}
system("clear");
printf("Seu vetor digitado:\n");
for(int i =0; i < tamanho; i++)
{
    printf("%d ",vetor[i]);
}

free(vetor);
}