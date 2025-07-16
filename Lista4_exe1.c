#include<stdio.h>
#include<stdlib.h>

typedef struct pessoa
{
    char nome[50];
    char endereco[50];
    int  numero;
} pessoa;
int main()
{
    struct pessoa cadastro_pessoa;
    printf("Qual é o nome da possoa?\n");
    scanf(" %[^\n]", cadastro_pessoa.nome);
    printf("Qual é o endereço da possoa?\n");
    scanf(" %[^\n]", cadastro_pessoa.endereco);
    printf("Qual é o telefone da possoa?\n");
    scanf(" %d", &cadastro_pessoa.numero);
    printf("Dados a serem de cadastro:\nNome: %s\nEndereço %s\nTelefone: %d\n",cadastro_pessoa.nome, cadastro_pessoa.endereco, cadastro_pessoa.numero);
}