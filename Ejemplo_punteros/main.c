#include <stdio.h>
#include <stdlib.h>
void calcular(int*);
int main()
{
   int x = 7;
   calcular(&x);
   printf("X=%d",x);

    return 0;
}
void calcular(int* p)
{
    *p=10;
}
