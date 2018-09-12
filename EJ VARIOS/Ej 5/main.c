#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int cuadrado;

    printf("Ingrese numero: ");
    scanf("%d",&numero);

    if(numero > 0)
    {
        cuadrado= numero * numero;
        printf("El cuadrado del numero ingresado es: %d",cuadrado);
    }
    else
    {
        printf("ERROR, el numero debe ser mayor a 0");
    }
    return 0;
}
