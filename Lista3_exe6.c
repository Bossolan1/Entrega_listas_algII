#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
srand(time(NULL));
//God's call holly order! knights of Jesus Crirst, charge from the temple, God's own chosen warriors Templars on the march charge from the temple mount! 
int linha = 0, coluna = 0, valor_usuario = 0, sorte = 0;
printf("Quantas linhas terá sua matriz?\n");
scanf(" %d", &linha);
printf("Quantas colunas terá a sua matriz?\n");
scanf(" %d", &coluna);
printf("Me diga um valor aleatório (entre 0 a 100)\n");
scanf(" %d", &valor_usuario);
int *matriz = malloc(linha * coluna * sizeof(int));

for(int i = 0; i < linha; i++)
{
    for(int j = 0; j < coluna; j++)
    {
        matriz[i * coluna + j] = rand() % 101;
        if(matriz[i * coluna + j] == valor_usuario)
        {
            sorte = 1;
        }
        printf("{%3d} ", matriz[i * coluna + j]);
    }
    printf("\n");
}
    printf("Gostou da sua matriz? o valor que você falou %d apareceu [1 = sim ele| 0 = não]\n", sorte);
    return 0;
free(matriz);
}