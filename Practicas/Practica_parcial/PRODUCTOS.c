#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "PRODUCTOS.h"
#include "FUNCIONESAUX.h"
void inicializarPublicaciones(ePublicacion pLista[], int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        pLista[i].estado= 0; // INICIAR DESACTIVADOS
    }
}

int pedirDatosPublicaciones(ePublicacion pLista[], int idPublicacion, int len)
{
    char texto[64];
    int idCliente;
    int numeroRubro;
    int opRealizada= -1;
    printf("AVISO ID NUMERO: %d\n", idPublicacion);

    printf("Ingrese id del cliente: ");
    idCliente= ingresoNumero();
    fflush(stdin);

    printf("Ingrese rubro de la publicacion: ");
    numeroRubro= ingresoNumero();
    printf("Ingrese texto de la publicaciones: ");
    gets(texto);
    verificarCadena(texto);
    fflush(stdin);

    opRealizada= agregarPublicacion( pLista, idCliente, idPublicacion, texto, numeroRubro);
    return opRealizada;
}

int agregarPublicacion(ePublicacion* pLista,int idCliente,int idPublicacion,char texto[], int numeroRubro)
{
    int operacionCompletada;
    operacionCompletada = -1; // SE PONE POR DEFAULT COMO INVALIDO

    pLista[idPublicacion].idCliente = idCliente;
    pLista[idPublicacion].idAviso= idPublicacion;
    pLista[idPublicacion].numeroRubro= numeroRubro;
    strcpy(pLista[idPublicacion].texto, texto);
    pLista[idPublicacion].estado= 1; // ACTIVO


    operacionCompletada = 1; // LA OPERACION FUE REALIZADA CON EXITO
    return operacionCompletada;
}
