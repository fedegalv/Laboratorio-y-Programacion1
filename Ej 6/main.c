#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int contadorMayorCero = 0;
    int contadorMenorCero = 0;
    int i;
    for(i=0; i<10; i++)
    {
        printf("Ingrese un numero (loop nro %d): ",i+1);
        scanf("%d",&numero);
        if(numero>0)
        {
            contadorMayorCero++;
        }
        else
        {
            contadorMenorCero++;
        }
        fflush(stdin);
    }

    printf("\nCantidad de nro mayor a cero: %d",contadorMayorCero);
    printf("\nCantidad de nro maenor a cero: %d",contadorMenorCero);

    return 0;
}
