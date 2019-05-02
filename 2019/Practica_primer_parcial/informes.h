#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avisos.h"
#include "clientes.h"
#include "FuncionesAux.h"
void mostrarMenuInformes(sClientes lista[], sAvisos listaAvisos[], int tamClientes, int tamAvisos);
void sCliente_MayorAvisosActivos(sClientes lista[], sAvisos listaAvisos[], int tamClientes, int tamAvisos);
void sCliente_MayorAvisosPausados(sClientes lista[], sAvisos listaAvisos[], int tamClientes, int tamAvisos);
void sCliente_ClienteConMasAvisos(sClientes lista[], sAvisos listaAvisos[], int tamClientes, int tamAvisos);
void sAvisos_PublicacionesActivas(sAvisos listaAvisos[], int tamAvisos);
void mostrarMenuInformesAvisos(sAvisos listaAvisos[], int tamAvisos);
void sAvisos_PublicacionesMenosActivas(sAvisos listaAvisos[], int tamAvisos);
void sAvisos_PublicacionesActivasPorRubro(sAvisos listaAvisos[], int tamAvisos);
