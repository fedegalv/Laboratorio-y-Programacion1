#include <stdio.h>
#include <stdlib.h>
/** \brief Calcula factorial de un numero
 *
 * \param int numero a factorear
 * \return int numero factoreado
 *
 */
int calcularFactorial(int);
int main()
{
    int numero;
    int factorial;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    factorial= calcularFactorial(numero);
    printf("%d",factorial);
    return 0;
}
int calcularFactorial(int numero)
{
    int factorial;
    if(numero == 0)
    {
        factorial=1;
    }
    else
    {
        factorial= numero * calcularFactorial(numero-1);
    }
    return factorial;
}
