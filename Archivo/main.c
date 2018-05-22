#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* pArchivo;
    char cadena[100] = "Me fui";
    char cadena2[100] = "Otro texto";

    pArchivo = fopen("miArchivo.txt","w");

    if(pArchivo != NULL)
    {
        fprintf(pArchivo, "Hola a todos\n");
        fprintf(pArchivo, cadena);
        fprintf(pArchivo, "\nAca con mascara %s", cadena2);
        fclose(pArchivo);
    }
    else
    {
        printf("Imposible abrir el archivo");
    }


    pArchivo = fopen("miArchivo.txt","r");

    if(pArchivo != NULL)
    {
        while(!feof(pArchivo))
        {
            fgets(cadena, 100, pArchivo);
            puts(cadena);
        }

        fclose(pArchivo);
    }
    else
    {
        printf("Imposible abrir el archivo");
    }




    return 0;
}
