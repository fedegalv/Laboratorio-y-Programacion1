#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "OPERACIONES_MATEMATICAS.h"
#include "MENU.h"

float menuOperaciones(float numeroA,float numeroB,char *tipoOperacion,unsigned int *factorUno, unsigned int *factorDos)
{
    fflush(stdin);
    char opcion;
    float resultado;
    do
    {
        fflush(stdin);
        printf("a) Calcular la suma (%.0f + %.0f)\n",numeroA,numeroB);
        printf("b) Calcular la resta (%.0f - %.0f)\n",numeroA,numeroB);
        printf("c) Calcular la multiplicacion (%.0f * %.0f)\n",numeroA,numeroB);
        printf("d) Calcular la division (%.0f / %.0f\n",numeroA,numeroB);
        printf("e) Calcular el factorial (!%.0f y !%.0f)\n",numeroA,numeroB);
        printf("f) Salir\n");
        scanf("%c",&opcion); // Lee la opcion
        switch(opcion)
        {
        case 'a':
            resultado = operacionSuma(numeroA,numeroB);
            printf("Suma realizada con exito\n");
            *tipoOperacion = 's';
            opcion = 'f'; // Ya que la operacion fue realizada, se setea opcion en 'f' para salir del loop
            break;
        case 'b':
            resultado = operacionResta(numeroA,numeroB);
            printf("Resta realizada con exito\n");
            *tipoOperacion = 'r';
            opcion = 'f';  // Ya que la operacion fue realizada, se setea opcion en 'f' para salir del loop
            break;
        case 'c':
            resultado= operacionMultiplicacion(numeroA,numeroB);
            printf("Multiplicacion realizada con exito\n");
            *tipoOperacion = 'm';
            opcion = 'f';  // Ya que la operacion fue realizada, se setea opcion en 'f' para salir del loop
            break;
        case 'd':
            resultado= operacionDivision(numeroA,numeroB);
            *tipoOperacion = 'd';
            opcion = 'f';  // Ya que la operacion fue realizada, se setea opcion en 'f' para salir del loop
            break;
        case 'e':
            operacionFactorial(numeroA, numeroB,&*factorUno,&*factorDos);
            printf("Factoreo realizado");
            *tipoOperacion = 'f';
            opcion = 'f';  // Ya que la operacion fue realizada, se setea opcion en 'f' para salir del loop
            break;
        case 'f':
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }
    }
    while(opcion != 'f');
    printf("Regresando al menu principal...\n");
    system("pause"); // pausa el programa, para limpiar
    system("cls"); // se limpia la consola

    return resultado;
}
void menuResultados(double resultado, char *tipoOperacion, int numeroA, int numeroB,unsigned int *factorUno,unsigned int *factorDos)
{
    switch(*tipoOperacion)
    {
    case 's':
        printf("El resultado de %d+%d es: %.2f\n",numeroA,numeroB,resultado);
        break;
    case 'r':
        printf("El resultado de %d-%d es: %.2f\n",numeroA,numeroB,resultado);
        break;
    case 'm':
        printf("El resultado de %dx%d es: %.2f\n",numeroA,numeroB,resultado);
        break;
    case 'd':
        printf("El resultado de %d/%d es: %.2f\n",numeroA,numeroB,resultado);
        break;
    case 'f':
        printf("El factorial de %d es %u y el factorial de %d es %u\n",numeroA,*factorUno,numeroB,*factorDos);
        //printf("El resultado del factorial de  es: %.2f\n",numeroA,numeroB,resultado);
        break;
    }
    /*
        printf("El resultado de la operacion realizada es: %.2f \n",resultado);
        printf("EL valor del puntero es: %c \n",*tipoOperacion);
        printf("Regresando al menu principal...\n");
        system("pause"); // pausa el programa, para limpiar
        system("cls"); // se limpia la consola
        */
}
int ingresoNumero(char opcion)
{
    int numero;
    int esNumero; // esNumero funcionara como booleano, para validar si el numero es valido o no, en caso que no sea valido se volvera a pedirlo
    int numeroDevolver; // lo que se va a devolver  la funcion es numeroDevolver, para usar un solo return
    if(opcion == '1') //si se eligio la opcion, leer el valor, comprobar si es un numero y guardarlo en variable
    {
        do
        {
            char term;
            printf("Ingrese numero A: ");
            if(scanf("%d%c", &numero, &term) != 2 || term != '\n') // Comprueba si lo ingresado es un int o no
            {
                esNumero= 0;
                printf("No ingreso un numero valido. Reintentelo otra vez\n");
                fflush(stdin); // limpia el buffer de stdin
            }
            else
            {
                printf("El numero ingresado es: %d\n", numero);
                esNumero =1;
                numeroDevolver = numero; // Se prepara una variable que guarda el numero a retornar
                fflush(stdin);
            }
        }
        while(esNumero == 0);  //

    }
    if(opcion == '2')
    {
        do
        {
            char term;
            printf("Ingrese numero B: ");
            if(scanf("%d%c", &numero, &term) != 2 || term != '\n') // Comprueba si lo ingresado es un int o no
            {
                esNumero= 0;
                printf("No ingreso un numero valido. Reintentelo otra vez\n");
                fflush(stdin);
            }
            else
            {
                printf("El numero ingresado es: %d\n", numero);
                esNumero =1;
                numeroDevolver = numero; // Se prepara una variable que guarda el numero a retornar
                fflush(stdin);
            }
        }
        while(esNumero == 0);

    }
    return numeroDevolver; // Se devuelve un numero previamente verificado y validado.
}
