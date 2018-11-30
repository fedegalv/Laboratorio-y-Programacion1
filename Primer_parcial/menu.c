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
        printf("Para volver al menu principal escriba -1 \n");
        printf("INGRESE ID A MODIFICAR: ");
        idProvista= ingresoNumero();
        if(idProvista== -1)
        {
            limpiarPantalla();
            return;
        }
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
    int index;
    activos= propietariosActivos(listaPropietarios, tam);
    if(activos >=1)
    {
        limpiarPantalla();
        printf("****** MENU BAJA DE PROPIETARIOS ******\n\n");

        mostrarListaPropietarios(listaPropietarios,tam);
        printf("Para volver al menu principal escriba -1 \n");
        printf("INGRESE ID A DAR DE BAJA: ");
        idProvista= ingresoNumero();
        if(idProvista== -1)
        {
            limpiarPantalla();
            return cantProp;
        }
        fflush(stdin);
        idEncontrada= buscarPropietario(listaPropietarios,tam,idProvista);
        if(idEncontrada == NO_ENCONTRADO)
        {
            printf("ID NO ENCONTRADA O VALIDA\n");
            limpiarPantalla();
        }
        else
        {
            printf("ID ENCONTRADA\n\n\n");

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

                index= buscarIndexEnLista(listaPropietarios, tam, idProvista);
                mostrarNombrePropietario(listaPropietarios, index, nombreProp);

                printf("%s %5s %15s %20s %20s\n","ID","NOMBRE", "APELLIDO","DIRECCION","NUMERO TARJETA");
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

int menuAltaVehiculos(sPropietario listaPropietarios[],sAutomovil listaAutomoviles[], sAutomovil historialAutos[],int cantProp,int autosEstacionados, int maxAutos, int autosActivos)
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
            printf("Para volver al menu principal escriba -1 \n");
            printf("Ingrese ID del propietario del auto: ");

            idPropietarioAuto=ingresoNumero();
            if(idPropietarioAuto== -1)
            {
                limpiarPantalla();
                return autosEstacionados;
            }
            idEncontrada= buscarPropietario(listaPropietarios,cantProp,idPropietarioAuto);
            if(idEncontrada == NO_ENCONTRADO)
            {
                printf("ID NO ENCONTRADA O VALIDA\n");
                break;
            }
            else
            {

                movilOK= pedirDatosAutomovil(listaAutomoviles, historialAutos,idPropietarioAuto,maxAutos, autosActivos);
                autosEstacionados++;
                printf("AUTOMOVIL AGREGADO\n");

            }

        }
        while(movilOK == INVALIDO);
    }
    else
    {
        printf("NO SE INGRESO NADA PARA MOSTRAR O NO HAY VEHICULOS PARA MOSTRAR...\n");
    }
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
    int index;
    if(hayVehiculos(listaAutomoviles,maxVehiculos ) >=1)
    {
        do
        {
            limpiarPantalla();
            estadiaOK=INVALIDO;
            printf("******MENU EGRESO DE AUTOS******\n\n");
            mostrarListaPropietarios(listaPropietarios,maxProp);
            printf("Para volver al menu principal escriba -1 \n");
            printf("Ingrese ID del propietario del auto: ");
            idPropietarioAuto=ingresoNumero();
            if(idPropietarioAuto== -1)
            {
                limpiarPantalla();
                return;
            }
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
                    index = buscarIndexEnLista(listaPropietarios,maxProp, idPropietarioAuto);
                    mostrarNombrePropietario(listaPropietarios,index,nombreProp);
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

void menuListarRecaudacionTotalEstacionamiento(sAutomovil historialAutos[], int maxVehiculos)
{
    int recaudacionFinal;
    if(hayVehiculos(historialAutos,maxVehiculos ) >=1)
    {

        recaudacionFinal= recaudacionTotal(historialAutos,maxVehiculos);
        printf("********** RECAUDACION TOTAL A TRAVES DEL TIEMPO **********\n\n");
        printf("\n%10s %15s %15s %15s %15s\n","PATENTE","MARCA","HORAS ESTADIA","PRECIO ESTADIA","TOTAL ESTADIA");
        totalPagarPropietarioHistorial(historialAutos, 0, maxVehiculos);
        printf("\n\nRECAUDACION TOTAL: $%d\n", recaudacionFinal);

    }
    else
    {
        printf("NO SE INGRESO NADA PARA MOSTRAR O NO HAY VEHICULOS PARA MOSTRAR...\n");
    }
    limpiarPantalla();
}

void menuRecaudacionTotalMarcas(sAutomovil historialAutos[], int maxAutos)
{
    if(hayVehiculos(historialAutos,maxAutos ) >=1)
    {
        printf("********** RECAUDACION TOTAL MARCAS **********\n\n");
        recaudacionTotalMarca(historialAutos,maxAutos);
    }
    else
    {
        printf("NO SE INGRESO NADA PARA MOSTRAR O NO HAY VEHICULOS PARA MOSTRAR...\n");
    }
    limpiarPantalla();
}
void menuMostrarAutosPorPropietarios(sAutomovil listaAutomoviles[], sPropietario listaPropietarios[], int maxAutos, int maxProp)
{
    int index;
    int idProvista;
    int idEncontrada;
    char nombreProp[25];
    limpiarPantalla();
    if(hayVehiculos(listaAutomoviles,maxAutos ) >=1)
    {


        printf("****** MOSTRAR AUTOS POR PROPIETARIOS******\n\n");
        mostrarListaPropietarios(listaPropietarios,maxProp);
        printf("INGRESE ID A BUSCAR: ");
        idProvista= ingresoNumero();
        fflush(stdin);
        idEncontrada= buscarPropietario(listaPropietarios,maxProp,idProvista);
        if(idEncontrada == NO_ENCONTRADO)
        {
            printf("ID NO ENCONTRADA O VALIDA\n");
            limpiarPantalla();
        }
        else
        {
            index = buscarIndexEnLista(listaPropietarios, maxProp, idProvista);
            mostrarNombrePropietario(listaPropietarios,index,nombreProp);
            mostrarVehiculoEnProp(listaAutomoviles,idProvista,maxAutos);
        }
    }
    else
    {
        printf("NO SE INGRESO NADA PARA MOSTRAR O NO HAY VEHICULOS PARA MOSTRAR...\n");
    }

    printf("\n\n");
    limpiarPantalla();
}

void menuPropietariosConAudi(sPropietario listaPropietarios[], sAutomovil listaAutomoviles[], int maxAutos, int maxProp)
{
    int audiEncontrado;
    int j;
    int index;
    if(hayVehiculos(listaAutomoviles,maxAutos ) >=1)
    {


        printf("***** PROPIETARIOS CON AUDI *****\n\n");
        printf("%s %5s %15s %20s %20s\n","ID","NOMBRE", "APELLIDO","DIRECCION","NUMERO TARJETA");
        for(j=0; j<maxAutos ; j++)
        {
            if(listaPropietarios[j].estado == VALIDO)
            {
                audiEncontrado= buscarAudi(listaAutomoviles, maxAutos, listaPropietarios[j].idPropietario);
                if(audiEncontrado == VALIDO)
                {
                    index= buscarIndexEnLista(listaPropietarios, maxProp, listaPropietarios[j].idPropietario);
                    mostrarPropietario(listaPropietarios,index);
                }


            }

        }
    }
    else
    {
        printf("NO SE INGRESO NADA PARA MOSTRAR O NO HAY VEHICULOS PARA MOSTRAR...\n");
    }

    printf("\n\n\n");
    limpiarPantalla();
}

void mostrarInformacionAutoYProp(sAutomovil listaAutomoviles[], sPropietario listaPropietarios[], int maxProp, int maxAutos )
{
    int i;
    int index;
    char marcaTexto[51];
    printf("\n%8s %20s %15s | %15s %15s %15s %20s \n","ID PROP","PATENTE","MARCA", "NOMBRE","APELLIDO", "DIRECCION", "NRO TARJETA" );
    for (i= 0; i < maxAutos; i++)
    {
        if(listaAutomoviles[i].estado == 1)
        {
            codigoMarcas(listaAutomoviles[i].marca,marcaTexto);
            index= buscarIndexEnLista(listaPropietarios, maxProp, listaAutomoviles[i].idPropietario);
            if(index < 0 || index > maxProp)
            {
                continue;
            }
            else
            {
                printf("%8d %20s %15s |",listaAutomoviles[i].idPropietario, listaAutomoviles[i].patente, marcaTexto);
                printf("%15s %15s %15s %20s\n", listaPropietarios[index].nombre, listaPropietarios[index].apellido, listaPropietarios[index].direccion, listaPropietarios[index].numeroTarjeta);
            }

        }
    }
}
int menuAutosOrdenadosPatentes(sAutomovil listaAutos[],sPropietario listaPropietarios[],  int maxAutos, int maxProp)
{
    if(hayVehiculos(listaAutos,maxAutos ) >=1)
    {


        sAutomovil autosOrdenados[maxAutos];
        copiarVehiculos(listaAutos, autosOrdenados, maxAutos);

        ordenararPatentes(autosOrdenados, maxAutos);

        //mostrarVehiculos(autosOrdenados,maxAutos);
        mostrarInformacionAutoYProp(autosOrdenados, listaPropietarios, maxProp, maxAutos );
        limpiarPantalla();
    }
    else
    {
        printf("NO SE INGRESO NADA PARA MOSTRAR O NO HAY VEHICULOS PARA MOSTRAR...\n");
        limpiarPantalla();
    }
    return 1;
}
// 1111111111112321

