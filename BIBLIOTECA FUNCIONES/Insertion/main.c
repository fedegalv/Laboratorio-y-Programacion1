#include <stdio.h>
#include <stdlib.h>
void insertion(int[],int);

int main()
{
    int len;
    int i;
    int vectorPrueba[11]={2,5,8,3,9,4,5,10,56,12,7};
    //len = sizeof(vectorPrueba)/sizeof(vectorPrueba[0]); // MEDIR LARGO DE ARRAY

    //printf("%d tamanio\n",len);
    insertion(vectorPrueba,11);
    for(i=0;i<11;i++)
    {
        printf("%d--", vectorPrueba[i]);
    }
    return 0;
}

void insertion(int data[], int len)
{
    int i, j;
    int temp;
    for(i=1;i<len;i++)
    {
        temp= data[i];
        j= i-1;
        while(j>=0 && temp<data[j])
        {
            data[j+1] = data [j];
            j--;
        }
        data[j+1]= temp;
    }
}
