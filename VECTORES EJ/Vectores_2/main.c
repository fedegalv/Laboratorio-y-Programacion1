#include <stdio.h>
#include <stdlib.h>
#include "Array.h"
#define T 100

int main()
{
    int suma;
    int miVector[T];
    int opcion;
    inicializarVector(miVector,T);
    do
    {
        printf("\n1 - Cargar \n2 - Mostrar \n3 - Sumar \n4 - Salir\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
                cargarVector(miVector,T);
                break;
        case 2:
            mostrarVector(miVector,T);
            break;
        case 3:
            suma = sumarValores(miVector,T);
            printf("\nLa suma es :%d\n", suma);
            break;
        case 4:
            break;

        }

    }while(opcion != 4);



    return 0;
}
