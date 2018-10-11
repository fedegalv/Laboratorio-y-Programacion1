#include "Usuario.h"
#include "Serie.h"
typedef struct
{
    int clienteID;
    char serieID;
}eClienteSerie;
void mostrarSerieconUsuario(eUsuario[], int , eSerie[], int );
void mostrarUsuarioConSuSerie(eUsuario [], int , eSerie [], int );
void inicializarSeriesUsuariosHardCode(eClienteSerie []);
void mostrarClientesEnSeries(eUsuario [], int , eSerie [],int , eClienteSerie [] );
