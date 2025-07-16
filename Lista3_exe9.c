#include<stdio.h>
#include<stdlib.h>

int main();
char *inverte_string(char *string);

int main()
{
    char string[] = ".asnep ecov euq odut me eifnoc oaN", *string_invertida; 
    printf("%s\n", string);
    printf("Frase invertida\n");
    string_invertida = inverte_string(string);
    //tamanho da string 33 + 1;
    string_invertida = inverte_string(string);
    printf("%s\n", string_invertida);
    free(string_invertida);   
}

char *inverte_string(char *string)
{
    char *invertido = malloc(sizeof(char) * 34);
    int j = 0;
    for(int i = 33; i > 0; i--)
    {
        invertido[j] = string[i];
        j++;
    }
    invertido[j] = '\0';
    
    return invertido;
}