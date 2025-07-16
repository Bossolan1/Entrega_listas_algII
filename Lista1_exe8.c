#include<stdio.h>
#include<stdlib.h>

int define_categoria(int idade)
{
    if(idade <= 4)
    return 0;
    if(idade >= 5 && idade <= 7)
    return 1;
    if(idade >= 8 && idade <= 10)
    return 2;
    if(idade >= 11 && idade <= 13)
    return 3;
    if(idade >= 14 && idade <= 17)
    return 4;
    if(idade >= 18)
    return 5;
}

void tabela()
{
    system("clear");
    printf("     Tabela      categoria  \n");
    printf("|------------------------------|\n");
    printf("|    Idade    |  Categoria     |\n");
    printf("|  5    a   7 | infaltil A[1]  |\n");
    printf("|  8    a  10 | infaltil B[2]  |\n");
    printf("|  11   a  13 | juvenill A[3]  |\n");
    printf("|  14   a  17 | juvenill B[4]  |\n");
    printf("|  18   a  xx | Adulto    [5]  |\n");
    printf("|------------------------------|\n");
}

int main()
{
int idade = 0, categoria = 0;
    printf("Me diga a sua idade, nadador?\n");
    scanf("%d", &idade);
    categoria = define_categoria(idade);
    tabela();
    printf("Sua categoria eh = %d\n", categoria);   
return (0);
}