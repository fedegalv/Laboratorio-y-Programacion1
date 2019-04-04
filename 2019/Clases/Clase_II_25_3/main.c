#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "biblioteca.h"
int main()
{
    char letra;
    char palabra[100];

    //scanf("%c", &letra);
    //printf("\nletra %c\n",letra);
    //fflush(stdin);

    scanf("%s", palabra);
    printf("\nstring %s",palabra);
    int indice= 0;
    int es;
    while(indice < strlen(palabra) )
    {
        printf("\nletra %c", palabra[indice]);

        indice++;
    }
    es= esUnNumero(palabra);
    if(es == 1)
    {
        printf("es correcto");
    }
    else{
        printf("no lo es");
    }


    /*
    int miDato= 333;
    cambiarValor(miDato);
    printf("Mi dato es: %d\n", miDato);

    cambiarValorReferencia(&miDato);
    printf("\nMi dato es: %d", miDato);
    //saludar();
    int dato;
    dato = dividir(6);
    printf("el dato es : %d\n", dato);
    dato = dividir(0);
    printf("el dato es: %d", dato);
    int edad;
    int retorno= 0;
    do
    {
        printf("Ingrese una edad: ");
        retorno= scanf("%d",&edad);
        //dividir(edad);
        fflush(stdin);
    }
    while(retorno== 0);

    printf("la respuesta es: %d\n", retorno);
    printf("la edad es: %d", edad);

    int unFactorial;
    unFactorial= factorial(4);
    printf("El factorial es: %d", unFactorial);
    */
    return 0;
}

