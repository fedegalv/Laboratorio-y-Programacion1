#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
char tarjeta [23];
printf("ingrese tarjeta");
gets(tarjeta);
int tamTarjeta;
int i;
int esValido =0 ;
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
        break;
    }
}
if( esValido != 0)
{

    printf("%d\n",tamTarjeta);
    if (tamTarjeta < 16 || tamTarjeta > 16)
    {
        printf("No tiene el largo correcto.");
    }
    else
    {
        printf("TIENE LARGO CORRECTO");
    }
}
return esValido;
