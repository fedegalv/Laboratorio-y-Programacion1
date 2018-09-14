#include <stdio.h>
#include <stdlib.h>
#define T 3
#include "Funciones.h"
#include <string.h>


int main()
{
    char nombre[T][50];
    int respuesta;
    int legajo[T]= {0};
    int nota1[T]= {0};
    int nota2[T]= {0};
    int nota3[T]= {0};
    float promedio[T]= {0};
    char sexo[T]= {};
    int cargaRealizada= 0; // PARA MARCAR SI SE REALIZO AL MENOS UNA CARGA

    inicializaNombre(nombre); // INICIA LOS NOMBRES CON N/A

    printf("INGRESO DE ALUMNOS\n");
    do
    {
        fflush(stdin);
        printf("1 - CARGA DE DATOS\n");
        printf("2 - MODIFICACION DE DATOS\n");
        printf("3 - MOSTRAR TODOS LOS DATOS\n");
        printf("4 - INFORMES VARIOS\n");
        printf("5 - SALIR\n");
        printf("SELECCIONA UNA OPCION: ");
        scanf("%d",&respuesta);

        switch(respuesta)
        {
        case 1:
            cargaRealizada= cargarAlumnos(nombre,nota1,nota2,nota3, promedio, T,sexo,legajo,cargaRealizada);
            // CORREGIR VERIFICACION DE SEXO
            break;
        case 2:
            if(cargaRealizada > 0) // COMPROBAR SI SE REALIZO CARGA, SI NO SE REALIZO NO SE PUEDE MODIFICAR
            {
                modificarDatos(nombre,legajo,sexo,nota1,nota2,nota3,promedio,T);
            }
            else
            {
                printf("No se realizaron cargas de datos previamente, no se puede modificar\n");
            }

            break;
        case 3:
            mostrarResultados(nombre,legajo,sexo,nota1,nota2,nota3,promedio,T);
            break;
        case 4:
            break;
        case 5:
            break;

        }

    }
    while(respuesta != 5);

}
