#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"


void manejador(int (*funcion)(int), int);


int main()
{
    //manejador(mostrar, 10);
    int i,r;
    int (*funcion[2])(int);

    funcion[0] = mostrar;

    funcion[1] = mostrarDOS;

    for(i=0; i<2; i++)
    {
         r=funcion[i](100);
         printf("Retorno funcion %d -> %d\n", i+1, r);
    }

    return 0;
}

void manejador(int (*funcion)(int), int valor)
{
    int retorno;
    retorno = funcion(valor);
    printf("El incremento es: %d", retorno);
}








/**/
