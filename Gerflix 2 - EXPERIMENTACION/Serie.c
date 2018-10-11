#include <stdio.h>
#include <stdlib.h>
#include "Serie.h"
#include <string.h>

/*
    int idSerie;
    char nombre[50];
    char genero[20];
    int cantidadTemporadas;
    int estado;

*/

void inicializarSeriesEstado(eSerie series[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        series[i].estado = 0;
    }
}


void inicializarSeriesHardCode(eSerie series[])
{
    int idSerie[5] = {100,101,102,103,104};
    int estado[5]= {1,1,1,1,1};
    char titulo[5][30]= {"TBBT","BB","GOT","AHS","SCD"};
    int temporadas[5] = {10,9,7,5,2};
    char genero[5][30]= {"Comedia","Policial","Ciencia Ficcion","Terror","Comedia"};

    int i;

    for(i=0; i<5; i++)
    {
        series[i].idSerie = idSerie[i];
        series[i].estado = estado[i];
        strcpy(series[i].titulo, titulo[i]);
        series[i].temporadas= temporadas[i];
        strcpy(series[i].genero, genero[i]);
    }
}
void mostrarListaSeries(eSerie series[],int tam)
{
    int i;
    printf("%15s %15s %15s %15s \n","NOMBRE","GENERO", "C. TEMP", "ID");
    for( i=0; i<tam; i++)
    {
        if(series[i].estado == 1)  // SE PODRIA REMOVER YA QUE POR DEFECTOS TODOS LOS ESTADOS SON INICIALIZADOS EN 1
        {
            printf("%15s %15s %15d %15d \n",series[i].titulo, series[i].genero, series[i].temporadas, series[i].idSerie);
        }
    }


}
