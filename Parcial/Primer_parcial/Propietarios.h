typedef struct
{
    int idPropietario;
    char nombre[51];
    char apellido[51];
    char direccion[51];
    char numeroTarjeta[53];
    int estado;

} sPropietario;
int pedirDatos(sPropietario [],int );
int agregarPropietarios(sPropietario  [], int , char[], char[], char[] , char[]);
int buscarPropietario ( sPropietario* , int , int );
int modificarPropietario(sPropietario* , int );
int bajaPropietarios(sPropietario [], int );
void inicializarPropEstado(sPropietario [], int tam);
void inicializarPropietariosHardcoded(sPropietario []);
void mostrarListaPropietarios(sPropietario [], int );

