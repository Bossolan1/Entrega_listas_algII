#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
typedef struct pessoa
{
    int idade;
    char nome[50];
} pessoa;

//fiquei de saco cheio de ficar escrevendo ainda mais seis vezes >:(
const char* personagens[] = {
    "Kris Light",
    "Susie Dark",
    "Ralsei Shadow",
    "Lancer Moon",
    "Noelle King",
    "Berdly Queen",
    "Spamton Knight",
    "Jevil Mage",
    "Queen Blade",
    "Rouxls Wolf",
    "Seam Flame",
    "Gaster Stone",
    "Jockington Shade",
    "Muffet Ghost",
    "Clover Spark",
    "Shyren Void",
    "Rouxls Wind",
    "Asgore Fire",
    "Toriel Hearth"
};

int main()
{
    srand(time(NULL));
    pessoa pessoas[6];
    int mais_novo = 100000, mais_velho = 0;
    for(int i =0; i < 6; i++)
    {
        const char* nome_aleatorio = personagens[rand() % (sizeof(personagens)/sizeof(personagens[0]))];
        strcpy(pessoas[i].nome, nome_aleatorio);
        pessoas[i].idade = rand()%100000;
        if(pessoas[i].idade < mais_novo)
        {
            mais_novo = pessoas[i].idade;
        }
        if(pessoas[i].idade > mais_velho)
        {
            mais_velho = pessoas[i].idade;
        }
    }
    for(int i =0; i < 6; i++)
    {
        if(mais_velho == pessoas[i].idade)
        {
            printf("%s é o mais velho!\n",pessoas[i].nome);
        }
        if(mais_novo == pessoas[i].idade)
        {
            printf("%s é o mais novo!\n",pessoas[i].nome);
        }
    }
}