#include <stdio.h>
#include <stdlib.h>
int saludar(void)
{
    printf("hola biblioteca");
    return 0;
}
int esDistitoCero(int numero)
{
    if(numero != 0)
    {
        return 1; // NO PONER MAS DE UN RETURN
    }
    return 0;
}
int dividir(int numero)
{
    int respuesta;
    int resultado;
    respuesta= esDistitoCero(numero);
    if (respuesta == 1)
    {
        resultado= numero/2;
    }

    return respuesta;
}
int factorial(int numero)
{
    int respuesta;
    if(numero == 1)
    {
        return 1;
    }
    respuesta= numero*factorial(numero-1);
    return respuesta;
}
int cambiarValor(int valor)
{
    valor= 9999;
    return 1;
}
int cambiarValorReferencia(int* valor)
{
    printf("el valor es %d", *valor);
    *valor= 9999;
    return 1;
}

int dividirPorDiferencia(int datoUno, int datoDos, float* respuesta)
{
    if(datoUno != 0)
    {
        *respuesta= (float)datoUno/datoDos;
        return 1;
    }
    return 0;
}
int esUnNumero(char* cadena)
{
    printf("\npalabra por parametro: %s", cadena);
    int indice= 0;
    int retorno= 0;
    while(cadena[indice] != '\0')
    {
        if(cadena[indice] < '0' || cadena[indice] > '9')
        {
            break;
        }
        else{
            indice++;
        }
    }

    if(cadena[indice] != '\0')
    {
        retorno=1;
    }
    return retorno;
}

