#include <stdio.h>
#include <stdlib.h>
#include "Propietarios.h"
#include "Automoviles.h"
#include "Funciones_aux.h"

#define CANT_PROP 20
#define LUGAR_DISP 20
#define VALIDO 1
#define INVALIDO 0
#define NO_ENCONTRADO -1

int main()
{

    int opcion;
    int cantProp;
    int ingresoOK;
    int idProvista;
    int idEncontrada;
    int movilOK, estadiaOK, bajaPropOK, hayVehiculosOK, hayVehiculosPropOK;
    int idPropietarioAuto;
    int autosEstacionados;
    char nombreProp[25];
    int importeFinal;
    autosEstacionados= 0;
    cantProp = 5;
    sPropietario listaPropietarios[CANT_PROP];
    sAutomovil listaAutomoviles[LUGAR_DISP];

    inicializarPropEstado(listaPropietarios,CANT_PROP);
    inicializarPropietariosHardcoded(listaPropietarios);
    inicializarAutosEstado(listaAutomoviles,LUGAR_DISP);

    do
    {
        printf("***** MENU PRINCIPAL ESTACIONAMIENTO**** \n\n");
        printf("1- INGRESO DE DATOS DE PROPIETARIOS"
               "\n2- MODIFICAR DATOS DEL PROPIETARIO"
               "\n3- BAJA DEL PROPIETARIO"
               "\n4- LISTAR PROPIETARIOS"
               "\n5- INGRESO DE AUTOMOVIL"
               "\n6- EGRESO DE AUTOMOVIL"
               "\n10- SALIR PROGRAMA\n"
               "\nOPCIONES SELECCIONADA: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            limpiarPantalla();
            printf("****** MENU ALTAS PROPIETARIOS ******\n\n");
            ingresoOK= pedirDatos(listaPropietarios,CANT_PROP);
            if(ingresoOK == VALIDO)
            {
                cantProp++;
                printf("INGRESO REALIZADO CON EXITO...\n");
            }
            limpiarPantalla();
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
<<<<<<< HEAD
                    printf("ID ENCONTRADA\n");
=======
                    //printf("ID ENCONTRADA");
>>>>>>> 290e981725e6083b281704df77a5c15f4b9d2a30
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
                        bajaPropOK= bajaPropietarios(listaPropietarios,idEncontrada,importeFinal);
                        if(bajaPropOK == VALIDO && hayVehiculosOK == VALIDO)
                        {
                            bajaAutomoviles(listaAutomoviles,idEncontrada,LUGAR_DISP);
                        }
                    }
                    else
                    {
                        mostrarNombrePropietario(listaPropietarios,idEncontrada,nombreProp);
                        importeFinal= totalPagarPropietario(listaAutomoviles,idEncontrada,LUGAR_DISP);
                        bajaPropOK= bajaPropietarios(listaPropietarios,idEncontrada,importeFinal);
                        if(bajaPropOK == VALIDO && hayVehiculosOK == VALIDO)
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

        }
    }
    while(opcion != 10); //CONDICION PARA MANTENER MENU
    return 0;
}
