#include <stdio.h>
#include <stdlib.h>

void funcionUno(int [], int);

void funcionDos(int [], int);

void funcionTres(int*, int);

void funcionCuatro(int*, int);

int main()
{
    int vec[5];
    int i;

    for(i=0;i<5;i++)
    {
        printf("Ingrese un numero\n");
        scanf("%d", &vec[i]);
    }


    funcionUno(vec, 5);
    funcionDos(vec, 5);
    funcionTres(vec, 5);
    funcionCuatro(vec, 5);

    return 0;
}

void funcionUno(int vec[], int tam)
{
    int i;

    printf("Funcion uno\n");


    for(i=0;i<tam;i++)
    {
        printf("%d\n", vec[i]);
    }
}

void funcionDos(int vec[], int tam)
{
    int i;

    printf("Funcion dos\n");

    for(i=0;i<tam;i++)
    {
        printf("%d\n", *(vec + i));
    }
}

void funcionTres(int* vec, int tam)
{
    int i;

    printf("Funcion tres\n");


    for(i=0;i<tam;i++)
    {
        printf("%d\n", vec[i]);
    }
}

void funcionCuatro(int* vec, int tam)
{
    int i;

    printf("Funcion cuatro\n");

    for(i=0;i<tam;i++)
    {
        printf("%d\n", *(vec + i));
    }
}
