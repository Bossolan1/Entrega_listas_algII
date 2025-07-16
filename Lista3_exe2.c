#include<stdio.h>
#include<stdlib.h>

typedef struct dados_aluno
{
    int  numero_matricula;
    char nome[100];
    int notas[3];
};

int main()
{
    struct dados_aluno aluno;
    printf("O tamnaho é de %d\n", sizeof(aluno.numero_matricula) + sizeof(aluno.nome) + sizeof(aluno.notas));
    printf("O tamanho mais diereto é de: %d", sizeof(aluno));
}