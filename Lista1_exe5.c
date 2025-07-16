#include<stdio.h>
#include<stdlib.h>

void converte_tempo(int tempo)
{
    printf("Em horas   : %.2f\n", (((float)tempo / 60) / 60));
    printf("Em minutos : %.2f\n", (float)tempo / 60);
    printf("Em segundos: %d\n", tempo);
}

int main()
{
int segundos = 0;
    printf("Me diga qual é o tempo em segundos expresso na fábrica\n");
    scanf("%d", &segundos);
    converte_tempo(segundos);
return 0;
}