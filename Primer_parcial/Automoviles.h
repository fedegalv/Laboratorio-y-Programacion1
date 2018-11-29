#ifndef AUTOMOVILES_H_INCLUDED
#define AUTOMOVILES_H_INCLUDED
typedef struct
{
    int idPropietario;
    char patente[51];
    int marca;
    int estado;

} sAutomovil;
#endif

void inicializarAutosEstado(sAutomovil [], int );
int autosBuscarLugarLibre(sAutomovil [],int );
void iniciarAutosHardcoded (sAutomovil []);
int pedirDatosAutomovil(sAutomovil [],sAutomovil [], int,int, int pCantHistorial);
int agregarAutomovil(sAutomovil [], int , char [],int, int);
int emitirTicket(sAutomovil [], int ,int, char nombreProp[] );
int totalPagarPropietario(sAutomovil [],int ,int );
int bajaAutomoviles(sAutomovil [], int , int );
int hayVehiculos(sAutomovil[] , int );
int hayVehiculoEnPropietario(sAutomovil [], int ,int );
int mostrarVehiculos(sAutomovil [], int );
int copiarVehiculosHistorial(sAutomovil [], sAutomovil [], int );
int recaudacionTotal(sAutomovil [], int );
void codigoMarcas(int, char[]);
int precioPorHora(int );
int recaudacionTotalMarca(sAutomovil  [], int );
void mostrarVehiculoEnProp(sAutomovil [], int , int );
int buscarAudi(sAutomovil [], int );
int agregarHistorialVehiculos(sAutomovil [], int, int idPropietario, char patente[], int marca, int pCantHistorial );
