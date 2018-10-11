#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcion;

    do
    {
        printf("***** MENU PRINCIPAL **** \n");
        printf("1- ALTA DE CLIENTE"
               "\n2- MODIFICAR DATOS DEL CLIENTE"
               "\n3- BAJA DEL CLIENTE"
               "\n4- PUBLICAR"
               "\n5- PAUSAR PUBLICACION"
               "\n6- REANUDAR PUBLICACION"
               "\n7- IMPRIMIR CLIENTES"
               "\n8- IMPRIMIR PUBLICACIONES\n"
               "\nOPCION SELECCIONADA: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:

            break;

        case 2:

            break;

        case 3:

            break;
        case 4:

            break;

        case 5:

            break;

        case 6:

            break;

        case 7:

            break;

        case 8:

            break;
        }

    }
    while(opcion != 10);//CONDICION PARA MANTENER MENU
    return 0;
}
