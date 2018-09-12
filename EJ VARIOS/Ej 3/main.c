#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1;
    int numero2;
    int producto;
    int cuadradoNumero;
    do{
        printf("Ingrese el primer numero: ");
        scanf("%d",&numero1);
    }while(numero1 == 0);

    do{
        printf("Ingrese el segundo numero: ");
        scanf("%d",&numero2);
    }while(numero2 == 0);
    producto= numero1 * numero2;
    cuadradoNumero= numero1 * numero1;

    printf("El producto de los numeros: %d",producto);
    printf("\nEl cuadrado del primer numero es: %d",cuadradoNumero);

    return 0;
}
