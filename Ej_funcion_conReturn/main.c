#include <stdio.h>
#include <stdlib.h>
int sumar(void);

int main()
{
    int suma;
    suma = sumar();
    printf("La suma es: %d",suma);
    return 0;
}
int sumar(void)
{
    int numeroUno;
    int numeroDos;
    int suma;

    printf("Ingrese el primer numero: ");
    scanf("%d", &numeroUno);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &numeroDos);

    suma = numeroUno+ numeroDos;

    return suma;

}


