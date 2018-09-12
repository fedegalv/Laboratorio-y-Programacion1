#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void ingresoNombre(char *nombre)
{
    fflush(stdin);
    printf("Ingrese nombre: ");
    scanf("%[^\n]",nombre); // LEE LO INGRESADO PERO NO EL \n , QUE ES UN SALTO DE LINEA(enter)
}

void ingresoApellido(char *apellido)
{
    fflush(stdin);
    printf("Ingrese apellido: ");
    scanf("%[^\n]",apellido); // LEE LO INGRESADO PERO NO EL \n , QUE ES UN SALTO DE LINEA(enter)
}
void upperPrimeraLetra(char *texto)
{
    int i; // VARIABLE CONTROL
    int largo; // VARIABLE ALMACENA LARGO DEL STRING
    texto[0]=toupper(texto[0]); // SE CAMBIA LA PRIMERA LETRA A MAYUSCULA
    largo = strlen(texto); // SE ALMACENA EN largo LA CANTIDAD DE CARACTERES DEL STRING
    for(i=0;i< largo;i++) // SE RECORRE EL STRING
    {
        if(texto[i]==' ') // SI ENCUENTRA UN ESPACIO EN LA CADENA, ENTRA EN EL IF
        {
            texto[i+1]=toupper(texto[i+1]); // SE PONE EN MAYUSCULA EL CARACTER QUE LE SIGUE A EL ESPACIO(i ES EL ESPACIO, i+1 ES EL CARACTER QUE LE SIGUE)
        }
    }

}
void formateoNombreApellido(char* nombreApellido,char *nombre, char *apellido)
{
    strcpy(nombreApellido,apellido); // COPIA PRIMERO EL APELLIDO EN UNA UNA CADENA nombreApellido
    strcat(nombreApellido,", "); // SE CONCATENA UN ", " A nombreApellido
    strcat(nombreApellido, nombre); // SE CONCATENA nombre EN LA CADENA nombreApellido
}
