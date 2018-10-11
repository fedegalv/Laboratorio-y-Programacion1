#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "string.h"
#include "Funciones_auxiliares.h"
#include <ctype.h>

int initEmployees(sEmployee* eLista, int tam)
{
    int operacionCompletada;
    operacionCompletada = -1; // SE PONE POR DEFAULT COMO INVALIDO
    int i;
    for(i = 0; i < tam; i++)
    {
        eLista[i].isEmpty = 1;
    }
    operacionCompletada = 0; // LA OPERACION FUE REALIZADA CON EXITO
    return operacionCompletada;

}

int addAEmployees(sEmployee* eLista,int id,int len,char name[], char lastName[], float salary, int sector)
{
    int operacionCompletada;
    operacionCompletada = -1; // SE PONE POR DEFAULT COMO INVALIDO

    eLista[id].id= id;
    eLista[id].salary= salary;
    eLista[id].sector= sector;
    strcpy(eLista[id].name, name);
    strcpy(eLista[id].lastName, lastName);
    eLista[id].isEmpty= 0;

    operacionCompletada = 0; // LA OPERACION FUE REALIZADA CON EXITO
    return operacionCompletada;
}

int findEmployeeById ( sEmployee* eLista, int ELEMENTS, int idProvista)
{
    int i;
    idProvista= idProvista;
    int idEncontrada;
    idEncontrada= -1;
    for (i=0; i < ELEMENTS; i++)
    {
        if (eLista[i].isEmpty == 0 && eLista[i].id == idProvista) // SI EL EL EMPLEADO TIENE LA BANDERA DE VACIO BAJA Y LA ID PROVISTA CONCIDE CON LA ID DEL EMPLEADO
        {
            idEncontrada = i; // GUARDA EN idEncontrada LA POSICION EN EL ARRAY DEL EMPLEADO CON EL ID A BUSCAR
        }
    }

    return idEncontrada;
}

int modifyEmployee(sEmployee* eLista, int indexEncontrado, int ELEMENTS)
{
    char respuesta;
    char respuestaContinuar;
    char auxiliarCadena[51];

    fflush(stdin);
    printf("MODIFICACION DE DATOS EMPLEADO ID %d \n",eLista[indexEncontrado].id);
    printf("%4s %10s %10s %10s %8s \n", "ID", "Nombre","Apellido", "Salario", "Sector");
    printf("%4d %10s %10s %10.2f %8d \n", eLista[indexEncontrado].id, eLista[indexEncontrado].name,eLista[indexEncontrado].lastName, eLista[indexEncontrado].salary, eLista[indexEncontrado].sector);

    printf("QUE DESEA MODIFICAR?\n");
    printf("(N)ombre\n(A)pellido\n(S)alario\nSec(T)or\nPARA CANCELAR LA MODIFICACION, INGRESE (E)\n");
    printf("SELECCIONE UNA OPCION: ");
    scanf("%c",&respuesta);
    respuesta = toupper(respuesta); // CONVERTIMOS EN MAYUSCULA LA RESPUESTA

    fflush(stdin);

    switch(respuesta)
    {
    case 'N':
        printf("DATO A MODIFICAR: %s\n", eLista[indexEncontrado].name);
        printf("DESEA CONTINUAR? (S)i o (N)o \nOPCION SELECCIONADA: ");
        scanf("%c",&respuestaContinuar);

        fflush(stdin);

        respuestaContinuar=toupper(respuestaContinuar);
        if(respuestaContinuar == 'S')
        {
            printf("INGRESE NUEVO NOMBRE: ");
            gets(auxiliarCadena);
            verificarCadena(auxiliarCadena); // LO VERIFICO
            formateoCadenas(auxiliarCadena); // DA FORMATO
            strcpy(eLista[indexEncontrado].name, auxiliarCadena);
            printf("DATO MODIFICADO CON EXITO...\n");
            limpiarPantalla();

        }
        else
        {
            printf("Cancelando...\n");
            limpiarPantalla();
        }

        break;
    case 'A':
        printf("DATO A MODIFICAR: %s\n", eLista[indexEncontrado].lastName);
        printf("DESEA CONTINUAR? (S)i o (N)o \nOPCION SELECCIONADA: ");
        scanf("%c",&respuestaContinuar);

        fflush(stdin);
        respuestaContinuar=toupper(respuestaContinuar);
        if(respuestaContinuar == 'S')
        {
            printf("INGRESE NUEVO APELLIDO: ");
            gets(auxiliarCadena);
            verificarCadena(auxiliarCadena);
            formateoCadenas(auxiliarCadena);
            strcpy(eLista[indexEncontrado].lastName, auxiliarCadena);
            printf("DATO MODIFICADO CON EXITO...\n");
            limpiarPantalla();

        }
        else
        {
            printf("Cancelando...\n");
        }
        break;
    case 'S':
        printf("DATO A MODIFICAR: %.2f\n",eLista[indexEncontrado].salary);
        printf("DESEA CONTINUAR? (S)i o (N)o \nOPCION SELECCIONADA: ");
        scanf("%c",&respuestaContinuar);

        fflush(stdin);
        respuestaContinuar=toupper(respuestaContinuar);
        if(respuestaContinuar == 'S')
        {
            printf("INGRESE NUEVO SALARIO: ");
            scanf("%f", &eLista[indexEncontrado].salary);
            printf("DATO MODIFICADO CON EXITO...\n");
            limpiarPantalla();


        }
        else
        {
            printf("Cancelando...\n");
        }
        break;
    case 'T':
        printf("DATO A MODIFICAR: %d\n",eLista[indexEncontrado].sector);
        printf("DESEA CONTINUAR? (S)i o (N)o \nOPCION SELECCIONADA: ");
        scanf("%c",&respuestaContinuar);

        fflush(stdin);
        respuestaContinuar=toupper(respuestaContinuar);
        if(respuestaContinuar == 'S')
        {
            printf("INGRESE NUEVO SECTOR: ");
            eLista[indexEncontrado].sector = ingresoNumero();
            printf("DATO MODIFICADO CON EXITO...\n");
            limpiarPantalla();


        }
        else
        {
            printf("Cancelando...\n");
        }
        break;
    case 'E':
        printf("VOLVIENDO AL MENU PRINCIPAL...");
        limpiarPantalla();
        break;
    default:
        printf("NO SELECCIONO UNA OPCION VALIDA");
    }

    return 0;
}

