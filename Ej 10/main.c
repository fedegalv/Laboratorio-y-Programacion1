#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int cantidadImpares = 0;

    for(i=0; i<=100; i++)
    {
        if( (i%3)== 0)
        {
            printf("%d\n",i);
            cantidadImpares++;
        }
    }

    printf("La cantidad de numeros impares es: %d",cantidadImpares);
    return 0;
}
