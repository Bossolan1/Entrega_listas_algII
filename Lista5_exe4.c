#include<stdio.h>
#include<stdlib.h>

int main()
{
    float matriz[3][3];
    for(int i=0; i < 3; i++)
    {
        for(int j =0; j < 3; j++)
        {
            printf("matriz[%d][%d] está na posição %p\n",i+1,j+1,matriz);
        }
    }
}