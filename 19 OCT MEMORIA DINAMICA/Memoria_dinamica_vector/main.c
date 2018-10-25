#include <stdio.h>
#include <stdlib.h>
#define T 5
int main()
{
    int* vector;
    int* pAux; /// SE GUARDA LO QUE DEVUELVE realloc EN UN AUXILIAR PARA QUE NO SE PIERDA LOS DATOS SI NO ENCUENTA ESPACIO
    int i;
    vector= (int*) malloc(sizeof(int)*T); /// RESERVO 5 ESPACIOS
    /// vector = (int*) calloc(sizeof(int), T); /// INICIALIZA EN 0 EL VECTOR

    if(vector != NULL)
    {
        for(i=0; i<T; i++)
        {
            *(vector +i)= i+1; /// CARGO VALORES
        }
        for(i=0; i<T; i++)
        {
            printf("%d\n", *(vector+i) );
        }
        /// FUNCION QUE AGREGA MAS ESPACIO CONSECUTIVOS, SI NO LOS ENCUENTA LOS RELOCALIZA DE MANERA CONSECUTIVA
        pAux= realloc(vector, sizeof (int) * (T+5) *5);
        ///                             LO QUE TENIA(T+6) * LO QUE QUIERO (*5) (EL DOBLE)
        /// realloc(variable, tamaño);

        if(pAux != NULL) /// SI realloc ENCONTRO UN LUGAR EN MEMORIA SE GUARDA EN UN AUXILIAR
        {
            vector = pAux;
            for(i=T; i< T+5; i++) /// i EMPIEZA DESDE DONDE DEJO DE CARGAR, PARA CARGAR LO QUE FALTA LUEGO DEL realloc
            {
                *(vector+i) = i+1;
            }
            printf("MOSTRAMOS INFO\n");
            for(i=0; i< T+5; i++) /// MOSTRAMOS COMLPETO
            {
                printf("\n%d", *(vector+i) );
            }
            printf("\nMOSTRAMOS 3 LUEGO DE REDUCIR");
            vector= realloc(vector, sizeof(int)*3 ); /// REDUCIMOS EL TAMAÑO A 3, LOS DEMAS DATOS QUEDAN LIBERADOS

            for(i=0; i< 3; i++) /// MOSTRAMOS LO QUE QUEDO, SI TUVIERA QUE RECORRER COMO ERA ANTES MOSTRARIA BASURA
            {
                printf("\n%d", *(vector+i) );
            }
        }
    }
    else
    {
        printf("NO HAY ESPACIO");
    }
    return 0;
}
