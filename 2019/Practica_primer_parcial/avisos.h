#include "clientes.h"
#ifndef avisos_H
#define avisos_H
typedef struct
{
    int idCliente;
    int numeroRubro;
    char textoAviso[64];
    int estado;

} sAvisos;
int altaAviso(sAvisos lista[], sClientes listaClientes[], int tamClientes, int id);
int sAvisos_buscarLugarLibre(sAvisos listado[],int limite);
int sAvisos_Init( sAvisos listado[],int limite);
int buscarAvisosID(sAvisos lista[], int tam);
int pausarAviso(sAvisos lista[],sClientes listaClientes[], int tam,int );
void mostrarAvisos(sAvisos lista[], int tam);
int buscarAvisosID(sAvisos lista[], int tam);
void mostrarAvisoUnico(sAvisos lista[],int posicion);
void avisosHardcoded(sAvisos lista[]);
int reanudarAviso(sAvisos lista[], sClientes listaClientes[], int tam,int );
int buscarEnAvisos(sAvisos lista[], int tam);
void mostrarAvisosCliente(sAvisos lista[],int , int tam, int tipo);
int posicionAvisoPorID(sAvisos lista[], int tam, int idProvista);
int posicionAvisoPausadosPorID(sAvisos lista[], int tam, int idProvista);





#endif

