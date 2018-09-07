#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[20]; // ADENTRO SE DEFINE EL LIMITE DE CARACTERES
    int cantidad;
    printf("ingrese nombre:");
    scanf("%[^\n]",nombre); // IGNORA EL \N
    //fgets(nombre,20, stdin); // fgets(VARIABLE, CANTIDAD CARACTERES A GUARDAR, DESTINO); TOMAR EN CUENTA QUE FGETS AGREGA UN CARACTAR \N AL FINAL
    puts(nombre);
    nombre[strlen(nombre)-1]='\o';
    cantidad = strlen(nombre);
    printf("Cantidad %d", cantidad);
    return 0;
}
