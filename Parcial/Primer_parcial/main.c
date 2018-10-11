#include <stdio.h>
#include <stdlib.h>
#include "Propietarios.h"
#include "Funciones_aux.h"


#define LUGAR_DISP 20
int main()
{

    int opcion;
    int cantProp;
    int ingresoOK;
    int idProvista;
    int idEncontrada;
    cantProp = 5;
    sPropietario listaPropietarios[LUGAR_DISP];

    inicializarPropEstado(listaPropietarios,LUGAR_DISP);
    inicializarPropietariosHardcoded(listaPropietarios);
    do
    {
        printf("***** MENU PRINCIPAL **** \n");
        printf("1- INGRESO DE DATOS"
               "\n2- MODIFICAR DATOS DEL PROPIETARIO"
               "\n3- BAJA DEL PROPIETARIO"
               "\n4- LISTAR PROPIETARIOS"
               "\n10- SALIR PROGRAMA\n"
               "\nOPCIONES SELECCIONADA: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            ingresoOK= pedirDatos(listaPropietarios,LUGAR_DISP);
            if(ingresoOK == 1)
            {
                cantProp++;
                printf("INGRESO REALIZADO CON EXITO...\n");
            }
            limpiarPantalla();
            break;
        case 2:
            if(cantProp >=1)
            {
                printf("INGRESADO A MODULO MODIFICACION...\n");
                limpiarPantalla();
                mostrarListaPropietarios(listaPropietarios,LUGAR_DISP);
                printf("INGRESE ID A MODIFICAR: ");
                idProvista= ingresoNumero();
                fflush(stdin);
                idEncontrada= buscarPropietario(listaPropietarios,LUGAR_DISP,idProvista);
                if(idEncontrada == -1)
                {
                    printf("ID NO ENCONTRADA O VALIDA\n");
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
                printf("INGRESADO A MODULO BAJA DE PROPIETARIO...\n");
                limpiarPantalla();
                mostrarListaPropietarios(listaPropietarios,LUGAR_DISP);
                printf("INGRESE ID A DAR DE BAJA: ");
                idProvista= ingresoNumero();
                fflush(stdin);
                idEncontrada= buscarPropietario(listaPropietarios,LUGAR_DISP,idProvista);
                if(idEncontrada == -1)
                {
                    printf("ID NO ENCONTRADA O VALIDA\n");
                }
                else
                {
                    //printf("ID ENCONTRADA\n");
                    bajaPropietarios(listaPropietarios,idEncontrada);
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
                mostrarListaPropietarios(listaPropietarios,LUGAR_DISP);
            }
            else
            {
                printf("NO SE INGRESO NADA PARA MOSTRAR...\n");
            }
            limpiarPantalla();
            break;

        }
    }
    while(opcion != 10); //CONDICION PARA MANTENER MENU
    return 0;
}
