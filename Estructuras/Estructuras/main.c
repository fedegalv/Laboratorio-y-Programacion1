#include <stdlib.h>
#include "Alumno.h"
#define A 3




int main()
{
    sAlumno listadoMain[A];
    int i;

    cargarListadoDeAlumnos(listadoMain, A);

    mostrarListadoDeAlumnos(listadoMain, A);

    printf("Ordenar\n");

    ordenarListadoDeAlumnosPorNombre(listadoMain, A);

    mostrarListadoDeAlumnos(listadoMain, A);




    return 0;
}

