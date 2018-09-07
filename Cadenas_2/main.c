#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[20]="Juana";
    char otroNombre[20]="Anibal";
    int i;
    /*strupr(otroNombre); // CONVIERTE LA CADENA A MAYUSCULA
    strlwr(nombre); // CONVIERTE LA CADENA A MINUSCULA
    */
    /*
    strcat(nombre," "); // PRIMERO CONCATENAR UN ESPACIO, LA CADENA nombre SERA LA QUE RECIBE LA NUEVA CADENA CONCATENADA
    strcat(nombre,otroNombre);// CONCATENA CADENAS, VARIBALE+VARIABLE o VARIABLE + CONSTANTE.
    */
    for(i=0; i < strlen(nombre); i++)
    {
        if(tolower(nombre[i] == 'a')) // tolwer PASA A MINUSCULA A EL CHAR EN SUBINDICE nombre[i], COMPARA CON 'a' Y SI LO ENCUENTRA LO MUESTRA
        {
            printf("%c",nombre[i]); // SIRVE PARA ENCONTRAR LETRAS EN ESPECIFICO
        }
        //printf("%c-",nombre[i]); MOSTRAR CARACTER POR CARACTER
    }
    while(nombre[i] != '\o')
    {
        printf("%c",nombre[i]);
    }
    printf("\n%s\n",otroNombre);
    printf("%s\n",nombre);
    return 0;
}

/* EJERCICIO
VARIABLES:
nombre  | --> INGRESO MAXIMO DE 20 CARACTERES C/U
apellido|

apellidoynombre ---> CONCATENA EN EL SIGUIENTE FORMATO
                        Gomez, Juan Luis (PRIMER LETRA EN MAYUSCULA, RESPETAR ESPACIOS)
