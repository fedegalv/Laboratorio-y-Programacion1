#include <stdio.h>
#include <stdlib.h>
#include "Series_y_usuarios.h"

#define TAM_USUARIO 10
#define TAM_SERIE 10
int main()
{
    int cont=1;
    int opcion;
    eUsuario users[TAM_USUARIO];
    eSerie series[TAM_SERIE];

    do
    {
        printf("1-ALTAS\n"
               "2-BAJAS\n"
               "3-MODIFICACION\n"
               "4-MOSTRAR\n\n");
        printf("SELECCIONE OPCION: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            printf("ALTAS:....");
            inicializarSeriesEstado(series,TAM_USUARIO);
            inicializarUsuariosEstado(users,TAM_USUARIO);
            inicializarUsuariosHardCode(users);
            inicializarSeriesHardCode(series);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            printf("MOSTRANDO..\n");
            mostrarListaUsuarios(users, TAM_USUARIO);
            mostrarListaSeries(series, TAM_SERIE);
            break;
        default:
            break;
        }


    }while(cont == 1);
    return 0;
}
