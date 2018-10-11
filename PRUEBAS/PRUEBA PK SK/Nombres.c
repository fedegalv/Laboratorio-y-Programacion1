#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Nombres.h"

void initNameState(eNombre listaNombres[], int lenght)
{
    int i;

    for(i=0; i<lenght; i++)
    {
        listaNombres[i].estado = 0;
    }
}

void initNamesHardCoded(eNombre listaNombres[], int lenght)
{
    int idNombre[5] = {1,2,3,4,5};
    int estado[5]= {1,1,1,1,1};
    char nombre[5][30]= {"Marina","Gonzalo","Esteban","Milton","Raul"};

    int i;

    for(i=0; i<5; i++)
    {
        listaNombres[i].idNombre = idNombre[i];
        listaNombres[i].estado = estado[i];
        strcpy(listaNombres[i].nombre, nombre[i]);
    }
}


void showNameList(eNombre nombres[],int tam)
{
    int i;
    printf("%15s %15s \n","NOMBRE", "ID");
    for( i=0; i<tam; i++)
    {
        if(nombres[i].estado == 1)  // SE PODRIA REMOVER YA QUE POR DEFECTOS TODOS LOS ESTADOS SON INICIALIZADOS EN 1
        {
            printf("%15s %15d \n",nombres[i].nombre, nombres[i].idNombre);
        }
    }


}
