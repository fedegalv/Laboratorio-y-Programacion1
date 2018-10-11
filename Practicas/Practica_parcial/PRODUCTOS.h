typedef struct
{
    int idCliente;
    int idAviso;
    int numeroRubro;
    char texto[64];
    int estado;

} ePublicacion;
void inicializarPublicaciones(ePublicacion [], int );
int pedirDatosPublicaciones(ePublicacion [], int, int );
int agregarPublicacion(ePublicacion*,int,int,char [], int );


