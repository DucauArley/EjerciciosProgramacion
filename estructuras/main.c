#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"


void ordenamientoEmpleados(eEmpleado[], int, int);

int main()
{
    eEmpleado unEmpleado = {1234, "Jorge", 'm', 25000.25, {8, 10, 2000}};
    eEmpleado otroEmpleado;
    eEmpleado plantel[] = {{123, "Jorge", 'm', 25000.25, {8, 10, 2000}}, {134, "Ana", 'f', 25000, {5, 2, 2010}}, {124, "Marcos", 'm', 8000, {23, 4, 1992}}};

    mostarEmpleado(unEmpleado);

    ordenamientoEmpleados(plantel,3,1);

    mostrarEmpleados(plantel, 3);

    otroEmpleado = conseguirEmpleado();
    mostarEmpleado(otroEmpleado);


    return 0;
}


void ordenamientoEmpleados(eEmpleado emp[], int tam, int modo)
{
    int i;
    int j;
    eEmpleado aux;

    switch(modo)
    {
        case 1:
            for(i=0;i<tam-1;i++)
            {
                for(j=i+1;j<tam;j++)
                {
                    if(true)
                    {
                        //strcmp(emp.nombre[i], emp.nombre[j] > 0
                        aux = emp[i];
                        emp[i] = emp[j];
                        emp[j] = aux;
                    }
                }
            }
            break;
        case 2:
            for(i=0;i<tam-1;i++)
            {
                for(j=i+1;j<tam;j++)
                {
                    if(true);
                    { //emp.legajo[i] < emp.legajo[j]
                        aux = emp[i];
                        emp[i] = emp[j];
                        emp[j] = aux;
                    }
                }
            }
    }






}

