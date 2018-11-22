#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
int mostrarMenu()
{
    int opcion;
    printf("***** MENU PRINCIPAL ESTACIONAMIENTO**** \n\n");
    printf("1- INGRESO DE DATOS DE PROPIETARIOS"
           "\n2- MODIFICAR DATOS DEL PROPIETARIO"
           "\n3- BAJA DEL PROPIETARIO"
           "\n4- LISTAR PROPIETARIOS"
           "\n5- INGRESO DE AUTOMOVIL"
           "\n6- EGRESO DE AUTOMOVIL"
           "\n7- MOSTRAR AUTOS ESTACIONADO"
           "\n8- RECAUDACION TOTAL ESTACIONAMIENTO"
           "\n9- RECAUDACION POR MARCA"
           "\n10- AUTOS POR PROPIETARIOS"
           "\n11- LISTADO DE AUTOS AUDI"
           "\n11- LISTADO DE AUTOS ORDENADO POR PATENTES\n"
           "\nOPCIONES SELECCIONADA: ");
    scanf("%d",&opcion);
    return opcion;
}
