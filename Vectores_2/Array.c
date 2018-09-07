#include <stdio.h>
#include <stdlib.h>
#include "Array.h"

void cargarVector(int vector[],int tam)
{
    char seguir;
    int posicion;
    do
    {
        fflush(stdin);
        printf("Ingrese posicion: ");
        scanf("%d",&posicion);

        printf("Ingrese un valor: ");
        scanf("%d",&vector[posicion-1]);
        fflush(stdin);
        printf("Desea seguir con el ingreso: ");
        scanf("%c",&seguir);

    }
    while(seguir == 's');
}

void mostrarVector(int miVector[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(miVector[i] != -1)
        {
            printf("%d\n",miVector[i]);
        }

    }

}
void inicializarVector(int miVector[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        miVector[i]= -1;
    }

}
int sumarValores(int miVector[],int tam )
{
    int acumulador = 0;
    int i;
    for(i=0;i<tam;i++ )
    {
        if(miVector[i] != -1)
        {
            acumulador = acumulador + miVector[i];
        }
    }
    return acumulador;
}

