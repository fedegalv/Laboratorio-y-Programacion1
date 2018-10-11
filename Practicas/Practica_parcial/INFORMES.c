#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#include "INFORMES.H"
void showListaClientes(sCliente cLista[], int cantidadClientes, ePublicacion listaPublicacion [], int cantidadAvisos,int tamAvisos)
{
    int i;
    int avisosActivos;
    printf("%4s %10s %10s %10s %8s %8s \n", "ID", "Nombre","Apellido", "CUIT", "ESTADO", "AVISOS ACTIVOS");

    for(i= 0; i<cantidadClientes; i++)
    {
        if (cLista[i].estado == 1)
        {
            avisosActivos=cantidadAvisosActivos(listaPublicacion,tamAvisos,i);
            printf("%4d %10s %10s %10d %8d %8d\n", cLista[i].idCliente, cLista[i].nombre,cLista[i].apellido, cLista[i].cuit, cLista[i].estado,avisosActivos);
        }
    }
}
int cantidadAvisosActivos(ePublicacion listaPublicacion[], int tamAvisos,int idProvista)
{
    int i;
    int avisosActivos;
    avisosActivos= 0;
    for(i=0; i< tamAvisos; i++)
    {
        if(listaPublicacion[i].idCliente == idProvista)
        {
            avisosActivos++;
        }
    }

    return avisosActivos;
}
