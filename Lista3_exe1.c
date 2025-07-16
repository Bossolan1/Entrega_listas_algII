#include<stdio.h>
#include<stdlib.h>

typedef struct tamanhos
{
    int inteiro;
    int caractere;
    int flutuante;
    int dobrado;
}; 

int main()
{
    struct tamanhos variaveis;
    variaveis.inteiro   = sizeof(int);
    variaveis.caractere = sizeof(char);
    variaveis.flutuante = sizeof(float);
    variaveis.dobrado   = sizeof(double);

    printf("Tamanhos das variaveis\n");
    printf("int    = %d\n", variaveis.inteiro);
    printf("char   = %d\n", variaveis.caractere);   
    printf("float  = %d\n", variaveis.flutuante);
    printf("double = %d\n", variaveis.dobrado);
}