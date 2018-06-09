#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    char buffer[4][50];
    ArrayList* lista;
    Employee aux;

    pFile = fopen("data.csv", "r");

    if(pFile == NULL)
    {
        printf("No se ha podido abrir el archivo\n");
        exit(1);
    }

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);


    while(!feof(pFile))
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        aux.id = atoi(buffer[0]);
        strcpy(aux.nombre,buffer[1]);
        strcpy(aux.apellido,buffer[2]);

        if(strcmp(buffer[3], "true") == 0)
        {
            aux.id = 1;
        }
        else
        {
            aux.id = 0;
        }

        al_add(pArrayListEmployee, aux);
    }

    return 0;
}
