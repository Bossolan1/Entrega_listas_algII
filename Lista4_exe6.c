#include<stdio.h>
#include<stdlib.h>

typedef struct nota
{
    int nota_1;
    int nota_2;
    int nota_3;
}nota;

typedef struct aluno
{
    int matricula;
    char nome[50];
    nota notas; 
    float media;
} aluno;



int main()
{
    float maior_media = 0; 
    aluno alunos[5];
    for(int i = 0; i < 5; i++)
    {
        printf("Qual é o número da matrícula?\n");
        scanf(" %d", &alunos[i].matricula);
        printf("Qual é o nome do aluno?\n");
        scanf(" %50[^\n]",alunos[i].nome);
        printf("Qual foi a primeira nota?\n");
        scanf(" %d", &alunos[i].notas.nota_1);
        printf("Qual foi a segunda nota?\n");
        scanf(" %d", &alunos[i].notas.nota_2);
        printf("Qual foi a terceira nota?\n");
        scanf(" %d", &alunos[i].notas.nota_3);
        alunos[i].media = (alunos[i].notas.nota_1 + alunos[i].notas.nota_2 + alunos[i].notas.nota_3) / 3;       
        if(maior_media < alunos[i].media)
        {
            maior_media = alunos[i].media;
        }
    }
        

    printf("Maior(es) média(s) dos 5 alunos\n");
        for(int i =0; i < 5; i++)
        {
            if(alunos[i].media == maior_media)
            {
                printf("Nome : %s\n", alunos[i].nome);
                printf("Media: %.2f\n", alunos[i].media);
            }
        }
}