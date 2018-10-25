#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void cargar(int* , int);
void mostrar(int* , int);
int main()
{
    //char caracter = 'c';
    //char* pCaracter = NULL;
    //pCaracter = &caracter;
    //pCaracter = &caracter;
    /*
    printf("%p\n", &caracter);
    printf("%p\n", &pCaracter);
    printf("%c\n", caracter);

    printf("%p\n", pCaracter); //MUESTA LA DIRECCION de MEMORIA GUARDAD EN pCaracter

    if(pCaracter != NULL)
    {
        printf("%c", *pCaracter);// MUESTRA EL CONTENIDO DE LA DIRECCION QUE GUARDA EL PUNTERO pCaracter
    }
    */
    /**< MANERAS DE GUARDAR VARIABLES EN PUNTEROS */
    /*
    printf("Ingrese char: ");
    //scanf("%c", &caracter);
    caracter = getchar();
    printf("%c\n", *pCaracter); // MOSTRAR CONTENIDO DEL PUNTERO pCaracter
    fflush(stdin);



    printf("Ingrese otro char: ");
    //scanf("%c\n", pCaracter);
    *pCaracter = getchar();
    printf("%c\n", *pCaracter);
 // ARITMETICA DE PUNTEROS
    */

    /*
    int entero;
    int* pEntero;
    pEntero = &entero;
    printf("%d\n", &entero);
    printf("%d\n", pEntero);
    printf("%d\n", pEntero+1);
    printf("%d\n", pEntero+2);
    printf("%d\n", pEntero+3);
    */

    int array[5];
    int* pEntero;
    /*
    int i;

    pEntero = array;
    for(i =0; i< 5; i++)
    {
        printf("ingrese numero: ");
        scanf("%d", pEntero+i);
    }


    for(i =0; i< 5; i++)
    {
        printf("%d\n", *(pEntero+i));
    }
    */
    cargar(array,5);
    mostrar(array,5);




    return 0;
}

void cargar(int* pArray, int len )
{
    int i;
    for(i =0; i< 5; i++)
    {
        printf("ingrese numero: ");
        scanf("%d", pArray+i);
    }
}
void mostrar(int* pArray, int len)
{
    int i;
    for(i =0; i< 5; i++)
    {
        printf("%d\n", *(pArray+i));
    }
}
