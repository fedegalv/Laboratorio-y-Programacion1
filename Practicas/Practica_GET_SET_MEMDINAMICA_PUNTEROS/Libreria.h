#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre[15];
    int edad;

}ePersona;

ePersona* newPerson()
{
    ePersona* miPersona;
    miPersona= (ePersona*) malloc(sizeof(ePersona));

}
