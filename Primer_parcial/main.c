#include <stdio.h>
#include <stdlib.h>
#include "Propietarios.h"
#include "Automoviles.h"
#include "Funciones_aux.h"
#include "menu.h"

/*
REVISAR VERIFICACION DE PATENTES, CONVERTIRE A MAYUSCULAS EN FORMATE AAA 123
ARRGLADO - ERROR MOSTRAR AUTOS ESTACIONADOS, EJ ID 1 MUESTRA 15, SIN ORDENAR MUESTRA BIEN LAS ID, lUEGO DE ORDENAR MUESTRA MAL
OK- REVISAR MOSTRAR RECAUDACION TOTAL DEL ESTACIONAMIENTO AGREGAR CHECKEO SI HAY AUTOS PARA mostrar
REVISAR RECAUDACION POR MARCAS, RESULTADO ALETARIOS AGREGAR CHECKEO SI HAY AUTOS PARA mostrar
OK-  MENU EGRESO ALUMNOS , AGREGAR CONFIRMACION, AGREGAR CHECKEO SI HAY AUTOS PARA EGRESAR
10- MOSTAR AUTOS POR PROP, CHECKEAR SI HAY AUTOS PARA MOSTRAR
OPCION 11 CRASHEA
1111111111111111
*/

#define CANT_PROP 20
#define LUGAR_DISP 20
#define HISTORIAL_AUTOS 40
#define VALIDO 1
#define INVALIDO 0
#define NO_ENCONTRADO -1

int main()
{

    int opcion;
    int cantProp = 0;
    int* pCantProp= &cantProp;
    int autosEstacionados;
    int aux;
    autosEstacionados= 0;
    sPropietario listaPropietarios[CANT_PROP];
    sAutomovil listaAutomoviles[LUGAR_DISP];
    sAutomovil historialAutos[HISTORIAL_AUTOS];

    inicializarPropEstado(listaPropietarios,CANT_PROP);
    inicializarAutosEstado(listaAutomoviles,LUGAR_DISP);
    inicializarAutosEstado(historialAutos,HISTORIAL_AUTOS);


    do
    {
        fflush(stdin);
        opcion= mostrarMenu();
        switch(opcion)
        {
        case 1:
            cantProp= altaPropietarios(listaPropietarios,CANT_PROP,pCantProp);
            break;
        case 2:
            aux= propietariosActivos(listaPropietarios, CANT_PROP);
            menuModificar(listaPropietarios, aux, CANT_PROP);
            break;
        case 3:
            cantProp= menuBajaPropietarios(listaPropietarios,listaAutomoviles, CANT_PROP, LUGAR_DISP, cantProp);
            break;
        case 4:
            menuMostrarListaOrdenada(listaPropietarios, cantProp, CANT_PROP);
            break;
        case 5:
            autosEstacionados= menuAltaVehiculos(listaPropietarios,listaAutomoviles,historialAutos, CANT_PROP,autosEstacionados, LUGAR_DISP, autosEstacionados);
            break;
        case 6:
            menuBajaVehiculos(listaPropietarios, listaAutomoviles, LUGAR_DISP,CANT_PROP);
            break;
        case 7:
            menuListaAutomoviles(listaAutomoviles, LUGAR_DISP);
            break;
        case 8:
            menuListarRecaudacionTotalEstacionamiento(historialAutos,HISTORIAL_AUTOS);
            break;
        case 9:
            menuRecaudacionTotalMarcas(historialAutos, HISTORIAL_AUTOS);
            break;
        case 10:
            menuMostrarAutosPorPropietarios(listaAutomoviles,listaPropietarios, LUGAR_DISP, CANT_PROP);
            break;
        case 11:
            menuPropietariosConAudi(listaPropietarios, listaAutomoviles, LUGAR_DISP, CANT_PROP); // QUE MUESTRE MENSAJE NO HAY AUDIS SI NO LOS HAY
            break;
        case 12:
            menuAutosOrdenadosPatentes(listaAutomoviles, listaPropietarios, LUGAR_DISP, CANT_PROP);
            break;
        case 13:
            exit(0);
            break;
        default:
            printf("OPCION NO VALIDA");
            limpiarPantalla();
            break;

        }
    }
    while(opcion != 13); //CONDICION PARA MANTENER MENU
    return 0;
}
