#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pEntero;

    pEntero= (int* )malloc(sizeof(int)
);
    /// malloc(size)
    /// ASIGNAMOS A pEntero la direccion de memoria reservada por malloc y esta se castea a int para que sea consistente
    /// LO QUE ESTOY DEVOLVEIENDO CON LO QUE RECIBE
    /// MALLOC BUSCA ESPACIO EN MEMORIA EN EL HEAP
    if(pEntero != NULL)
    {
       *pEntero = 9;
       printf("%d\n", *pEntero);
    }
    else{
        printf("NO HAY SUFICIENTE ESPACIO");
    }
    free(pEntero);
    /// FREE LIBERA EL ESPACIO RESERVADO POR MALLOC,
    printf("%d", *pEntero);

    return 0;
}
