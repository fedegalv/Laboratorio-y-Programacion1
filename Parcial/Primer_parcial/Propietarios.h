typedef struct
{
    int idPropietario;
    char nombre[51];
    char apellido[51];
    char direccion[51];
    long int numeroTarjeta;
    int estado;

} sPropietario;
int pedirDatos(sPropietario [],int );
int agregarPropietarios(sPropietario  [], int , char[], char[], char[] , long int);
int buscarPropietario ( sPropietario* , int , int );
int modificarPropietario(sPropietario* , int );
void inicializarPropEstado(sPropietario [], int tam);
void inicializarPropietariosHardcoded(sPropietario []);
void mostrarListaPropietarios(sPropietario [], int );

