#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "OPERACIONES_MATEMATICAS.h"
#include "MENU.h"

int main()
{
    char opcion;
    int numeroA;
    int numeroB;
    double resultado;
    int numeroValidoA;
    int numeroValidoB;
    int operacionRealizada;
    char *tipoOperacion;
    unsigned int *factorUno;
    unsigned int *factorDos;

    operacionRealizada = 0; // Para verificar si una operacion fue realizada, si lo fue cambia a 1.
    numeroValidoA = 0; //Para verificar que se ingreso correctamente el primer numero, si lo fue cambia a 1
    numeroValidoB = 0; // Para verificar que se ingreso correctamente el segundo numero, si lo fue cambia a 1
    numeroA= 0; //donde se guarda el numero ingresado
    numeroB= 0; //donde se guarda el numero ingresado
    do
    {
        printf("BIENVENIDO\n");
        printf("POR FAVOR, SELECCIONA UNA OPCION \n");
        printf("(1) Ingresar 1er operando(A= %d): \n",numeroA);
        printf("(2) Ingresar 2do operando(B= %d: \n",numeroB);
        printf("(3) Operaciones: \n");
        printf("(4) Informar resultados \n");
        printf("(5) Salir\n");
        fflush(stdin); // limpiar el buffer
        scanf("%c",&opcion);

        switch(opcion)
        {
        case '1': // INGRESAR 1ER OPERANDO
            numeroA=ingresoNumero(opcion); // llama a la funcion ingresoNumero, y devuelve un numero que se guarda en la variable
            printf("Numero ingresado con exito, ahora se limpiara la pantalla...\n");
            numeroValidoA = 1; // Se cambia a 1 ya que el valor fue validado
            system("pause"); // pausa el programa, para limpiar
            system("cls"); // se limpia la consola
            break;

        case '2': //INGRESAR 2DO OPERANDO
            numeroB=ingresoNumero(opcion);
            printf("Numero ingresado con exito, ahora se limpiara la pantalla...\n");
            numeroValidoB = 1; // Se cambia a 1 ya que el valor fue validado
            system("pause"); // pausa el programa, para limpiar
            system("cls"); // se limpia la consola
            break;

        case '3': //OPERACIONES
            if ((numeroValidoA+numeroValidoB) == 2) // Si se ingresaron 2 numeros, validados en la funcion ingresoNumero, se procede a realizar las operaciones
            {
                resultado= menuOperaciones(numeroA,numeroB,&tipoOperacion,&factorUno,&factorDos); // llama a menuOperaciones, que trae un menu para elegir entre operaciones matematicas
                operacionRealizada= 1; // La operacion se realizo, entonces cambia a 1
            }
            else
            {
                printf("No ingreso la cantidad suficiente de numeros para operar, volviendo al menu principal..\n");
            }
            break;
        case '4': //INFORMAR RESULTADO
            if (operacionRealizada == 1) // Si se realizo una operacion, se muestra el resultado
            {
                menuResultados(resultado,&tipoOperacion,numeroA,numeroB,&factorUno,&factorDos);
            }
            else
            {
                printf("No se realizaron operaciones y no hay resultados que mostrar, volviendo al menu principal...\n");
            }
            break;
        case '5': // SALIR
            break;
        default:
            printf("Opcion invalida. Por favor seleccione una de las opciones provistas.\n");
        }


        //system("pause"); // pausa el programa, para limpiar
        //system("cls"); // se limpia la consola
        fflush(stdin);
    }
    while(opcion != '5');
    return 0;
}
