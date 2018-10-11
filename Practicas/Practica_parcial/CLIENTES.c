#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include "CLIENTES.h"
#include "FUNCIONESAUX.h"

void inicializarClientes(sCliente cLista[], int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        cLista[i].estado= 0; // INICIAR DESACTIVADOS
    }
}

int pedirDatosCliente(sCliente cLista[], int id, int len)
{
    char nombre[51];
    char apellido[51];
    int cuit;
    int opRealizada= -1;
    printf("CLIENTE NUMERO DE ID: %d\n", id);
    fflush(stdin);

    printf("Ingrese nombre del cliente: ");
    gets(nombre);
    verificarCadena(nombre);
    formateoCadenas(nombre);

    fflush(stdin);

    printf("Ingrese apellido del cliente: ");
    gets(apellido);
    verificarCadena(apellido);
    formateoCadenas(apellido);
    fflush(stdin);

    printf("Ingrese cuit del cliente: ");
    cuit=ingresoNumero();

    // AGREGAR VERIFICACION DE DATOS, AL VERIFICAR TODOS LOS DATOS Y QUE ESTOS DEN 3, DEVOLVER VALIDO 0, SI NO DEVOLVER OTRO VALOR

    opRealizada= agregarClientes( cLista, id, len, nombre,apellido,cuit);
    return opRealizada;
}

int agregarClientes(sCliente* cLista,int id,int len,char nombre[],char apellido[], int cuit )
{
    int operacionCompletada;
    operacionCompletada = -1; // SE PONE POR DEFAULT COMO INVALIDO

    cLista[id].idCliente= id;
    cLista[id].cuit= cuit;
    strcpy(cLista[id].nombre, nombre);
    strcpy(cLista[id].apellido, apellido);
    cLista[id].estado= 1;

    operacionCompletada = 1; // LA OPERACION FUE REALIZADA CON EXITO
    return operacionCompletada;
}
int buscarClienteID(sCliente cLista[], int len, int idProvista)
{
    int i;
    int idEncontrada;
    idEncontrada= -1;
    for (i=0; i < len; i++)
    {
        if(cLista[i].estado == 1 && cLista[i].idCliente == idProvista)
        {
            idEncontrada = i; // GUARDA EN idEncontrada LA POSICION EN EL ARRAY DEL EMPLEADO CON EL ID A BUSCAR
        }
    }

    return idEncontrada;
}
