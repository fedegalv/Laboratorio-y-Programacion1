#include <stdio.h>
#include <stdlib.h>
#include "string.h"
void mostrarVector(int datos[], int tamanio);
void mostrarVectorString(char usuario[][10], int tamanio);
void cargaDatos(char usuario [][10], int nota[] );
int main()
{

    //char usuario[10][10];
    //int nota[10];
    char usuario[5][10]= {"jose","maria","jesus","melchor","gaspar"};
    int nota[10]= {8,5,2,10,3}; // INICUALIZACION DE VECTOR INT

    int i;
    int j;
    int aux;
    char auxChar[10];

   /// ORDENAMIENTO COMPARACION STRINGS
   /*
    for(i=0; i< 5; i++)
    {
        for(j=i+1; j<5; j++)
        {
            if( strcmp(usuario[i], usuario[j]) > 0)
            {
                aux= nota[i];
                nota[i]= nota[j];
                nota[j]= aux;

                strcpy(auxChar, usuario[i]);
                strcpy(usuario[i], usuario[j]);
                strcpy(usuario[j], auxChar);
            }
        }
    }
    for(i=0;i<5;i++)
    {
        printf("alumno %s    nota %d   \n", usuario[i], nota[i]);
    }
    */
    /// ORDENAMIENTO BURBUJEO NUMERO POR NOTA
/*
    for(i=0; i< 5; i++)
    {
        for(j=0; j<4; j++)
        {
            //printf("%d --> %d \n", nota[i], nota[j]);
            if(nota[i] < nota [j])
            {
                aux= nota[i];
                nota[i]= nota[j];
                nota[j]= aux;

                strcpy(auxChar, usuario[i]);
                strcpy(usuario[i], usuario[j]);
                strcpy(usuario[j], auxChar);
            }
        }
    }
    for(i=0;i<5;i++)
    {
        printf("alumno %s    nota %d   \n", usuario[i], nota[i]);
    }

   ///////////////////////

    for(i=0; i< 5; i++)
    {
        for(j=i+1; j<5; j++)
        {
            //printf("%d --> %d \n", nota[i], nota[j]);
            if(nota[i] > nota [j])
            {
                aux= nota[i];
                nota[i]= nota[j];
                nota[j]= aux;

                strcpy(auxChar, usuario[i]);
                strcpy(usuario[i], usuario[j]);
                strcpy(usuario[j], auxChar);
            }
        }
    }
 for(i=0;i<5;i++)
    {
        printf("alumno %s    nota %d   \n", usuario[i], nota[i]);
    }

*/





    /* for(i=0;i<10;i++) // INICIALIZACION ARRAYS EN PARALELO
    {
        strcpy(usuario[i], " ");
        //usuario[i][0]= NULL;
        //nota[i]= 0;
    }
*/
/*
    int tamanio= strlen(usuario[1]);
    //int arrayLen= sizeof(nota);
    for(i=0;i<5;i++)
    {
        printf("alumno %s    nota %d   \n", usuario[i], nota[i]);
    }
*/

    //printf("TAMANIO %d    \n", tamanio);
    //printf("TAMANIO %d    \n", arrayLen);
mostrarVector(nota, 5);
mostrarVectorString(usuario, 5);

cargaDatos(usuario, nota);
mostrarVector(nota, 5);
mostrarVectorString(usuario, 5);


    return 0;
}
void mostrarVector(int datos[], int tamanio)
{
    int i;
    for(i=0; i< tamanio; i++)
    {
        printf("nota: %d \n", datos[i]);
    }
}
void mostrarVectorString(char usuario[][10], int tamanio)
{
    int i;
    for(i=0; i< tamanio; i++)
    {
        printf("nombre: %s\n", usuario[i]);
    }
}
void cargaDatos(char usuario [][10], int nota[] )
{
    int i;
    for(i=0;i<5;i++)
    {
        fflush(stdin);
        printf("Ingrese usuario #  %d: ", i+1);
        gets(usuario[i]);
        printf("Ingrese nota #  %d: ", i+1);
        scanf("%d", &nota[i]);
    }
}
