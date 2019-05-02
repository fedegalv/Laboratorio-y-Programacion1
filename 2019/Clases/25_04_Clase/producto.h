#ifndef producto_H_INCLUDED
#define producto_H_INCLUDED
typedef struct
{
    int productoID;
    int estado;
    char codigoDeBarra[13];
    float precio;
    char nombre[50];
    char fechaDeVencimiento[50];
    //char proveedor[50];
    int idProveedor;

}eProducto;
typedef struct
{
    int id;
    char descripcion[50];
    char localidad[50];
    char cuit[10];
    char duenio[50];

}eProveedor;

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
void inicializarProductos(eProducto arrayProductos[], int tam);
void inicializarProveedores(eProveedor arrayProveedores[], int tam);
void mostrarProductoV2(eProducto producto, eProveedor listaProveedor[], int tam);
void mostrarArrayV2(eProducto arrayProductos[], eProveedor arrayProveedor[] ,int tam, int tamProveedor);
void mostrarInfoId(eProducto producto,eProveedor lista[], int tam);
void mostrarProveedoresYProductos(eProducto listaProductos[], eProveedor listaProveedor[], int tamProducto, int tamProveedor);

#endif // producto_H_IINCLUDED
