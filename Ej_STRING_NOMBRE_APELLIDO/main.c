#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FUNCIONES.h"

int main()
{
    char nombre[20];
    int largo;
    char apellido[20];
    char nombreApellido[20];
    ingresoNombre(nombre);
    ingresoApellido(apellido);
    largo= strlen(nombre);
    printf("nombre es %s y apellido es %s, y el largo del nombre es %d\n",nombre,apellido,largo);
    nombre[0]=toupper(nombre[0]);
    apellido[0]=toupper(apellido[0]);
    strcpy(nombreApellido,apellido);
    strcat(nombreApellido,", ");
    strcat(nombreApellido, nombre);
    puts(nombreApellido);

    return 0;
}
