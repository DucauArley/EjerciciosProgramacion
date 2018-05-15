#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vec[5];
    int i;

    for(i=0;i<5;i++)
    {
        printf("Ingrese un numero\n");
        scanf("%d", (vec + i));
    }

    printf("Los numeros ingresados son: \n");

    for(i=0;i<5;i++)
    {
        printf("%d\n", *(vec + i));
    }

    return 0;
}
