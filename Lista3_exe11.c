#include<stdio.h>
#include<stdlib.h>

int main();
int *gera_matriz(int lin, int col);

int main()
{
    int linha = 0, coluna = 0, *matriz;
    printf("Me diga o numero de linhas\n");
    scanf(" %d", &linha);
    printf("Me diga o numero de colunas\n");
    scanf(" %d", &coluna);
    matriz = gera_matriz(linha,coluna);

    for(int i = 0; i < linha; i++)
    {
        for(int j = 0; j < coluna; j++)
        {
            if(i == j)
                matriz[i*coluna+j] = 1;
            else
                matriz[i*coluna+j] = 0;

            printf("[%d]",matriz[i*coluna+j]);
        }
        printf("\n");
    }


}

int *gera_matriz(int lin, int col)
{
    int *matriz = malloc(lin * col * sizeof(int));
    return matriz;
}