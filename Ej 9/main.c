#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int contadorA = 0;
    int contadorE = 0;
    int contadorI = 0;
    int contadorO = 0;
    int contadorU = 0;
    char caracter;

    for(i=0;i<10;i++)
    {
        printf("\n(loop %d)Ingrese un caracter: ",i+1);
        scanf("%c",&caracter);
        switch(caracter)
        {
        case 'a':
            contadorA++;
            break;
        case 'e':
            contadorE++;
            break;
        case 'i':
            contadorI++;
            break;
        case 'o':
            contadorO++;
            break;
        case 'u':
            contadorU++;
            break;
        }
        fflush(stdin);


    }
    printf("Cantidad de veces que un caracter se repitio:");
    printf("\nA: %d , E: %d , I: %d , O: %d , U: %d",contadorA,contadorE,contadorI,contadorO,contadorU);
    return 0;
}
