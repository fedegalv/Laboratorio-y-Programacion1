#include <stdio.h>
#include <stdlib.h>
#define T 3
#include "Funciones.h"
#include <string.h>


int main()
{
    char nombre[T][50];
    int respuesta;
    int respuestaInformes;
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
            printf("SELECCIONE TIPO DE INFORME\n");
            printf("1-Cantidad de alumnos con 6 o mas de promedio\n");
            printf("2- El/los alumnos con mejor promedio\n");
            printf("3- La/las alumnas con peor promedio\n");
            printf("4- Cantidad alumnos aprobados y desaprobados\n");
            printf("SELECCIONA UNA OPCION: ");
            scanf("%d",&respuestaInformes);
            switch(respuestaInformes)
            {
            case 1:
                alumnosPromedioMayor6(legajo,promedio);
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;

            case 4:
                break;
            default:
                break;

            }


            break;
        case 5:
            break;

        }

    }
    while(respuesta != 5);

}
