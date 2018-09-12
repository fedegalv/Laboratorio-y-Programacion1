#include <stdio.h>
#include <stdlib.h>
int pedirNumeros(char[]);
int main()
{
    /*numero= pedirNumero();
    printf("EL numero es: %d",numero);
    */
    int legajo;
    int nota;
    int edad;
    legajo = pedirNumeros("Ingrese un legajo: ");
    nota= pedirNumeros("Ingrese una nota: ");
    edad= pedirNumeros("Ingrese una edad: ");
    return 0;
}
/*
int pedirNumero()
{
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d".&numero);
    return numero;

}
*/
int pedirNumeros(char texto[])
{
    int numero;
    printf("%s",texto);
    scanf("%d",&numero);
    return numero;
