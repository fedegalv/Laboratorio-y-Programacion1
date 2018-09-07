#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char nombre[20];
    int cantidad;
    char otroNombre[20]="Anahi";
    int compara;
    strcpy(nombre,"Mauricio"); // strcpy(destino,origen) el origen puede ser una variable o una constante como en este caso
    //comprara= stricmp(nombre,otroNombre) compara ignorando mayuscula
    compara = strcmp(nombre,otroNombre); // COMPARA UNA CADENA CON OTRA; SI SON IGUALES O ORDEN ALFABETICO
    if(compara == 0)
    {
        printf("Son iguales \n", compara);
    }else{
        if(compara < 0)
        {
            printf("%s esta despues que %s ",otroNombre,nombre);
        }
        else{
            printf("%s esta despues que %s ",nombre,otroNombre);
        }
    }
    /*printf("Ingrese su nombre: ");
    fflush(stdin); // Limpiar buffer
    gets(nombre); // LEER CADENAS, MAS DE UNA PALABRA
*/
    cantidad= strlen(nombre); // funcion que mide la cantidad de caracteres, incluidos los espacios

    printf("Su nombre es %s\n",nombre);
    printf("La cantidad de caracteres es %d",cantidad);
    return 0;
}
