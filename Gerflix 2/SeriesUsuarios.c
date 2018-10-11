#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SeriesUsuarios.h"
void inicializarSeriesUsuariosHardCode(eClienteSerie listaSeriesUsuarios[])
{
    int cliente[20] = {   1, 1,  1,  2,  2,  3,  4,  4,  5,  5,  5,  7, 8,   8,  8,  9, 10, 10, 10, 10};
    int serie[20]= {    101,102,103,104,103,101,101,102,104,101,103,101,101,102,103,102,101,103,102,104};
    int i;

    for(i=0; i<20; i++)
    {
        listaSeriesUsuarios[i].clienteID= cliente[i];
        listaSeriesUsuarios[i].serieID = serie[i];

    }
}

void mostrarClientesEnSeries(eUsuario usuarios[], int tamUsuario, eSerie series[],
                             int tamSerie, eClienteSerie listaSeriesUsuarios[] )
{
    int i;
    int j;
    int k;


    int idSerieEncontrada;
    for(i=0; i < 20; i++)
    {
        for(j = 0;j <20; j++)//tamUsuario
        {
            if(listaSeriesUsuarios[i].clienteID == usuarios[j].idUsuario)
            {
                printf("Series vistas por el usuario:  %s\n", usuarios[j].nombre);
                idSerieEncontrada= listaSeriesUsuarios[i].serieID;
                for(k=0; k < 20; k++) // tamSerie
                {
                    if (series[k].idSerie == idSerieEncontrada)
                    {
                        printf("%8s\n", series[k].titulo);
                    }
                }

            }
        }
    }

}

/*********************
idEncontrada = listaSeriesUsuarios[i].clienteID;
                idSerieEncontrada = listaSeriesUsuarios[i].serieID;
                printf("Series vistas por %s: \n", usuarios[idEncontrada].nombre);
                for(k= 0; k < tamSerie; k++)
                {
                    if(series[j].idSerie == idSerieEncontrada)
                    {
                        printf("%10s ",series[j].titulo);
                    }
                }


**************************************/



