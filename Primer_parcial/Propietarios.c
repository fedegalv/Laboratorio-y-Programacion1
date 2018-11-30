#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include "Propietarios.h"
#include "Funciones_aux.h"
int obtenerIdMasAltaProp(sPropietario listaPropietario[], int tam, int flagPrimeraVez)
{
    int retorno = 0;
    int i;
    if(tam > 0 && listaPropietario != NULL)
    {
        for(i=0; i<tam; i++)
        {
            if(listaPropietario[i].estado == 1)
            {
                    if(listaPropietario[i].idPropietario>retorno)
                    {
                         retorno=listaPropietario[i].idPropietario;
                    }

            }
        }
    }

    return retorno+1;

}
int propietariosActivos(sPropietario listaPropetarios[], int tam)
{
    int cont= 0;
    int i;
    for(i=0; i < tam; i++)
    {
        if(listaPropetarios[i].estado == 1)
        {
            cont++;
        }
    }
    return cont;
}

int pedirDatos(sPropietario listaPropietarios[], int tam, int idDisponible)
{
    char nombre[51];
    char apellido[51];
    char direccion[51];
    char tarjeta[51];
    int tarjetaValida;
    int opRealizada= -1;
    fflush(stdin);

    printf("Ingrese nombre del propietario: ");
    gets(nombre);
    verificarCadena(nombre);
    formateoCadenas(nombre);
    fflush(stdin);

    printf("Ingrese apellido del propietario: ");
    gets(apellido);
    verificarCadena(apellido);
    formateoCadenas(apellido);
    fflush(stdin);

    printf("Ingrese direccion del propietario: ");
    gets(direccion);
    fflush(stdin);
    do
    {
        printf("Ingrese numero de tarjeta de credito(16 digitos) : ");
        gets(tarjeta);
        tarjetaValida=verificarTarjeta(tarjeta);
        fflush(stdin);
    }
    while(tarjetaValida == 0);
    opRealizada= agregarPropietarios(listaPropietarios,idDisponible,nombre,apellido,direccion,tarjeta, tam);
    return opRealizada;
}
int agregarPropietarios(sPropietario listaPropietarios [], int idPropietario, char nombre[], char apellido[], char direccion [],char tarjeta[],int tam)
{
    int operacionCompletada;
    int retorno = -1;
    int i;
    if(tam > 0 && listaPropietarios != NULL)
    {
        retorno = -2;
        for(i=0;i<tam;i++)
        {
            if(listaPropietarios[i].estado == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    operacionCompletada = -1; // SE PONE POR DEFAULT COMO INVALIDO

    if(retorno >= 0)
    {
        listaPropietarios[retorno].idPropietario= idPropietario;
        strcpy(listaPropietarios[retorno].direccion, direccion);
        listaPropietarios[retorno].estado= 1;
        strcpy(listaPropietarios[retorno].numeroTarjeta, tarjeta);
        strcpy(listaPropietarios[retorno].nombre, nombre);
        strcpy(listaPropietarios[retorno].apellido, apellido);
        printf("Datos agregados\n");
    }


    operacionCompletada = 1; // LA OPERACION FUE REALIZADA CON EXITO
    return operacionCompletada;
}

int buscarPropietario ( sPropietario* listaPropietarios, int tam, int idProvista)
{
    int i;
    int idEncontrada;
    idEncontrada= -1; // -1 SI NO ENCUENTRA, 1 SI ENCUENTRA
    for (i=0; i < tam; i++)
    {
        if (/*listaPropietarios[i].estado == 1 && */listaPropietarios[i].idPropietario == idProvista) // SI EL EL EMPLEADO TIENE LA BANDERA DE VACIO BAJA Y LA ID PROVISTA CONCIDE CON LA ID DEL EMPLEADO
        {
            if(listaPropietarios[i].estado == 1)
            {
                idEncontrada= 1;
                break;
            }
             //= i; // GUARDA EN idEncontrada LA POSICION EN EL ARRAY DEL EMPLEADO CON EL ID A BUSCAR
        }
    }

    return idEncontrada;
}
int modificarPropietario(sPropietario* listaPropietarios, int idEncontrado,int tam)
{
    char respuestaContinuar;
    char nuevaTarjeta[53];
    int tarjetaValida;
    int retorno= buscarIndexEnLista(listaPropietarios, tam, idEncontrado);

    fflush(stdin);
    printf("MODIFICACION DE DATOS\n\n");
    printf("%4s %15s %15s %19s \n", "ID", "Nombre","Apellido", "NRO TARJETA");
    printf("%4d %15s %15s %19s \n\n", listaPropietarios[retorno].idPropietario,listaPropietarios[retorno].nombre,listaPropietarios[retorno].apellido, listaPropietarios[retorno].numeroTarjeta);


    printf("DATO A MODIFICAR: TARJETA DE CREDITO\n");
    printf("DESEA CONTINUAR? (S)i o (N)o \nOPCION SELECCIONADA: ");
    scanf("%c",&respuestaContinuar);

    fflush(stdin);

    respuestaContinuar=toupper(respuestaContinuar);
    if(respuestaContinuar == 'S')
    {
        do
        {
            printf("Ingrese nuevo numero de tarjeta: ");
            gets(nuevaTarjeta);
            tarjetaValida=verificarTarjeta(nuevaTarjeta);
            fflush(stdin);
        }
        while(tarjetaValida == 0);
        strcpy(listaPropietarios[retorno].numeroTarjeta, nuevaTarjeta);
        printf("DATO MODIFICADO CON EXITO...\n");
    }
    else
    {
        printf("Cancelando...\n");
    }

    return 0;
}

int bajaPropietarios(sPropietario listaPropietarios[], int idProvisto,int importeTotal, int tam)
{
    int operacionCompletada;
    operacionCompletada = 0; // SE PONE POR DEFAULT COMO INVALIDO
    char respuestaContinuar;
    int index;
    index = buscarIndexEnLista(listaPropietarios,tam, idProvisto);
    printf("\nESTA A PUNTO DE DAR DE BAJA:\n ID: %d\nNOMBRE: %s\nAPELLIDO: %s\n", listaPropietarios[index].idPropietario, listaPropietarios[index].nombre,
           listaPropietarios[index].apellido);
    printf("EL TOTAL A ABONAR POR TODOS SUS AUTOS AL RETIRARSE ES: $ %d\n",importeTotal);
    printf("DESEA CONTINUAR? (S)i o (N)o \nOPCION SELECCIONADA: ");
    scanf("%c",&respuestaContinuar);

    fflush(stdin);
    respuestaContinuar=toupper(respuestaContinuar);
    if(respuestaContinuar == 'S')
    {
        listaPropietarios[index].estado= 0;
        operacionCompletada= 1;
        printf("BAJA EXITOSA\n");
    }
    else
    {
        printf("Cancelando...\n");
        operacionCompletada = 0;
    }
    return operacionCompletada;
}

void inicializarPropEstado(sPropietario listaPropietarios[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        listaPropietarios[i].estado = 0; // vacio
        listaPropietarios[i].idPropietario= 0;
    }
}
void inicializarPropietariosHardcoded(sPropietario listaPropietarios[])
{
    int id[6] = {1,2,3,4,5,6};
    char nombre[6][51]= {"Juan","Maria","Pedro","Luis","Romina","Manuel"};
    char apellido[6][51]= {"Perez","Berticelli","Pasos","Santana","Paciel","Bustos"};
    char direccion[6][51]= {"Av. vilbaso 2121","Las piedritas 788","Pueyrredon 4411","Bustos 4654","Av. Mallorca 2222","Afen 452"};
    char numeroTarjeta[6][53]= {"1234567891565478","456987413265897457","1265478956412354","13658974589569845","1236598741478547","254512541254125"};
    int i;

    for(i=0; i<3; i++)
    {
        listaPropietarios[i].idPropietario=id[i];
        listaPropietarios[i].estado = 1;
        strcpy(listaPropietarios[i].numeroTarjeta, numeroTarjeta[i]);
        strcpy(listaPropietarios[i].nombre, nombre[i]);
        strcpy(listaPropietarios[i].apellido, apellido[i]);
        strcpy(listaPropietarios[i].direccion, direccion[i]);

    }
}
void mostrarListaPropietarios(sPropietario listaPropietarios[], int tam)
{
    int i;
    printf("%s %5s %15s %20s %20s\n","ID","NOMBRE", "APELLIDO","DIRECCION","NUMERO TARJETA");
    for( i=0; i<tam; i++)
    {
        if(listaPropietarios[i].estado == 1) // SE PODRIA REMOVER YA QUE POR DEFECTOS TODOS LOS ESTADOS SON INICIALIZADOS EN 1
        {
            printf("%d %5s %15s %20s %20s \n",listaPropietarios[i].idPropietario,listaPropietarios[i].nombre,
                   listaPropietarios[i].apellido, listaPropietarios[i].direccion, listaPropietarios[i].numeroTarjeta);
        }
    }

}
int ordenarPropietarios(sPropietario listaP[], int tam)
{
    sPropietario aux;
    aux.estado = 1;
    int i;
    int j;


    for(i=0; i<tam; i++)
    {
        if(listaP[i].estado == 1)
        {
            for(j=i+1; j<tam; j++)
            {
                if(strcmp(listaP[i].nombre,listaP[j].nombre)>0)
                {
                    aux = listaP[i];
                    listaP[i]=listaP[j];
                    listaP[j]=aux;
                }
                else
                {
                    if(strcmp(listaP[i].nombre,listaP[j].nombre)==0)
                    {
                        if(strcmp(listaP[i].apellido,listaP[j].apellido)>0)
                        {
                            aux = listaP[i];
                            listaP[i]=listaP[j];
                            listaP[j]=aux;

                        }

                    }
                }

            }

        }

    }

    return 0;

}


void mostrarNombrePropietario(sPropietario listaPropietarios[], int idProvista, char nompreProp[])
{

    printf("Para el propietario %s se encontro \n",listaPropietarios[idProvista].nombre);
    strcpy(nompreProp,listaPropietarios[idProvista].nombre);


}
void mostrarPropietario(sPropietario listaPropietarios[], int idProvista)
{
    printf("%d %5s %15s %20s %20s \n",listaPropietarios[idProvista].idPropietario,listaPropietarios[idProvista].nombre,
               listaPropietarios[idProvista].apellido, listaPropietarios[idProvista].direccion, listaPropietarios[idProvista].numeroTarjeta);


}
//** BUSCA INDEX EN LA LISTA DE PROP *** //
int buscarIndexEnLista(sPropietario listaPropietarios[], int tam, int idProvista)
{
    int i;
    int index= -1;
    for(i=0; i< tam; i++)
    {
        if(listaPropietarios[i].idPropietario == idProvista)
        {
            index= i;
        }
    }
    return index;
}
