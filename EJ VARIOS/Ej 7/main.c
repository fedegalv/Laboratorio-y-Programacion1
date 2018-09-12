#include <stdio.h>
#include <stdlib.h>

int main()
{
    int base;
    int altura;
    int superficie;

    printf("Ingrese la base: ");
    scanf("%d",&base);

    printf("\nIngrese la altura: ");
    scanf("%d",&altura);

    superficie= (base*altura) / 2;

    printf("\nLa superficie del triangulo es : %d m2",superficie);
    return 0;
}
