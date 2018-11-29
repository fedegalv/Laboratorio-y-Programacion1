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
            modificarPropietario(listaPropietarios,idProvista, tam);
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
            printf("ID ENCONTRADA\n");

            hayVehiculosOK= hayVehiculos(listaAutomoviles,tam);
            if(hayVehiculosOK == INVALIDO)
            {
                printf("NO HAY VEHICULOS PARA MOSTRAR\n");
                importeFinal= totalPagarPropietario(listaAutomoviles,idProvista,tam);
                bajaPropietarios(listaPropietarios, idProvista, importeFinal, tam);
                cantProp--;
            }
            else
            {
                mostrarNombrePropietario(listaPropietarios, idProvista, nombreProp);
                importeFinal= totalPagarPropietario(listaAutomoviles, idProvista, tam);
                bajaPropOK=bajaPropietarios(listaPropietarios, idProvista, importeFinal, tam);
                if(bajaPropOK == VALIDO)
                {
                    bajaAutomoviles(listaAutomoviles,idProvista,tam);
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
    if(propietariosActivos(listaPropietarios, tam) >=1)
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

int menuAltaVehiculos(sPropietario listaPropietarios[],sAutomovil listaAutomoviles[], sAutomovil historialAutos[] ,int cantProp,int autosEstacionados, int maxAutos, int* pCantHistorial)
{
    int movilOK;
    int idPropietarioAuto;
    int idEncontrada;
    if(propietariosActivos(listaPropietarios,cantProp) >=1)

    {


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
                movilOK= pedirDatosAutomovil(listaAutomoviles, historialAutos,idPropietarioAuto,maxAutos, *pCantHistorial);
                autosEstacionados++;
                printf("AUTOMOVIL AGREGADO\n");
            }

        }
        while(movilOK == INVALIDO);
    }
    else{printf("NO SE INGRESO NADA PARA MOSTRAR O NO HAY VEHICULOS PARA MOSTRAR...\n");}
    limpiarPantalla();
    return autosEstacionados;

}

void menuBajaVehiculos(sPropietario listaPropietarios[], sAutomovil listaAutomoviles[], int maxVehiculos, int maxProp)
{
    int estadiaOK;
    int idPropietarioAuto;
    int idEncontrada;
    int hayVehiculosPropOK;
    char nombreProp[25];
    if(hayVehiculos(listaAutomoviles,maxVehiculos ) >=1)
    {
        do
        {
            limpiarPantalla();
            estadiaOK=INVALIDO;
            printf("******MENU EGRESO DE AUTOS******\n\n");
            mostrarListaPropietarios(listaPropietarios,maxProp);
            printf("Ingrese ID del propietario del auto: ");
            //printf("Para volver al menu principal escriba -1 ");
            idPropietarioAuto=ingresoNumero();
            idEncontrada= buscarPropietario(listaPropietarios,maxProp,idPropietarioAuto);
            if(idEncontrada == NO_ENCONTRADO)
            {
                printf("ID NO ENCONTRADA O VALIDA\n");
                estadiaOK = 1;
                break;
            }
            else
            {
                hayVehiculosPropOK= hayVehiculoEnPropietario(listaAutomoviles,maxVehiculos,idPropietarioAuto);
                if(hayVehiculosPropOK == VALIDO)
                {
                    mostrarNombrePropietario(listaPropietarios,idPropietarioAuto,nombreProp);
                    estadiaOK= emitirTicket(listaAutomoviles,idPropietarioAuto,maxVehiculos,nombreProp);

                }
                else
                {
                    printf("NO HAY VEHICULOS PARA MOSTRAR\n");
                    estadiaOK = 1;
                    break;
                }
                //mostrarNombrePropietario(listaPropietarios,idEncontrada,nombreProp);
                //estadiaOK= emitirTicket(listaAutomoviles,idEncontrada,LUGAR_DISP,nombreProp);
            }
        }
        while(estadiaOK == INVALIDO);

    }
    else
    {
        printf("NO SE INGRESO NADA PARA MOSTRAR O NO HAY VEHICULOS PARA MOSTRAR...\n");
    }
    limpiarPantalla();
}

void menuListaAutomoviles(sAutomovil listaAutomoviles[], int maxAutos)
{
    if(hayVehiculos(listaAutomoviles,maxAutos ) >=1)
            {
                 printf("******LISTA AUTOMOVILES EN ESTACIONAMIENTO******\n\n");
                mostrarVehiculos(listaAutomoviles,maxAutos);
            }
            else
            {
                printf("NO SE INGRESO NADA PARA MOSTRAR O NO HAY VEHICULOS PARA MOSTRAR...\n");
            }
            limpiarPantalla();
}
