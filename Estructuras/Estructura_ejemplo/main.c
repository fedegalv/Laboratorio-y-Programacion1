#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumnos.h"
#include "Cursos.h"
#define A 3
#define VACIO 0
#define OCUPADO 1
#define ELIMINADO -1
//DEFINICION DE ESTRUCTURA

void COMENTARIOS()
{
    /* eAlumno miAlumno = {14,"pepe",3.4};  INICIALIZA

    eAlumno miAlumno; // eAlumno es ahora un tipo de variable, como un int, y hay que crear una variable con ella.
    miAlumno.legajo= 15;
    strcpy(miAlumno.nombre,"Juan"); / COMO ES UN STRING, PARA ASIGNAR SE USA STRCPY
    miAlumno.promedio= 21.10;
    printf("%d %s %f ",miAlumno.legajo,miAlumno.nombre,miAlumno.promedio); // SE DESEMPACA LA ESTRUCTURA PARA MOSTRARLA

    eAlumno otroAlumno; // SE DECLARA OTRA VARIABLE DEL TIPO eAlumno
    otroAlumno= miAlumno; // SE PUEDE ASIGNAR FACILMENTE ENTRE VARIABLES DEL MISMO TIPO
    */
}
int main()
{


    eAlumno listaAlumno[A];
    eCursos eMisCursos[3];
    inicializarCursos(eMisCursos);
    mostrarTodosLosCursos(eMisCursos,3);
    int opcion;
    inicializarAlumnos(listaAlumno,A,VACIO);
    inicializarAlumnosConDatos(listaAlumno,A);

    do
    {
        fflush(stdin);
        printf("1.Cargar \n2.Mostrar \n3.Borrar \n4.Modificar \n5.Salir \nEliga opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            if(cargarAlumnoEnListado(listaAlumno, A))
            {
                printf("Dato cargado con exito\n");
            }
            else{
                printf("No exite espacio disponible\n");
            }
            break;
        case 2:
            mostrarListado(listaAlumno, A);
            break;
        case 3:
            if(!borrarAlumno(listaAlumno,A))
            {
                printf("Dato no encontrado");
            }
            break;
        case 4:
                if(!modificarAlumno(listaAlumno,A))
            {
                printf("Dato no encontrado");
            }
                break;

        default:
            break;
        }

    }
    while(opcion!= 5);
    //cargarAlumnoEnListado(listaAlumno,A);
    //mostrarListado(listaAlumno,A);
    //otroAlumno = cargarAlumno();
    //mostrarAlumno(otroAlumno);

    return 0;
}
