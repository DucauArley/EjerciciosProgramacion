#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* vector;
    int i;
    int* aux;

    vector = (int*) malloc(sizeof(int) * 5);

    if(vector == NULL)
    {
        printf("No se pudo adquirir memoria\n");
        exit(1);
    }

    for(i=0;i<5;i++)
    {
        printf("Ingrese un numero\n");
        scanf("%d", vector + i);
    }


    for(i=0;i<5;i++)
    {
        printf("%d\n", *(vector + i));
    }
    printf("\n\n");

    aux = (int*) realloc(vector, 10 * sizeof(int));

    if(aux != NULL)
    {
        vector = aux;
        printf("Se agrando el array con exito\n");
    }
    else
    {
        printf("No se puede agrandar el array\n");
    }

     for(i=5;i<10;i++)
    {
        printf("Ingrese un numero\n");
        scanf("%d", vector + i);
    }


    for(i=0;i<10;i++)
    {
        printf("%d\n", *(vector + i));
    }
    printf("\n\n");

    printf("se achico el array a 6 elementos");

    vector = (int*) realloc(vector, 6 * sizeof(int));

    for(i=0;i<10;i++)
    {
        printf("%d\n", *(vector + i));
    }
    printf("\n\n");

    free(aux);
    free(vector);

    return 0;
}
