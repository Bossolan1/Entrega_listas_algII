#include<stdio.h>
#include<stdlib.h>

int main();
int *gera_matriz(int lin, int col);


int main()
{
int linha = 0, coluna = 0, *matriz;
printf("Me fale o número de linhas\n");
scanf(" %d", &linha);
printf("Me fale o número de colunas\n");
scanf(" %d", &coluna);
matriz = gera_matriz(linha , coluna);
for(int i =0; i < linha; i++)
{
    for(int j = 0; j < coluna; j++)
    {
        matriz[i*coluna+j] = 5;
    }
}
for(int i =0; i < linha; i++)
{
    for(int j = 0; j < coluna; j++)
    {
        if(i == j)
        matriz[i*coluna+j] = 0;
        if(j - 1 >= 0 && i==j)
        {
            matriz[i*coluna+(j-1)] = -1;
        }
        if(j + 1 <= coluna && i==j)
        {
            matriz[i*coluna+(j+1)] = 1;
        }
    }
}
for(int i = 0; i < linha; i++)
{
    for(int j = 0; j < coluna; j++)
    {
        printf("[ %2d ]",matriz[i*coluna+j]);
    }
    printf("\n");
}
free(matriz);
return 0 ;
}

int *gera_matriz(int lin, int col)
{
    int *matriz = malloc(lin*col*sizeof(int));
    return matriz;
}