#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* pArchivo;
    int dato = 20;
    int aux;
    //pArchivo= fopen("archivoBinario.dat", "wb");
    pArchivo= fopen("archivoBinario.dat", "rb");
    if(pArchivo != NULL)
    {
        /// FUNCION ESCRIBIR EN ARCHIVO
        //fwrite(&dato, sizeof(int), 1, pArchivo);
     ///fwrite(NOMBRE DEL PUNTERO, TAMANIO DE LA VARIABLE, CANTIDAD DE DATOS A ESCRIBIR, PUNTERO AL ARCHIVO)
        fread(&aux,sizeof(int), 1, pArchivo);
        printf("EL NUMERO ES: %d",aux);

    }else{printf("NO SE PUDO ESCRIBIR EL ARCHIVO\n");}
    return 0;
}
