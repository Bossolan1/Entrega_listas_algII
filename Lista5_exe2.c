#include<stdio.h>
#include<stdlib.h>

int main()
{
int *a, *b;
printf("Me fale um valor\n");
scanf(" %d", &a);
printf("me fale outro valor\n");
scanf(" %d", &b);
if(a > b)
{
    printf("Como a está mais a frente, seu valor é %d\n", a);
}
else
{
    printf("Como a está mais b frente, seu valor é %d\n", b);
}

return 0;
}