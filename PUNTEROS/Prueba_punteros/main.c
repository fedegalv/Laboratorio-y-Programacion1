#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int modelo;
    char tipo;
} eMoto;

int main()
{
    int* pModelo = NULL;
    int modelo;
    eMoto suzuki[2]= { {4,'A'} , {5,'B'} }; /// DECLARACION VARIABLE
    eMoto* pSuzuki= NULL;

    modelo = 22;
    pModelo = &modelo; /// GUARDA LA DIRECCION DE MEMORIA DE modelo A pModelo
    pSuzuki = suzuki; /// GUARDA LA DIRECCION DE MEMORIA DEL VECTOR suzuki A pSuziki


    printf("direccion %p\n", pModelo);
    printf("%d\n", modelo);

    *pModelo= *pModelo + 5;
    printf("%d\n", *pModelo);
    printf("%d\n", modelo);


    printf("direccion %p\n",pSuzuki);
    printf("modelo sin puntero %d\n", suzuki[0].modelo);
    pSuzuki->modelo = 22; /// USANDO LA FLECHA


    printf("%d\n",  pSuzuki->modelo);
    (*pSuzuki).modelo = 33; /// USANDO PARENTRESIS
    printf("%d",(*pSuzuki).modelo);

   // printf("%d", *(pSuzuki+1).modelo);
    //printf("%d\n", )




    return 0;
}
