#include<stdio.h>
#include<stdlib.h>


void cria_arquivos();
int procura_codigo(int codigo, int arquivo);
void cadastra_estacao();
void cadastra_estilista();
void cadastra_roupa();
void relatorio();

int main()
{
    int resposta = -1;
    do
    {
        printf("O que você deseja fazer?\n[1]criar arquivos\n[2]cadastrar_algo\n[0]sair\n");
        scanf(" %d", &resposta);
        switch(resposta)
        {
            case 1:
                cria_arquivos();
            break;
            case 2:
                printf("O que você deseja cadastar?\n [1] estacao\n [2] estilista\n [3] roupa\n");
                scanf( "%d",&resposta);
                switch(resposta)
                {   
                    case 1:
                        cadastra_estacao();
                        break;
                    case 2:
                        cadastra_estilista();
                        break;
                    case 3:
                        cadastra_roupa();
                    default:
                        printf("opcao invalida\n");
                        break;
                }
            break;
            default:
                printf("opção invalida!\n");
                break;
        }
    }while(resposta != 0);
}

void cria_arquivos()
{
    FILE *estacao, *roupa, *estilista;
    estacao   = fopen("estacao.csv", "r"); 
    roupa     = fopen("roupa.csv", "r");
    estilista = fopen("estilista.csv", "r");

    if(estacao == NULL)
    {
        estacao   = fopen("estacao.csv","w"); 
        if(estacao == NULL)
        {
            printf("Erro para criar os arquivo estacao!\n");
        }
        fprintf(estacao,"codigo_estacao,nome_estacao\n");
    }
    else
    {
        printf("Arquivo já estacao criado!\n");
    }

    if(roupa == NULL)
    {
        roupa   = fopen("roupa.csv","w"); 
        if(roupa == NULL)
        {
            printf("Erro para criar os arquivo estacao!\n");
        }
        fprintf(roupa,"codigo_roupa,descricao_roupa,codigo_do_estilista,codigo_da_estacao,ano\n");
    }
    else
    {
        printf("Arquivo roupa já criado!\n");
    }

    if(estilista == NULL)
    {
        estilista = fopen("estilista.csv","w");  
        if(estilista == NULL)
        {
            printf("Erro para criar os arquivo estacao!\n");
        }  
        fprintf(estilista, "codigo_estilista,nome_estilista,salario\n");
    }
    else
    {
        printf("Arquivo estilista já criado!\n");
    }
    fclose(roupa);
    fclose(estacao);
    fclose(estilista);
}

int procura_codigo(int codigo, int numero_arquivo)
{
    FILE *arquivo;
    arquivo = (numero_arquivo == 1) ? fopen("estacao.csv", "r") : (numero_arquivo == 2) ? fopen("estilista.csv", "r") : fopen("roupa.csv", "r");
    int codigo_lido = 0;
    char linha[256];
    
    
    if(arquivo == NULL)
    {
        printf("Erro para procurar o codigo no arquivo\n!");
        return -1;
    }

    fgets(linha, sizeof(linha), arquivo);

    while(fgets(linha, sizeof(linha), arquivo))
    {
        if(sscanf(linha, "%d,", &codigo_lido) == 1)
        {
        if(codigo_lido == codigo)
        {
            fclose(arquivo);
            return 1;
        }
        }
    }
    fclose(arquivo);
    return 0;
}


void cadastra_estacao()
{
    FILE *arquivo;
    int cod_estacao = 0, status = 0, tentativas = 0, ret = 0;
    char estacao[50];

    do
    {
        printf("Qual o codigo da estacao?\n");
        scanf(" %d", &cod_estacao);
        status = procura_codigo(cod_estacao, 1);
        tentativas++;
    }while((status == 1 || status == -1) && tentativas < 3);
    if(status == -1 || tentativas == 3)
    {
        printf("Não será possível prosseguir com o cadastro! erro para verificar o codigo!\n");
        return;
    }

    do
    {
        printf("Qual o nome da estacao??\n");
        ret = scanf(" %49[^\n]", estacao);
        if(ret == 0)
        {
            printf("Entrada vazia! Por favor, digite algo.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }while(ret == 0);


        
    arquivo = fopen("estacao.csv", "a");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }
    fprintf(arquivo,"%d,%s\n",cod_estacao,estacao);
    fclose(arquivo);
}


void cadastra_estilista()
{
    FILE *arquivo;
    int cod_estilista = 0, status = 0, tentativas = 0, ret = 0;
    char nome[50];
    float salario = 0;

    do
    {
        printf("Qual o codigo do estilista?\n");
        scanf(" %d", &cod_estilista);
        status = procura_codigo(cod_estilista, 2);
        tentativas++;
    }while((status == 1 || status == -1) && tentativas < 3);
    if(status == -1 || tentativas == 3)
    {
        printf("Não será possível prosseguir com o cadastro! erro para verificar o codigo!\n");
        return;
    }

    do
    {
        printf("Qual o nome do estilista??\n");
        ret = scanf(" %49[^\n]", nome);
        if(ret == 0)
        {
            printf("Entrada vazia! Por favor, digite algo.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }while(ret == 0);

    do
    {
        printf("Qual o salario do estilista?\n");
        scanf(" %f", &salario);
    }while(salario <= 0);
        
    arquivo = fopen("estilista.csv", "a");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }
    fprintf(arquivo,"%d,%s,%.2f\n",cod_estilista,nome,salario);
    fclose(arquivo);
}


void cadastra_roupa()
{
    FILE *arquivo;
    int cod_roupa = 0,cod_estilista = 0, cod_estacao = 0, ano = 0, status = 0, tentativas = 0, ret = 0;
    char descricao[50];
    do
    {
        printf("Qual o codigo da roupa\n");
        scanf(" %d", &cod_roupa);
        status = procura_codigo(cod_roupa, 3);
        tentativas++;
    }while((status == 1 || status == -1) && tentativas < 3);
    if(status == -1 || tentativas == 3)
    {
        printf("Não será possível prosseguir com o cadastro! erro para verificar o codigo!\n");
        return;
    }
    tentativas = 0;
    do
    {
        printf("Qual a descricao da roupa?\n");
        ret = scanf(" %49[^\n]", descricao);
        if(ret == 0)
        {
            printf("Entrada vazia! Por favor, digite algo.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }while(ret == 0);
    tentativas = 0;
    do
    {
        printf("Qual o codigo do estilista?\n");
        scanf(" %d", &cod_estilista);
        status = procura_codigo(cod_estilista, 2);
        tentativas++;
    }while((status == 0 || status == -1) && tentativas < 3);
    if(status == -1 || tentativas == 3)
    {
        printf("Não será possível prosseguir com o cadastro! erro para verificar o codigo!\n");
        return;
    }
    tentativas = 0;

    do
    {
        printf("Qual o codigo da estacao?\n");
        scanf(" %d", &cod_estacao);
        status = procura_codigo(cod_estacao, 1);
        tentativas++;
    }while((status == 0 || status == -1) && tentativas < 3);
    if(status == -1 || tentativas == 3)
    {
        printf("Não será possível prosseguir com o cadastro! erro para verificar o codigo!\n");
        return;
    }
    tentativas = 0;
   
    do
    {
        printf("Qual o ano da roupa?\n");
        scanf(" %d", &ano);
    }while(ano <= 0);
        
    arquivo = fopen("roupa.csv", "a");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }
    fprintf(arquivo,"%d,%s,%d,%d,%d\n",cod_roupa,descricao,cod_estilista,cod_estacao,ano);
    fclose(arquivo);
}



