#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include "Automoviles.h"
#include "Funciones_aux.h"
#include "Propietarios.h"

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTROS 4

void inicializarAutosEstado(sAutomovil listaAutomoviles[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        listaAutomoviles[i].estado = 0; // vacio
    }
}
int autosBuscarLugarLibre(sAutomovil listaAutomoviles[],int tam)
{
    int retorno;
    int i;
    if(tam > 0 && listaAutomoviles != NULL)
    {
        for(i=0; i<tam; i++)
        {
            if(listaAutomoviles[i].estado == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int pedirDatosAutomovil(sAutomovil listaAutomoviles[], sAutomovil historialAutos[], int idPropietario, int maxAutos, int autosActivos)
{
    char patente[51];
    int marca;
    int seleccionMarca;
    int marcaValida;
    int opRealizada= 0;
    int patenteValida;

    do
    {
        fflush(stdin);
        patenteValida= 0;
        printf("Ingrese patente del propietario: ");
        gets(patente);
        patenteValida= validacionPatente(patente);
    }
    while(patenteValida == 0);
    fflush(stdin);
    do
    {
        marcaValida=0;
        printf("MARCAS DISPONIBLES:\n");
        printf("1-ALPHA ROMEO\n2-FERRARI\n3-AUDI\n4-OTROS\n");
        printf("Ingrese marca del propietario: ");
        seleccionMarca = ingresoNumero();
        switch(seleccionMarca)
        {
        case ALPHA_ROMEO:
            marca= ALPHA_ROMEO;
            marcaValida=1;
            break;
        case FERRARI:
            marca= FERRARI;
            marcaValida=1;
            break;
        case AUDI:
            marca= AUDI;
            marcaValida=1;
            break;
        case OTROS:
            marca= OTROS;
            marcaValida=1;
            break;
        default:
            printf("MARCA NO VALIDA\n");
            break;
        }

    }
    while(marcaValida == 0);

    opRealizada= agregarAutomovil(listaAutomoviles, idPropietario,patente,marca, maxAutos, autosActivos);
    agregarHistorialVehiculos( historialAutos, 40, idPropietario,patente,marca);
    return opRealizada;
}
void iniciarAutosHardcoded (sAutomovil listaAutos[])
{
    int id[6] = {1,2,3,3,4,6};
    char patente[6][51] = {"aaa 453", "bgr 456", "huj 787", "lol 222", "wth 456","ahh 569"};
    int marcas[6] = {ALPHA_ROMEO,AUDI,FERRARI,FERRARI,OTROS,AUDI};
    int i;
    for(i=0; i<3; i++)
    {
        listaAutos[i].idPropietario= id[i];
        listaAutos[i].marca = marcas[i];
        listaAutos[i].estado = 1;
        strcpy(listaAutos[i].patente, patente[i]);
    }
}
int agregarAutomovil(sAutomovil listaAutomovil[], int idPropietario, char patente[], int marca, int tam, int autosActivos)
{
    int operacionCompletada;
    int index= autosActivos;
    int i;
    operacionCompletada = 0; // SE PONE POR DEFAULT COMO INVALIDO
    //BUSCA LUGAR VACIO

    if(tam > 0 && listaAutomovil != NULL && autosActivos > 20)
    {
        index = -2;
        for(i=0; i<tam; i++)
        {
            if(listaAutomovil[i].estado == 0)
            {
                index = i;
                break;
            }
        }
    }
   // printf("index lista normal //%d\n", index);
    listaAutomovil[index].idPropietario= idPropietario;
    listaAutomovil[index].marca= marca;
    listaAutomovil[index].estado= 1;
    strcpy(listaAutomovil[index].patente, patente);



    operacionCompletada = 1; // LA OPERACION FUE REALIZADA CON EXITO
    return operacionCompletada;
}
void codigoMarcas(int marca, char marcaTexto[])
{
    switch(marca)
    {
    case 1:
        strcpy(marcaTexto,"ALPHA ROMEO");
        break;
    case 2:
        strcpy(marcaTexto,"FERRARI");
        break;
    case 3:
        strcpy(marcaTexto,"AUDI");
        break;
    case 4:
        strcpy(marcaTexto,"OTROS");
        break;
    }
}
int precioPorHora(int marca)
{
    int precio;
    switch(marca)
    {
    case 1:
        precio = 150;
        break;
    case 2:
        precio = 175;
        break;
    case 3:
        precio = 200;
        break;
    case 4:
        precio = 250;
        break;
    }
    return precio;
}

int emitirTicket(sAutomovil listaAutomovil[],int idProvisto,int tam, char nombreProp[])
{
    int i;
    char patenteSeleccionada[51];
    char marcaTexto[15];
    //int pantenteValida;
    int autoEncontrado;
    int totalEstadia;
    int horasEstadia;
    int precioEstadia;
    int patenteValida;

    printf("\n%10s %15s\n","PATENTE","MARCA");
    for (i= 0; i < tam; i++)
    {
        if(listaAutomovil[i].idPropietario == idProvisto && listaAutomovil[i].estado == 1)
        {
            codigoMarcas(listaAutomovil[i].marca,marcaTexto);
            printf("%10s %15s\n",listaAutomovil[i].patente,marcaTexto);
        }
    }
    do
    {
        fflush(stdin);
        patenteValida= 0;
        printf("QUE AUTO DESEA RETIRAR DEL ESTACIONAMIENTO? INGRESE LA PATENTE\nPATENTE SELECCIONADA: ");
        gets(patenteSeleccionada);
        patenteValida= validacionPatente(patenteSeleccionada);
    }
    while(patenteValida == 0);

    fflush(stdin);
    for (i= 0; i < tam; i++)
    {
        fflush(stdin);
        autoEncontrado= 0;

        //pantenteValida = strcmp(listaAutomovil[i].patente, aux);
        //printf("%d",pantenteValida);
        if(listaAutomovil[i].estado == 1 && strcmp(listaAutomovil[i].patente, patenteSeleccionada) == 0)
        {
            horasEstadia= devolverHorasEstadia();
            precioEstadia= precioPorHora(listaAutomovil[i].marca);
            totalEstadia= precioEstadia * horasEstadia;
            codigoMarcas(listaAutomovil[i].marca, marcaTexto);

            printf("GENERANDO TICKET...");
            limpiarPantalla();
            printf("*********************** TICKET ***********************\n");// 8
            printf("** NOMBRE DEL PROPIETARIO: %4s                    **\n",nombreProp);//5
            printf("** PATENTE DEL AUTO:       %14s           **\n",listaAutomovil[i].patente);
            printf("** MARCA DEL AUTO:         %14s           **\n",marcaTexto);
            printf("** HORAS ESTACIONADO:      %14d           **\n",horasEstadia);
            printf("** TOTAL A PAGAR:          %14d           **\n",totalEstadia);
            printf("******************************************************\n");

            //printf("AUTO ENCONTRADO GENERANDO TICKET\n");
            listaAutomovil[i].estado= 0; //DADO DE BAJA
            autoEncontrado= 1;
            break;
        }
    }
    if(autoEncontrado==0)
    {
        printf("PATENTE NO ENCONTRADA O VALIDA\n");
    }

    return autoEncontrado;
}

int totalPagarPropietario(sAutomovil listaAutomovil[],int idProvisto,int tam)
{
    int i;
    char marcaTexto[15];
    //int pantenteValida;
    int totalEstadia;
    int horasEstadia;
    int precioEstadia;
    int importeFinal;
    importeFinal = 0;

    for (i= 0; i < tam; i++)
    {
        if(listaAutomovil[i].idPropietario == idProvisto  && listaAutomovil[i].estado == 1)
        {
            horasEstadia= devolverHorasEstadia();
            precioEstadia= precioPorHora(listaAutomovil[i].marca);
            totalEstadia= precioEstadia * horasEstadia;
            codigoMarcas(listaAutomovil[i].marca,marcaTexto);
            printf("%10s %15s %15d %15d %15d\n",listaAutomovil[i].patente,marcaTexto, horasEstadia, precioEstadia, totalEstadia);
            importeFinal= importeFinal+ totalEstadia;
        }
    }
    //printf("importe total %d\n",importeFinal);


    return importeFinal;
}
int totalPagarPropietarioHistorial(sAutomovil listaHistorial[],int idProvisto,int tam)
{
    int i;
    char marcaTexto[15];
    int totalEstadia;
    int horasEstadia;
    int precioEstadia;
    int importeFinal;
    importeFinal = 0;

    for (i= 0; i < tam; i++)
    {
        if(listaHistorial[i].estado == 1)
        {
            horasEstadia= devolverHorasEstadia();
            precioEstadia= precioPorHora(listaHistorial[i].marca);
            totalEstadia= precioEstadia * horasEstadia;
            codigoMarcas(listaHistorial[i].marca,marcaTexto);
            printf("%10s %15s %15d %15d %15d\n",listaHistorial[i].patente,marcaTexto, horasEstadia, precioEstadia, totalEstadia);
            importeFinal= importeFinal+ totalEstadia;
        }
    }
    //printf("importe total %d\n",importeFinal);


    return importeFinal;
}
int bajaAutomoviles(sAutomovil listaAutomovil[], int idProvisto, int tam)
{
    int cont;
    int i;
    cont=0;
    for (i= 0; i < tam; i++)
    {
        if(listaAutomovil[i].idPropietario == idProvisto && listaAutomovil[i].estado == 1)
        {
            listaAutomovil[i].estado= 0; //DADO DE BAJA
            cont++;
        }
    }
    printf("HAN SIDO DADO DE BAJA %d AUTO/S \n",cont);
    return cont;
}
int hayVehiculos(sAutomovil listaAutomoviles[], int tam)
{
    int i;
    int hayVehiculos;
    for(i=0; i<tam; i++)
    {
        if (listaAutomoviles[i].estado == 0)
        {
            hayVehiculos= 0;
        }
        else if(listaAutomoviles[i].estado == 1)
        {
            hayVehiculos = 1;
            break;
        }
    }
    return hayVehiculos;
}
int hayVehiculoEnPropietario(sAutomovil listaAutomoviles[], int tam,int idProvista)
{
    int i;
    int hayVehiculos;
    hayVehiculos=0;
    for(i=0; i<tam; i++)
    {
        if(/*listaAutomoviles[i].estado == 1 && */listaAutomoviles[i].idPropietario == idProvista)
        {
            hayVehiculos = 1;
        }
    }
    return hayVehiculos;

}
int mostrarVehiculos(sAutomovil listaAutomoviles[], int tam)
{
    int i;
    int hayVehiculos;
    char marcaTexto[51];
    hayVehiculos = 0;
    printf("\n%8s %20s %15s\n","ID PROP","PATENTE","MARCA");
    for (i= 0; i < tam; i++)
    {
        if(listaAutomoviles[i].estado == 1)
        {
            codigoMarcas(listaAutomoviles[i].marca,marcaTexto);
            printf("%8d %20s %15s\n",listaAutomoviles[i].idPropietario, listaAutomoviles[i].patente, marcaTexto);
            hayVehiculos++;
        }
    }
    return hayVehiculos;
}
int copiarVehiculos(sAutomovil listaAutomoviles[], sAutomovil historialAutos[], int tam)
{
    int i;
    for (i= 0; i < tam; i++)
    {

            historialAutos[i] = listaAutomoviles[i];

    }
    return 1;
}
int agregarHistorialVehiculos(sAutomovil historialAutos[], int maxHistorial, int idPropietario, char patente[], int marca )
{
    int indexHistorial;
    //printf("cant historial //  %d\n", indexHistorial);
    indexHistorial= autosBuscarLugarLibre(historialAutos, maxHistorial);
    //printf("historial guard pos // %d\n", indexHistorial);
    historialAutos[indexHistorial].idPropietario= idPropietario;
    historialAutos[indexHistorial].marca= marca;
    historialAutos[indexHistorial].estado= 1;
    strcpy(historialAutos[indexHistorial].patente, patente);
    return 1;

}

int recaudacionTotal(sAutomovil historialAutos[], int tam)
{
    int i;
    int recaudacionTotal;
    int horasEstadia, precioEstadia, totalEstadia;
    recaudacionTotal = 0;
    for (i= 0; i < tam; i++)
    {
        if(historialAutos[i].estado == 1)
        {
            horasEstadia= devolverHorasEstadia();
            precioEstadia= precioPorHora(historialAutos[i].marca);
            totalEstadia= precioEstadia * horasEstadia;
            recaudacionTotal= recaudacionTotal + totalEstadia;
        }
    }
    return recaudacionTotal;
}

int recaudacionTotalMarca(sAutomovil historialAutos [], int tam)
{
    int i;
    int totalAlpha;
    int totalFerrari;
    int totalAudi;
    int totalOtros;
    int horasEstadia;
    int precioEstadia;
    int totalEstadia;
    char textoAlpha[20];
    char textoFerrari[20];
    char textoAudi[20];
    char textoOtros[20];

    totalAlpha = 0;
    totalFerrari = 0;
    totalAudi = 0;
    totalOtros = 0;
    for(i=0; i < tam; i++)
    {
        if(historialAutos[i].estado == 1)
        {
            horasEstadia= devolverHorasEstadia();
            precioEstadia= precioPorHora(historialAutos[i].marca);
            totalEstadia= precioEstadia * horasEstadia;
            switch(historialAutos[i].marca)
            {
            case 1:
                totalAlpha = totalAlpha + totalEstadia;
                break;
            case 2:
                totalFerrari= totalFerrari + totalEstadia;
                break;
            case 3:
                totalAudi= totalAudi + totalEstadia;
                break;
            case 4:
                totalOtros= totalOtros + totalEstadia;
                break;
            }

        }
    }
    codigoMarcas(1,textoAlpha);
    codigoMarcas(2,textoFerrari);
    codigoMarcas(3,textoAudi);
    codigoMarcas(4,textoOtros);

    printf("TOTAL POR MARCAS: \n");
    printf("%s: $%d\n",textoAlpha, totalAlpha);
    printf("%s: $%d\n",textoFerrari, totalFerrari);
    printf("%s: $%d\n",textoAudi, totalAudi);
    printf("%s: $%d\n",textoOtros, totalOtros);
    return 0;
}
void mostrarVehiculoEnProp(sAutomovil listaAutos[], int idProvisto, int tam)
{
    int i;
    char marcaTexto[53];
    printf("\n%10s %15s\n","PATENTE","MARCA");
    for (i= 0; i < tam; i++)
    {
        if(listaAutos[i].idPropietario == idProvisto && listaAutos[i].estado == 1)
        {
            codigoMarcas(listaAutos[i].marca,marcaTexto);
            printf("%10s %15s\n",listaAutos[i].patente,marcaTexto);
        }
    }

}
int buscarAudi(sAutomovil listaAutos[], int tam, int idProp)
{
    int encontrado= 0;
    int i;
    for (i= 0; i < tam; i++)
    {
        if(listaAutos[i].idPropietario == idProp  && listaAutos[i].estado == 1)
        {
            if(listaAutos[i].marca == AUDI)
            {
                encontrado= 1;
                break;
            }

        }
    }

    return encontrado;
}

int ordenarAutos(sAutomovil listaA[], int tam)
{
    sAutomovil aux;
    aux.estado = 1;
    int i;
    int j;


    for(i=0; i<tam; i++)
    {
        if(listaA[i].estado == 1)
        {
            for(j=i+1; j<tam; j++)
            {
                if(strcmp(listaA[i].patente,listaA[j].patente)>0)
                {
                    aux = listaA[i];
                    listaA[i]=listaA[j];
                    listaA[j]=aux;
                }
            }

        }

    }

    return 1;
}
int buscarIndexEnListaAutos(sAutomovil listaAutos[], int tam, int idProvista)
{
    int i;
    int index;
    for(i=0; i< tam; i++)
    {
        if(listaAutos[i].idPropietario == idProvista)
        {
            index= i;
        }
    }
    return index;
}
int ordenararPatentes(sAutomovil listaAutos[], int tam)
{
    sAutomovil aux;
    aux.estado = 1;
    int i;
    int j;


    for(i=0; i<tam; i++)
    {
        if(listaAutos[i].estado == 1)
        {
            for(j=i+1; j<tam; j++)
            {
                if(strcmp(listaAutos[i].patente,listaAutos[j].patente)>0) //A-B
                {
                    aux = listaAutos[i];
                    listaAutos[i]=listaAutos[j];
                    listaAutos[j]=aux;
                }

            }

        }

    }

    return 0;

}


