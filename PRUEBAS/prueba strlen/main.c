#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
int main()
{
    /*
    char tarjeta [23];
    printf("ingrese tarjeta:");
    gets(tarjeta);
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
            printf("CARACTER NO VALIDO");
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

*/
    char patente [23];
    printf("ingrese patente:");
    gets(patente);
    int tamPantente;
    int j;
    int patenteValida = 1;
    tamPantente= strlen(patente);
    if(tamPantente == 6)
        for(j=0; j <3; j++)
        {
            if( isalpha(patente[j]) )
            {
                continue;
            }
            else
            {
                patenteValida= 0;
                printf("PATENTE NO VALIDA, EL FORMATO ES: AAA 111");
                break;
            }
        }
    if(patenteValida == 1)
    {
        for(j=3; j <= 6; j++)
        {
            if( isspace(patente[j] ))
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
                    printf("PATENTE NO VALIDA, EL FORMATO ES: AAA 111");
                    break;
                }
            }
        }
    }
    puts(patente);

    return 0;
}
