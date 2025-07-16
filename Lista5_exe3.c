#include<stdio.h>
#include<stdlib.h>

int main()
{
    float vetor[10];
    for(int i = 0; i < 10;i++)
    {
        vetor[i] = 0;
        printf("O %d° valor está na posição %p\n",i+1, vetor[i]);
    }
}