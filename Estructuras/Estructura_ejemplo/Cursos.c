#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumnos.h"
#include "Cursos.h"

void inicializarCursos(eCursos cursos[])
{
    int id[3]= {100,101,102};
    char nombre[3][51] = {"PHP","VB","C#"};
    int duracion[3]= {3,5,6};
    char profesor[3][51]= {"Christian", "Octavio", "Maxi"};
    int i;
    for(i=0; i< 3 ; i++)
    {
        cursos[i].id = id[i];
        cursos[i].duracion = duracion[i];
        strcpy(cursos[i].nombre, nombre[i]);
        strcpy(cursos[i].profesor, profesor[i]);
    }
}

void mostrarCursos(eCursos curso)
{
    printf("%d  -- %s  -- %s -- %d \n",curso.id, curso.nombre, curso.profesor, curso.duracion);

}
void mostrarTodosLosCursos(eCursos cursos[] , int tam)
{
    int i;
    for(i=0; i < tam; i++)
    {
        mostrarCursos(cursos[i]);
    }
}
