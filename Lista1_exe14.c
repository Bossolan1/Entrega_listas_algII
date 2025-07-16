#include<stdio.h>
#include<stdlib.h>

float media(int n)
{
    int valores[n], media = 0;
    for(int i = 0; i < n; i++)
    {
        printf("Me diga o °%%d valor", i + 1);
        scanf("%d", &valores[i]);
        media += valores[i];
    }
    media /= n;
    return (media);
}

int main()
{
    float numero_exercicio_14 = 0;
    printf("me diga um numero de valores a serem somados a media\n");
    scanf("%f", &numero_exercicio_14);
    numero_exercicio_14 = midia(numero_exercicio_14);
    printf("a media eh de %.2f\n", nunero_exercicio_14);
    return 0;
}