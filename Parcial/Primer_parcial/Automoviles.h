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
int totalPagarPropietario(sAutomovil [],int ,int );
int bajaAutomoviles(sAutomovil [], int , int );
int hayVehiculos(sAutomovil[] , int );
int hayVehiculoEnPropietario(sAutomovil [], int ,int );
void codigoMarcas(int, char[]);
int precioPorHora(int );
