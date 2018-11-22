#include <stdio.h>
#include <stdlib.h>
#include "Propietarios.h"
#include "Automoviles.h"
#include "Funciones_aux.h"
#include "menu.h"

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
    int idProvista;
    int idEncontrada;
    int movilOK, estadiaOK, hayVehiculosPropOK;
    int hayVehiculosOK;
    int bajaPropOK;
    int idPropietarioAuto;
    int autosEstacionados;
    char nombreProp[25];
    int importeFinal;
    int recaudacionFinal;
    int j;
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
            if(cantProp >=1)
            {
                limpiarPantalla();
                printf("****** MENU DE MODIFICACIONES ******\n\n");
                mostrarListaPropietarios(listaPropietarios,CANT_PROP);
                printf("INGRESE ID A MODIFICAR: ");
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
                    //printf("ID ENCONTRADA");
                    modificarPropietario(listaPropietarios,idEncontrada);
                }
            }
            else
            {
                printf("NO SE INGRESO NADA PARA MOSTRAR...\n");
            }
            limpiarPantalla();
            break;
        case 3:
            if(cantProp >=1)
            {
                limpiarPantalla();
                printf("****** MENU BAJA DE PROPIETARIOS ******\n\n");
                mostrarListaPropietarios(listaPropietarios,CANT_PROP);
                printf("INGRESE ID A DAR DE BAJA: ");
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
                    //printf("ID ENCONTRADA\n");

                    hayVehiculosOK= hayVehiculos(listaAutomoviles,LUGAR_DISP);
                    if(hayVehiculosOK == INVALIDO)
                    {
                        printf("NO HAY VEHICULOS PARA MOSTRAR\n");
                        importeFinal= totalPagarPropietario(listaAutomoviles,idEncontrada,LUGAR_DISP);
                        bajaPropietarios(listaPropietarios,idEncontrada,importeFinal);
                    }
                    else
                    {
                        mostrarNombrePropietario(listaPropietarios,idEncontrada,nombreProp);
                        importeFinal= totalPagarPropietario(listaAutomoviles,idEncontrada,LUGAR_DISP);
                        bajaPropOK=bajaPropietarios(listaPropietarios,idEncontrada,importeFinal);
                        if(bajaPropOK == VALIDO)
                        {
                            bajaAutomoviles(listaAutomoviles,idEncontrada,LUGAR_DISP);
                        }
                    }

                }
            }
            else
            {
                printf("NO SE INGRESO NADA PARA MOSTRAR...\n");
            }
            limpiarPantalla();
            break;
        case 4:
            if(cantProp >=1)
            {
                limpiarPantalla();
                //printf("****** LISTA PROPIETARIOS ******\n\n");
                //mostrarListaPropietarios(listaPropietarios,CANT_PROP);
                printf("****** LISTA PROPIETARIOS ORDENADA******\n\n");
                ordenarPropietarios(listaPropietarios,CANT_PROP);
                mostrarListaPropietarios(listaPropietarios,CANT_PROP);
            }
            else
            {
                printf("NO SE INGRESO NADA PARA MOSTRAR...\n");
            }
            limpiarPantalla();
            break;
        case 5:
            do
            {
                fflush(stdin);
                limpiarPantalla();
                movilOK=INVALIDO;
                printf("****** MENU ALTAS AUTOMOVILES ******\n\n");
                mostrarListaPropietarios(listaPropietarios,CANT_PROP);
                printf("Ingrese ID del propietario del auto: ");
                idPropietarioAuto=ingresoNumero();
                idEncontrada= buscarPropietario(listaPropietarios,CANT_PROP,idPropietarioAuto);
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
            break;
        case 6:
            if(cantProp >=1)
            {
                do
                {
                    limpiarPantalla();
                    estadiaOK=INVALIDO;
                    printf("******MENU EGRESO DE AUTOS******\n\n");
                    mostrarListaPropietarios(listaPropietarios,CANT_PROP);
                    printf("Ingrese ID del propietario del auto: ");
                    //printf("Para volver al menu principal escriba -1 ");
                    idPropietarioAuto=ingresoNumero();
                    idEncontrada= buscarPropietario(listaPropietarios,CANT_PROP,idPropietarioAuto);
                    if(idEncontrada == NO_ENCONTRADO)
                    {
                        printf("ID NO ENCONTRADA O VALIDA\n");
                        estadiaOK = 1;
                        break;
                    }
                    else
                    {
                        hayVehiculosPropOK= hayVehiculoEnPropietario(listaAutomoviles,LUGAR_DISP,idEncontrada);
                        if(hayVehiculosPropOK == VALIDO)
                        {
                            mostrarNombrePropietario(listaPropietarios,idEncontrada,nombreProp);
                            estadiaOK= emitirTicket(listaAutomoviles,idEncontrada,LUGAR_DISP,nombreProp);

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
            limpiarPantalla();
            break;
        case 7:
            if(cantProp >=1)
            {
                 printf("******LISTA AUTOMOVILES EN ESTACIONAMIENTO******\n\n");
                mostrarVehiculos(listaAutomoviles,LUGAR_DISP);
            }
            else
            {
                printf("NO SE INGRESO NADA PARA MOSTRAR...\n");
            }
            limpiarPantalla();
            break;
        case 8:
             if(cantProp >=1)
            {
                copiarVehiculosHistorial(listaAutomoviles, historialAutos, HISTORIAL_AUTOS);
                recaudacionFinal= recaudacionTotal(historialAutos,HISTORIAL_AUTOS);
                printf("********** RECAUDACION TOTAL A TRAVES DEL TIEMPO **********\n\n");
                for(j= 0; j < HISTORIAL_AUTOS; j++)
                {
                    if( historialAutos[j].estado == 1)
                    {
                        totalPagarPropietario(historialAutos, j, HISTORIAL_AUTOS);
                    }

                }
                printf("\n\nRECAUDACION TOTAL: $%d\n", recaudacionFinal);
            }
            else
            {
                printf("NO SE INGRESO NADA PARA MOSTRAR...\n");
            }
            limpiarPantalla();
            break;
        case 9:
            if(cantProp >=1)
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
                    mostrarNombrePropietario(listaPropietarios,idEncontrada,nombreProp);
                    mostrarVehiculoEnProp(listaAutomoviles,idEncontrada,LUGAR_DISP);
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
