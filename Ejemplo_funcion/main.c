#include <stdio.h>
#include <stdlib.h>
void sumar(void);
int main()
{
    sumar();
    return 0;
}

void sumar(void)
{
    int numeroUno;
    int numeroDos;
    int suma;

    printf("Ingrese el primer numero: ");
    scanf("%d", &numeroUno);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &numeroDos);

    suma = numeroUno+ numeroDos;

    printf("La suma es : %d",suma);

}
