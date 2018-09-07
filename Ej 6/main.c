#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int numero;
    int mayoresCero= 0;
    int menoresCero= 0;
    for(i=0;i<10;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&numero);

        if(numero > 0)
        {
            mayoresCero++;
        }
        if(numero <0)
        {
            menoresCero++;
        }
    }
    printf("Mayores a cero: %d\n",mayoresCero);
    printf("Menos a cero: %d",menoresCero);

    return 0;
}
