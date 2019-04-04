#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "OPERACIONES_MATEMATICAS.h"
#include "MENU.h"

float operacionSuma(float numeroA,float numeroB)
{
    float suma;
    suma= numeroA + numeroB;

    return suma;
}
float operacionResta(float numeroA,float numeroB)
{
    float resta;
    resta = numeroA - numeroB;
    return resta;
}

float operacionMultiplicacion(float numeroA,float numeroB)
{
    float multiplicacion;
    multiplicacion = numeroA * numeroB;
    return multiplicacion;

}

float operacionDivision(float numeroA,float numeroB)
{
    float division;
    if(numeroB == 0)
    {
        printf("No se puede dividir por cero \n");
        return 0; // Para que no tire warnings
    }
    else
    {
        division=(float)numeroA / (float)numeroB;
        printf("Division realizada con exito\n");

        return division;

    }
}

void operacionFactorial(int numeroA,int numeroB,unsigned int *factorUno, unsigned int *factorDos)
{
    unsigned int respuestaFactoreoUno= 1; // se inicializa el resultado del factoreo en 1
    unsigned int respuestaFactoreoDos= 1;
    int i;

    if (numeroA < 0 && numeroB < 0) // Se verifica que el numero se a mayor a 0, osea factorizable
    {
        printf("Error, no se puede factorizar un numero negativo.");
    }

    else
    {
        for(i=1; i<=numeroA; ++i)
        {
            respuestaFactoreoUno= respuestaFactoreoUno * i;
        }
        printf("factor %u\n",respuestaFactoreoUno);

        for(i=1; i<=numeroB; ++i)
        {
            respuestaFactoreoDos= respuestaFactoreoDos * i;
        }
        printf("factor %u\n",respuestaFactoreoDos);

        *factorUno= respuestaFactoreoUno;
        *factorDos= respuestaFactoreoDos;
    }
    return;
}






