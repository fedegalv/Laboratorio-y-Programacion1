#include <stdio.h>
#include <stdlib.h>
#define T 3
#include "Funciones.h"
#include <string.h>
#include <ctype.h>

int cargarAlumnos(char nombre[][50], int nota1[],int nota2[],int nota3[],float promedio[], int tam, char sexo[],int legajo[],int cargaRealizada)
{
    int i;
    printf("INGRESO DE ALUMNOS\n");
    printf("INDIQUE EN QUE LEGAJO GUARDAR: ");
    scanf("%d", &i);

    i= i-1;
    legajo[i]= i;

    fflush(stdin);

    printf("Ingrese su nombre: ");
    gets(nombre[i]);

    verificarNombre(nombre[i]);

    printf("Ingrese la nota 1: ");
    scanf("%d", &nota1[i]);
    verificarNota(nota1[i]);

    printf("Ingrese la nota 2: ");
    scanf("%d", &nota2[i]);
    verificarNota(nota2[i]);

    printf("Ingrese la nota 3: ");
    scanf("%d", &nota3[i]);
    verificarNota(nota3[i]);

    fflush(stdin);

    printf("Ingrese sexo: ");
    scanf("%c", &sexo[i]);
    verificarSexo(sexo[i]);

    promedio[i] = calcularPromedio(nota1[i], nota2[i], nota3[i]);
    cargaRealizada =1; // SI SE REALIZO LA CARGA CORRECTAMENTE SE LEVANTA BANDERA

    return cargaRealizada;
}


float calcularPromedio(int nota1, int nota2, int nota3)
{
    float promedio;

    promedio = (float)(nota1 + nota2 + nota3)/3;
    return promedio;
}


int inicializaNombre(char nombre[][50])
{
    int i;

    for(i=0; i<T; i++)
    {
        strcpy(nombre[i],"N/A");
    }
    return 0;
}


int mostrarResultados (char nombre[][50], int legajo[], char sexo[], int nota1[],int nota2[],int nota3[],float promedio[], int tam)
{
    int i;
    //int tempLegajo = legajo{i} -1:
    printf("%18s %8s %8s %8s %8s %8s %8s \n", "Nombre","Legajo","Sexo", "Nota 1", "Nota 2", "Nota 3", "Promedio" );
    for(i=0; i<tam; i++)
    {
        printf("%18s %8d %8c %8d %8d %8d %8.2f \n", nombre[i],legajo[i]+1,sexo[i], nota1[i], nota2[i], nota3[i], promedio[i]);
    }
    return 0;
}
int verificarNombre(char nombre[50])
{
    int largoNombre;
    int i;
    largoNombre= strlen(nombre); // SE TOMA EL LARGO DEL NOMBRE
    int banderaNombre=0; // BANDERA PARA MARCAR QUE SE ENCONTRO UN CARACTER NO ALFABETICO, INICIALIZADO EN 0
    do
    {

        fflush(stdin);
        for(i=0; i<largoNombre; i++) // RECORRE EL STRING
        {
            if( isalpha(nombre[i]) || isspace(nombre[i]) ) // isalpha DEVUELVE UN VALOR DISTINTO A CERO SI EL CARACTER ES ALFABETICO, SI NO 0
            {
                banderaNombre = 1; // banderaNombre MARCARA 1 SI ES QUE EL CARACTER ANALIZADO ES ALFABETICO
            }
            else
            {
                banderaNombre=0; // EN CASO DE ENCONTRAR UN CARACTER NO ALFABETICO , SE BAJA LA BANDERA
                break;
            }
        }
        if(banderaNombre== 0) // SI EN ALGUN MOMENTO LA BANDERA FUE BAJADA, O NUNCA FUE SUBIDA, SE PIDE QUE REINGRESE EL NOMBRE Y SE VERIFICARA EN EL PROXIMO LOOP
        {
            puts(nombre);
            printf("INGRESO ALGUN CARACTER INVALIDO. Reingrese su nombre de manera correcta:");
            scanf("%[^\n]",nombre);
        }

        largoNombre= strlen(nombre); // SE VUELVE A MEDIR EL LARGO DEL NUEVO STRING

    }
    while(banderaNombre == 0);

    return 0;
}

int verificarNota(int nota)

{
    int banderaNota = 0;
    do
    {
        fflush(stdin);
        if(isalpha(nota))
        {
            banderaNota= 0;
        }
        if( nota >= 0 && nota <= 10)
        {
            banderaNota = 1;
        }

        if(isalpha(nota))
        {
            banderaNota= 0;
        }

        if(banderaNota == 0)
        {
            printf("VALOR INVALIDO. Reingrese nota(0-10): ");
            scanf("%d",&nota);
        }

    }
    while(banderaNota == 0);
    return 0;

}

int verificarSexo(char sexo)
{
    int banderaSexo = 0;
    sexo= toupper(sexo);

    do
    {
        fflush(stdin);
        if(sexo == 'M' || sexo == 'F')
        {
            banderaSexo = 1;
        }
        else
        {

                printf("DATO INVALIDO. Reingrese un sexo valido: ");
                scanf("%c",&sexo);
                sexo= toupper(sexo);

        }
    }
    while(banderaSexo == 0);
    return 0;

}

int modificarDatos(char nombre[][50], int legajo[], char sexo[], int nota1[],int nota2[],int nota3[],float promedio[], int tam)
{
    int legajoCambiar;
    printf("Ingrese legajo a modificar: ");
    scanf("%d", &legajoCambiar); // AGREGAR VERIFICACION
    /*if(legajo[legajoCambiar-1] == 0)
    {
        printf("Legajo vacio, volviendo al menu..");
    }else
    */
    modificaAlumnos(nombre,nota1,nota2,nota3,promedio,tam,sexo,legajo,legajoCambiar);



    return 0;
}

int modificaAlumnos(char nombre[][50], int nota1[],int nota2[],int nota3[],float promedio[], int tam, char sexo[],int legajo[],int legajoCambiar)
{
    int i;
    printf("MODIFICANDO LEGAJO NUMERO: %d \n",legajoCambiar);
    i= legajoCambiar-1;
    legajo[i]= i;

    fflush(stdin);

    printf("Ingrese su nombre: ");
    gets(nombre[i]);

    verificarNombre(nombre[i]);

    printf("Ingrese la nota 1: ");
    scanf("%d", &nota1[i]);
    verificarNota(nota1[i]);

    printf("Ingrese la nota 2: ");
    scanf("%d", &nota2[i]);
    verificarNota(nota2[i]);

    printf("Ingrese la nota 3: ");
    scanf("%d", &nota3[i]);
    verificarNota(nota3[i]);

    fflush(stdin);

    printf("Ingrese sexo: ");
    scanf("%c", &sexo[i]);
    verificarSexo(sexo[i]);

    promedio[i] = calcularPromedio(nota1[i], nota2[i], nota3[i]);


    return 0;
}

int alumnosPromedioMayor6(int legajo[],float promedio[])
{

}
