#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"


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
