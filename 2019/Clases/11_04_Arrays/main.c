#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#define T 4
void cargarDatos(char [][50], char [][50], int[], int[]);
void mostrarDatos(char nombre[][50], char apellido[][50], int edad[], int nota[]);
int getString(char mensaje[], char input[]);
int verificarCadena(char cadena[51]);
int esSoloLetras(char palabra[]);
int main()
{
    char nombre[T][50];
    char apellido[T][50];
    int edad[T];
    int nota[T];

    cargarDatos(nombre,apellido,edad, nota);
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
        printf("\nIngrese nombre: ");
        gets(nombre[i]);
        esSoloLetras(nombre[i]);
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
        printf("%20s %20s %6d %6d\n", nombre[i], apellido[i],edad[i],nota[i]);
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

int esSoloLetras(char palabra[])
{
    int i;
    int flag= 0;
    for(i=0; i< strlen(palabra); i++);
    if( palabra[i] != ' ')
    {
        if(palabra[i] < 'a' && palabra[i] > 'z')
        {
            if(palabra[i] < 'A' && palabra[i] > 'Z')
            {
                flag= 1;
            }
            else{flag=1;}
        }
    }
    if(flag == 0)
    {
        printf("\nINGRESO UN CARACTER INVALIDO");
    }
    return flag;
}
