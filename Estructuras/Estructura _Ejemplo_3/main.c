#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void inicializarVector(int[],int,int);
int buscarLibre(int[],int,int);

int main()
{
    int array[5];
    int i;
    char seguir;
    int indice;

    inicializarVector(array,5,-1);

    do{
        indice= buscarLibre(array,5,-1);
        if(indice != -1)
        {
            printf("Ingrese un numero: ");
            scanf("%d",&array[indice]);
            printf("Ya no se encuentra lugar");
            break;
        }

        fflush(stdin);
        printf("Desea seguir: ");
        scanf("%c",&seguir);

    }while(seguir == 's');



    return 0;
}

void inicializarVector(int array[],int B, int cargaVacio)
{
    int i;
    for(i= 0; i < B; i++)
    {
        array[i] = cargaVacio;
    }

}

int buscarLibre(int array[],int B,int valor)
{
    int indice = -1;
    int i;
    for (i=0; i< B; i++)
    {
        if (array[i]== valor);
        {
            indice = i;
            break;
        }
    }

    return indice;
}
