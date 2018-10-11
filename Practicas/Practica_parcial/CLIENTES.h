#ifndef CLIENTES_H
#define CLIENTES_H
typedef struct
{
    int idCliente;
    char nombre[51];
    char apellido[51];
    int cuit;
    int estado;

}sCliente;
void inicializarClientes(sCliente [], int );
int pedirDatosCliente(sCliente [], int , int );
int agregarClientes(sCliente [] ,int ,int ,char [],char [], int  );
int buscarClienteID(sCliente [],int, int);

#endif
