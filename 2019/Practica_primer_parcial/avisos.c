#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avisos.h"
#include "clientes.h"
#include "FuncionesAux.h"

int sAvisos_Init( sAvisos listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= 0;
            listado[i].idCliente= 0;
        }
    }
    return retorno;
}
void avisosHardcoded(sAvisos lista[])
{
    char textoAvisos[5][50]= {"TEXTO PRUEBA 1", "TEXTO PRUEBA 2", "TEXTO PRUEBA 3", "TEXTO PRUEBA 4", "TEXTO PRUEBA 5"};
    int id[5] = {1, 2, 3, 4, 3};
    int numeroAviso[5] = {2, 2, 3, 3, 5};

    for(int i=0; i < 5; i++)
    {
        lista[i].idCliente = id[i];
        lista[i].numeroRubro = numeroAviso[i];
        strcpy(lista[i].textoAviso, textoAvisos[i]);
        lista[i].estado= 1;
    }
}

int altaAviso(sAvisos lista[], sClientes listaClientes[], int tamClientes, int id)
{
    int idProvisto;
    int idEncontrada;
    printf("Ingrese ID de cliente para dar alta el aviso: ");
    idProvisto= ingresoNumero();
    idEncontrada= buscarClienteID(listaClientes, tamClientes);
    if(idEncontrada != -1)
    {
        char auxTexto[64];
        fflush(stdin);
        printf("Ingrese numero de rubro: ");
        lista[id].numeroRubro= ingresoNumero();
        printf("Ingrese texto del aviso(maximo 64 caracteres: ");
        gets(auxTexto);
        strcpy(lista[id].textoAviso, auxTexto);
        lista[id].idCliente= idProvisto;
        lista[id].estado = 1;

    }
    else
    {
        printf("ID CLIENTE NO EXISTE\n");
    }
    limpiarPantalla();
    return 0;
}
int sAvisos_buscarLugarLibre(sAvisos listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
void mostrarAvisos(sAvisos lista[], int tam)
{
    printf("%10s %10s %20s\n","ID CLIENTE","NRO RUBRO", "TEXTO AVISO");
    for(int i=0; i < tam; i++)
    {
        if(lista[i].estado == 1)
        {
            printf("%10d %10d %20s\n", lista[i].idCliente, lista[i].numeroRubro, lista[i].textoAviso);

        }
    }
    limpiarPantalla();
}

int buscarAvisosID(sAvisos lista[], int tam)
{
    int id;
    int posicionEncontrada= -1;
    printf("Ingrese id a buscar: ");
    id= ingresoNumero();
    for(int i= 0; i < tam; i++)
    {
        if(lista[i].idCliente == id && lista[i].estado == 1)
        {
            posicionEncontrada= i;
        }
    }
    return posicionEncontrada;
}
int posicionAvisoPorID(sAvisos lista[], int tam, int idProvista)
{
    int posicionEncontrada= -1;
    for(int i= 0; i < tam; i++)
    {
        if(lista[i].idCliente == idProvista && lista[i].estado == 1)
        {
            posicionEncontrada= i;
        }
    }
    return posicionEncontrada;
}
int posicionAvisoPausadosPorID(sAvisos lista[], int tam, int idProvista)
{
    int posicionEncontrada= -1;
    for(int i= 0; i < tam; i++)
    {
        if(lista[i].idCliente == idProvista && lista[i].estado == 2)
        {
            posicionEncontrada= i;
        }
    }
    return posicionEncontrada;
}
int buscarEnAvisos(sAvisos lista[], int tam)
{
    int id;
    int posicionEncontrada= -1;
    printf("Ingrese id a buscar: ");
    id= ingresoNumero();
    for(int i= 0; i < tam; i++)
    {
        if(lista[i].idCliente == id)
        {
            posicionEncontrada= i;
        }
    }
    return posicionEncontrada;
}
int pausarAviso(sAvisos lista[], sClientes listaClientes[], int tam, int tamClientes)
{
    //int posicionEncontrada = buscarAvisosID(lista, tam);
    int posicionEncontrada;
    int id;
    printf("Ingrese id a buscar: ");
    scanf("%d", &id);
    posicionEncontrada= posicionClientePorID(listaClientes, tamClientes, id);
    if(posicionEncontrada != -1)
    {
        char opcion;
        int nroRubro;
        //mostrarAvisoUnico(lista, posicionEncontrada);
        mostrarClienteUnico(listaClientes, posicionEncontrada);
        mostrarAvisosCliente(lista, id, tam, 1);
        fflush(stdin);
        printf("Que aviso/s desea pausar? Seleccion numero de rubro: ");
        scanf("%d", &nroRubro);
        fflush(stdin);
        printf("Desea pausar el aviso (S/N)?: ");
        scanf("%c", &opcion);
        switch(opcion)
        {
        case 's':
            for(int i=0; i<tam; i++)
            {
                if(nroRubro == lista[i].numeroRubro)
                {
                    lista[i].estado = 2;
                }

            }

            printf("AVISO PAUSADO\n");
            break;
        case 'n':
            printf("Cancelando..\n");
            break;
        default:
            printf("OPCION INVALIDA\n");
        }
    }
    else
    {
        printf("ID NO ENCONTRADA\n");
    }
    limpiarPantalla();
    return 0;
}
void mostrarAvisoUnico(sAvisos lista[],int posicion)
{
    printf("%5s  %8s  %24s\n", "ID CLIENTE", "NRO RUBRO", "TEXTO AVISO");
    printf("%5d  %8d  %24s\n", lista[posicion].idCliente,lista[posicion].numeroRubro,lista[posicion].textoAviso);

}
void mostrarAvisosCliente(sAvisos lista[],int id, int tam, int tipo)
{
    printf("%5s  %8s  %24s\n", "ID CLIENTE", "NRO RUBRO", "TEXTO AVISO");
    if(tipo == 2)
    {
        for(int i= 0; i < tam; i++)

        {
            if(lista[i].estado == 2 && lista[i].idCliente == id)
            {
                printf("%5d  %8d  %24s\n", lista[i].idCliente,lista[i].numeroRubro,lista[i].textoAviso);
            }

        }
    }
    if(tipo == 1)
    {
        for(int i= 0; i < tam; i++)
        {
            if(lista[i].estado == 1 && lista[i].idCliente == id)
            {
                printf("%5d  %8d  %24s\n", lista[i].idCliente,lista[i].numeroRubro,lista[i].textoAviso);
            }

        }

    }



}
int reanudarAviso(sAvisos lista[], sClientes listaClientes[], int tam, int tamClientes)
{
    int posicionEncontrada;
    int id;
    printf("Ingrese id a buscar: ");
    scanf("%d", &id);
    posicionEncontrada= posicionAvisoPausadosPorID(lista, tamClientes, id);
    if(posicionEncontrada != -1)
    {
        char opcion;
        int nroRubro;
        //mostrarAvisoUnico(lista, posicionEncontrada);
        mostrarClienteUnico(listaClientes, posicionEncontrada);
        mostrarAvisosCliente(lista, id, tam,2);
        fflush(stdin);
        printf("Que aviso/s desea reanudar? Seleccion numero de rubro: ");
        scanf("%d", &nroRubro);
        fflush(stdin);
        printf("Desea reanudar el aviso (S/N)?: ");
        scanf("%c", &opcion);
        switch(opcion)
        {
        case 's':
            for(int i=0; i<tam; i++)
            {
                if(nroRubro == lista[i].numeroRubro)
                {
                    lista[i].estado = 1;
                }

            }

            printf("AVISO REANUDADO\n");
            break;
        case 'n':
            printf("Cancelando..\n");
            break;
        default:
            printf("OPCION INVALIDA\n");
        }
    }
    else
    {
        printf("NO HAY AVISOS PAUSADOS\n");
    }
    limpiarPantalla();
    return 0;
}
