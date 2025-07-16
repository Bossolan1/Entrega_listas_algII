#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
    printf("Pressione ENTER para continuar...");
    getchar();
}

//exercicio 1 (cria arquivos) concluiddo!
/*
cabeçalho, arquivos:
arquivo 1 = arquivo_cliente.csv:
Cod_cliente,Nome,Endereco,Telefone
|-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|
arquivo 2 = arquivo_recebimento.csv
arquivo_recebimento.csv
Cod_recibo,Cod_cliente,Valor_recibo,Data_emisao,Data_vencimento
*/

//exercicio 2 (Cadastrar_clientes)
/*
Basicamente nesse exercicio ele quer que eu cadastre clientes!
*/
int main();
void intro_logo();
int procura_cliente(int codigo);//2 e 3
int procura_recebimento(int codigo);//2 e 3
void cadastra_cliente();//2
void cadastra_recebimento();//2
void deleta_cliente();//3
void deleta_recebimento(int codigo_cli_apagar);//3
void altera_cliente(int codigo_para_alterar);//5
void altera_recebimento();//6
void exibe_recebimentos_no_periodo(); // 7
void exibe_recebimentos_cliente(); // 8
void exibe_recebimentos_acima_valor(); // 9
void exibe_recebimentos_abaixo_valor(); // 10
void exibe_recebimentos_entre_valores(); // 11
void menu();
void cria_arquivos(int numero_arquivo); // 1
// cada numero na frente da função é o seu equivalente no exercicio yay.


int main()
{
    int resposta = -1, arquivo = 0;
    intro_logo();
    do
    {
        menu();
        scanf(" %d", &resposta);
        switch(resposta)
        {
            case 1:
                printf("Qual arquivo deseja criar? clientes[1], recebimentos[2]\n");
                scanf(" %d", &arquivo);
                cria_arquivos(arquivo);
            break;
            case 2:
                printf("Qual arquivo deseja criar? clientes[1], recebimentos[2]\n");
                scanf(" %d", &arquivo);
                switch(arquivo)
                {
                    case 1:
                        cadastra_cliente();
                    break;
                    case 2:
                        cadastra_recebimento();
                    break;
                    default:
                        printf("Arquivo invalido!\n");
                    break;
                }
            break;
            case 3:
                printf("Qual arquivo você deseja apagar? clientes[1], recebimentos[2]\n");
                scanf(" %d", &arquivo);
                switch(arquivo)
                {
                   case 1:
                        deleta_cliente();
                        break;
                    case 2:
                        deleta_recebimento(0);
                        break;
                    default:
                        printf("Opção invalida\n");
                        break;
                }
            break;
            case 4:
                printf("Qual arquivo você deseja alterar? clientes[1], recebimentos[2]\n");
                scanf(" %d", &arquivo);
                switch(arquivo)
                {
                   case 1:
                        int codigo = 0;
                        printf("Qual o codigo?\n");
                        scanf(" %d", &codigo);
                        altera_cliente(codigo);
                        break;
                    case 2:
                        altera_recebimento();
                        break;
                    default:
                        printf("Opção invalida\n");
                        break;
                }
            break;
            case 5:
                printf("Que que você deseja procurar? 1[recibos dentro de um periodo de tempo]\n2[Recebimentos de um cliente X]\n3[exibir recibos acima de um valor]\n4[abaixo de um valor x]\n5[Para exibir entre dois valores]\n");
                scanf(" %d", &resposta);
                switch(resposta)
                {
                    case 1:
                        exibe_recebimentos_no_periodo();
                    break;
                    case 2:
                        exibe_recebimentos_cliente();
                    break;
                    case 3:
                        exibe_recebimentos_acima_valor();
                    break;
                    case 4:
                        exibe_recebimentos_abaixo_valor();
                    break;
                    case 5:
                        exibe_recebimentos_entre_valores();
                    default:
                        printf("Opcao invalida!\n");
                    break;
                }
            default:
                printf("Respsota inválida, escreva novamente!\n");
                break;
            case 0:
                printf("Obrigado por usar o software s2\n");
                break;
        }
        printf("Pressione Enter para continuar...");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        getchar();
        system("clear");
    }while(resposta != 0);
return 0;
}

