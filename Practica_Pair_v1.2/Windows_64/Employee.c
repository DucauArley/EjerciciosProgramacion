#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "string.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    int retorno = 0;

    if(strcmp(employee_getNombre(pEmployeeA), employee_getNombre(pEmployeeB)) < 0)
    {
        retorno = 1;
    }
    if(strcmp(employee_getNombre(pEmployeeA), employee_getNombre(pEmployeeB)) > 0)
    {
        retorno = -1;
    }

    return retorno;
}


void employee_print(Employee* empleado)
{
    printf("%d ", employee_getId(empleado));
    printf("%s ", employee_getNombre(empleado));
    printf("%s\n", employee_getApellido(empleado));
}

void employee_printAll(ArrayList* lista)
{
    int i = al_isEmpty(lista);
    int tam;
    Employee* aux;

    if(lista != NULL && i == 0)
    {
        aux = employee_new();
        tam = al_len(lista);

        for(i=0;i<tam;i++)
        {
            aux = al_get(lista,i);
            if(employee_getEstado(aux) == 1)
            {
                employee_print(aux);
            }
        }
    }
    else
    {
        printf("El Array esta vacio o no se pudo abrir el archivo\n");
    }
}

void employee_printLots(ArrayList* lista ,int desde, int hasta)
{
    int i = al_isEmpty(lista);
    Employee* aux;
    int tam = al_len(lista);

    aux = employee_new();

    if(desde < hasta && lista != NULL && hasta < tam && desde >= 0 && i == 0)
    {
        for(i=desde;i<hasta;i++)
        {
            aux = al_get(lista, i);
            if(employee_getEstado(aux) == 1)
            {
                employee_print(aux);
            }
        }
    }
    else
    {
        printf("Error, no se pudo imprimir\n");
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

void employee_delete(ArrayList* lista)
{
    int id;
    int indice;

    printf("Ingrese la id del empleado que desea eliminar\n");
    scanf("%d", &id);

    indice = esta(lista, id);

    if(indice == -1)
    {
        printf("El empleado que desea eliminar no existe\n");
    }
    else
    {
        al_remove(lista, indice);
        printf("El empleado ha sido removido exitosamente\n");
    }

}

void employee_add(ArrayList* lista)
{
    int id;
    int ok;
    Employee* aux;

    if(lista != NULL)
    {
        printf("Ingrese el id\n");
        scanf("%d", &id);

        ok = esta(lista, id);

        if(ok != -1)
        {
            printf("Ya existe un empleado con esa id\n");
        }
        else
        {
            aux = employee_new();

            printf("Ingrese el nombre\n");
            scanf("%s", aux->nombre);

            printf("Ingrese el apellido\n");
            scanf("%s", aux->apellido);

            employee_setEstado(aux, 1);
            employee_setId(aux, id);


            al_add(lista, aux);
        }
    }
}



int employee_setId(Employee* empleado, int id)
{
    int retorno = -1;

    if(empleado != NULL)
    {
        empleado->id = id;
        retorno = 0;
    }

    return retorno;
}

int employee_getId(Employee* empleado)
{
    int id;
    if(empleado != NULL)
    {
        id = empleado->id;
    }

    return id;
}

int employee_setEstado(Employee* empleado, int estado)
{
    int retorno = -1;

    if(empleado != NULL && (estado == 1 || estado == 0))
    {
        empleado->estado = estado;
        retorno = 0;
    }

    return retorno;
}

int employee_getEstado(Employee* empleado)
{
    int estado;

    if(empleado != NULL)
    {
        estado = empleado->estado;
    }

    return estado;
}

int employee_setNombre(Employee* empleado, char* nombre)
{
    int retorno = -1;

    if(empleado != NULL)
    {
        strcpy(empleado->nombre, nombre);
        retorno = 0;
    }

    return retorno;
}


char* employee_getNombre(Employee* empleado)
{
    char* retorno;

    retorno = (char*) malloc(sizeof(char) * 50);

    if(empleado != NULL && retorno != NULL)
    {
        strcpy(retorno, empleado->nombre);
    }

    return retorno;
}

int employee_setApellido(Employee* empleado, char* apellido)
{
    int retorno = -1;

    if(empleado != NULL)
    {
        strcpy(empleado->apellido, apellido);
        retorno = 0;
    }

    return retorno;
}


char* employee_getApellido(Employee* empleado)
{
    char* retorno;

    retorno = (char*) malloc(sizeof(char) * 50);

    if(empleado != NULL && retorno != NULL)
    {
        strcpy(retorno, empleado->apellido);
    }

    return retorno;
}

int esta(ArrayList* lista, int id)
{
    int i = al_isEmpty(lista);
    Employee* aux;
    int tam = al_len(lista);
    int indice = -1;

    aux = employee_new();

    if(lista != NULL && i == 0)
    {
        for(i=0;i<tam;i++)
        {
            aux = al_get(lista,i);
            if(employee_getId(aux) == id)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}






