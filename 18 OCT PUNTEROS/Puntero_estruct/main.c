#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int entero;
    char caracter;
}eDato;

int main()
{
    /*
    eDato miDato = {1,'B'};
    eDato* pDato;
    pDato = &miDato;

    printf("%d -- %c\n", miDato.entero, miDato.caracter);
    printf("%d -- %c\n", (*pDato).entero, (*pDato).caracter); // ACCEDER AL DATO DENTRO DE LA ESTRUCTURA PUNTERO

    */
    eDato miDato[2] = { {1,'B'}, {2,'R'} };
    eDato* pDato;
    pDato = miDato;
    int i;
    for(i=0; i<2; i++)
    {
        printf("%d -- %c\n", (*(pDato+i)).entero, (*(pDato+i)).caracter );
    }

    /*
    printf("%d -- %c\n", miDato.entero, miDato.caracter);
    printf("%d -- %c\n", (*pDato).entero, (*pDato).caracter); // ACCEDER AL DATO DENTRO DE LA ESTRUCTURA PUNTERO
    */
    return 0;
}
