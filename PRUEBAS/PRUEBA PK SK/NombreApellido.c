#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NombreApellido.h"

void initNameAndSurnameHardCoded(eCliente clientList[])
{
    int idNombre[10]= {  1, 1, 2, 5, 2, 3, 3, 4, 5, 1};
    int idApellido[10]= { 4, 2, 3, 4, 2, 2, 1, 5, 3, 1};
    int i;

    for(i=0; i<10; i++)
    {
        clientList[i].idNombre= idNombre[i];
        clientList[i].idApellido = idApellido[i];

    }

}

void showClientFullname (eNombre listaNombres[], int tamNombre, eApellido listaApellidos[], int tamApellido, eCliente listaClientes[], int tamCliente)
{
    int i, j, k;
    int idApellidoEncontrada;

    for (i=0; i < tamCliente; i++)
    {
        for(j=0; j < tamNombre; j++)
        {
            if(listaClientes[i].idNombre == listaNombres[j].idNombre)
            {
                printf("NOMBRE COMPLETO DE CLIENTE nro %d \n",listaClientes[i].idNombre);
                idApellidoEncontrada= listaClientes[i].idApellido;
                puts(listaNombres[i].nombre);

                for(k=0 ; k < tamApellido; k++)
                {
                    if(listaApellidos[j].idApellido == idApellidoEncontrada)

                    {
                        //printf("%s\n", listaApellidos[j].apellido);
                        puts(listaApellidos[j].apellido);
                    }
                }

            }


        }

    }
}



