#include <stdio.h>
#include <stdlib.h>
#include "string.h"
typedef struct
{
    int modelo;
    char sigla;
    char nombre[10];

}eMoto;

eMoto* cargarPuntero(void);

int main()
{
    eMoto* pMoto;
    // CREAR ESTRUCTURA, CREAR UNA FUNCION QUE DEVUELVA PUNTERO A ESA ESTRUCT
    // ADENTRO DE LA FUNCION CREAR PUNTERO, CARGARLO CON DATO Y DEVOLVERLO
    // EN EL MAIN RECIBIR LLAMO A EL PUNTERO Y MOSTRAR LOS DATOS
    pMoto= cargarPuntero();
    printf("%d\n", pMoto->modelo);
    printf("%c\n", pMoto->sigla);
    puts(pMoto->nombre);


    return 0;
}

/*eMoto* cargarPuntero(void)
{
    eMoto honda;
    eMoto* pHonda;
    //honda.sigla= 'A';
    pHonda= &honda;

    pHonda->modelo= 22;
    //pHonda->sigla= 'A';
    return pHonda;
}*/
eMoto* cargarPuntero() /// CONSTRUCTOR? FUNCION QUE RESERVA EN MEMORIA E INICIALIZA
{
    eMoto* honda;
    honda= (eMoto*) malloc(sizeof(eMoto));
    honda->modelo= 22;
    honda->sigla= 'A';
    realloc(honda->nombre, sizeof(char)*15); /// REASIGNAMOS A EL CAMPO nombre EL ESPACIO RESERVADO DE 5 A 15
    strcpy(honda->nombre, "15 CARACTERES!!");
    return honda;
}
