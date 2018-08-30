#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char opcion;
    do
    {
        printf("(A)lta usuario: \n");
        printf("(B)aja usuario: \n");
        printf("(M)odificar usuario : \n");
        printf("(S)alir \n");
        fflush(stdin);
        scanf("%c",&opcion);
        opcion= toupper(opcion); //recibe un parametro y convierte a mayuscula

        switch(opcion)
        {
        case 'A':
            printf("Dando de alta el usuario...");
            break;
        case 'B':
            printf("Dando de baja el usuario...");
            break;
        case 'M':
            printf("Modificando el usuario...");
            break;
        }
        system("pause"); // pausa el programa, para limpiar
        system("cls"); // se limpia la consola
    }while(opcion != 'S');
    return 0;
}
