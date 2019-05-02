#include <stdio.h>
#include <stdlib.h>
#include "producto.h"

int main()
{
    //eProducto unProducto;
    eProducto arrayProductos[10];
    //unProducto= pedirProducto();
    //mostrarProducto(unProducto);
    construirArray(arrayProductos, 2);
    cargarArray(2, arrayProductos);
    mostrarArray(arrayProductos, 2);
    return 0;
}
