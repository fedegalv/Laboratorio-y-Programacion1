#include "pantallas.h"
#ifndef pantallas_H
#define pantallas_H
typedef struct
{
    int tipoPantalla;
    int idPantalla;
    int precioPantalla;
    int estado;
    char nombre[64];
    char direccion[64];
} sPantalla;

#endif

