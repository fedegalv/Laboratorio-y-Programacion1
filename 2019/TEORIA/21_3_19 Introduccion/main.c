#include <stdio.h>
#include <stdlib.h>

void saludar (void);
int dameNumero(void);
float sacarPromedio(int suma,int cantidad);
void esPrimo(int numero);
int main()
{
    int edad;
    float altura;
    int contador;
    int numero;
    int suma;
    float promedio;
    int limite;
    altura=82.5;
    edad=66;
    saludar();
    limite= dameNumero();

    printf("\n ingrese su altura :");
    scanf("%f", &altura);
    printf("\n ingrese su edad :");
    scanf("%d", &edad);

    contador=0;
    suma=0;

    while(contador<limite)
        {
            //5 4 4 4 4
            printf("\n ingrese un numero:");
            scanf("%d", &numero);

            suma=suma+numero;
            contador++;
        }
       // promedio= (float)suma/contador; //aca el float funciona como funcion, transformando la operacion en con coma
        promedio=sacarPromedio(suma,contador);
        printf(" el promedio es :%.2f",promedio); // el .2 me sirve para reducir los 00 pos coma, 4,2000 = 4,20


    return 0;

}
void saludar (void)
{
    printf("hola mundo c");
}
int dameNumero(void)
{
    int cantidad;
    printf("\n ingrese la cantidad de iteraciones: ");
    scanf("%d",&cantidad);

    return cantidad;
}
float sacarPromedio(int suma,int cantidad)
{
    float promedio;
    promedio= (float)suma/cantidad;
    return promedio;
}
