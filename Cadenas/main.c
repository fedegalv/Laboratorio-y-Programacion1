#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[15];
    printf("Ingrese su nombre: ");
    fflush(stdin); // Limpiar buffer
    gets(nombre); // LEER CADENAS, MAS DE UNA PALABRA
    printf("Su nombre es %s",nombre);
    return 0;
}
