#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include <time.h>
#include "Propietarios.h"
int mostrarMenu(void)
{
    int opcion;
    printf("***** MENU PRINCIPAL ESTACIONAMIENTO**** \n\n");
        printf("1- INGRESO DE DATOS DE PROPIETARIOS"
               "\n2- MODIFICAR DATOS DEL PROPIETARIO"
               "\n3- BAJA DEL PROPIETARIO"
               "\n4- LISTAR PROPIETARIOS"
               "\n5- INGRESO DE AUTOMOVIL"
               "\n6- EGRESO DE AUTOMOVIL"
               "\n7- MOSTRAR AUTOS ESTACIONADO"
               "\n8- RECAUDACION TOTAL ESTACIONAMIENTO"
               "\n9- RECAUDACION POR MARCA"
               "\n10- AUTOS POR PROPIETARIOS"
               "\n11- LISTADO DE AUTOS AUDI"
               "\n12- LISTADO DE AUTOS ESTACIONADO CON LOS DATOS DE  SUS PROPIETARIOS, ORDENADO POR PATENTE"
               "\n13- SALIR DEL PROGRAMA\n"
               "\nOPCIONES SELECCIONADA: ");
        scanf("%d",&opcion);
        return opcion;
}

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
int verificarTarjeta(char tarjeta[])
{
    int tamTarjeta;
    int i;
    int esValido =1 ;
    tamTarjeta= strlen(tarjeta);
    for(i=0; i <tamTarjeta; i++)
    {
        if( isdigit(tarjeta[i]) )
        {
            continue;
        }
        else
        {
            esValido= 0;
            printf("INGRESO ALGUN CARACTER NO VALIDO, VUELVA A INGRESAR\n");
            break;
        }
    }
    if( esValido != 0)
    {

        printf("LARGO DE TARJETA INGRESADA: %d\n",tamTarjeta);
        if (tamTarjeta < 16 || tamTarjeta > 16)
        {
            printf("No tiene el largo correcto\n");
            esValido= 0;
        }
        else
        {
            printf("TARJETA VALIDA\n");
        }
    }
    return esValido;
}

int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}

int validacionPatente(char patente[])
{
    int tamPantente;
    int j;
    int patenteValida = 1;
    tamPantente= strlen(patente);
    if(tamPantente == 7)
        for(j=0; j <3; j++)
        {
            if( isalpha(patente[j]) )
            {
                continue;
            }
            else
            {
                patenteValida= 0;
                printf("PATENTE NO VALIDA, EL FORMATO ES: AAA 111\n");
                break;
            }
        }
    if(patenteValida == 1)
    {
        for(j=3; j < 7; j++)
        {
            if( j== 3 && isspace(patente[j] ))
            {
                continue;
            }
            else
            {
                if( isdigit(patente[j]) )
                {
                    continue;
                }
                else
                {
                    patenteValida = 0;
                    printf("PATENTE NO VALIDA, EL FORMATO ES: AAA 111\n");
                    break;
                }
            }
        }
    }
    return patenteValida;
}
