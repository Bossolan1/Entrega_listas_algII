#include<stdio.h>
#include<stdlib.h>

int main()
{
    char string1[50], string2[50], *p1 = string1, *p2 = string2;
    printf("Me fale uma palavra\n");
    scanf(" %s", p1);
    printf("Me fale mais uma palavra (pode ser a mesma)\n");
    scanf(" %s", p2);
    int encontrou = 0;

    for (int i = 0; string1[i] != '\0'; i++) 
    {
        int j;
        for (j = 0; string2[j] != '\0'; j++) {
            if (*(p1 + i + j) == '\0' || *(p1 + i + j) != *(p2 + i + j)) {
                break;  
            }
        }
        if (*(p2+j) == '\0') {
            encontrou = 1;  
            break;
        }
    }

    if (encontrou) {
        printf("A segunda string ocorre dentro da primeira.\n");
    } else {
        printf("A segunda string nao ocorre dentro da primeira.\n");
    }
}