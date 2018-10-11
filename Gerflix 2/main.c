#include <stdio.h>
#include <stdlib.h>
#include "SeriesUsuarios.h"
#define TAMSERIE 5
#define TAMUSUARIO 10
#define TAM_USUARIOCLIENTES 20

int main()
{
    eSerie listaDeSeries[TAMSERIE];
    eUsuario listaDeUsuarios[TAMUSUARIO];
    eClienteSerie listaSeriesUsuarios[TAM_USUARIOCLIENTES];

    inicializarSeriesEstado(listaDeSeries, TAMSERIE);
    inicializarSeriesHardCode(listaDeSeries);

    inicializarUsuariosEstado(listaDeUsuarios,TAMUSUARIO);
    inicializarUsuariosHardCode(listaDeUsuarios);

    inicializarSeriesUsuariosHardCode(listaSeriesUsuarios);
    mostrarListaSeries(listaDeSeries, TAMSERIE);
    printf("\n");
    mostrarListaUsuarios(listaDeUsuarios,TAMUSUARIO);
    printf("\n");
    printf("\n");

    mostrarClientesEnSeries(listaDeUsuarios, TAMUSUARIO, listaDeSeries,
                             TAMSERIE, listaSeriesUsuarios );
    //mostrarUsuarioConSuSerie(listaDeUsuarios, TAMSERIE, listaDeSeries, TAMSERIE);
    //mostrarSerieconUsuario(listaDeUsuarios, TAMSERIE, listaDeSeries, TAMSERIE);


/*  1. Mostrar el listado de series
    2. Mostrar el listado de usuarios
    3. Mostrar el listado de Usuarios con el nombre de la serie que ve
    4. Mostrar por cada serie, el nombre de los usuarios que la ven.
*/




    return 0;
}
