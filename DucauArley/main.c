#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "string.h"
#include "Funciones.h"


int main()
{
    ArrayList* lista;
    eEmpleado* empleado;
    int i;
    int tam;
    int estado;

    lista = al_newArrayList();

    if(empleado != NULL && lista != NULL)
    {
        parserEmpleado(lista);

        tam = al_len(lista);

        estado = al_isEmpty(lista);

        if(estado == 0)
        {
            al_sort(lista, ordenar, 0);
            map(lista, calcularSueldo);

            printf("Id    Nombre     Direccion           Horas             Sueldo\n");
            for(i=0;i<tam;i++)
            {
                empleado = al_get(lista, i);
                printEmpleado(empleado);
            }

            estado = guardarEnArchivo(lista, "Sueldos.csv");

            if(estado == 0)
            {
                printf("Guardado exitoso");
            }

        }
        else
        {
            printf("El array esta vacio\n");
        }
    }

    return 0;
}
