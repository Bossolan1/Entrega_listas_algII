#include<stdio.h>

int main()
{
    int a, *b, **c, ***d;
    a = 2;
    b = &a;
    c = &b;
    d = &c;
    
    printf("Valor de a: %d\n",a);
    printf("Valor de b: %d\n",(*b) * 2);
    printf("Valor de c: %d\n",(**c) * 3);
    printf("Valor de d: %d\n",(***d) * 4);
    return 0;

}