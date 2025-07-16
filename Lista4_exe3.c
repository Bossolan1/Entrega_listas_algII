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
    struct coordenada pontos[2];
    for(int i =0; i < 2; i++)
    {
        printf("Qual o ponto x%d?\n",i+1);
        scanf(" %d", &pontos[i].x);
        printf("Qual o ponto y%d?\n",i+1);
        scanf(" %d", &pontos[i].y);
    }
    printf("A distancia dos pontos é de: %.3f", round(sqrt(((pontos[0].x - pontos[1].x) * (pontos[0].x - pontos[1].x)) + ((pontos[0].y - pontos[1].y) * (pontos[0].y - pontos[1].y))) * 1000) / 1000);
    return 0;
}