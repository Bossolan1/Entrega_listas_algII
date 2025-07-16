#include<stdio.h>
#include<stdlib.h>

int preenche(int *vetor, int valor)
{
    int *p = vetor;
    for(int i = 0; i < 5; i++)
    {
        *(p + i) = valor;
        printf("[%d]",*(p + i));
    }
}
int main()
{
    int valor = 0, vetor[5];
    printf("Me fale um valor:\n");
    scanf("%d", &valor);
    printf("Preenchendo um vetor com esse valor:\n");
    preenche(vetor, valor);
    printf("\n");
    return 0;
}