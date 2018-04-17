#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarEmpleados(char[][20], int[], char[], float[], int);
void mostrarEmpleado(char[], int, char, float);
void ordenamiento(char[][20], int[], char[], float[], int);

int main()
{
    char nombres[5][20];
    int legajos[5];
    char sexo[5];
    float sueldo[5];
    int i;

    for(i=0;i<5;i++)
    {
        printf("Ingrese un nombre\n");
        fflush(stdin);
        gets(nombres[i]);

        printf("Ingrese un legajo\n");
        scanf("%d", &legajos[i]);

        printf("Ingrese un sexo f o m\n");
        fflush(stdin);
        scanf("%c", &sexo[i]);

        printf("Ingrese el sueldo\n");
        scanf("%f", &sueldo[i]);
    }


    mostrarEmpleados(nombres, legajos, sexo, sueldo, i);

    ordenamiento(nombres, legajos, sexo, sueldo, i);

    mostrarEmpleados(nombres, legajos, sexo, sueldo, i);

    return 0;
}

void mostrarEmpleados(char nombres[][20], int legajo[], char sexo[], float sueldo[], int tam)
{
    int i;

    printf("Nombres  Legajo  Sexo  Sueldo \n");
    for(i=0;i<tam;i++)
    {
        mostrarEmpleado(nombres[i], legajo[i], sexo[i], sueldo[i]);
    }

}

void mostrarEmpleado(char nombres[], int legajo, char sexo, float sueldo)
{
    printf("%s   %3d   %5c    %.2f    \n", nombres, legajo, sexo, sueldo);
}

void ordenamiento(char nombres[][20], int legajo[], char sexo[], float sueldo[], int tam)
{
    int i;
    int j;
    int auxI;
    float auxF;
    char auxS[20];
    char auxC;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmp(nombres[i], nombres[j]) > 0)
            {
                strcpy(auxS, nombres[i]);
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], auxS);

                auxI = legajo[i];
                legajo[i]  = legajo[j];
                legajo[j] = auxI;

                auxC = sexo[i];
                sexo[i] = sexo[j];
                sexo[j] = auxC;

                auxF = sueldo[i];
                sueldo[i] = sueldo[j];
                sueldo[j] = auxF;

            }
        }
    }
}


