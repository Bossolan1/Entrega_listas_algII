#include<stdio.h>
#include<stdlib.h>

void escreve_texto(char a[100])
{
    printf("%s s2\n", a);
}

int main()
{
char palavra[100];
    printf("Me escreva algo\n");
    scanf("%s", palavra);
    escreve_texto(palavra);
return(0);
}