void menu()
{
    printf("-------------------------------------\n");
    printf("|----------------Menu---------------|\n");
    printf("-------------------------------------\n");
    printf("| 1 para criar os arquivos..........|\n");
    printf("| 2 para cadastrar em um arquivo....|\n");
    printf("| 3 para apagar em um arquivo.......|\n");
    printf("| 4 para editar em um arquivo.......|\n");
    printf("| 5 para procurar em um arquivo.....|\n");
    printf("| 0 para sair do programa...........|\n");
    printf("-------------------------------------\n");
}
//exercicio 1
void cria_arquivos(int numero_arquivo)
{
    FILE *arquivo;
    char linha[256];
    if(numero_arquivo != 1 && numero_arquivo != 2)
    {
        printf("Numero arquivo invalido\n");
        return;
    }
    arquivo = (numero_arquivo == 1) ? fopen("arquivo_cliente.csv", "r") : fopen("arquivo_recebimento.csv", "r");
    if(arquivo == NULL)
    {
        arquivo = (numero_arquivo == 1) ? fopen("arquivo_cliente.csv", "w") : fopen("arquivo_recebimento.csv", "w");
        if(arquivo == NULL)
        {
            printf("Erro para criar o arquivo\n");
            return;
        }
        if(numero_arquivo == 1)
        {
            fprintf(arquivo,"Cod_cliente,Nome,Endereco,Telefone\n");
        }
        if(numero_arquivo == 2)
        {
            fprintf(arquivo,"Cod_recibo,Cod_cliente,Valor_recibo,Data_emissao,Data_vencimento\n");
        }
        fclose(arquivo);
    }
    else
    {
        printf("O arquivo já existe!\n");
        fclose(arquivo);
    }
}
//exercicio 2 && funcao para o 3

