#include <stdio.h>
#include <stdlib.h>
#define T 3
/*
a-CARGA DE DATOS (CARGA ALEATORIA, EL USUARIO ELIGE)
b- MODIFICAR (AGREGAR LEGAJO) , SE INGRESA EL LEGAJO, LO BUSCA Y MODIFICA LA NOTA 1


c- INFORMES:
PEDIR SOLO NOMNRE; NO COMPLETO
CREAR UN MENU PARA ELEGIR
1- ALUMNOS CON PROMEDIO 6 O MAS
2- EL O LOS ALUMNOS CON MAXIMO PROMEDIO
3- SEXO DEL ALUMNO
4- LA O LAS ALUMNA CON MINIMO PROMEDIO
5- CANTIDAD DE ALUMNOS DESAPROBADOS
6- CANTIDAD DE ALUMNOS APROBADOS
7- PORCENTAJE DE APROBADOS Y DESAPROBADOS (SE APRUEBA CON 6 O MAS)
8- LOS ALUMNOS QUE SE LLAMEN JUAN MOSTRARLOS
9- ORDENAR LOS DATOS ALFABETICAMENTE POR NOMBRE
10- ORDENAR LOS DATOS POR NOMBRE Y ANTE IGUALDAD DE NOMBRE POR PROMEDIO
11- MOSTRAR LOS ALUMNOS CUYO NOMMBRE COMIENZA CON P
12- ORDENAR ALUMNOS POR SEXO
13- MOSTRAR UN GRAFICO QUE MUESTRA:
    ALUMNOS ENTRE 15-18 INCLUSIVE
                  19-25 INCLUSIVE
                  26 O MAS



*/

float calcularPromedio(int, int, int);
int cargarAlumnos(char[][50], int[],int[],int[],float[],int);
int mostrarResultados(char[][50], int[],int[],int[],float[],int);
int main()
{
    char nombreCompleto[T][50]; // DECLARA VECTOR BI DIMENSIONAL, T REPRESENTA I, 50 J
    int nota1[T];
    int nota2[T];
    int nota3[T];
    float promedio[T];
    int i;
    cargarAlumnos(nombreCompleto,nota1,nota2,nota3,promedio,T);
    printf("%20s %6s %6s %6s %6s \n", "Nombre","Nota1","Nota2", "Nota3", "Promedio");
    for (i= 0; i< T;i++)
    {
        printf("%20s %6d %6d %6d %6.2f \n", nombreCompleto[i], nota1[i],nota2[i],nota3[i],promedio[i]);
    }




    return 0;
}

float calcularPromedio(int nota1, int nota2, int nota3)
{
    float promedio;
    promedio =( (float)(nota1 + nota2 + nota3) / 3);
    return promedio;
}

int cargarAlumnos(char nombre[][50], int nota1[],int nota2[],int nota3[],float promedio[],int tam)
{
    int i;

    for(i= 0; i< T;i++)
    {
        printf("Ingrese su nombre completo: ");
        gets(nombre[i]);
        fflush(stdin);
        printf("Ingrese la nota 1: ");
        scanf("%d", &nota1[i]);
        fflush(stdin);
        printf("Ingrese la nota 2: ");
        scanf("%d", &nota2[i]);
        fflush(stdin);
        printf("Ingrese la nota 3: ");
        scanf("%d", &nota3[i]);
        fflush(stdin);
        promedio[i]= calcularPromedio(nota1[i],nota2[i],nota3[i]); // LA FUNCION RECIBE LOS VALORES DENTRO DEL ARRAY, NO HACE FALTA EN VIAR EL ARRAY ENTERO
    }


    return 0;
}
