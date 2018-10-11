#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>

void limpiarPantalla(void)
{
    system("pause"); // pausa el programa, para limpiar
    system("cls"); // se limpia la consola
}

int ingresoNumero(void)
{
    int numero;
    int esNumero; // esNumero funcionara como booleano, para validar si el numero es valido o no, en caso que no sea valido se volvera a pedirlo
    int numeroDevolver; // Numero a devolver
    do
    {
        //COMPROBACION DEL NUMERO INGRESADO
        char aux;
        if(scanf("%d%c", &numero, &aux) != 2 || aux != '\n') // Comprueba si lo ingresado valido o no
        {
            esNumero= 0;
            printf("No ingreso un numero valido. Reintentelo otra vez\n");
            fflush(stdin); // Limpiar el buffer de teclado
        }
        else
        {
            esNumero =1;
            numeroDevolver = numero; // Variable que guarda el numero a retornar
            fflush(stdin); // Limpiar el buffer de teclado
        }
    }
    while(esNumero == 0); // Realizar el pedido mientras el numero no sea valido.

    return numeroDevolver;
}

int verificarCadena(char cadena[])
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

void formateoCadenas(char* texto)
{
    int i; // VARIABLE CONTROL
    int largo; // VARIABLE ALMACENA LARGO DEL STRING
    for(i = 0; texto[i]; i++) // POR SI ACASO PASAMOS TODOS LOS CARACTERES A MINUSCULA
    {
        texto[i] = tolower(texto[i]);
    }
    texto[0]=toupper(texto[0]); // SE CAMBIA LA PRIMERA LETRA A MAYUSCULA
    largo = strlen(texto); // SE ALMACENA EN largo LA CANTIDAD DE CARACTERES DEL STRING
    for(i=0; i< largo; i++) // SE RECORRE EL STRING
    {
        if(texto[i]==' ') // SI ENCUENTRA UN ESPACIO EN LA CADENA, ENTRA EN EL IF
        {
            texto[i+1]=toupper(texto[i+1]); // SE PONE EN MAYUSCULA EL CARACTER QUE LE SIGUE A EL ESPACIO(i ES EL ESPACIO, i+1 ES EL CARACTER QUE LE SIGUE)
        }
    }

}



