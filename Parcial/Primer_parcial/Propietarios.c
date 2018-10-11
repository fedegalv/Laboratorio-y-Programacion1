#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include "Propietarios.h"
#include "Funciones_aux.h"

int pedirDatos(sPropietario listaPropietarios[], int tam)
{
    int idPropietario;
    int banderaRepetido;
    char nombre[51];
    char apellido[51];
    char direccion[51];
    char tarjeta[51];
    int tarjetaValida;
    int opRealizada= -1;
    int i;
    do
    {
        banderaRepetido = 0;
        printf("Ingrese ID del propietario: ");
        idPropietario=ingresoNumero();
        for(i=0; i< tam; i++)
        {
            if (listaPropietarios[i].estado == 1 && listaPropietarios[i].idPropietario == idPropietario) // SI EL EL EMPLEADO TIENE LA BANDERA DE VACIO BAJA Y LA ID PROVISTA CONCIDE CON LA ID DEL EMPLEADO
            {
                banderaRepetido = 1;
                break;
            }
        }
        if(banderaRepetido == 1)
        {
            printf("ID YA USADA, INGRESE OTRA ID\n");
        }
        else
        {
            banderaRepetido = 0;
        }
        fflush(stdin);
    }
    while(banderaRepetido == 1);
    //printf("%d",idPropietario);
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
    opRealizada= agregarPropietarios(listaPropietarios,idPropietario,nombre,apellido,direccion,tarjeta);
    return opRealizada;
}
int agregarPropietarios(sPropietario listaPropietarios [], int idPropietario, char nombre[], char apellido[], char direccion [],char tarjeta[])
{
    int operacionCompletada;
    int idPr;
    idPr = idPropietario;
    operacionCompletada = -1; // SE PONE POR DEFAULT COMO INVALIDO

    listaPropietarios[idPr].idPropietario= idPr;
    strcpy(listaPropietarios[idPr].direccion, direccion);
    listaPropietarios[idPr].estado= 1;
    strcpy(listaPropietarios[idPr].numeroTarjeta, tarjeta);
    strcpy(listaPropietarios[idPr].nombre, nombre);
    strcpy(listaPropietarios[idPr].apellido, apellido);

    operacionCompletada = 1; // LA OPERACION FUE REALIZADA CON EXITO
    return operacionCompletada;
}

int buscarPropietario ( sPropietario* listaPropietarios, int tam, int idProvista)
{
    int i;
    int idEncontrada;
    idEncontrada= -1;
    for (i=0; i < tam; i++)
    {
        if (listaPropietarios[i].estado == 1 && listaPropietarios[i].idPropietario == idProvista) // SI EL EL EMPLEADO TIENE LA BANDERA DE VACIO BAJA Y LA ID PROVISTA CONCIDE CON LA ID DEL EMPLEADO
        {
            idEncontrada = i; // GUARDA EN idEncontrada LA POSICION EN EL ARRAY DEL EMPLEADO CON EL ID A BUSCAR
        }
    }

    return idEncontrada;
}
int modificarPropietario(sPropietario* listaPropietarios, int idEncontrado)
{
    char respuestaContinuar;
    char nuevaTarjeta[53];
    int tarjetaValida;

    fflush(stdin);
    printf("MODIFICACION DE DATOS\n\n");
    printf("%4s %10s %10s %10s \n", "ID", "Nombre","Apellido", "NRO TARJETA");
    printf("%4d %10s %10s %10s \n\n", listaPropietarios[idEncontrado].idPropietario,listaPropietarios[idEncontrado].nombre,listaPropietarios[idEncontrado].apellido, listaPropietarios[idEncontrado].numeroTarjeta);


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
        strcpy(listaPropietarios[idEncontrado].numeroTarjeta, nuevaTarjeta);
        printf("DATO MODIFICADO CON EXITO...\n");
    }
    else
    {
        printf("Cancelando...\n");
    }

    return 0;
}

int bajaPropietarios(sPropietario listaPropietarios[], int idProvisto)
{
    int operacionCompletada;
    operacionCompletada = -1; // SE PONE POR DEFAULT COMO INVALIDO
    char respuestaContinuar;
    printf("ESTA A PUNTO DE DAR DE BAJA:\n ID: %d\nNOMBRE: %s\nAPELLIDO: %s\n", listaPropietarios[idProvisto].idPropietario, listaPropietarios[idProvisto].nombre,
           listaPropietarios[idProvisto].apellido);
    printf("DESEA CONTINUAR? (S)i o (N)o \nOPCION SELECCIONADA: ");
    scanf("%c",&respuestaContinuar);

    fflush(stdin);
    respuestaContinuar=toupper(respuestaContinuar);
    if(respuestaContinuar == 'S')
    {
        listaPropietarios[idProvisto].estado= 0;
        printf("BAJA EXITOSA\n");
    }
    else
    {
        printf("Cancelando...\n");
        operacionCompletada = -1;
    }
    return operacionCompletada;
}

void inicializarPropEstado(sPropietario listaPropietarios[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        listaPropietarios[i].estado = 0; // vacio
    }
}
void inicializarPropietariosHardcoded(sPropietario listaPropietarios[])
{
    int id[5] = {1,2,3,4,5};
    char nombre[5][51]= {"Juan","Maria","Pedro","Luis","Romina"};
    char apellido[5][51]= {"Perez","Berticelli","Pasos","Santana","Paciel"};
    char direccion[5][51]= {"Av. vilbaso 2121","Las piedritas 788","Pueyrredon 4411","Bustos 4654","Av. Mallorca 2222",};
    char numeroTarjeta[5][53]= {"1234567891565478","456987413265897457","1265478956412354","13658974589569845","1236598741478547"};
    int i;

    for(i=0; i<5; i++)
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
    printf("%s %15s %24s %24s %30s\n","ID","NOMBRE", "APELLIDO","DIRECCION","NUMERO TARJETA");
    for( i=0; i<tam; i++)
    {
        if(listaPropietarios[i].estado == 1) // SE PODRIA REMOVER YA QUE POR DEFECTOS TODOS LOS ESTADOS SON INICIALIZADOS EN 1
        {
            printf("%d %15s %24s %24s %30s \n",listaPropietarios[i].idPropietario,listaPropietarios[i].nombre,
                   listaPropietarios[i].apellido, listaPropietarios[i].direccion, listaPropietarios[i].numeroTarjeta);
        }
    }

}
void mostrarNombrePropietario(sPropietario listaPropietarios[], int idProvista)
{
    if(listaPropietarios[idProvista].estado == 1) // SE PODRIA REMOVER YA QUE POR DEFECTOS TODOS LOS ESTADOS SON INICIALIZADOS EN 1
    {
        printf("Para el propietario %s se encontro \n",listaPropietarios[idProvista].nombre);
    }

}
