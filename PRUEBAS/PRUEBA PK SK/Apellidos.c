#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Apellidos.h"

void initSurnamesState(eApellido listaApellidos[], int length)
{
    int i;

    for(i=0; i<length; i++)
    {
        listaApellidos[i].estado = 0;
    }
}
void initSurnamesHardCoded(eApellido listaApellidos[], int lenght)
{
    int idApellido[5] = {1,2,3,4,5};
    int estado[5]= {1,1,1,1,1};
    char apellido[5][30]= {"Galena","Perez","Galvan","Garcia","Stolker"};

    int i;

    for(i=0; i<5; i++)
    {
        listaApellidos[i].idApellido = idApellido[i];
        listaApellidos[i].estado = estado[i];
        strcpy(listaApellidos[i].apellido, apellido[i]);
    }
}
void showSurnameList(eApellido apellidos[],int tam)
{
    int i;
    printf("%15s %15s \n","APELLIDO", "ID");
    for( i=0; i<tam; i++)
    {
        if(apellidos[i].estado == 1)  // SE PODRIA REMOVER YA QUE POR DEFECTOS TODOS LOS ESTADOS SON INICIALIZADOS EN 1
        {
            printf("%15s %15d \n",apellidos[i].apellido, apellidos[i].idApellido);
        }
    }
}
