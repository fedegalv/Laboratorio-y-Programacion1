#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int numero;
    int suma = 0;
    for(i=0;i<10;i++)
    {
        printf("Ingrese un numero %d: ",i+1);
        scanf("\n %d", &numero);
        suma = suma + numero;
    }
    printf("La suma es %d",suma);
    return 0;
}
