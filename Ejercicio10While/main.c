#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    char respuesta;
    int numero;
    int maximo = INT_MIN;
    int minimo = INT_MAX;
    int sumaPositivos = 0;
    int sumaNegativos = 0;
    int cantidadPositivos = 0;
    int cantidadNegativos = 0;
    int cantidadCeros = 0;
    int cantidadPares = 0;
    float promedioPositivos;
    float promedioNegativos;
    int diferenciaPositivosYNegativos;
    int contador = 0;

    do
    {
        printf("\n(iteracion nro %d) Ingrese el numero: ",contador+1);
        scanf("%d",&numero);
        if(numero == 0)
        {
            cantidadCeros++;
        }
        if(numero > 0)
        {
            cantidadPositivos++;
            sumaPositivos=sumaPositivos + numero;
        }
        if(numero < 0)
        {
            cantidadNegativos++;
            sumaNegativos = sumaNegativos + numero;
        }

        if( (numero%2)==0 )
        {
            cantidadPares++;
        }

        if(numero > maximo)
        {
            maximo = numero;
        }
        if(numero < minimo)
        {
            minimo= numero;
        }

        printf("\nDesea seguir ingresando numeros (s/n): ");
        fflush(stdin);
        scanf("%c",&respuesta);
        contador++;
    }
    while(respuesta == 's');

    diferenciaPositivosYNegativos= sumaPositivos-sumaNegativos;
    promedioPositivos= (float)sumaPositivos / (float)cantidadPositivos;
    promedioNegativos= (float)sumaNegativos / (float)cantidadNegativos;

    printf("La suma de los positivos es: %d\n",sumaPositivos);
    printf("La suma de los negativos es: %d\n",sumaNegativos);
    printf("La cantidad de positivos es: %d y la cantidad de negativos es: %d\n",cantidadPositivos,cantidadNegativos);
    printf("La cantidad de ceros es: %d\n",cantidadCeros);
    printf("La cantidad de pares es: %d\n",cantidadPares);
    printf("Promedio de positivos es: %.2f  y el promedio de negativos es: %.2f \n",promedioPositivos,promedioNegativos);
    printf("La diferencia entre positivos y negativos es %d\n",diferenciaPositivosYNegativos);
    printf("El numero maximo es: %d y el numero minimo es: %d\n",maximo,minimo);

        return 0;
}
