#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define A 3
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
typedef struct // DECLARACION
{
    int legajo; // DECLARACION CAMPOS, ATRIBUTOS
    char nombre[50]; // CADENA DE CHAR
    float promedio;


}eAlumno; // NOMBRE ESTRUCTURA

void mostrarAlumno(eAlumno);
eAlumno cargarAlumno();
void mostrarListado(eAlumno [],int );
void cargarListado(eAlumno [], int );


int main()
{
   /*
    eAlumno otroAlumno;
    otroAlumno = cargarAlumno(); // LLAMA LA FUNCION, Y ASIGNA A LA ESTRUCTURA otroAlumno EL RETORNO DE LA FUNCION
    mostrarAlumno(otroAlumno);
    */

    eAlumno listaAlumno[A];
    cargarListado(listaAlumno[],A);
    mostrarListado(listaAlumno[],A);
    //otroAlumno = cargarAlumno();
    //mostrarAlumno(otroAlumno);

    return 0;
}
void mostrarAlumno(eAlumno alumnoParametro)
{
    printf("%d-- %s-- %f \n",alumnoParametro.legajo,alumnoParametro.nombre,alumnoParametro.promedio);

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
void cargarListado(eAlumno listaAlumno[], int tam)
{
    int i;
    for(i=0; i < tam; i++)
    {
        listaAlumno[i] = cargarAlumno();
    }


}
void mostrarListado(eAlumno listaAlumno[],int tam)
{
    int i;
    for(i=0; i < tam; i++)
    {
        mostrarAlumno(listaAlumno[i]);
    }
}
