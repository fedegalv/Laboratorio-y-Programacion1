#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include "Automoviles.h"
#include "Propietarios.h"
#include "Funciones_aux.h"

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
