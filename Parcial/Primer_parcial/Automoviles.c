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

    }while(marcaValida == 0);

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

int emitirTicket(sAutomovil listaAutomovil[],int idProvisto,int tam)
{
    int i;
    printf("%10s %10s\n","PATENTE","MARCA");
    for (i= 0; i < tam; i++)
    {
        if(listaAutomovil[i].idPropietario == idProvisto && listaAutomovil[i].estado == 1)
        {
            printf("%10s %10d\n",listaAutomovil[i].patente, listaAutomovil[i].marca);
        }

    }

    return 0;
}
