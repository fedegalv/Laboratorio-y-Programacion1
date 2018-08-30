#include <stdio.h>
#include <stdlib.h>
int sumar (int , int);
int main()
{
    int numeroUno;
    int numeroDos;
    int suma;

    printf("Ingrese el primer numero: ");
    scanf("%d", &numeroUno);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &numeroDos);

    suma = sumar(numeroUno,numeroDos);
    printf("La suma es: %d",suma);


    return 0;
}
int sumar(int numeroUno, int numeroDos)
{
    int suma;
    suma = numeroUno+numeroDos;
    return suma;
}
