#include <stdio.h>
#include <string.h>
#include "Alumno.h"
sAlumno pedirAlumno()
{
    sAlumno alumnito;


    printf("Ingrese legajo: ");
    scanf("%d", &alumnito.legajo);
    printf("Ingrese Nombre: ");
    fflush(stdin);
    gets(alumnito.nombre);
    printf("Ingrese promedio: ");
    scanf("%f", &alumnito.promedio);
    printf("Ingrese edad: ");
    scanf("%d", &alumnito.edad);

    return alumnito;

}


void mostrarUnAlumno(sAlumno miAlumno)
{
    printf("%d--%s--%f--%d\n", miAlumno.legajo, miAlumno.nombre,
           miAlumno.promedio, miAlumno.edad);

}

void cargarListadoDeAlumnos(sAlumno listado[], int tam)
{
    int i;
     for(i=0; i<tam; i++)
    {
       listado[i]=pedirAlumno();

    }
}
void mostrarListadoDeAlumnos(sAlumno listado[], int tam)
{
    int i;

     for(i=0; i<tam; i++)
    {
        mostrarUnAlumno(listado[i]);
    }
}

void ordenarListadoDeAlumnosPorNombre(sAlumno listado[], int tam)
{
    sAlumno auxAlumno;
    int i;
    int j;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listado[i].nombre,listado[j].nombre)>0)
            {
                auxAlumno = listado[i];
                listado[i] = listado[j];
                listado[j] = auxAlumno;

            }
        }
    }


}

