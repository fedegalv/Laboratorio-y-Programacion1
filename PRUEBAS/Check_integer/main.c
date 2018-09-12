#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    int i;
    int flag=0;
    scanf("%c",&ch);
    for(i=48; i<=57; i++)
    {
        if(ch==i) //Checking for ASCII value of entered character(chequeado el valor ASCII del caracter ingresado)
        {
            flag=1; //If it is an Integer it must have ASCII value between 48-57 (si es un int, debe tener un valor ASCII entre 48-57)
            break;
        }
    }
    if(flag==1)
        printf("Integer");
    else
        printf("Not Integer");
 // aca se intenta convertir o almacenar el int de char en otra variable
    int numero = ch;
    if (numero > 0)
    {
        numero=numero +5; // se suma 5 a la varible, pero en este caso se agrega 5 al valor ascii, ejemplo numero 2
    }
    printf("\n%d",numero);
    return 0;
}
