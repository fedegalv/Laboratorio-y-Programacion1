#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int entero;
    char caracter;
}eDato;

int main()
{
    eDato miDato= {1,'B'};
    eDato* pDato = &miDato;

    printf("%d -- %c\n", (*(pDato)).entero, (*(pDato)).caracter );
    printf("%d -- %c\n", pDato->entero, pDato->caracter );
    return 0;
}
