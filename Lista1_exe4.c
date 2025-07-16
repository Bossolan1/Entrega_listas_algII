#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void bhaskara(float a, float b, float c)
{
    float delta = 0, x1, x2;
    delta = sqrt((b * b) - (4 * a * c));
    if(delta >= 0)
    {
        x1 = (((-b) + delta) / 2 * a);
        printf("x1 = %f\n",x1);
        x2 = (((-b) - delta) / 2 * a);
        printf("x2 = %f\n",x2);
        printf("Se saiu um valor satânico provavelmente a raiz do delta é encapetada e eu nao vou arrumar ela s2\n");
    }
    else
    {
        printf("delta invalido, nao existem raizes (pois ele é negativo)");
    }
}


int main()
{
float a = 0, b = 0 ,c = 0;
    printf("Me diga o valor de A\n");
    scanf("%f",&a);
    printf("Me diga o valor de B\n");
    scanf("%f",&b);
    printf("Me diga o valor de C\n");
    scanf("%f",&c);
bhaskara(a, b, c);
return (0);
}