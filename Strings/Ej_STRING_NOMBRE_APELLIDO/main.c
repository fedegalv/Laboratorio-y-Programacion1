#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FUNCIONES.h"

int main()
{
    char nombre[20];
    char apellido[20];
    char nombreApellido[41];
    ingresoNombre(nombre);
    ingresoApellido(apellido);
    upperPrimeraLetra(nombre);
    upperPrimeraLetra(apellido);
    formateoNombreApellido(nombreApellido,nombre,apellido);
    puts(nombreApellido);

    return 0;
}
