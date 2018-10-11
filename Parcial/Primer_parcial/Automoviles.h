typedef struct
{
    int idPropietario;
    char patente[51];
    int marca;
    int estado;

} sAutomovil;
void inicializarAutosEstado(sAutomovil [], int );
int pedirDatosAutomovil(sAutomovil [], int,int);
int agregarAutomovil(sAutomovil [], int , char [], int ,int);
int emitirTicket(sAutomovil [], int ,int, char nombreProp[] );
void codigoMarcas(int, char[]);
int precioPorHora(int );
