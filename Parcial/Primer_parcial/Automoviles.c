#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include "Automoviles.h"
#include "Funciones_aux.h"
#include "Propietarios.h"

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTROS 4

void inicializarAutosEstado(sAutomovil listaAutomoviles[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        listaAutomoviles[i].estado = 0; // vacio
    }
}

int pedirDatosAutomovil(sAutomovil listaAutomoviles[],int idPropietario,int index)
{
    char patente[51];
    int marca;
    int seleccionMarca;
    int marcaValida;
    int opRealizada= 0;

    printf("Ingrese patente del propietario: ");
    gets(patente);
    fflush(stdin);
    do
    {
        marcaValida=0;
        printf("MARCAS DISPONIBLES:\n");
        printf("1-ALPHA ROMEO\n2-FERRARI\n3-AUDI\n4-OTROS\n");
        printf("Ingrese marca del propietario: ");
        seleccionMarca = ingresoNumero();
        switch(seleccionMarca)
        {
        case ALPHA_ROMEO:
            marca= ALPHA_ROMEO;
            marcaValida=1;
            break;
        case FERRARI:
            marca= FERRARI;
            marcaValida=1;
            break;
        case AUDI:
            marca= AUDI;
            marcaValida=1;
            break;
        case OTROS:
            marca= OTROS;
            marcaValida=1;
            break;
        default:
            printf("MARCA NO VALIDA\n");
            break;
        }

    }
    while(marcaValida == 0);

    opRealizada= agregarAutomovil(listaAutomoviles,idPropietario,patente,marca,index);
    return opRealizada;
}

int agregarAutomovil(sAutomovil listaAutomovil[], int idPropietario, char patente[], int marca, int index)
{
    int operacionCompletada;
    int idPr;
    idPr = idPropietario;
    operacionCompletada = 0; // SE PONE POR DEFAULT COMO INVALIDO

    listaAutomovil[index].idPropietario= idPr;
    listaAutomovil[index].marca= marca;
    listaAutomovil[index].estado= 1;
    strcpy(listaAutomovil[index].patente, patente);

    operacionCompletada = 1; // LA OPERACION FUE REALIZADA CON EXITO
    return operacionCompletada;
}
void codigoMarcas(int marca, char marcaTexto[])
{
    switch(marca)
    {
    case 1:
        strcpy(marcaTexto,"ALPHA ROMEO");
        break;
    case 2:
        strcpy(marcaTexto,"FERRARI");
        break;
    case 3:
        strcpy(marcaTexto,"AUDI");
        break;
    case 4:
        strcpy(marcaTexto,"OTROS");
        break;
    }
}
int precioPorHora(int marca)
{
    int precio;
    switch(marca)
    {
    case 1:
        precio = 150;
        break;
    case 2:
        precio = 175;
        break;
    case 3:
        precio = 200;
        break;
    case 4:
        precio = 250;
        break;
    }
    return precio;
}

int emitirTicket(sAutomovil listaAutomovil[],int idProvisto,int tam, char nombreProp[])
{
    int i;
    char patenteSeleccionada[51];
    char marcaTexto[15];
    //int pantenteValida;
    int autoEncontrado;
    int totalEstadia;
    int horasEstadia;
    int precioEstadia;

    printf("\n%10s %15s\n","PATENTE","MARCA");
    for (i= 0; i < tam; i++)
    {
        if(listaAutomovil[i].idPropietario == idProvisto && listaAutomovil[i].estado == 1)
        {
            codigoMarcas(listaAutomovil[i].marca,marcaTexto);
            printf("%10s %15s\n",listaAutomovil[i].patente,marcaTexto);
        }
    }
    printf("QUE AUTO DESEA RETIRAR DEL ESTACIONAMIENTO? INGRESE LA PATENTE\nOPCION SELECCIONADA: ");
    gets(patenteSeleccionada);
    fflush(stdin);
    for (i= 0; i < tam; i++)
    {
        //pantenteValida = strcmp(listaAutomovil[i].patente, aux);
        //printf("%d",pantenteValida);
        if(listaAutomovil[i].estado == 1 && strcmp(listaAutomovil[i].patente, patenteSeleccionada) == 0)
        {
            horasEstadia= devolverHorasEstadia();
            precioEstadia= precioPorHora(listaAutomovil[i].marca);
            totalEstadia= precioEstadia * horasEstadia;
            codigoMarcas(listaAutomovil[i].marca, marcaTexto);

            printf("GENERANDO TICKET...");
            limpiarPantalla();
            printf("*********************** TICKET ***********************\n");// 8
            printf("** NOMBRE DEL PROPIETARIO: %2s                   **\n",nombreProp);//5
            printf("** PATENTE DEL AUTO:       %14s           **\n",listaAutomovil[i].patente);
            printf("** MARCA DEL AUTO:         %14s           **\n",marcaTexto);
            printf("** HORAS ESTACIONADO:      %14d           **\n",horasEstadia);
            printf("** TOTAL A PAGAR:          %14d           **\n",totalEstadia);
            printf("******************************************************\n");
            limpiarPantalla();
            //printf("AUTO ENCONTRADO GENERANDO TICKET\n");
            autoEncontrado= 1;
            break;

        }
        else
        {
            printf("PATENTE NO ENCONTRADA O VALIDA\n");
            autoEncontrado= 0;
            break;
        }
    }

    return autoEncontrado;
}
