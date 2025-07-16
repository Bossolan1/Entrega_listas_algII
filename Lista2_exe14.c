#include<stdio.h>
#include<stdlib.h>

void cria_arquivo();
void insere_arquivo();
void imprime_medias();
int main()
{

int resposta = -1;

do
{
    printf("Digite 1 para criar o arquivo, 2 para incluir nesse arquivo, e depois ver as medias\n");
    scanf(" %d", &resposta);
    switch(resposta)
    {
        case 1:
            cria_arquivo();
            break;
        case 2:
            insere_arquivo();
            break; 
        default:
            printf("opcao invalida\n");
            break;
    }
}while(resposta != 0);
}


void cria_arquivo()
{
    FILE *arquivo;
    arquivo = fopen("arquivo.csv", "r");
    if(arquivo == NULL)
    {
        arquivo = fopen("arquivo.csv", "w");
        if(arquivo == NULL)
        {
            printf("Erro para criar o arquivo\n");
            return; 
        }
        fprintf(arquivo,"numero,nome,nota1,nota2\n");
        fclose(arquivo);  
    }
    else
    {
        printf("Arquivo já criado!\n");
        fclose(arquivo);  
    }
}

void insere_arquivo()
{
int resposta = -1;
do
{
    FILE * arquivo;
    int numero = 0, nota1 =0, nota2 = 0, ret = 0; 
    char nome[50];
    
    do
    {
        printf("Qual o numero do usuario?\n");
        scanf(" %d", &numero);
    }while(numero <= 0);
    
    
    do
    {
        printf("Qual foi a nota 1?\n");
        scanf(" %d", &nota1);
    }while(nota1 < 0);

    do
    {  
        printf("Qual foi a nota 2?\n");
        scanf(" %d", &nota2);
    }while(nota2 < 0);
    
     do
    {
        printf("Qual o nome?\n");
        ret = scanf(" %49[^\n]", nome);
        if(ret == 0)
        {
            printf("Entrada vazia! Por favor, digite algo.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }while(ret == 0);
    arquivo = fopen("arquivo.csv", "a");

    if(arquivo == NULL)
    {
        printf("Erro para abrir o arquivo\n");
        return;
    }
    fprintf(arquivo, "%d,%s,%d,%d\n",numero,nome,nota1,nota2);
    fclose(arquivo);
    printf("Deseja continuar? 1 para sim 0 para não\n");
    scanf(" %d", &resposta);
}while(resposta != 0);
imprime_medias();
}

void imprime_medias()
{
    FILE *arquivo = fopen("arquivo.csv", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return;
    }

    char linha[128];
    int numero, nota1, nota2;
    char nome[50];

    // Lê a primeira linha (cabeçalho)
    fgets(linha, sizeof(linha), arquivo);

    printf("Número | Nome                      | Nota1 | Nota2 | Média\n");
    printf("------------------------------------------------------------\n");

    while (fgets(linha, sizeof(linha), arquivo))
    {
        if (sscanf(linha, "%d,%49[^,],%d,%d", &numero, nome, &nota1, &nota2) == 4)
        {
            float media = (nota1 + nota2) / 2.0;
            printf("%6d | %-25s | %5d | %5d | %.2f\n", numero, nome, nota1, nota2, media);
        }
    }

    fclose(arquivo);
}
