#include <stdio.h>
#include <stdlib.h>
#define T 5
ordenarVector(miVector,tam)
int main()
{
    int miVector[T]={2,6,1,3,4};
    int i;
    int j;
    int aux;
    int flag =0;
    // ORDENA MAYOR A MENOr
    for(i=0; i<T-1; i++)
    {
        for(j=i+1; j< T, j++)
        {
            if(miVector[i] > miVector[j])//Criterio ordenamiento
            {
                aux= miVector[i];
                miVector[i]= miVector[j];
                miVector[j]= aux];

            }
        }
    }
    return 0;
}
CARGAR ORDENAR BUSCAR REEMPLAZAR MOSTRAR EN UN MENU
