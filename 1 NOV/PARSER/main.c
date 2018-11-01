#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r;
    char id[10];
    char nombre[30];
    char hsTrabajadas[10];
    char sueldo[30];

    FILE* archivo;
    archivo = fopen("data.csv", "r");
    if(archivo == NULL)
     {
     printf("El archivo no existe");
     exit(EXIT_FAILURE);
     }
    do
    {
        r= fscanf(archivo, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, hsTrabajadas, sueldo);
        if(r==4){
        printf("%s -- %s -- %s -- %s\n ", id, nombre, hsTrabajadas, sueldo);
        }
        else{break;}
    }while(!feof(archivo));

    fclose(archivo);

    return 0;
}
