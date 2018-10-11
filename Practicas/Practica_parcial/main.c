#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "FUNCIONESAUX.h"
#include "INFORMES.H"
#define TAM_CLIENTE 10
#define TAM_PUBLICACION 10

int main()
{
    int opcion, pedidosClienteOK, pedidoAvisoOk,idClienteOK;
    int cantidadClientes, cantidadAvisos;
    int idProvista;
    cantidadClientes = 0;
    cantidadAvisos = 0;
    sCliente listaClientes[TAM_CLIENTE];
    ePublicacion listaPublicaciones [TAM_PUBLICACION];

    do
    {
        printf("***** MENU PRINCIPAL **** \n");
        printf("1- ALTA DE CLIENTE"
               "\n2- MODIFICAR DATOS DEL CLIENTE"
               "\n3- BAJA DEL CLIENTE"
               "\n4- PUBLICAR"
               "\n5- PAUSAR PUBLICACION"
               "\n6- REANUDAR PUBLICACION"
               "\n7- IMPRIMIR CLIENTES"
               "\n8- IMPRIMIR PUBLICACIONES\n"
               "\nOPCION SELECCIONADA: ");
        scanf("%d",&opcion);
        fflush(stdin);
        switch(opcion)
        {
        case 1:
            pedidosClienteOK= pedirDatosCliente(listaClientes,cantidadClientes,TAM_CLIENTE);
            if(pedidosClienteOK == 1)
            {
                cantidadClientes++;
            }
            limpiarPantalla();
            break;

        case 2:
            printf("INGRESE ID A MODIFICAR: \n");
            idProvista = ingresoNumero();
            idClienteOK= buscarClienteID(listaClientes,TAM_CLIENTE,idProvista);
            if(idClienteOK != -1)
            {
                printf("ID ENCONTRADA\n");
                limpiarPantalla();
            }
            else
            {
                printf("ID NO ENCONTRADA O VALIDA\n");
                limpiarPantalla();
            }
            break;

        case 3:

            break;
        case 4:
            pedidoAvisoOk=pedirDatosPublicaciones(listaPublicaciones,cantidadAvisos,TAM_PUBLICACION);
           if(pedidoAvisoOk == 1)
            {
                cantidadAvisos++;
            }
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            showListaClientes(listaClientes,cantidadClientes,listaPublicaciones,cantidadAvisos,TAM_PUBLICACION);
            break;
        case 8:

            break;
             default:
            printf("OPCION NO VALIDA\n");
            break;
        }

    }
    while(opcion != 10);//CONDICION PARA MANTENER MENU
    return 0;
}
