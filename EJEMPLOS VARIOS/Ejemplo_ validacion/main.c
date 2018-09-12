#include <stdio.h>
#include <stdlib.h>
#include "UTN_INPUT.h"
int main()
{
    int edad;
    edad = pedirEntero("edad: ",18,65);
    printf("La edad es: %d",edad);
    return 0;
}
