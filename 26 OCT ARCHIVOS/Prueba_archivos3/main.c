#include <stdio.h>
#include <stdlib.h>
/// GUARDAR ARRAY DE NOMBRES Y LUEGO RESCATAR ESOS NOMBRES EN MEMORIA Y MOSTRAR
int main()
{
    /*
    FILE* pArchivo;
    pArchivo = fopen("texto.txt", "w");


    if(pArchivo!= NULL)
    {
        fprintf(pArchivo, "hola\n");
        fprintf(pArchivo, "chau");


    }else{printf("NO SE PUDO ESCRIBIR EL ARCHIVO\n");}
    fclose(pArchivo);
    ESCRIBIR */
    FILE* archivo;
    char p1[30];
    char p2[30];

    archivo= fopen("texto.txt", "r");
    if(archivo!= NULL)
    {
        fgets(p1,20,archivo); /// LEE LA PRIMERA LINEA DEL ARCHIVO
        puts(p1);

        fgets(p2,20,archivo);
        puts(p2);

    }else{printf("NO SE PUDO ESCRIBIR EL ARCHIVO\n");}






    return 0;
}
