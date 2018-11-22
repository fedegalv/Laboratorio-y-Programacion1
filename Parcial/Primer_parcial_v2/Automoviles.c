typedef struct
{
    int idPropietario;
    char nombre[51];
    char apellido[51];
    char direccion[51];
    char numeroTarjeta[53];
    int estado;

}sAutomovil;

void inicializarAutosEstado(sAutomovil listaAutomoviles[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        listaAutomoviles[i].estado = 0;
        //listaAutomoviles[i].idPropietario = 0;
    }
}
