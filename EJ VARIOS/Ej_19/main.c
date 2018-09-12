#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int i;
    int acumulador = 0;

    printf("Ingrese un numero: ");
    scanf("%d",&numero);
    for(i=0;i<=numero;i++)
    {
        acumulador= acumulador + i;
    }
    printf("La suma fue de : %d",acumulador);
    return 0;
}
