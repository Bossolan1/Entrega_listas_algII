#include<stdlib.h>
#include<stdio.h>


void escreve_palavra_exercicio_3(char *a)
{   
    char *b=a;
    printf("%s\n",a);
    *a='O';
    a++;
    *a='K';
    a++;
    *a='\0';
    a=b;
}


int main()
{
    char palavra_exercicio_3[100];
    printf("escreva uma palavra\n");
    scanf("%s", palavra_exercicio_3);
    escreve_palavra_exercicio_3(palavra_exercicio_3);
    printf("%s\n",palavra_exercicio_3);
    return 0;
}