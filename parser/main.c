#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* archivo;
    int cant;
    int n1, n2, n3, n4;

    archivo = fopen("archivo.txt","r");

    if(archivo == NULL)
    {
        printf("No se pudo abrir el archivo");
    }
    else
    {
        while(!feof(archivo))
        {
            cant = fscanf(archivo, "%d,%d,%d,%d\n", &n1, &n2, &n3, &n4);

            if(cant != 4)
            {
                printf("No se pudieron leer todos los datos\n");
            }
            else
            {
                printf("n1: %d n2: %d n3: %d n4: %d\n", n1, n2, n3, n4);
            }
        }

    }



    return 0;
}
