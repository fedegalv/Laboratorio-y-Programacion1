#ifndef PROPIETARIOS_H_INCLUDED
#define PROPIETARIOS_H_INCLUDED
typedef struct
{
    int idPropietario;
    char nombre[51];
    char apellido[51];
    char direccion[51];
    char numeroTarjeta[53];
    int estado;

} sPropietario;

#endif
int pedirDatos(sPropietario [],int ,int);
int obtenerIdMasAltaProp(sPropietario [], int , int );
int agregarPropietarios(sPropietario  [], int , char[], char[], char[] , char[], int);
int buscarPropietario ( sPropietario* , int , int );
int modificarPropietario(sPropietario* , int ,int);
int bajaPropietarios(sPropietario [], int, int, int);
void inicializarPropEstado(sPropietario [], int tam);
void inicializarPropietariosHardcoded(sPropietario []);
void mostrarListaPropietarios(sPropietario [], int );
void mostrarNombrePropietario(sPropietario [],int ,char []);
int ordenarPropietarios(sPropietario [], int );
void mostrarPropietario(sPropietario [], int );
int propietariosActivos(sPropietario[] , int );
int buscarIndexEnLista(sPropietario[], int, int );

