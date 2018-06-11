#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    return 0;
}


void employee_print(Employee* empleado)
{
    printf("%d ", empleado->id);
    printf("%s ", empleado->nombre);
    printf("%s ", empleado->apellido);
}

void employee_printLots(Employee* empleado, int tam)
{
    int i;

    if(empleado != NULL)
    {
        for(i=0;i<tam;i++)
        {
            if((empleado + i)->estado == 1)
            {
                employee_print(empleado+i);
            }
        }
    }
}


Employee* employee_new()
{
    Employee* returnAux;

    returnAux = (Employee*) malloc(sizeof(Employee));

    if(returnAux != NULL)
    {
        returnAux->id = -1;
        returnAux->estado = 0;
        strcpy(returnAux->nombre, "");
        strcpy(returnAux->apellido, "");
    }
    else
    {
        printf("No se pudo conseguir espacio en memoria\n");
    }
    return returnAux;
}

void employee_delete(Employee* empleado, ArrayList* listaEmpleados)
{
    int i;
    int tam;
    int id;

    tam = al_len(listaEmpleados);
    printf("Ingrese el id del empleado que desea eliminar\n");
    scanf("%d", &id);

    for(i=0;i<tam;i++)
    {
        if()

    }

}

int employee_setId(Employee* empleado, int id)
{

    return 0;

}

int employee_getId(Employee* empleado)
{

    return 0;

}


