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

    for(int i = linha - 1; i >= 0; i--)
    {
        for(int j = coluna - 1; j >= 0; j--)
        {
            matriz[i * coluna + j] = 0;
            if(i + j == coluna -1)
            {
                matriz[i*coluna+j] = 1;
            }
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