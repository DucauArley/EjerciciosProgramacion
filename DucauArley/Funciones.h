#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "string.h"

typedef struct
{
    int id;
    char nombre[20];
    char direccion[20];
    int hora;
    int sueldo;
}eEmpleado;

eEmpleado* nuevoEmpleado();

int setId(eEmpleado*, int);

int getId(eEmpleado*);

int setNombre(eEmpleado*, char*);

char* getNombre(eEmpleado*);

int setDireccion(eEmpleado*, char*);

char* getDireccion(eEmpleado*);

int setHoras(eEmpleado*, int);

int getHoras(eEmpleado*);

int setSueldo(eEmpleado*, int);

int getSueldo(eEmpleado*);

void printEmpleado(eEmpleado*);

int parserEmpleado(ArrayList*);

int ordenar(void*, void*);

int calcularSueldo(void*);

int guardarEnArchivo(ArrayList*, char*);
