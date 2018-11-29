#include <stdio.h>
#include <stdlib.h>
#include "Propietarios.h"
#include "Automoviles.h"
#include "Funciones_aux.h"
#include "menu.h"

/*
REVISAR VERIFICACION DE PATENTES, CONVERTIRE A MAYUSCULAS EN FORMATE AAA 123
ARRGLADO - ERROR MOSTRAR AUTOS ESTACIONADOS, EJ ID 1 MUESTRA 15, SIN ORDENAR MUESTRA BIEN LAS ID, lUEGO DE ORDENAR MUESTRA MAL
REVISAR MOSTRAR RECAUDACION TOTAL DEL ESTACIONAMIENTO AGREGAR CHECKEO SI HAY AUTOS PARA mostrar
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
    int idProvista;
    int idEncontrada;
    int cantProp = 0;
    int* pCantProp= &cantProp;
    int autosEstacionados;
    char nombreProp[25];
    int j;
    int aux;
    autosEstacionados= 0;
    sPropietario listaPropietarios[CANT_PROP];
    sAutomovil listaAutomoviles[LUGAR_DISP];
    sAutomovil historialAutos[HISTORIAL_AUTOS];

    inicializarPropEstado(listaPropietarios,CANT_PROP);
    //inicializarPropietariosHardcoded(listaPropietarios);
    inicializarAutosEstado(listaAutomoviles,LUGAR_DISP);
    inicializarAutosEstado(historialAutos,HISTORIAL_AUTOS);
    //iniciarAutosHardcoded(listaAutomoviles);

    do
    {
        copiarVehiculosHistorial(listaAutomoviles, historialAutos, HISTORIAL_AUTOS);
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
            if(propietariosActivos(listaPropietarios, CANT_PROP) >=1)
            {
                printf("********** RECAUDACION TOTAL MARCAS **********\n\n");
                recaudacionTotalMarca(historialAutos,HISTORIAL_AUTOS);
            }
            else
            {
                printf("NO SE INGRESO NADA PARA MOSTRAR...\n");
            }
            limpiarPantalla();
            break;
        case 10:
            limpiarPantalla();
            if(hayVehiculos(listaAutomoviles,LUGAR_DISP ) >=1)
            {


                printf("****** MOSTRAR AUTOS POR PROPIETARIOS******\n\n");
                mostrarListaPropietarios(listaPropietarios,CANT_PROP);
                printf("INGRESE ID A BUSCAR: ");
                idProvista= ingresoNumero();
                fflush(stdin);
                idEncontrada= buscarPropietario(listaPropietarios,CANT_PROP,idProvista);
                if(idEncontrada == NO_ENCONTRADO)
                {
                    printf("ID NO ENCONTRADA O VALIDA\n");
                    limpiarPantalla();
                    break;
                }
                else
                {
                    mostrarNombrePropietario(listaPropietarios,idProvista,nombreProp);
                    mostrarVehiculoEnProp(listaAutomoviles,idProvista,LUGAR_DISP);
                }
            }
            else
            {
                printf("NO SE INGRESO NADA PARA MOSTRAR O NO HAY VEHICULOS PARA MOSTRAR...\n");
            }

            limpiarPantalla();
            break;
        case 11:
            printf("***** PROPIETARIOS CON AUDI *****");
            for(j=0; j<CANT_PROP ; j++)
            {
                if(listaPropietarios[j].estado == VALIDO)
                {
                    idProvista= buscarAudi(listaAutomoviles,LUGAR_DISP);
                    mostrarPropietario(listaPropietarios,idProvista);

                }

            }

            break;
        case 12:
            printf("***** PROPIETARIOS CON AUDI *****");
            for(j=0; j<CANT_PROP ; j++)
            {
                if(listaPropietarios[j].estado == VALIDO)
                {

                }

            }
            break;

        }
    }
    while(opcion != 13); //CONDICION PARA MANTENER MENU
    return 0;
}
