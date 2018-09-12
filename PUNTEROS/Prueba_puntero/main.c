#include <stdio.h>
#include <stdlib.h>
int esValido(int,int,int*);
int main()
{
    int numeroA= 0;
    int numeroB= 0;
    int operacionValida; // DECLARO VARIABLE
    int resultado;
    printf("Ingrese numero 1:\n");
    scanf("%d",&numeroA);
    printf("Ingrese numero 2: \n");
    scanf("%d",&numeroB);
    resultado=esValido(numeroA,numeroB,&operacionValida); // ENVIO COMO ARGUMENTO LA DIRECCION EN MEMORIA DE operacionValida
    if(operacionValida == 1)
    {
        printf("Numero valido, la suma es %d",resultado);
    }


    return 0;
}
int esValido(int numeroA, int numeroB,int *operacionValida) // INGRESA COMO ARGUMENTO LA DIRECCION DE MEMORIA DE operacionValida
{
    int suma;
    if(numeroA>0 && numeroB>0)
    {
        *operacionValida = 1;
        printf("Es valido \n");
        suma= numeroA+numeroB;
    }

    return suma;
}
