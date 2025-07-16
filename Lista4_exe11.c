#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct data
{
    int dia;
    int mes;
    int ano;
}data;
int main()
{
    data datas[2];
    printf("Calculador de diferença de dias\n");
    for(int i; i < 2; i++)
    {
    printf("%d° data\n",i+1);
        printf("Dia\n");
        scanf(" %d", &datas[i].dia);
        printf("mês\n");
        scanf(" %d", &datas[i].mes);
        printf("Ano\n");
        scanf(" %d", &datas[i].ano);
    }
    int diferenca = ((datas[0].ano * 365.25) + (datas[0].mes * 30.4369) + datas[0].ano) - ((datas[1].ano * 365.25) + (datas[1].mes * 30.4369) + datas[1].ano);
    printf("Dias a parte %d\n",abs(diferenca));
    return 0;    
}