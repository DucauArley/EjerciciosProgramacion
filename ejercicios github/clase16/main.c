#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[20];
    int edad;
    int dni;
}ePersona;

int loadPersona(ePersona*);

void printPersona(ePersona*);

int main()
{
    ePersona person;
    int retorno;

    retorno = loadPersona(&person);

    if(retorno == 0)
    {
        printf("No se pudo cargar la persona");
    }
    else
    {
        printPersona(&person);
    }
    return 0;
}

int loadPersona(ePersona* persona)
{
    int flag = 0;

    if(persona != NULL)
    {
        printf("Ingrese el nombre\n");
        gets(persona->nombre);

        printf("Ingrese el dni\n");
        scanf("%d", &persona->dni);

        printf("Ingrese la edad\n");
        scanf("%d", &persona->edad);

        flag = 1;
    }
    return flag;
}

void printPersona(ePersona* persona)
{
    printf("Nombre: %s\n", persona->nombre);
    printf("Edad: %d\n", persona->edad);
    printf("DNI: %d\n", persona->dni);
}

