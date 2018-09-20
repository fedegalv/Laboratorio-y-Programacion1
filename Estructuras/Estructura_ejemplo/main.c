#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
typedef struct // DECLARACION
{
    int legajo; // DECLARACION CAMPOS, ATRIBUTOS
    char nombre[50]; // CADENA DE CHAR
    float promedio;
    int estado;


} eAlumno; // NOMBRE ESTRUCTURA

void mostrarAlumno(eAlumno);
eAlumno cargarAlumno();
void mostrarListado(eAlumno [],int );
int cargarAlumnoEnListado(eAlumno [], int );
void inicializarAlumnos(eAlumno [],int , int );
int buscarEspacio(eAlumno[], int);
int borrarAlumno(eAlumno[], int);


int main()
{
    /*
     eAlumno otroAlumno;
     otroAlumno = cargarAlumno(); // LLAMA LA FUNCION, Y ASIGNA A LA ESTRUCTURA otroAlumno EL RETORNO DE LA FUNCION
     mostrarAlumno(otroAlumno);
     */

    eAlumno listaAlumno[A];
    int opcion;
    inicializarAlumnos(listaAlumno,A,VACIO);

    do
    {
        fflush(stdin);
        printf("1.Cargar \n2.Mostrar \n3.Borrar \n4.Salir \nEliga opcion: ");
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
        default:
            break;
        }

    }
    while(opcion!= 4);
    //cargarAlumnoEnListado(listaAlumno,A);
    //mostrarListado(listaAlumno,A);
    //otroAlumno = cargarAlumno();
    //mostrarAlumno(otroAlumno);

    return 0;
}
void mostrarAlumno(eAlumno alumnoParametro)
{
    printf("%d  -- %s  -- %f \n",alumnoParametro.legajo,alumnoParametro.nombre,alumnoParametro.promedio);

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

