#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumnos.h"
#define A 3
#define VACIO 0
#define OCUPADO 1
#define ELIMINADO -1
void mostrarAlumno(eAlumno alumnoParametro)
{
    printf("%d  -- %s  -- %f -- \n",alumnoParametro.legajo,alumnoParametro.nombre,alumnoParametro.promedio);

}

void inicializarAlumnos(eAlumno lista[],int tam, int estado)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado= VACIO;
    }
}

eAlumno cargarAlumno()
{
    eAlumno miAlumno;
    printf("INGRESE UN LEGAJO: ");
    scanf("%d",&miAlumno.legajo); // &miAlumno marca direccion de memoria a legajo
    fflush(stdin);
    printf("INGRESE UN NOMBRE: ");
    gets(miAlumno.nombre);
    printf("INGRESE UN PROMEDIO: ");
    scanf("%f",&miAlumno.promedio);
    return miAlumno; // DEVUELVE miAlumno Y SUS CONTENIDOS


}
int cargarAlumnoEnListado(eAlumno listaAlumno[], int tam)
{
    int indice;
    int encontro= 0;
    indice = buscarEspacio(listaAlumno,tam);
    if(indice != -1)
    {
        listaAlumno[indice] = cargarAlumno();
        listaAlumno[indice].estado = OCUPADO;
        encontro = 1;
    }
   return encontro;
}
void mostrarListado(eAlumno listaAlumno[],int tam)
{
    int i;
    for(i=0; i < tam; i++)
    {
        if(listaAlumno[i].estado == OCUPADO)
        {
            mostrarAlumno(listaAlumno[i]);
        }

    }
}

int buscarEspacio(eAlumno listaAlumno[], int tam)
{
    int indice= -1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(listaAlumno[i].estado == VACIO)
        {
            indice = i;
            break;
        }

    }
    return indice;
}

int borrarAlumno(eAlumno listaAlumno[], int tam)
{
    int legajo;
    int i;
    int encontro= 0;

    printf("Ingrese legajo a borrar: ");
    scanf("%d",&legajo);

    for(i=0;i<tam;i++)
    {
        if(legajo == listaAlumno[i].legajo && listaAlumno[i].estado == OCUPADO) // BORRA SI ENCUENTRA EL LEGAJO Y EL ALUMNO ESTA OCUPADO
        {
            listaAlumno[i].estado= ELIMINADO;
            encontro = 1;
            break;
        }
    }

    return encontro;
}
int modificarAlumno(eAlumno listaAlumno[], int tam)
{
    int legajo;
    int i;
    int encontro= 0;
    float promedio;

    printf("Ingrese legajo a modificar: ");
    scanf("%d",&legajo);

    for(i=0;i<tam;i++)
    {
        if(legajo == listaAlumno[i].legajo && listaAlumno[i].estado == OCUPADO) // BORRA SI ENCUENTRA EL LEGAJO Y EL ALUMNO ESTA OCUPADO
        {
            printf("Ingrese el nuevo promedio: ");
            scanf("%f",&promedio);
            listaAlumno[i].promedio= promedio;
            encontro = 1;
            break;
        }
    }

    return encontro;
}

void inicializarAlumnosConDatos(eAlumno listaAlumno[], int tam)
{
    int legajo[5]= {1,2,3,4,5}; // DECLARACION CAMPOS, ATRIBUTOS
    char nombre[5][50]= {"Juan","Maria","Pedro","Ricardo","Ana",}; // CADENA DE CHAR
    float promedio[5]= {3,6,7,9,1};
    int i;

    for(i=0; i<5; i++)
    {
        listaAlumno[i].legajo = legajo[i];
        strcpy(listaAlumno[i].nombre,nombre[i]);
        listaAlumno[i].promedio = promedio[i];
        listaAlumno[i].estado = OCUPADO;
    }
}
