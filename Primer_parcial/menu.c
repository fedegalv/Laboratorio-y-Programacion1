#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include "Automoviles.h"
#include "Propietarios.h"
#include "Funciones_aux.h"
#define VALIDO 1
#define INVALIDO 0
#define NO_ENCONTRADO -1

int altaPropietarios(sPropietario listaPropietarios[],int tam, int* cantProp)
{
    limpiarPantalla();
    int ingresoOK;
    int idDisponible=

        printf("****** MENU ALTAS PROPIETARIOS ******\n\n");
    idDisponible= obtenerIdMasAltaProp(listaPropietarios, tam, *cantProp);
    printf("ID DE PROPIETARIO NRO %d\n",idDisponible);
    ingresoOK= pedirDatos(listaPropietarios, tam, idDisponible);
    if(ingresoOK == 1)
    {
        cantProp++;
        printf("INGRESO REALIZADO CON EXITO...\n");
    }
    limpiarPantalla();
    return ingresoOK;
}

void menuModificar(sPropietario listaPropietarios[], int cantProp, int tam)
{
    int idProvista;
    int idEncontrada;
    if(cantProp >=1)
    {
        limpiarPantalla();
        printf("****** MENU DE MODIFICACIONES ******\n\n");
        mostrarListaPropietarios(listaPropietarios,tam);
        printf("INGRESE ID A MODIFICAR: ");
        idProvista= ingresoNumero();
        fflush(stdin);
        idEncontrada= buscarPropietario(listaPropietarios,tam,idProvista);
        if(idEncontrada == NO_ENCONTRADO)
        {
            printf("ID NO ENCONTRADA O VALIDA\n");
            limpiarPantalla();
        }
        else
        {
            //printf("ID ENCONTRADA");
            modificarPropietario(listaPropietarios,idEncontrada);
        }
    }
    else
    {
        printf("NO SE INGRESO NADA PARA MOSTRAR...\n");
    }
    limpiarPantalla();
}
int menuBajaPropietarios(sPropietario listaPropietarios[], sAutomovil listaAutomoviles[], int tam, int cantAutomoviles,int cantProp)
{
    int idProvista;
    int idEncontrada;
    int hayVehiculosOK;
    int importeFinal;
    char nombreProp[25];
    int bajaPropOK;
    int activos;
    activos= propietariosActivos(listaPropietarios, tam);
    if(activos >=1)
    {
        limpiarPantalla();
        printf("****** MENU BAJA DE PROPIETARIOS ******\n\n");
        mostrarListaPropietarios(listaPropietarios,tam);
        printf("INGRESE ID A DAR DE BAJA: ");
        idProvista= ingresoNumero();
        fflush(stdin);
        idEncontrada= buscarPropietario(listaPropietarios,tam,idProvista);
        if(idEncontrada == NO_ENCONTRADO)
        {
            printf("ID NO ENCONTRADA O VALIDA\n");
            limpiarPantalla();
        }
        else
        {
            //printf("ID ENCONTRADA\n");

            hayVehiculosOK= hayVehiculos(listaAutomoviles,tam);
            if(hayVehiculosOK == INVALIDO)
            {
                printf("NO HAY VEHICULOS PARA MOSTRAR\n");
                importeFinal= totalPagarPropietario(listaAutomoviles,idEncontrada,tam);
                bajaPropietarios(listaPropietarios,idEncontrada,importeFinal);\
                cantProp--;
            }
            else
            {
                mostrarNombrePropietario(listaPropietarios,idEncontrada,nombreProp);
                importeFinal= totalPagarPropietario(listaAutomoviles,idEncontrada,tam);
                bajaPropOK=bajaPropietarios(listaPropietarios,idEncontrada,importeFinal);
                if(bajaPropOK == VALIDO)
                {
                    bajaAutomoviles(listaAutomoviles,idEncontrada,tam);
                }
                cantProp--;
            }

        }
    }
    else
    {
        printf("NO SE INGRESO NADA PARA MOSTRAR...\n");
    }
    limpiarPantalla();
    return cantProp;
}

void menuMostrarListaOrdenada(sPropietario listaPropietarios[],int cantProp, int tam)
{
    if(cantProp >=1)
    {
        limpiarPantalla();
        //printf("****** LISTA PROPIETARIOS ******\n\n");
        //mostrarListaPropietarios(listaPropietarios,CANT_PROP);
        printf("****** LISTA PROPIETARIOS ORDENADA******\n\n");
        ordenarPropietarios(listaPropietarios,tam);
        mostrarListaPropietarios(listaPropietarios,tam);
    }
    else
    {
        printf("NO SE INGRESO NADA PARA MOSTRAR...\n");
    }
    limpiarPantalla();
}

void menuAltaVehiculos(sPropietario listaPropietarios[],sAutomovil listaAutomoviles[], int cantProp,int autosEstacionados)
{
    int movilOK;
    int idPropietarioAuto;
    int idEncontrada;
     do
            {
                fflush(stdin);
                limpiarPantalla();
                movilOK=INVALIDO;
                printf("****** MENU ALTAS AUTOMOVILES ******\n\n");
                mostrarListaPropietarios(listaPropietarios,cantProp);
                printf("Ingrese ID del propietario del auto: ");
                idPropietarioAuto=ingresoNumero();
                idEncontrada= buscarPropietario(listaPropietarios,cantProp,idPropietarioAuto);
                if(idEncontrada == NO_ENCONTRADO)
                {
                    printf("ID NO ENCONTRADA O VALIDA\n");
                    break;
                }
                else
                {
                    movilOK= pedirDatosAutomovil(listaAutomoviles,idEncontrada,autosEstacionados);
                    autosEstacionados++;
                    printf("AUTOMOVIL AGREGADO\n");
                }

            }
            while(movilOK == INVALIDO);
            limpiarPantalla();

}
