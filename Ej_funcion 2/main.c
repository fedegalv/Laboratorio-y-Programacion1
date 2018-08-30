#include <stdio.h>
#include <stdlib.h>
void sumar(int , int);
int main()
{
    int numeroUno;
    int numeroDos;
    printf("Ingrese el primer numero: ");
    scanf("%d", &numeroUno);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &numeroDos);

    sumar(numeroUno,numeroDos);

    return 0;
}

void sumar(int n1, int n2)
{
    int suma;
    suma = n1+ n2;

    printf("La suma es : %d",suma);
}