int procura_cliente(int codigo)
{
    FILE *arquivo;
    arquivo = fopen("arquivo_cliente.csv", "r");
    int codigo_lido = 0;
    char linha[256];
    
    
    if(arquivo == NULL)
    {
        printf("Erro para procurar o cliente no arquivo\n!");
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

int procura_recebimento(int codigo)
{
    FILE *arquivo;
    arquivo = fopen("arquivo_recebimento.csv", "r");
    int codigo_lido = 0;
    char linha[256];
    
    
    if(arquivo == NULL)
    {
        printf("Erro para procurar o recebimento no arquivo\n!");
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
void cadastra_cliente()
{
    FILE *arquivo;
    int cod_cliente = 0, telefone = 0, ret = 0, status = 0, tentativas = 0;
    char nome[50], endereco[50]; 
    arquivo = fopen("arquivo_cliente.csv", "r");
    if(arquivo == NULL)
    {
        printf("O arquivo não foi criado, ou foi deletado, por favor selecione a opção 1 para prosseguir\n");
        return;
    }
    fclose(arquivo);


    do
    {
        printf("Qual o codigo do cliente?\n");
        scanf(" %d", &cod_cliente);
        status = procura_cliente(cod_cliente);
        tentativas++;
    }while((status == 1 || status == -1) && tentativas < 3);
    if(status == -1 || tentativas == 3)
    {
        printf("Não será possível prosseguir com o cadastro! erro para verificar o codigo!\n");
        return;
    }
    do
    {
        printf("Qual o nome do cliente?\n");
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
        printf("Qual o endereço do cliente?\n");
        ret = scanf(" %49[^\n]", endereco);
        if(ret == 0)
        {
            printf("Entrada vazia! Por favor, digite algo.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }while(ret == 0);
    
    
    do
    {
        printf("Qual o telefone do cliente?\n");
        scanf(" %d", &telefone);

    }while(telefone <= 0);
    
    arquivo = fopen("arquivo_cliente.csv", "a");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }
    fprintf(arquivo,"%d,%s,%s,%d\n",cod_cliente,nome,endereco,telefone);

    fclose(arquivo);
}

//exercicio 3 cadastra recebimento

void cadastra_recebimento()
{
 FILE *arquivo;
    int cod_recebimento = 0, cod_cliente = 0,data_emissao[3], data_vencimento[3], status = 0, tentativas = 0; 
    float valor = 0;
    arquivo = fopen("arquivo_recebimento.csv", "r");
    if(arquivo == NULL)
    {
        printf("O arquivo não foi criado, ou foi deletado, por favor selecione a opção 1 para prosseguir\n");
        return;
    }
    fclose(arquivo);

    do
    {
        printf("Qual o codigo do cliente?\n");
        scanf(" %d", &cod_cliente);
        status = procura_cliente(cod_cliente);
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
        printf("Qual o codigo do recebimento\n");
        scanf(" %d", &cod_recebimento);
        status = procura_recebimento(cod_recebimento);
        tentativas++;
    }while((status == 1 || status == -1) && tentativas < 3);
    if(status == -1 || tentativas == 3)
    {
        printf("Não será possível prosseguir com o cadastro! erro para verificar o codigo!\n");
        return;
    }

    do
    {
        printf("Qual o valor do recebimento?\n");
        scanf(" %f", &valor);
    }while(valor <= 0);
    //data lançamento
    for(int i =0; i < 3; i++)
    {
        if(i == 0)
        {
            do
            {
                printf("Qual é o dia de hoje?\n");
                scanf(" %d", &data_emissao[i]);
            }while(data_emissao[0] < 1 || data_emissao[0] > 31);
        }
        if(i == 1)
        {
            do
            {
                printf("Qual o mes atual?\n");
                scanf(" %d", &data_emissao[i]);
            }while(data_emissao[1] < 1 || data_emissao[1] > 12);
        }
        if(i == 2)
        {
            do
            {
                printf("Qual o ano atual?\n");
                scanf(" %d", &data_emissao[i]);
            }while(data_emissao[2] <= 0);
        }
    }

    //data vencimento
    for(int i =0; i < 3; i++)
    {
        if(i == 0)
        {
            do
            {
                printf("Qual a data de vencimento?\n");
                scanf(" %d", &data_vencimento[i]);
            }while(data_vencimento[0] < 1 || data_vencimento[0] > 31);
        }
        if(i == 1)
        {
            do
            {
                printf("Qual o mes do vencimento\n");
                scanf(" %d", &data_vencimento[i]);
            }while(data_vencimento[1] < 1 || data_vencimento[1] > 12);
        }
        if(i == 2)
        {
            do
            {
                printf("Qual o ano data do vencimento\n");
                scanf(" %d", &data_vencimento[i]);
            }while(data_vencimento[2] <= 0);
        }
    }

    arquivo = fopen("arquivo_recebimento.csv", "a");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }
    fprintf(arquivo,"%d,%d,%.2f,%d/%d/%d,%d/%d/%d\n",cod_recebimento,cod_cliente,valor,data_emissao[0],data_emissao[1],data_emissao[2],data_vencimento[0],data_vencimento[1],data_vencimento[2]);

    fclose(arquivo);
}

//exercicio 4, deletar cliente/recebimento

void deleta_cliente()
{
    FILE *arquivo, *temp;
    int cod_para_apagar = 0, cod_lido = 0;
    char nome[50], endereco[50], linha[256];
    int telefone = 0;
    int status = 0;

    printf("Qual cliente você deseja apagar?\n");
    scanf(" %d", &cod_para_apagar);

    arquivo = fopen("arquivo_cliente.csv", "r");
    temp = fopen("temp.csv", "w");

    if (arquivo == NULL || temp == NULL) 
    {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    if(fgets(linha,sizeof(linha),arquivo))
    {
        fputs(linha,temp);
    }

    while (fgets(linha, sizeof(linha), arquivo)) 
    {
        if (sscanf(linha, "%d,%49[^,],%49[^,],%d", &cod_lido, nome, endereco, &telefone) == 4) 
        {
            if (cod_lido == cod_para_apagar) 
            {
                status = 1;  
                continue;    
            }
            fputs(linha, temp);
        }
    }

    fclose(arquivo);
    fclose(temp);

    deleta_recebimento(cod_para_apagar); 

    if (status) 
    {
        remove("arquivo_cliente.csv");
        rename("temp.csv", "arquivo_cliente.csv");
        printf("Cliente %d foi apagado com sucesso.\n", cod_para_apagar);
    } 
    else 
    {
        remove("temp.csv");
        printf("Cliente %d não encontrado.\n", cod_para_apagar);
    }
}


void deleta_recebimento(int codigo_cli_apagar)
{
    FILE *arquivo, *temp2;
    int cod_para_apagar = codigo_cli_apagar, cod_lido;
    float valor;
    int dia_emissao, mes_emissao, ano_emissao;
    int dia_venc, mes_venc, ano_venc;
    char linha[256];
    int achou = 0;

    if(codigo_cli_apagar == 0)
    {
        printf("Digite o código do recebimento que deseja apagar:\n");
        scanf(" %d", &cod_para_apagar);
    }
    
    arquivo = fopen("arquivo_recebimento.csv", "r");
    temp2 = fopen("temp2.csv", "w");

    if (arquivo == NULL || temp2 == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    if (fgets(linha, sizeof(linha), arquivo)) {
        fputs(linha, temp2);
    }

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "%d", &cod_lido) == 1) {
            if (cod_lido == cod_para_apagar) {
                achou = 1;
                continue; 
            }
            fputs(linha, temp2);
        }
    }

    fclose(arquivo);
    fclose(temp2);

    if (achou) {
        remove("arquivo_recebimento.csv");
        rename("temp2.csv", "arquivo_recebimento.csv");
        printf("Recebimento %d foi apagado com sucesso.\n", cod_para_apagar);
    } else {
        remove("temp2.csv");
        printf("Recebimento %d não encontrado.\n", cod_para_apagar);
    }
}


void altera_cliente(int codigo_para_alterar) {
    FILE *arquivo, *temp;
    char linha[256];
    int cod_lido;
    char nome[50], endereco[50];
    int telefone;
    int achou = 0;

    arquivo = fopen("arquivo_cliente.csv", "r");
    temp = fopen("temp.csv", "w");
    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir arquivos.\n");
        return;
    }

    if (fgets(linha, sizeof(linha), arquivo)) {
        fputs(linha, temp);
    }

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "%d,%49[^,],%49[^,],%d", &cod_lido, nome, endereco, &telefone) == 4) {
            if (cod_lido == codigo_para_alterar) {
                achou = 1;
                printf("Digite o novo nome: ");
                scanf(" %49[^\n]", nome);
                printf("Digite o novo endereco: ");
                scanf(" %49[^\n]", endereco);
                printf("Digite o novo telefone: ");
                scanf(" %d", &telefone);

                fprintf(temp, "%d,%s,%s,%d\n", cod_lido, nome, endereco, telefone);
            } else {
                fputs(linha, temp);
            }
        }
    }

    fclose(arquivo);
    fclose(temp);

    if (achou) {
        remove("arquivo_cliente.csv");
        rename("temp.csv", "arquivo_cliente.csv");
        printf("Cliente %d alterado com sucesso.\n", codigo_para_alterar);
    } else {
        remove("temp.csv");
        printf("Cliente %d não encontrado.\n", codigo_para_alterar);
    }
}


