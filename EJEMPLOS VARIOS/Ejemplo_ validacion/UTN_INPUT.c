#include <stdio.h>
#include <stdlib.h>
#include "UTN_INPUT.h"
int pedirEntero(char texto[], int min, int max)
{
    int numero;
    printf("Ingrese %s",texto);
    scanf("%d", &numero);
    numero = validarEntero(numero, texto, min, max);
    return numero;
}
int validarEntero(int numero, char texto[], int min, int max)
{
    while ( numero<min || numero>max)
    {
        printf("Reingrese %s",texto);
        scanf("%d",&numero);

    }
    return numero;

}
