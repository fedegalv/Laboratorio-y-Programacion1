#include <stdio.h>
#include <stdlib.h>

int main()
{
    int miVector[5]={4,5,6,7,8};
    // int miVector[6]={} INICIALIZA TODO EN 0
    int i;
    int aux;
    for(i=0;i<5;i++)
    {
         printf("Ingrese un numero: \n");
         scanf("%d",&miVector[i]);
    }
    for(i=0;i<5;i++)
    {
       if (miVector[i]%2==0)
       {
             printf("%d\n",miVector[i]);
       }
    }
    printf("Ingrese numero a buscar: ");
    scanf("%d", &aux);
    for(i=0;i<5;i++)
    {
        if(aux == miVector[i])
        {
            printf("Posicion %d\n",i);
            break;
        }
    }



    return 0;
}
