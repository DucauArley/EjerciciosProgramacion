#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* vector;
    int i;
    int* aux;

    vector = (int*) calloc(5, sizeof(int) * 5);

    if(vector == NULL)
    {
        printf("No se pudo adquirir memoria\n");
        exit(1);
    }

    for(i=0;i<5;i++)
    {
        printf("%d\n", *(vector + i));
    }
    printf("\n\n");



    return 0;
}
