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

int pedirDatosAutomovil(sAutomovil listaAutomoviles[],int idPropietario)
{
    char patente[51];
    int marca;
    int seleccionMarca;
    int marcaValida;
    int opRealizada= -1;

    printf("Ingrese patente del propietario: ");
    gets(patente);
    fflush(stdin);
    do
    {
        marcaValida=0;
        printf("MARCAS DISPONIBLES\n: ");
        printf("1- ALPHA ROMEO\n2- FERRARI\n3- FERRARI\n4- OTROS\n");
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

    }while(marcaValida == 0);

    opRealizada= agregarAutomovil(listaAutomoviles,idPropietario,patente,marca);
    return opRealizada;
}

int agregarAutomovil(sAutomovil listaAutomovil[], int idPropietario, char patente[], int marca)
{
    int operacionCompletada;
    int idPr;
    idPr = idPropietario;
    operacionCompletada = -1; // SE PONE POR DEFAULT COMO INVALIDO

    listaAutomovil[idPr].idPropietario= idPr;
    listaAutomovil[idPr].marca= marca;
    listaAutomovil[idPr].estado= 1;
    strcpy(listaAutomovil[idPr].patente, patente);

    operacionCompletada = 1; // LA OPERACION FUE REALIZADA CON EXITO
    return operacionCompletada;
}
