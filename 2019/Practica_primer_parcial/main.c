#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "avisos.h"
#include "informes.h"
#include "FuncionesAux.h"
#define CLIENTES 10
#define PUBLICACIONES 20
int main()
{
    sClientes listaClientes[CLIENTES];
    sAvisos listaAvisos [PUBLICACIONES];

    sClientes_Init(listaClientes, CLIENTES);
    sAvisos_Init(listaAvisos, PUBLICACIONES);

    clientesHardcoded(listaClientes);
    avisosHardcoded(listaAvisos);

    int opcion;
    int id;

    do
    {
        opcion= menuOpciones();
        fflush(stdin);
        switch(opcion)
        {
        case 1:
            id= sClientes_buscarLugarLibre(listaClientes, CLIENTES);
            if(id != -1 && id != -2)
            {
                altaClientes(listaClientes, id);
            }
            else{
                    printf("LA LISTA ESTA LLENA O NO EXISTE/n");
                    limpiarPantalla();
                }
            break;
        case 2:
            id= buscarClienteID(listaClientes, CLIENTES);
            modificarCliente(listaClientes, id);
            break;
        case 3:
            id= buscarClienteID(listaClientes, CLIENTES);
            bajaCliente(listaClientes, id);
            break;
        case 4:
            id= sAvisos_buscarLugarLibre(listaAvisos, PUBLICACIONES);
            if(id != -1 && id != -2)
            {
                altaAviso(listaAvisos, listaClientes, CLIENTES, id);
            }
            else{
                    printf("LA LISTA ESTA LLENA O NO EXISTE/n");
                    limpiarPantalla();
                }
            break;
        case 5:
            pausarAviso(listaAvisos, listaClientes,  PUBLICACIONES, CLIENTES);
            break;
        case 6:
            reanudarAviso(listaAvisos, listaClientes, PUBLICACIONES, CLIENTES);
            break;
        case 7:
            mostrarClientes(listaClientes, CLIENTES);
            break;
        case 8:
            mostrarAvisos(listaAvisos, PUBLICACIONES);
            break;
        case 9:
            mostrarMenuInformes(listaClientes, listaAvisos, CLIENTES, PUBLICACIONES);
            break;
        case 10:
            mostrarMenuInformesAvisos(listaAvisos, PUBLICACIONES);
            break;
        default:
            printf("OPCION NO VALIDA/n");
        }
/////// COMPLETAR INFORMES /////
    }
    while(opcion != 11);


}
