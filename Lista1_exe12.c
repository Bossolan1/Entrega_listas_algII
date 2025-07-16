#include<stdio.h>
#include<stdlib.h>

void ordena_vetor(int *var)
{
    int aux = 0;
    //*var = valor var = posicao
    for(int i = 0; i < 3; i++)
    {
        for(int j = i + 1; j < 3; j++)
        {
            if(*(var + i) > *(var + j))
            {
                aux = *(var + i);
                *(var + i) = *(var + j);
                *(var + j) = aux;
            }
        }
    }
}

int main()
{
    int valores[3];
    printf("Me diga três valores, para isso basta escrevelo, precionar enter e repetir esse processo\n");
    scanf("%d %d %d", &valores[0], &valores[1], &valores[2]);
    ordena_vetor(valores);
    printf("Esses valores em ordem crescente:\n");
    for(int i = 0; i < 3; i++)
    {
        printf("%d\n", valores[i]);
    }
    
    return 0;
}