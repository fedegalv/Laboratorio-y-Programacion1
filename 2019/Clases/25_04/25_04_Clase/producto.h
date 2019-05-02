#ifndef producto_H_INCLUDED
#define producto_H_INCLUDED
typedef struct
{
    int estado;
    char codigoDeBarra[13];
    float precio;
    char nombre[50];
    char fechaDeVencimiento[50];
    char proveedor[50];

}eProducto;

eProducto pedirProducto();
void mostrarProducto(eProducto );
void cargarArray(int tam, eProducto[] );
void mostrarArray(eProducto [], int tam);
void construirArray(eProducto [],int tam);
///
int insertProducto(eProducto, eProducto [], int);
int dameLugarLibre(eProducto[], int tam);
int existeProducto(eProducto, eProducto [], int tam);
int borrarProducto(eProducto, eProducto [], int tam);
int editarProducto(eProducto, eProducto[]);

#endif // producto_H_IINCLUDED
