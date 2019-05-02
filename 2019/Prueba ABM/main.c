#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#define T 2
void cargarDatos(char [][50], char [][50], int[], int[]);
int menuOpcion(void );
int bajas();
void mostrarDatos(char nombre[][50], char apellido[][50], int edad[], int nota[]);
int getString(char mensaje[], char input[]);
int verificarCadena(char cadena[51]);
int esSoloLetras(char palabra[]);
int buscar( char mensaje[], char cadena[][50], int tam);

int main()
{
    char nombre[T][50];
    char apellido[T][50];
    int edad[T];
    int nota[T];
    int opcion=0;
    int idEncontrado;
    do{
        opcion= menuOpcion();
       switch(opcion)
        {
            case 1:
                cargarDatos(nombre,apellido,edad, nota);
                fflush(stdin);
                break;
            case 2:
                fflush(stdin);
                idEncontrado= buscar("\nIngrese nombre para dar de baja: ", nombre, T);
                if(idEncontrado != -1)
                {
                    nota[idEncontrado]= -1; // BAJA LOGICA
                    printf("BAJA COMPLETADA");
                }
                break;
            case 3:
                fflush(stdin);
                idEncontrado= buscar("\nIngrese nombre para modificar: ", nombre, T);
                if(idEncontrado != -1)
                {
                    printf("\nINGRESE NOMBRE NUEVO: ");
                    gets(nombre[idEncontrado]);
                    printf("CAMBIO EXITOSO\n");
                }
                break;
            case 4:
                mostrarDatos(nombre,apellido,edad,nota );
                break;

        }
        fflush(stdin);
    }while(opcion != 5);

    /*
    char nombre[T][50]= {"Mariana", "Julio", "Ricardo", "Daniel"};
    char apellido[T][50]= {"Calgr", "Roca", "Pelok", " York"};
    int edad[T] = {19, 29, 22,54};
    int nota[T] = {2, 8, 9, 7};
    */
    mostrarDatos(nombre,apellido, edad, nota);


    return 0;
}

void cargarDatos(char nombre[][50], char apellido[][50], int edad[], int nota[])
{
    int i;
    for(i=0; i< T; i++)
    {
        //printf("\nIngrese nombre: ");
        //gets(nombre[i]);
        getString("\nIngrese nombre: ", nombre[i]);
        //esSoloLetras(nombre[i]);
        verificarCadena(nombre[i]);
        printf("\nIngrese apellido: ");
        gets(apellido[i]);
        printf("\nIngrese edad: ");
        scanf("%d", &edad[i]);
        printf("\nIngrese nota: ");
        scanf("%d", &nota[i]);
        fflush(stdin);
    }


}

void mostrarDatos(char nombre[][50], char apellido[][50], int edad[], int nota[])
{
    int i;
    printf("\n##############################################################\n");
    printf("%20s %20s %6s %6s \n", "Nombre","Apellido","Edad", "Nota");
    for (i= 0; i< T;i++)
    {
        if(nota[i] != -1)
        {
            printf("%20s %20s %6d %6d\n", nombre[i], apellido[i],edad[i],nota[i]);
        }

    }
}
int getString(char mensaje[], char input[])
{
    printf(mensaje);
    scanf("%s", input);
    return 0;
}
int verificarCadena(char cadena[51])
{
    int largoCadena;
    int i;
    largoCadena= strlen(cadena); // SE TOMA EL LARGO DEL NOMBRE
    int banderaCadena=0; // BANDERA PARA MARCAR QUE SE ENCONTRO UN CARACTER NO ALFABETICO, INICIALIZADO EN 0
    do
    {

        fflush(stdin);
        for(i=0; i<largoCadena; i++) // RECORRE EL STRING
        {
            if( isalpha(cadena[i]) || isspace(cadena[i]) ) // isalpha DEVUELVE UN VALOR DISTINTO A CERO SI EL CARACTER ES ALFABETICO, SI NO 0
            {
                banderaCadena = 1; // banderaCadena MARCARA 1 SI ES QUE EL CARACTER ANALIZADO ES ALFABETICO
            }
            else
            {
                banderaCadena=0; // EN CASO DE ENCONTRAR UN CARACTER NO ALFABETICO , SE BAJA LA BANDERA
                break;
            }
        }
        if(banderaCadena== 0) // SI EN ALGUN MOMENTO LA BANDERA FUE BAJADA, O NUNCA FUE SUBIDA, SE PIDE QUE REINGRESE EL NOMBRE Y SE VERIFICARA EN EL PROXIMO LOOP
        {
            printf("INGRESO ALGUN CARACTER INVALIDO. Reingrese de manera correcta:");
            scanf("%[^\n]",cadena);
        }
        //banderaCadena= 0;
        largoCadena= strlen(cadena); // SE VUELVE A MEDIR EL LARGO DEL NUEVO STRING

    }
    while(banderaCadena == 0);

    return 0;
}
int menuOpcion(void)
{
    int opcion;
    printf("Menu opciones: \n"
           "1- ALTAS\n"
           "2- BAJAS\n"
           "3- MODIFICACION\n"
           "4- MOSTRAR\n"
           "5- SALIR\n"
           "OPCION: ");
    scanf("%d", &opcion);


    return opcion;
}
int buscar(char mensaje[], char cadena[][50],int tam)
{
    char cadenaAux[50];
    int encontrado= -1;
    //printf("Ingrese nombre a buscar: ");
    printf(mensaje);
    gets(cadenaAux);
    for(int i= 0; i < tam; i++)
    {
        if(strcmp(cadenaAux, cadena[i])== 0)
        {
            printf("ID ENCONTRADO\n");
            encontrado = i;
            break;
        }
    }
    return encontrado;
}


