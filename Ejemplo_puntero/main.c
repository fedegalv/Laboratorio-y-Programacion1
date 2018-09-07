#include <stdio.h>
#include <stdlib.h>
int miFuncion(int*);
int main()
{
    int miEntero =3;
    int estado;
    estado =  miFuncion(&miEntero);
    printf("EL nuevo valor es %d\n",miEntero);
    if(estado == 1)
    {
        printf("El valor es mayor a 15\n");
    }
    else{
        printf("EL valor es menor o igual.\n");
    }
    return 0;
}
int miFuncion(int* pValor)
{
    int queDevuelve= 0;
    printf("%d",*pValor);
    // int aux;
    //aux = (*pValor);
    //aux += 10;
    /*
    if (aux>15)
    {
    queDevuelve= 1;
    }
    *pValor = aux;
    */
    (*pValor) += 10;
    if(*pValor>15)
    {
        queDevuelve = 1;
    }
    return queDevuelve;
}
