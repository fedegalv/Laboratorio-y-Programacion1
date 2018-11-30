int altaPropietarios(sPropietario listaPropietarios[],int tam, int* cantProp);
void menuModificar(sPropietario listaPropietarios[], int, int);
int menuBajaPropietarios(sPropietario listaPropietarios[],sAutomovil listaAutomoviles[], int, int, int);
void menuMostrarListaOrdenada(sPropietario listaPropietarios[],int ,int );
int menuAltaVehiculos(sPropietario listaPropietarios[], sAutomovil historialAutos[], sAutomovil[], int , int ,int, int);
void menuBajaVehiculos(sPropietario listaPropietarios[], sAutomovil listaAutomoviles[],int , int);
void menuListaAutomoviles(sAutomovil listaAutomoviles[], int);
void menuListarRecaudacionTotalEstacionamiento(sAutomovil[] , int);
void menuRecaudacionTotalMarcas(sAutomovil [], int maxAutos);
void menuMostrarAutosPorPropietarios(sAutomovil listaAutomoviles[], sPropietario listaPropietarios[] , int , int );
void menuPropietariosConAudi(sPropietario listaPropietarios[], sAutomovil listaAutomoviles[], int , int );
int menuAutosOrdenadosPatentes(sAutomovil [],sPropietario [],  int , int );
void mostrarInformacionAutoYProp(sAutomovil [], sPropietario [], int , int  );

/*
printf("%8d %20s %15s | %15s %15s %15s %20s\n",listaAutomoviles[i].idPropietario, listaAutomoviles[i].patente, marcaTexto,
                    listaPropietarios[index].nombre, listaPropietarios[index].apellido, listaPropietarios[index].direccion, listaPropietarios[index].numeroTarjeta);


*/