void altera_recebimento()
{
    FILE *arquivo, *temp;
    char linha[256];
    int cod_lido, cod_para_alterar;
    int cod_cliente, dia_emis, mes_emis, ano_emis, dia_venc, mes_venc, ano_venc;
    float valor;
    int achou = 0;

    printf("Digite o código do recibo a alterar: ");
    scanf(" %d", &cod_para_alterar);

    arquivo = fopen("arquivo_recebimento.csv", "r");
    temp = fopen("temp_recebimento.csv", "w");
    if (arquivo == NULL || temp == NULL)
    {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    if (fgets(linha, sizeof(linha), arquivo))
        fputs(linha, temp);

    while (fgets(linha, sizeof(linha), arquivo))
    {
        if (sscanf(linha, "%d,%d,%f,%d/%d/%d,%d/%d/%d",
                   &cod_lido, &cod_cliente, &valor,
                   &dia_emis, &mes_emis, &ano_emis,
                   &dia_venc, &mes_venc, &ano_venc) == 9)
        {
            if (cod_lido == cod_para_alterar)
            {
                achou = 1;
                printf("Digite o novo código do cliente: ");
                scanf(" %d", &cod_cliente);
                printf("Digite o novo valor do recibo: ");
                scanf(" %f", &valor);

                printf("Digite a nova data de emissão (dia mes ano): ");
                scanf(" %d %d %d", &dia_emis, &mes_emis, &ano_emis);

                printf("Digite a nova data de vencimento (dia mes ano): ");
                scanf(" %d %d %d", &dia_venc, &mes_venc, &ano_venc);

                fprintf(temp, "%d,%d,%.2f,%02d/%02d/%04d,%02d/%02d/%04d\n",
                        cod_lido, cod_cliente, valor,
                        dia_emis, mes_emis, ano_emis,
                        dia_venc, mes_venc, ano_venc);
            }
            else
            {
                fputs(linha, temp);
            }
        }
        else
        {
            fputs(linha, temp);
        }
    }

    fclose(arquivo);
    fclose(temp);

    if (achou)
    {
        remove("arquivo_recebimento.csv");
        rename("temp_recebimento.csv", "arquivo_recebimento.csv");
        printf("Recibo %d alterado com sucesso.\n", cod_para_alterar);
    }
    else
    {
        remove("temp_recebimento.csv");
        printf("Recibo %d não encontrado.\n", cod_para_alterar);
    }
}


int data_para_int(int dia, int mes, int ano) {
    return ano * 10000 + mes * 100 + dia;
}

void exibe_recebimentos_no_periodo()
{
    FILE *arquivo;
    char linha[256];
    int dia, mes, ano;
    int dia_inicio, mes_inicio, ano_inicio;
    int dia_fim, mes_fim, ano_fim;
    int cod_recibo, cod_cliente;
    float valor;
    int dia_emis, mes_emis, ano_emis;
    int dia_venc, mes_venc, ano_venc;

    printf("Digite a data inicial (dia mes ano): ");
    scanf(" %d %d %d", &dia_inicio, &mes_inicio, &ano_inicio);

    printf("Digite a data final (dia mes ano): ");
    scanf(" %d %d %d", &dia_fim, &mes_fim, &ano_fim);

    int data_inicio_int = data_para_int(dia_inicio, mes_inicio, ano_inicio);
    int data_fim_int = data_para_int(dia_fim, mes_fim, ano_fim);

    arquivo = fopen("arquivo_recebimento.csv", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    if (fgets(linha, sizeof(linha), arquivo) == NULL)
    {
        printf("Arquivo vazio.\n");
        fclose(arquivo);
        return;
    }

    printf("Recibos no período de %02d/%02d/%04d até %02d/%02d/%04d:\n",
           dia_inicio, mes_inicio, ano_inicio,
           dia_fim, mes_fim, ano_fim);

    int encontrou = 0;
    while (fgets(linha, sizeof(linha), arquivo))
    {
        if (sscanf(linha, "%d,%d,%f,%d/%d/%d,%d/%d/%d",
                   &cod_recibo, &cod_cliente, &valor,
                   &dia_emis, &mes_emis, &ano_emis,
                   &dia_venc, &mes_venc, &ano_venc) == 9)
        {
            int data_venc_int = data_para_int(dia_venc, mes_venc, ano_venc);

            if (data_venc_int >= data_inicio_int && data_venc_int <= data_fim_int)
            {
                encontrou = 1;
                printf("Recibo: %d | Cliente: %d | Valor: %.2f | Emissão: %02d/%02d/%04d | Vencimento: %02d/%02d/%04d\n",
                       cod_recibo, cod_cliente, valor,
                       dia_emis, mes_emis, ano_emis,
                       dia_venc, mes_venc, ano_venc);
            }
        }
    }
    if (!encontrou)
    {
        printf("Nenhum recebimento encontrado nesse período.\n");
    }

    fclose(arquivo);
}


void exibe_recebimentos_cliente() {
    FILE *arquivo;
    int cod_cliente, cod_lido;
    int cod_recibo;
    float valor;
    char data_emissao[20], data_vencimento[20];
    char linha[256];
    int achou = 0;

    printf("Digite o código do cliente: ");
    scanf(" %d", &cod_cliente);

    arquivo = fopen("arquivo_recebimento.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de recebimentos.\n");
        return;
    }

    if (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "%d,%d,%f,%19[^,],%19[^\n]",
                   &cod_recibo, &cod_lido, &valor, data_emissao, data_vencimento) == 5) {
            if (cod_lido == cod_cliente) {
                printf("%d,%d,%.2f,%s,%s\n", cod_recibo, cod_lido, valor, data_emissao, data_vencimento);
                achou = 1;
            }
        }
    }

    fclose(arquivo);

    if (!achou) {
        printf("Nenhum recebimento encontrado para o cliente %d.\n", cod_cliente);
    }
}


