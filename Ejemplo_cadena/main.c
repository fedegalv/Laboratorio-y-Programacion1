#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char cadena1[10];
    char cadena2[50]="hola a todos, como estan";
    strncpy(cadena1,cadena2,9);
    printf("%s", cadena1);
    return 0;
}
