#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* pArchivo;
    char palabra[20]= "TEXTO A COPIAR";
    pArchivo= fopen("texto","r"); // DISTINTOS MODOS W, R, A ETC
    ///            (PATH ES EL ARCHIVO EN SI,MODO SEA READ WRITE ETC)
    if(pArchivo!= NULL)
    {
        /// ESCRIBE TEXTO CON FORMATO DESEADO
        //fprintf(pArchivo, "%s hellooooooo\n todos!!\n",palabra);
        /// fprintf(DESTINO, ORIGEN)
        fgets(palabra, 20, pArchivo);
        puts(palabra);
    }else{printf("NO SE PUDO ESCRIBIR EL ARCHIVO\n");}
    fclose(pArchivo);

    return 0;
}
