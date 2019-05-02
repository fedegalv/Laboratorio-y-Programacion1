#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "FuncionesAux.h"
void clientesHardcoded(sClientes lista[])
{
    char nombre[5][50]= {"ARIEL", "FERNANDO", "MARIA", "PAOLA", "GERARD"};
    char apellido[5][50]= {"MACRON", "PFITEZ", "GONZALES", "STIFFLER", "POLKSI"};
    int cuit[5] = {2354565, 21245789, 213245, 1234565, 45612};
    int idCliente[5] = {1, 2, 3, 4, 5};

    for(int i=0; i < 5; i++)
    {
        lista[i].idCliente = idCliente[i];
        lista[i].cuit = cuit[i];
        strcpy(lista[i].nombre, nombre[i]);
        strcpy(lista[i].apellido, apellido[i]);
        lista[i].estado= 1;
    }
}
int altaClientes(sClientes lista[], int idAsignada)
{
    char nombre[50];
    char apellido[50];
    int cuit;
    printf("\nIngrese nombre: ");
    gets(nombre);
    verificarCadena(nombre);

    printf("\nIngrese apellido: ");
    gets(apellido);
    verificarCadena(apellido);

    printf("\nIngrese CUIT: ");
    cuit= ingresoNumero();

    strcpy(lista[idAsignada].nombre, nombre);
    strcpy(lista[idAsignada].apellido, apellido);
    lista[idAsignada].cuit = cuit;
    lista[idAsignada].estado= 1;
    lista[idAsignada].idCliente= idAsignada+1;
    printf("Alta exitosa\n");
    limpiarPantalla();
    return 0;
}
int buscarClienteID(sClientes lista[], int tam)
{
    int id;
    int posicionEncontrada= -1;
    printf("Ingrese id a buscar: ");
    id= ingresoNumero();
    for(int i= 0; i < tam; i++)
    {
        if(lista[i].idCliente == id && lista[i].estado == 1)
        {
            posicionEncontrada= i;
        }
    }
    return posicionEncontrada;
}
int modificarCliente(sClientes lista[], int posicionProvista)
{
    int opcion;
    if(posicionProvista != -1)
    {
        fflush(stdin);
        char aux[50];
        printf("Que desea modificar?\n 1.NOMBRE\n2.APELLIDO\n3.CUIT\nOPCION SELECCIONADA: ");
        scanf("%d", &opcion );
        switch(opcion)
        {
        case 1:

            printf("Ingrese nuevo nombre: ");
            gets(aux);
            verificarCadena(aux);
            strcpy(lista[posicionProvista].nombre, aux);
            printf("NOMBRE CAMBIADO\n");
            break;
        case 2:
            printf("Ingrese nuevo apellido: ");
            gets(aux);
            verificarCadena(aux);
            strcpy(lista[posicionProvista].apellido, aux);
            printf("APELLIDO CAMBIADO\n");
            break;
        case 3:

            printf("Ingrese nuevo CUIT: ");
            lista[posicionProvista].cuit= ingresoNumero();
            printf("CUIT CAMBIADO\n");
            break;
        }
    }
    limpiarPantalla();
    return 0;
}
void mostrarClientes(sClientes lista[], int tam)
{
   printf("%s %20s %20s %15s\n","ID","NOMBRE", "APELLIDO","CUIT");
   for(int i=0; i < tam; i++)
   {
       if(lista[i].estado == 1)
       {
            printf("%d %20s %20s %15d\n", lista[i].idCliente, lista[i].nombre, lista[i].apellido, lista[i].cuit);

       }
   }
   limpiarPantalla();
}
void bajaCliente(sClientes lista[], int posicionProvista)
{
    if(posicionProvista != -1)
    {
        printf("Cliente dado de baja\n");
        lista[posicionProvista].estado= 0;
    }
    else{printf("EL CLIENTE NO EXISTE");}
    limpiarPantalla();
}
int sClientes_Init( sClientes listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= 0;
            listado[i].idCliente= 0;
        }
    }
    return retorno;
}

int sClientes_buscarLugarLibre(sClientes listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
void mostrarClienteUnico(sClientes lista[],int posicion)
{
     printf("%15s  %15s  %20s\n", "NOMBRE", "APELLIDO", "CUIT");
     printf("%15s  %15s  %20d\n", lista[posicion].nombre ,lista[posicion].apellido,lista[posicion].cuit);

}
int posicionClientePorID(sClientes lista[], int tam, int idProvista)
{
    int posicionEncontrada= -1;
    for(int i= 0; i < tam; i++)
    {
        if(lista[i].idCliente == idProvista && lista[i].estado == 1)
        {
            posicionEncontrada= i;
        }
    }
    return posicionEncontrada;
}
