#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avisos.h"
#include "clientes.h"
#include "FuncionesAux.h"
#include "informes.h"
void mostrarMenuInformes(sClientes lista[], sAvisos listaAvisos[], int tamClientes, int tamAvisos)
{
    char opcion;
    printf("MENU INFORMES\na) Clientes con mas avisos activos\nb) Cliente con mas avisos pausados\nc) Cliente con mas avisos\nOPCION: ");
    scanf("%c", &opcion);

    switch(opcion)
    {
    case 'a':
        sCliente_MayorAvisosActivos(lista, listaAvisos, tamClientes, tamAvisos);
        break;
    case 'b':
        sCliente_MayorAvisosPausados(lista, listaAvisos, tamClientes, tamAvisos);
        break;
    case 'c':
        sCliente_ClienteConMasAvisos(lista,listaAvisos,tamClientes, tamAvisos);
        break;
    default:
        printf("OPCION INVALIDA\n");
    }
    limpiarPantalla();

}
void mostrarMenuInformesAvisos(sAvisos listaAvisos[], int tamAvisos)
{
    char opcion;
    printf("MENU INFORMES AVISOS\na) Cantidad de publicaciones de un rubro\nb) Rubro con mas publicaciones activas\nc) Rubro con menos publicaciones activas\nOPCION: ");
    scanf("%c", &opcion);

    switch(opcion)
    {
    case 'a':
        sAvisos_PublicacionesActivasPorRubro(listaAvisos, tamAvisos);
        break;
    case 'b':
        sAvisos_PublicacionesActivas(listaAvisos, tamAvisos);
        break;
    case 'c':
        sAvisos_PublicacionesMenosActivas(listaAvisos, tamAvisos);
        break;
    default:
        printf("OPCION INVALIDA\n");
    }
    limpiarPantalla();

}


void sCliente_MayorAvisosActivos(sClientes lista[], sAvisos listaAvisos[], int tamClientes, int tamAvisos)
{
    int idMayor;
    int avisosActivos=0;
    int maxAvisosActivos= 0;
    int posicionCliente;
    for(int i=0; i < tamClientes; i++)
    {
        for(int j= 0; j < tamAvisos; j++)
        {
            if(lista[i].idCliente == listaAvisos[j].idCliente && listaAvisos[j].estado == 1 && lista[i].estado == 1)
            {
                avisosActivos ++;
                //printf("i=%d j=%d avisosActivos=%d\n",i,j,avisosActivos);
            }
        }
        if(avisosActivos > maxAvisosActivos)
        {
            maxAvisosActivos= avisosActivos;
            idMayor= lista[i].idCliente;
        }
        avisosActivos= 0;

    }
    posicionCliente= posicionClientePorID(lista, tamClientes, idMayor);

    printf("El cliente con mas avisos activos es:\nNombre: %s\nNro ID: %d\nCon %d avisos\n", lista[posicionCliente].nombre, lista[posicionCliente].idCliente, maxAvisosActivos);
    limpiarPantalla();


}
void sCliente_MayorAvisosPausados(sClientes lista[], sAvisos listaAvisos[], int tamClientes, int tamAvisos)
{
    int idMayor;
    int avisosActivos=0;
    int maxAvisosActivos= 0;
    int posicionCliente;
    for(int i=0; i < tamClientes; i++)
    {
        for(int j= 0; j < tamAvisos; j++)
        {
            if(lista[i].idCliente == listaAvisos[j].idCliente && listaAvisos[j].estado == 2 && lista[i].estado == 1)
            {
                avisosActivos ++;
            }
        }
        if(avisosActivos > maxAvisosActivos)
        {
            maxAvisosActivos= avisosActivos;
            idMayor= lista[i].idCliente;
        }
        avisosActivos= 0;

    }
    posicionCliente= posicionClientePorID(lista, tamClientes, idMayor);
    if(maxAvisosActivos == 0)
    {
        printf("NO HAY AVISOS PAUSADOS\n");
    }
    else
    {
        printf("El cliente con mas avisos pausados es:\nNombre: %s\nNro ID: %d\nCon %d avisos\n", lista[posicionCliente].nombre, lista[posicionCliente].idCliente, maxAvisosActivos);
    }

    limpiarPantalla();


}

