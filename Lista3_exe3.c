#include<stdio.h>
#include<stdlib.h>

typedef struct cadastro
{
    int idade;
    char nome[100];
    char endereco[100];
} cadastro;

void escreve_cadastro(struct cadastro *cadastros, int num)
{
    printf("Nome    : %s\n", cadastros[num].nome);
    printf("Idade   : %d\n", cadastros[num].idade);
    printf("Endereco: %s\n", cadastros[num].endereco);
}

int main()
{
    int n = -1, r = 0;
    while(n < 0)
    {
        printf("Me diga um valor positivo\n");
        scanf(" %d", &n);
    }
    int tamanho = n * sizeof(cadastro);
    printf("O tamanho necessário é de: %d\n", tamanho);
    struct cadastro* cadastros = malloc(tamanho);
    printf("Preparando o vetor, de struct, prepare para cadastrar:\n");
    for(int i = 0; i < n; i++)
    {
        printf("__--- Clientr sendo cadastrado : %d ---___\n", i+ 1);
        printf("Qual o seu nome      ?\n");
        scanf(" %100[^\n]", cadastros[i].nome);
        printf("Qual é a sua idade   ?\n");
        scanf(" %d", &cadastros[i].idade);
        printf("Qual é o seu endereço?\n");
        scanf(" %100[^\n]", cadastros[i].endereco);
    }
    do{
        printf("Me fale um dos clientes, para serem lidos, 0 a %d\n", n - 1);
        scanf(" %d", &r);
        if(r >=0)
        escreve_cadastro(cadastros,r);
    }while(r >= 0);
    free(cadastros);
}