#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "producto.h"

eProducto pedirProducto()
{
    fflush(stdin);
    eProducto retorno;
    printf("\nIngrese nombre : ");
    gets(retorno.nombre);
    fflush(stdin);

    printf("Ingrese codigo de barra: ");
    gets(retorno.codigoDeBarra);
    fflush(stdin);

    printf("Ingrese fecha de vencimiento: ");
    gets(retorno.fechaDeVencimiento);
    fflush(stdin);

    printf("Ingrese proveedor: ");
    gets(retorno.proveedor);
    fflush(stdin);

    printf("Ingrese precio: ");
    scanf("%f", &retorno.precio);
    return retorno;
}
void mostrarProducto(eProducto producto)
{
    printf("\n\nNombre: %s\nCodigo de barra: %s\nFecha vencimiento: %s\nProveedor: %s\nPrecio: %.02f",
           producto.nombre, producto.codigoDeBarra, producto.fechaDeVencimiento,
           producto.proveedor, producto.precio);
}
void cargarArray(int tam, eProducto arrayProductos[])
{
    int i;
    for(i= 0; i< tam; i++)
    {
        arrayProductos[i]= pedirProducto();
    }
}
void mostrarArray(eProducto arrayProductos[], int tam)
{
    int i;
    for(i= 0; i< tam; i++)
    {
        if(arrayProductos[i].estado == 1)
        mostrarProducto(arrayProductos[i]);
    }
}

void construirArray(eProducto arrayProductos[],int tam)
{
     int i;
    for(i= 0; i< tam; i++)
    {
        arrayProductos[i].estado = 0;
    }
}
int insertProducto(eProducto elProducto, eProducto arrayProductos[], int tam)
{
    int indice;
    indice=dameLugarLibre(arrayProductos, tam);
    if(indice != -1)
    {
        arrayProductos[indice]=elProducto;
    }
    return indice;
}
int dameLugarLibre(eProducto arrayProducto[], int tam)
{
    int indice =-1;
    int i;
    for(i=0; i< tam; i++)
    {
        if(arrayProducto[i].estado == 0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}
int existeProducto(eProducto elProducto, eProducto arrayProductos[], int tam)
{
    int indice= -1;
    int i;
    for(i=0; i < tam; i++)
    {

        if( strcmp(elProducto.nombre, arrayProductos[i].nombre) )
        {
            indice = i;
        break;
        }
    }
    return indice;
}
int borrarProducto(eProducto elProducto, eProducto arrayProducto[], int tam)
{
    int indice;
    indice= existeProducto(elProducto, arrayProducto, tam);
    if(indice != -1)
    {
        arrayProducto[indice].estado= -1;
    }
    return indice;
}
int editarProducto(eProducto, eProducto[]);
