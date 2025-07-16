#include<stdio.h>
#include<stdlib.h>

typedef struct data_e_hora
{
    float horas;
    float minutos;
    float segundos;
    float tot_tempo;
}data_e_hora;

int main()
{
    data_e_hora datas[5];
    float maior_qtd_tempo = 0, aux = 0;
    for(int i =0; i < 5; i++)
    {
        printf("|---qual o %d tempo a ser cadastrado?---|\n",i+1);
        printf("Qual as horas?\n");
        do{
            scanf(" %f", &datas[i].horas);
        }while(datas[i].horas >= 24);
        printf("Qual os minutos?\n");
        do{
            scanf(" %f", &datas[i].minutos);
        }while(datas[i].minutos >= 60);
        printf("Qual os segundos?\n");
        do{
            scanf(" %f", &datas[i].segundos);
        }while(datas[i].segundos >= 60);
        datas[i].tot_tempo = datas[i].horas + (datas[i].minutos / 60) + (datas[i].segundos / 3600);
        if(datas[i].tot_tempo > maior_qtd_tempo)
        {
            maior_qtd_tempo = datas[i].tot_tempo;
        }   
    }
    for(int i =0; i < 5; i++)
    {
        if(maior_qtd_tempo == datas[i].tot_tempo)
        {
            
            if(aux != 1)
                printf("Maior tempo = %f:%f:%f",datas[i].horas, datas[i].minutos, datas[i].segundos);
            else
                printf("\ne se repitiu novamente com o horario número %d", i+1);
            aux = 1;
        }
        printf("\n");
    }
return 0;
}