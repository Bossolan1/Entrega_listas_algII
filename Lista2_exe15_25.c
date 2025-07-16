#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h> 

#define CYAN   "\033[36m"
#define RESET  "\033[0m"

void intro_logo() {
    printf(CYAN);
    printf("              ^                  ^\n");
    printf("             / \\                / \\\n");
    printf("            /   \\              /   \\\n");
    printf("           /  X  \\            /  X  \\\n");
    printf("          /  XXX  \\          /  XXX  \\\n");
    printf("         /    X    \\--------/    X    \\\n");
    printf("        (                              )\n");
    printf("       (                                )\n");
    printf("      (        U    U     U    U         )\n");
    printf("      (         U  U       U  U          )\n");
    printf("      (          UU         UU           )\n");
    printf("       (                                )\n");
    printf("         (          ------            ) \n");
    printf("                      ---                       \n");
    printf("          -----------------------------\n");
    printf("          .-..--.  .-----..  -.  .-. \n");
    printf("          | | ~~.- ._~~~~~_ | |  | | \n");
    printf("          | |.--.~ | |\\  |  `-'..`-' \n");
    printf("          | | ~~.- | | \\ |  .-.`'.-. \n");
    printf("          | |.--.~  ~___\\_~ | |  | | \n");
    printf("          `-' ~~   `-----'  `-'  `-'  \n\n");

    printf("         SISTEMA DE CADASTRO v1.3 - by L_b0x\n\n");
    printf(RESET);
    printf("Pressione ENTER para continuar...\n");
    getchar();
}


void cria_arquivo();
void cadastra_produto();
void consulta_produtos_500();
void altera_precos_15(int mais_menos);
void consulta_produtos_com_M();
void altera_precos_maiores_100_em_10(int mais_menos);
void exclui_produto();
void consulta_produtos_ate_15();
void consulta_comeca_com_X();
void deleta_produtos_maiores_200();
void menu();

int main()
{
    int resposta = 0;
    intro_logo();
    do
    {
    menu();
    printf("O que você deseja fazer?\n");
    scanf(" %d",&resposta);
        switch(resposta)
        {
            case 1:
                cria_arquivo();
                break;
            case 2:
                cadastra_produto();
                break;
            case 3:
                consulta_produtos_500();
                break;
            case 4:
                printf("Mais ou menos 15%?\n1[+]\n2[-]\n");
                scanf(" %d", &resposta);
                altera_precos_15(resposta);
                break;
            case 5:
                printf("Mais ou menos 10?\n1[+]\n2[-]\n");
                scanf(" %d", &resposta);
                altera_precos_maiores_100_em_10(resposta);
                break;
            case 6:
                consulta_produtos_com_M();
                break;
            case 7:
                exclui_produto();
                break;
            case 8:
                consulta_produtos_ate_15();
                break;
            case 9:
                consulta_comeca_com_X();
                break;
            case 10:
                deleta_produtos_maiores_200();
                break;
            case 0:
                printf("Obrigado por usar o app s2\n");
                break;
        }
    printf("Precissone enter para continuar...\n");
    getchar();
    getchar();
    system("clear");
    }while(resposta != 0);
}


void cria_arquivo()
{
    FILE *arquivo;
    arquivo = fopen("produto.csv", "r");
    if(arquivo == NULL)
    {
        arquivo = fopen("produto.csv", "w");
        if(arquivo == NULL)
        {
            printf("Erro para criar o arquivo\n");
            return; 
        }
        fprintf(arquivo,"codigo,descricao,preco\n");
        fclose(arquivo);  
    }
    else
    {
        printf("Arquivo já criado!\n");
        fclose(arquivo);  
    }
}

