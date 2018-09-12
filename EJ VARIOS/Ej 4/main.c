#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1;
    int numero2;
    int resta;

    printf("Ingrese el primero numero: ");
    scanf("\n%d",&numero1);
    printf("Ingrese el segundo numero: ");
    scanf("%d",&numero2);

    resta = numero1 + numero2;
    if(resta < 0)
    {
        printf("Resultado negativo");
    }
    else
    {
        printf("Resultado positivo");
    }
    return 0;
}
