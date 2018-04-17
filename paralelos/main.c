#include <stdio.h>
#include <stdlib.h>


void mostrarEmpleados(char mat[][20], char sex[], int leg[], float money[], int tam);
void mostrarEmpleado(char nombre[], char sex, int leg, float sueldo);
void ordenarEmpleados(char mat[][20], char sex[], int leg[], float money[], int tam);

int main()
{
    char nombres[][20] = {"Juan", "Alberto", "Ana", "Luisa", "Miguel"};
    char sexos[]= {'m', 'm', 'f', 'f', 'm'};
    int legajos[]= { 123, 333, 434, 675, 111};
    float sueldos[]= { 10000.50, 20000.75, 25555.90, 5300.60, 12500.50};


    mostrarEmpleados(nombres, sexos, legajos, sueldos, 5);

    ordenarEmpleados(nombres, sexos, legajos, sueldos, 5);

    mostrarEmpleados(nombres, sexos, legajos, sueldos, 5);

    return 0;
}

void mostrarEmpleados(char mat[][20], char sex[], int leg[], float money[], int tam)
{

    printf(" \n           Nombre     Sexo      Legajo     Sueldo\n\n");

    for(int i=0; i< tam; i++)
    {
        mostrarEmpleado(mat[i], sex[i], leg[i], money[i]);
    }
}
void mostrarEmpleado(char nombre[], char sex, int leg, float sueldo)
{

    printf(" %20s   %c         %d        %.2f\n", nombre, sex, leg, sueldo);
}


void ordenarEmpleados(char mat[][20], char sex[], int leg[], float money[], int tam)
{

    int auxInt;
    float auxFloat;
    char auxChar;
    char auxCad[20];

    for(int i=0; i< tam-1; i++)
    {
        for(int j = i+1; j < tam; j++)
        {

            if(strcmp(mat[i], mat[j])>0)
            {
                strcpy(auxCad, mat[i]);
                strcpy(mat[i], mat[j]);
                strcpy(mat[j], auxCad);

                auxChar = sex[i];
                sex[i] = sex[j];
                sex[j] = auxChar;

                auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;

                auxFloat= money[i];
                money[i] = money[j];
                money[j] = auxFloat;

            }

        }

    }
}
