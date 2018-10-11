#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuario.h"


void inicializarUsuariosEstado(eUsuario usuarios[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        usuarios[i].estado = 0;
    }
}
void inicializarUsuariosHardCode(eUsuario usuarios[])
{
    int id[10] = {1,2,3,4,5,6,7,8,9,10};
    char nombre[10][30]= {"juan","maria","pedro","luis","romina","jose","andrea","patricia","luciano","camila"};
    int i;

    for(i=0; i<10; i++)
    {
        usuarios[i].idUsuario=id[i];
        usuarios[i].estado = 1;
        strcpy(usuarios[i].nombre, nombre[i]);

    }
}

void mostrarListaUsuarios(eUsuario usuarios[], int tam)
{
    int i;
    printf("%15s %15s\n","NOMBRE","ID USUARIO");
    for( i=0; i<tam; i++)
    {
        if(usuarios[i].estado == 1) // SE PODRIA REMOVER YA QUE POR DEFECTOS TODOS LOS ESTADOS SON INICIALIZADOS EN 1
        {
            printf("%15s %15d \n",usuarios[i].nombre, usuarios[i].idUsuario);
        }
    }

}

