#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;


typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;

}eEmpleado;

void mostarEmpleado(eEmpleado);

eEmpleado conseguirEmpleado();

void mostrarEmpleados(eEmpleado[], int);

void ordenamientoEmpleados(eEmpleado[], int, int);
