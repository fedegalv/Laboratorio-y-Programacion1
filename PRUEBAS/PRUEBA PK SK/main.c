#include <stdio.h>
#include <stdlib.h>
#include "NombreApellido.h"

#define TAM_NOMBRE 10
#define TAM_APELLIDO 10
#define TAM_CLIENTES 10
int main()
{
    eNombre listaNombres[TAM_NOMBRE];
    eApellido listaApellidos[TAM_APELLIDO];
    eCliente listaClientes[TAM_CLIENTES];


    initNameState(listaNombres, TAM_NOMBRE);
    initNamesHardCoded(listaNombres,TAM_NOMBRE);

    initSurnamesState(listaApellidos,TAM_APELLIDO);
    initSurnamesHardCoded(listaApellidos,TAM_APELLIDO);

    showNameList(listaNombres, TAM_NOMBRE);
    printf("\n");
    printf("\n");
    showSurnameList(listaApellidos, TAM_APELLIDO);
    initNameAndSurnameHardCoded(listaClientes);

    showClientFullname(listaNombres,TAM_NOMBRE,listaApellidos,TAM_APELLIDO,listaClientes,TAM_CLIENTES);





    return 0;
}
