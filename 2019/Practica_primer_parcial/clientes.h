#ifndef clientes_H
#define clientes_H
typedef struct
{
    int idCliente;
    char nombre[51];
    char apellido[51];
    int cuit;
    int estado;

}sClientes;

int altaClientes(sClientes [], int idAsignada);
int buscarClienteID(sClientes[], int tam);
int modificarCliente(sClientes [], int );
void mostrarClientes(sClientes lista[], int tam);
void bajaCliente(sClientes lista[], int posicionProvista);
int sClientes_siguienteID(sClientes listado[],int limite);
int sClientes_Init( sClientes [],int );
int sClientes_buscarLugarLibre(sClientes [],int );
void clientesHardcoded(sClientes lista[]);
void mostrarClienteUnico(sClientes lista[],int posicion);
int posicionClientePorID(sClientes lista[], int tam, int idProvista);






#endif
