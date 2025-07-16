#include<stdio.h>
#include<stdlib.h>


int main()
{
    int *ponteiro, *ponteiro_safado;
    printf("Endereço A = %p, Endereço B = %p\n");
    if(*ponteiro > *ponteiro_safado)
    printf("ponteiro A é o maior\n");
    else
    printf("ponteiro B é o maior\n");
    return 0;
}