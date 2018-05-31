#include <stdio.h>
#include <stdlib.h>

void escribir();

void leer();


int main()
{
    int opcion;
    int flag = 0;

    while(flag == 0)
    {
        printf("1- Escribir\n");
        printf("2- Leer\n");
        scanf("%d", &opcion);

        if(opcion == 1)
        {
            escribir();
        }
        else
        {
            if(opcion == 2)
            {
                leer();
            }
            else
            {
                flag = 1;
            }
        }


    }



    return 0;
}

void escribir()
{
    FILE* archivo;
    int num = 123;

    archivo = fopen("caca.txt","ab");

    if(archivo != NULL)
    {
        fprintf(archivo, "Hola\n %d\n", num);
        fclose(archivo);
    }
}

void leer()
{
    FILE* archivo;
    char texto[50];
    int a;

    archivo = fopen("caca.txt", "rb");

    if(archivo != NULL)
    {
        fscanf(archivo, "%s\n %d\n", texto, &a);
        fclose(archivo);
    }

    printf("%s\n %d\n", texto, a);



}