void sCliente_ClienteConMasAvisos(sClientes lista[], sAvisos listaAvisos[], int tamClientes, int tamAvisos)
{
    int idMayor;
    int avisosActivos=0;
    int maxAvisos= 0;
    int posicionCliente;
    for(int i=0; i < tamClientes; i++)
    {
        for(int j= 0; j < tamAvisos; j++)
        {
            if(lista[i].idCliente == listaAvisos[j].idCliente && listaAvisos[j].estado > 0 && lista[i].estado == 1)
            {
                //printf("i=%d j=%d avisosActivos=%d\n",i,j,avisosActivos);
                avisosActivos ++;
            }
        }
        if(avisosActivos > maxAvisos)
        {
            maxAvisos= avisosActivos;
            idMayor= lista[i].idCliente;
        }
        avisosActivos= 0;

    }
    posicionCliente= posicionClientePorID(lista, tamClientes, idMayor);
    //printf("posicion cliente = %d, Idmayor = %d\n", posicionCliente, idMayor);

    printf("El cliente con mas avisos es:\nNombre: %s\nNro ID: %d\nCon %d avisos\n", lista[posicionCliente].nombre, lista[posicionCliente].idCliente, maxAvisos);
    limpiarPantalla();
}

void sAvisos_PublicacionesActivasPorRubro(sAvisos listaAvisos[], int tamAvisos)
{
    int avisosActivos = 0;
    int nroRubro;
    printf("Ingrese numero de rubro para informar: ");
    scanf("%d", &nroRubro);
    for(int i=0; i < tamAvisos; i++)
    {
        if(listaAvisos[i].numeroRubro == nroRubro)
        {
            avisosActivos++;
        }
    }

    printf("La cantidad de publicaciones activas del rubro %d es: %d\n", nroRubro, avisosActivos);
}

void sAvisos_PublicacionesActivas(sAvisos listaAvisos[], int tamAvisos)
{
    int avisosActivos = 0;
    int avisosMayor=0;
    int rubroMayor=0;
    for(int i=0; i < tamAvisos; i++)
    {

        for(int j=i; j< tamAvisos; j++)
        {
            if( (listaAvisos[i].numeroRubro == listaAvisos[j].numeroRubro) && listaAvisos[i].estado == 1 && listaAvisos[j].estado == 1)
            {
                avisosActivos++;
            }

        }
        if(avisosActivos > avisosMayor)
        {
            rubroMayor= listaAvisos[i].numeroRubro;
            avisosMayor= avisosActivos;
        }
        avisosActivos = 0;
    }

    printf("El rubro con mas publicaciones activas es %d\nCon %d avisos\n", rubroMayor, avisosMayor);
}
void sAvisos_PublicacionesMenosActivas(sAvisos listaAvisos[], int tamAvisos)
{
    int avisosActivos = 0;
    int avisosMenor=0;
    int rubroMenor=0;
    int flag =1;
    for(int i=0; i < tamAvisos; i++)
    {

        for(int j=i; j< tamAvisos; j++)
        {
            if( (listaAvisos[i].numeroRubro == listaAvisos[j].numeroRubro) && (listaAvisos[i].estado == 1 && listaAvisos[j].estado == 1))
            {
                avisosActivos++;
            }

        }

        if(flag == 1)
        {
            rubroMenor= listaAvisos[i].numeroRubro;
            avisosMenor= avisosActivos;
            flag= 0;
        }
        else
        {
            if(avisosActivos>0 && avisosActivos < avisosMenor)
            {
                rubroMenor= listaAvisos[i].numeroRubro;
                avisosMenor= avisosActivos;
            }

        }
        avisosActivos = 0;
    }

    printf("El rubro con menos publicaciones activas es %d\nCon %d avisos\n", rubroMenor, avisosMenor);
}




