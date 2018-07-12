#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "string.h"


int parserEmployee(ArrayList* pArrayListEmployee, char* path)
{
    char buffer[4][50];
    Employee* aux;
    FILE* pFile;
    int retorno = 0;

    pFile = fopen(path, "r");

    if(pFile == NULL)
    {
        printf("No se ha podido abrir el archivo\n");
        exit(1);
        retorno = -1;
    }

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);


    while(!feof(pFile))
    {
        aux = employee_new();
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        aux->id = atoi(buffer[0]);
        strcpy(aux->nombre,buffer[1]);
        strcpy(aux->apellido,buffer[2]);

        if(strcmp(buffer[3], "true") == 0)
        {
            aux->estado = 1;
        }
        else
        {
            aux->estado = 0;
        }

        al_add(pArrayListEmployee, aux);
    }

    return retorno;
}
