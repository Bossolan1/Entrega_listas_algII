#include<stdio.h>
#include<stdlib.h>

void tipo_triangulo(int a, int b, int c)
{
    if((abs(b-c) < a && b + c > a) && (abs(a-c) < b && a + c > b) && (abs(a-b) < c && a + b > c))
    {
        printf("Triangulo existente do tipo: ");
        if(a == b && a == c)
        {
            printf("Equilatero\n");
        }
        if(a != b && a != c)
        {
            printf("Escaleno\n");
        }
        if((a == b && a != c) || (a == c && a != b) || (b == c && b != a))
        {
            printf("Isoceles\n");
        }
    }
    else
    {
        printf("Triangulo impossivel\n");
    }
}


int main()
{
    int x = 0, y = 0, z = 0;
    printf("Me diga o lado A\n");
    scanf("%d", &x);
    printf("Me diga o lado B\n");
    scanf("%d", &y);
    printf("me diga o lado C\n");
    scanf("%d", &z);
    tipo_triangulo(x,y,z);
return 0;
}