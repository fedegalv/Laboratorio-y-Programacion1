#include <stdio.h>
#include <stdlib.h>
#include "Funciones_aux.h"
#include "Automoviles.h"
#include "Propietarios.h"
#include "Funciones_aux.h"
#define LUGAR_DISP 20
#define CANT_PROP 20

int main()
{
    sAutomovil listaAutomoviles[LUGAR_DISP];
    //sPropietario listaPropietarios[CANT_PROP];
    int opcion;
    inicializarAutosEstado(listaAutomoviles,LUGAR_DISP);
    do
    {
        opcion= mostrarMenu();

    }while(opcion != 13);

    return 0;
}