int removeEmployee(sEmployee* eLista, int indexEncontrado, int elementos )
{
    int operacionCompletada;
    operacionCompletada = -1; // SE PONE POR DEFAULT COMO INVALIDO
    char respuestaContinuar;
    printf("ESTA A PUNTO DE DAR DE BAJA:\n ID: %d\nNOMBRE: %s\nAPELLIDO: %s\nSECTOR: %d\n", eLista[indexEncontrado].id, eLista[indexEncontrado].name, eLista[indexEncontrado].lastName, eLista[indexEncontrado].sector);
    printf("DESEA CONTINUAR? (S)i o (N)o \nOPCION SELECCIONADA: ");
    scanf("%c",&respuestaContinuar);

    fflush(stdin);
    respuestaContinuar=toupper(respuestaContinuar);
    if(respuestaContinuar == 'S')
    {
        eLista[indexEncontrado].isEmpty= 1;
        operacionCompletada = 0;
    }
    else
    {
        printf("Cancelando...\n");
        limpiarPantalla();

    }
    return operacionCompletada;
}

int sortEmployees(sEmployee* eLista, int len, int order)
{
    sEmployee aux;
    aux.isEmpty=0;
    int i;
    int j;
    //ORDEN ASCENDENTE
    if(order == 1)
    {
        for(i=0; i<len; i++)
        {
            if(eLista[i].isEmpty == 0)
            {
                for(j=i+1; j<len; j++)
                {
                    if(strcmp(eLista[i].lastName,eLista[j].lastName)>0)
                    {
                        aux = eLista[i];
                        eLista[i]=eLista[j];
                        eLista[j]=aux;

                    }
                    else
                    {
                        if(strcmp(eLista[i].lastName,eLista[j].lastName)==0)
                        {
                            if(eLista[i].sector > eLista[j].sector)
                            {
                                aux = eLista[i];
                                eLista[i]=eLista[j];
                                eLista[j]=aux;

                            }

                        }
                    }

                }

            }

        }
    }
    // ORDEN DESCENDENTE
    if(order == 0)
    {
        for(i=0; i<len; i++)
        {
            if(eLista[i].isEmpty == 0)
            {
                for(j=i+1; j<len; j++)
                {
                    if(strcmp(eLista[i].lastName,eLista[j].lastName)<0)
                    {
                        aux = eLista[i];
                        eLista[i]=eLista[j];
                        eLista[j]=aux;

                    }
                    else
                    {
                        if(strcmp(eLista[i].lastName,eLista[j].lastName)==0)
                        {
                            if(eLista[i].sector > eLista[j].sector)
                            {
                                aux = eLista[i];
                                eLista[i]=eLista[j];
                                eLista[j]=aux;

                            }

                        }
                    }

                }

            }

        }

    }


    return 0;
}



int printEmployees( sEmployee* eLista, int numeroId)
{
    int i;
    int valido = 1;
    printf("%4s %10s %10s %10s %8s \n", "ID", "Nombre","Apellido", "Salario", "Sector");
    for(i= 0; i<numeroId; i++)
    {
        if (eLista[i].isEmpty == 0)
        {
            printf("%4d %10s %10s %10.2f %8d \n", eLista[i].id, eLista[i].name,eLista[i].lastName, eLista[i].salary, eLista[i].sector);
        }
        else
        {
            valido = 0;
        }

    }



    return valido;
}
