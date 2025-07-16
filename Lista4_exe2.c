#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct coordenada
{
    int x;
    int y;
} coordenada; 

int main()
{
    struct coordenada pontos;
    printf("Qual o ponto x?\n");
    scanf(" %d", &pontos.x);
    printf("Qual o ponto y?\n");
    scanf(" %d", &pontos.y);
    printf("A distancia da origem é de: %.3f", round(sqrt(pontos.x * pontos.x + pontos.y * pontos.y) * 1000) / 1000);
    return 0;
}