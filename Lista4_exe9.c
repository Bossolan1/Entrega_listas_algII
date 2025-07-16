#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
const char* atletas[] = {
    "Usain Bolt",
    "Michael Phelps",
    "Serena Williams",
    "Lionel Messi",
    "Cristiano Ronaldo",
    "Roger Federer",
    "LeBron James",
    "Simone Biles",
    "Tom Brady",
    "Novak Djokovic",
    "Rafael Nadal",
    "Marta Vieira",
    "Michael Jordan",
    "Tiger Woods",
    "Neymar Jr",
    "Nicolas Cage",      // O intruso
    "Kylian Mbappé",
    "Gabriel Medina",
    "Valentino Rossi",
    "Manny Pacquiao",
    "Lewis Hamilton",
    "Stephen Curry",
    "Kevin Durant",
    "Megan Rapinoe",
    "Alex Morgan",
    "Zinedine Zidane",
    "Kobe Bryant",
    "Diego Maradona",
    "Cristiano de Souza",
    "Lindsey Vonn",
    "Sergio Ramos"
};


const char* esportes[] = {
    "Atletismo", "Natação", "Tênis", "Futebol", "Futebol",
    "Tênis", "Basquete", "Ginástica", "Futebol Americano", "Tênis",
    "Tênis", "Futebol", "Basquete", "Golfe", "Futebol",
    "Ator", "Futebol", "Surfe", "Motovelocidade", "Boxe",
    "Fórmula 1", "Basquete", "Basquete", "Futebol", "Futebol",
    "Futebol", "Basquete", "Futebol", "Desconhecido", "Esqui Alpino",
    "Futebol"
};


typedef struct atleta
{
    char nome[100];
    char esporte[100];
    float altura;
    int idade;
} atleta;

float gerar_altura(float min, float max) {
    float r = (float) rand() / (float) RAND_MAX;
    return min + r * (max - min);
}


int main()
{
    srand(time(NULL));
    atleta lista_atleta[5];
    int mais_novo = 100000, mais_velho = 0;
    for(int i = 0; i < 5; i++)
    {
        float alturas = gerar_altura(1.40f, 2.10f); // metros
        const char* nome_aleatorio = atletas[rand() % (sizeof(atletas)/sizeof(atletas[0]))];
        strcpy(lista_atleta[i].nome, nome_aleatorio);
        const char* esporte_aleatorio = esportes[rand() % (sizeof(esportes)/sizeof(esportes[0]))];
        strcpy(lista_atleta[i].esporte, nome_aleatorio);
        lista_atleta[i].altura = alturas;
        lista_atleta[i].idade = rand() % 63;
        if(mais_novo > lista_atleta[i].idade)
        {
            mais_novo = lista_atleta[i].idade;
        }
        if(mais_velho < lista_atleta[i].idade)
        {
            mais_velho = lista_atleta[i].idade;
        }
    }
    for(int i =0; i < 6; i++)
    {
        if(mais_velho == lista_atleta[i].idade)
        {
            printf("%s é o mais velho!\n",lista_atleta[i].nome);
        }
        if(mais_novo == lista_atleta[i].idade)
        {
            printf("%s é o mais novo!\n",lista_atleta[i].nome);
        }
    }

    return 0;
}

