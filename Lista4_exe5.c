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
    ponto ponto_usr;
    printf("Qual é o ponto superior esquerdo?[x]&[y]\n");
    scanf(" %d %d", &retanguloA.sup_esquerdo.x, &retanguloA.sup_esquerdo.y);
    printf("Qual é o ponto inferior direito?[x]&[y]\n");
    scanf(" %d %d", &retanguloA.inf_direito.x, &retanguloA.inf_direito.y);
    printf("Agora para ficar divertido, me fale um ponto qualquer![x]&[y]\n");
    scanf(" %d %d", &ponto_usr.x , &ponto_usr.y);
    int xmin = (retanguloA.sup_esquerdo.x < retanguloA.inf_direito.x) ? retanguloA.sup_esquerdo.x : retanguloA.inf_direito.x;
    int xmax = (retanguloA.sup_esquerdo.x > retanguloA.inf_direito.x) ? retanguloA.sup_esquerdo.x : retanguloA.inf_direito.x;

    int ymin = (retanguloA.sup_esquerdo.y < retanguloA.inf_direito.y) ? retanguloA.sup_esquerdo.y : retanguloA.inf_direito.y;
    int ymax = (retanguloA.sup_esquerdo.y > retanguloA.inf_direito.y) ? retanguloA.sup_esquerdo.y : retanguloA.inf_direito.y;
    if(xmin <= ponto_usr.x && xmax >= ponto_usr.x && ymin <= ponto_usr.x && ymax >= ponto_usr.x )
    {
        printf("O ponto está dentro do retangulo\n");
    }
    else
    {
        printf("não está dentro do retangulo\n");
    }
}