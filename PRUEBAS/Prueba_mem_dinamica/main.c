#include <stdio.h>
#include <stdlib.h>
#include "string.h"
typedef struct {
    char nombre[15];
    int edad;
    int nota;
}eAlumno; // CREAMOS LA ESTRUCTURA

void pedirDatos(eAlumno*, int); //PROTOTIPO FUNCION
void mostrarDatos(eAlumno* , int ); // PROTOTIPO FUNCION
int main()
{
    eAlumno* pListaAlumnos; // CREAMOS PUNTERO
    eAlumno* auxListaAlumnos;// AUXILIAR PUNTERO

    int tam;
    int flag = 1;
    printf("Ingrese tamanio del vector: ");
    scanf("%d", &tam);
    pListaAlumnos= (eAlumno*) malloc( sizeof(eAlumno)* tam ); // ASIGNAMOS ESPACIO DE MEMORIA AL HEAP SEGUN EL TAMANIO INDICADO POR USUARIO
    printf("tamanio del vector %d\n", tam);

    do{
    pedirDatos(pListaAlumnos, tam);
    mostrarDatos(pListaAlumnos, tam);
    printf("DESEA CAMBIAR EL TAMANIO DEL VECTOR? 1/0: ");
    scanf("%d", &flag);
    if(flag== 1)
    {
        printf("Reingrese tamanio del vector: ");
        scanf("%d", &tam);
        auxListaAlumnos= (eAlumno*) realloc(pListaAlumnos, sizeof(eAlumno)* tam); // SE GUARDA EN UN AUX PARA NO PERDER EL DATO ORIGINAL EN CASO DE QUE DEVUELVA NULL POR FLATA DE MEMORIA
        if(auxListaAlumnos!= NULL)
        { // SI AUX ES DISTINTO A NULL, Y POR LO TNATO NO FUE BORRADO, SE GUARDA EN LA LISTA ORIGINAL EL CONTENIDO DEL AUXILIAR, EN CASO CONTRARIO SE ALERTA SOBRE LO QUE PASO
            pListaAlumnos= auxListaAlumnos;
        }


    }else{break;}
    }while (flag == 1);

    return 0;
}
void pedirDatos (eAlumno* pListaAlumnos, int tam ) // LA FUNCION RECIBE LISTA ALUMNOS COMO REFERENCIA( PUNTERO) Y NO POR VALOR
{
    int i;
    if(pListaAlumnos != NULL )
    {
        for(i=0; i<tam; i++)
        {
            printf("INGRESE nombre: \n");
            scanf("%s", (pListaAlumnos+i)->nombre ); // CADENA DE CARACTERES NO HACE FALTA EL AMPERSAM & &
            printf("INGRESE edad: \n");
            scanf("%d", &(pListaAlumnos+i)->edad); // REQUIERE AMPERSAN EN OTRO TIPO DE DATOS
            fflush(stdin);
        }
    }
    else{printf("NO HAY MEMORIA SUFICIENTE");}

}
void mostrarDatos(eAlumno* pListaAlumnos, int tam)
{
    int i;
    for(i=0; i<tam; i++)
        {
            printf("%s,", (pListaAlumnos+i)->nombre );// ESTOS DOS SON EQUIVALENTES
            //printf("%s", (*(pListaAlumnos+i)).nombre ); // EQUIVALENTES, SI NO SE USARA
            printf("%d\n", (pListaAlumnos+i)->edad );
        }

}
