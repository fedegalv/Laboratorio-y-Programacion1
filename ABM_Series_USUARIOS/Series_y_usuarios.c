#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Series_y_usuarios.h"
int buscarPorId(eUsuario listado[] , int idProvista,int limite)
{
    int retorno = -1;
    int i;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == 1 && listado[i].id == idProvista)
            {
                retorno = i;
                break;
            }
        }
    return retorno;
}
