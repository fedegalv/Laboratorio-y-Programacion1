#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ingresoNombre(char *nombre)
{
    //char nom[20];
    fflush(stdin);
    printf("Ingrese nombre: ");
    scanf("%[^\n]",nombre);
    //strcpy(nombre,nom);



}

void ingresoApellido(char *apellido)
{
    //char ape[20];
    fflush(stdin);
    printf("Ingrese apellido: ");
    scanf("%[^\n]",apellido);
    //strcpy(apellido, ape);


}