void exibe_recebimentos_acima_valor() {
    FILE *arquivo;
    int cod_recibo, cod_cliente;
    float valor, valor_min;
    char data_emissao[20], data_vencimento[20];
    char linha[256];
    int achou = 0;

    printf("Digite o valor mínimo: ");
    scanf(" %f", &valor_min);

    arquivo = fopen("arquivo_recebimento.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de recebimentos.\n");
        return;
    }

    if (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "%d,%d,%f,%19[^,],%19[^\n]",
                   &cod_recibo, &cod_cliente, &valor, data_emissao, data_vencimento) == 5) {
            if (valor >= valor_min) {
                printf("%d,%d,%.2f,%s,%s\n", cod_recibo, cod_cliente, valor, data_emissao, data_vencimento);
                achou = 1;
            }
        }
    }

    fclose(arquivo);

    if (!achou) {
        printf("Nenhum recebimento encontrado com valor acima de %.2f.\n", valor_min);
    }
}


void exibe_recebimentos_abaixo_valor()
{
    FILE *arquivo;
    int cod_recibo, cod_cliente;
    float valor, valor_min;
    char data_emissao[20], data_vencimento[20];
    char linha[256];
    int achou = 0;

    printf("Digite o valor máximo: ");
    scanf(" %f", &valor_min);

    arquivo = fopen("arquivo_recebimento.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de recebimentos.\n");
        return;
    }

    if (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "%d,%d,%f,%19[^,],%19[^\n]",
                   &cod_recibo, &cod_cliente, &valor, data_emissao, data_vencimento) == 5) {
            if (valor <= valor_min) {
                printf("%d,%d,%.2f,%s,%s\n", cod_recibo, cod_cliente, valor, data_emissao, data_vencimento);
                achou = 1;
            }
        }
    }

    fclose(arquivo);

    if (!achou) {
        printf("Nenhum recebimento encontrado com valor abaixo de %.2f.\n", valor_min);
    }
}


void exibe_recebimentos_entre_valores() 
{
    FILE *arquivo;
    int cod_recibo, cod_cliente;
    float valor, valor_min, valor_max;
    char data_emissao[20], data_vencimento[20];
    char linha[256];
    int achou = 0;

    printf("Digite o valor mínimo: ");
    scanf(" %f", &valor_min);

    printf("Digite o valor máximo: ");
    scanf(" %f", &valor_max);

    if (valor_min > valor_max) {
        float temp = valor_min;
        valor_min = valor_max;
        valor_max = temp;
    }

    arquivo = fopen("arquivo_recebimento.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de recebimentos.\n");
        return;
    }

    if (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "%d,%d,%f,%19[^,],%19[^\n]",
                   &cod_recibo, &cod_cliente, &valor, data_emissao, data_vencimento) == 5) {
            if (valor >= valor_min && valor <= valor_max) {
                printf("%d,%d,%.2f,%s,%s\n", cod_recibo, cod_cliente, valor, data_emissao, data_vencimento);
                achou = 1;
            }
        }
    }

    fclose(arquivo);

    if (!achou) {
        printf("Nenhum recebimento encontrado entre %.2f e %.2f.\n", valor_min, valor_max);
    }
}
