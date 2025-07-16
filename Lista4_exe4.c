#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct ponto
{
    int x;
    int y;
}ponto;

typedef struct retangulo
{
    ponto sup_esquerdo;
    ponto inf_direito;
}retangulo;

int main()
{
    retangulo retanguloA;
    printf("Qual é o ponto superior esquerdo?[x]&[y]\n");
    scanf(" %d %d", &retanguloA.sup_esquerdo.x, &retanguloA.sup_esquerdo.y);
    printf("Qual é o ponto inferior direito?[x]&[y]\n");
    scanf(" %d %d", &retanguloA.inf_direito.x, &retanguloA.inf_direito.y);
    printf("tamanho da diagonal:%.3f\n", round(sqrt(((retanguloA.sup_esquerdo.x - retanguloA.inf_direito.x) * (retanguloA.sup_esquerdo.x - retanguloA.inf_direito.x)) + ((retanguloA.sup_esquerdo.y - retanguloA.inf_direito.y) * (retanguloA.sup_esquerdo.y - retanguloA.inf_direito.y))) * 1000) / 1000);
    printf("Perimetro: %.2f\n",2 * (float)(abs(retanguloA.inf_direito.x - retanguloA.sup_esquerdo.x) + abs(retanguloA.inf_direito.y - retanguloA.sup_esquerdo.y)));

}