int procura_produto(int codigo)
{
    FILE *arquivo;
    arquivo = fopen("produto.csv", "r");
    int codigo_lido = 0;
    char linha[256];
    
    
    if(arquivo == NULL)
    {
        printf("Erro para procurar o produto no arquivo\n!");
        return -1;
    }

    fgets(linha, sizeof(linha), arquivo);

    while(fgets(linha, sizeof(linha), arquivo))
    {
        if(sscanf(linha, "%d", &codigo_lido) == 1)
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

void cadastra_produto()
{
    FILE *arquivo;
    int codigo_produto = 0, tentativas = 0, status = 0, ret = 0;
    char descricao[50];
    float valor = 0;
    do
    {
        printf("Qual o codigo do produto?\n");
        scanf(" %d", &codigo_produto);
        status = procura_produto(codigo_produto);
        tentativas++;
    }while((status == 1 || status == -1) && tentativas < 3);
    if(status == -1 || tentativas == 3)
    {
        printf("Não será possível prosseguir com o cadastro! erro para verificar o codigo!\n");
        return;
    }
    do
    {
        printf("Qual a descricao? Por favor colocar nome:bla...bla...\n");
        ret = scanf(" %49[^\n]", descricao);
        if(ret == 0)
        {
            printf("Entrada vazia! Por favor, digite algo.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }while(ret == 0);
    do
    {
        printf("Qual o valor?\n");
        scanf(" %f", &valor);
    }while(valor <= 0);

    arquivo = fopen("produto.csv","a");
    if(arquivo == NULL)
    {
        printf("falha para abrir e salvar no arquivo");
        return;
    }
    fprintf(arquivo,"%d,%s,%.2f\n",codigo_produto, descricao, valor);
    fclose(arquivo);
    printf("Produto cadastrado com sucesso!\n");
}

void consulta_produtos_500()
{
    FILE *arquivo = fopen("produto.csv", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    char linha[256];
    int codigo;
    char descricao[50];
    float preco;

    // Ignora o cabeçalho
    fgets(linha, sizeof(linha), arquivo);

    printf("\nProdutos com preço acima de R$500,00:\n");
    printf("--------------------------------------------\n");
    printf("Código | Descrição                  | Preço\n");
    printf("--------------------------------------------\n");

    int encontrou = 0;

    while (fgets(linha, sizeof(linha), arquivo))
    {
        if (sscanf(linha, "%d,%49[^,],%f", &codigo, descricao, &preco) == 3)
        {
            if (preco > 500.0f)
            {
                printf("%6d | %-25s | R$%.2f\n", codigo, descricao, preco);
                encontrou = 1;
            }
        }
    }

    if (!encontrou)
    {
        printf("Nenhum produto encontrado acima de R$500,00.\n");
    }

    printf("--------------------------------------------\n");
    fclose(arquivo);
}

void altera_precos_15(int mais_menos)
{

  if (mais_menos != 1 && mais_menos != 2)
    {
        printf("Opção inválida! Operação cancelada.\n");
        return;
    }

    FILE *arquivo = fopen("produto.csv", "r");
    FILE *temp = fopen("temp.csv", "w");

    if (arquivo == NULL || temp == NULL)
    {
        printf("Erro ao abrir arquivos para alteração.\n");
        return;
    }

    char linha[256];
    int codigo;
    char descricao[50];
    float preco;

    fgets(linha, sizeof(linha), arquivo);
    fprintf(temp, "codigo,descricao,preco\n");

    while (fgets(linha, sizeof(linha), arquivo))
    {
        if (sscanf(linha, "%d,%49[^,],%f", &codigo, descricao, &preco) == 3)
        {
            if (mais_menos == 1)
                preco *= 1.15;  
            else
                preco *= 0.85;  

            fprintf(temp, "%d,%s,%.2f\n", codigo, descricao, preco);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove("produto.csv");
    rename("temp.csv", "produto.csv");

    if (mais_menos == 1)
        printf("Todos os preços foram aumentados em 15%% com sucesso!\n");
    else
        printf("Todos os preços foram reduzidos em 15%% com sucesso!\n");
}


void altera_precos_maiores_100_em_10(int mais_menos)
{

    if (mais_menos != 1 && mais_menos != 2)
    {
        printf("Opção inválida! Operação cancelada.\n");
        return;
    }

    FILE *arquivo = fopen("produto.csv", "r");
    FILE *temp = fopen("temp.csv", "w");

    if (arquivo == NULL || temp == NULL)
    {
        printf("Erro ao abrir arquivos.\n");
        return;
    }

    char linha[256];
    int codigo;
    char descricao[50];
    float preco;

    fgets(linha, sizeof(linha), arquivo);
    fprintf(temp, "codigo,descricao,preco\n");

    while (fgets(linha, sizeof(linha), arquivo))
    {
        if (sscanf(linha, "%d,%49[^,],%f", &codigo, descricao, &preco) == 3)
        {
            if (preco > 100.0f)
            {
                if (mais_menos == 1)
                    preco += 10.0f;
                else
                {
                    preco -= 10.0f;
                    if (preco < 0) preco = 0;
                }
            }

            fprintf(temp, "%d,%s,%.2f\n", codigo, descricao, preco);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove("produto.csv");
    rename("temp.csv", "produto.csv");

    if (mais_menos == 1)
        printf("Preços acima de R$100 foram aumentados em R$10,00 com sucesso!\n");
    else
        printf("Preços acima de R$100 foram reduzidos em R$10,00 com sucesso!\n");
}

void consulta_produtos_com_M()
{
    FILE *arquivo = fopen("produto.csv", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    char linha[256];
    int codigo;
    char descricao[50];
    float preco;
    int encontrou = 0;

    fgets(linha, sizeof(linha), arquivo);

    printf("\nProdutos com 'M' ou 'm' na descrição:\n");
    printf("--------------------------------------------\n");
    printf("Código | Descrição                  | Preço\n");
    printf("--------------------------------------------\n");

    while (fgets(linha, sizeof(linha), arquivo))
    {
        if (sscanf(linha, "%d,%49[^,],%f", &codigo, descricao, &preco) == 3)
        {
            if (strpbrk(descricao, "mM") != NULL)
            {
                printf("%6d | %-25s | R$%.2f\n", codigo, descricao, preco);
                encontrou = 1;
            }
        }
    }

    if (!encontrou)
    {
        printf("Nenhum produto com 'M' ou 'm' encontrado na descrição.\n");
    }

    printf("--------------------------------------------\n");
    fclose(arquivo);
}


void exclui_produto()
{
    int codigo_excluir;
    printf("Digite o código do produto que deseja excluir: ");
    scanf(" %d", &codigo_excluir);

    FILE *arquivo = fopen("produto.csv", "r");
    FILE *temp = fopen("temp.csv", "w");

    if (arquivo == NULL || temp == NULL)
    {
        printf("Erro ao abrir arquivos.\n");
        return;
    }

    char linha[256];
    int codigo;
    char descricao[50];
    float preco;
    int encontrado = 0;

 
    fgets(linha, sizeof(linha), arquivo);
    fprintf(temp, "codigo,descricao,preco\n");

    while (fgets(linha, sizeof(linha), arquivo))
    {
        if (sscanf(linha, "%d,%49[^,],%f", &codigo, descricao, &preco) == 3)
        {
            if (codigo == codigo_excluir)
            {
                encontrado = 1;
                continue; 
            }
            fprintf(temp, "%d,%s,%.2f\n", codigo, descricao, preco);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove("produto.csv");
    rename("temp.csv", "produto.csv");

    if (encontrado)
        printf("Produto com código %d excluído com sucesso.\n", codigo_excluir);
    else
        printf("Produto com código %d não encontrado.\n", codigo_excluir);
}

void consulta_produtos_ate_15()
{
    FILE *arquivo = fopen("produto.csv", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    char linha[256];
    int codigo;
    char descricao[50];
    float preco;
    int encontrou = 0;

    fgets(linha, sizeof(linha), arquivo);

    printf("\nProdutos com preço menor ou igual a R$15,00:\n");
    printf("--------------------------------------------\n");
    printf("Código | Descrição                  | Preço\n");
    printf("--------------------------------------------\n");

    while (fgets(linha, sizeof(linha), arquivo))
    {
        if (sscanf(linha, "%d,%49[^,],%f", &codigo, descricao, &preco) == 3)
        {
            if (preco <= 15.0f)
            {
                printf("%6d | %-25s | R$%.2f\n", codigo, descricao, preco);
                encontrou = 1;
            }
        }
    }

    if (!encontrou)
    {
        printf("Nenhum produto com preço até R$15,00 foi encontrado.\n");
    }

    printf("--------------------------------------------\n");
    fclose(arquivo);
}


void consulta_comeca_com_X()
{
 char letra;
    printf("Digite a letra inicial que deseja buscar: ");
    scanf(" %c", &letra);
    letra = tolower(letra);  // torna a comparação minúscula

    FILE *arquivo = fopen("produto.csv", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    char linha[256];
    int codigo;
    char descricao[50];
    float preco;
    int encontrou = 0;

    // Ignora o cabeçalho
    fgets(linha, sizeof(linha), arquivo);

    printf("\nProdutos cuja descrição começa com '%c':\n", toupper(letra));
    printf("--------------------------------------------\n");
    printf("Código | Descrição                  | Preço\n");
    printf("--------------------------------------------\n");

    while (fgets(linha, sizeof(linha), arquivo))
    {
        if (sscanf(linha, "%d,%49[^,],%f", &codigo, descricao, &preco) == 3)
        {
            if (tolower(descricao[0]) == letra)
            {
                printf("%6d | %-25s | R$%.2f\n", codigo, descricao, preco);
                encontrou = 1;
            }
        }
    }

    if (!encontrou)
    {
        printf("Nenhum produto encontrado com essa letra inicial.\n");
    }

    printf("--------------------------------------------\n");
    fclose(arquivo);

}


void deleta_produtos_maiores_200()
{
    FILE *arquivo = fopen("produto.csv", "r");
    FILE *temp = fopen("temp.csv", "w");

    if (arquivo == NULL || temp == NULL)
    {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    char linha[256];
    int codigo;
    char descricao[50];
    float preco;
    int deletados = 0;


    fgets(linha, sizeof(linha), arquivo);
    fprintf(temp, "codigo,descricao,preco\n");

    while (fgets(linha, sizeof(linha), arquivo))
    {
        if (sscanf(linha, "%d,%49[^,],%f", &codigo, descricao, &preco) == 3)
        {
            if (preco > 200.0f)
            {
                deletados++;
                continue; 
            }

            fprintf(temp, "%d,%s,%.2f\n", codigo, descricao, preco);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove("produto.csv");
    rename("temp.csv", "produto.csv");

    if (deletados)
        printf("%d produto(s) com preço > R$200 foram excluídos.\n", deletados);
    else
        printf("Nenhum produto com preço acima de R$200 foi encontrado.\n");
}


void menu()
{
    printf("-------------------------------------\n");
    printf("|----------------Menu---------------|\n");
    printf("-------------------------------------\n");
    printf("| 1 para criar o arquivo............|\n");
    printf("| 2 para cadastrar um produto.......|\n");
    printf("| 3 para consultar produtos +500R$..|\n");
    printf("| 4 para alterar preços +/- 15%....|\n");
    printf("| 5 para alterar preços>100 em 10R$ |\n");
    printf("| 6 para consultar produtos com in M|\n");
    printf("| 7 para excluir produtos...........|\n");
    printf("| 8 para consultar produtos <= 15R$.|\n");
    printf("| 9 para consultar começa letra X...|\n");
    printf("| 10 para deltar produtos > 200R$...|\n");
    printf("| 0 para sair do programa...........|\n");
    printf("-------------------------------------\n");
}

