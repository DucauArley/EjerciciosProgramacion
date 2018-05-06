#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarEmpleados(eEmpleado[], int);

int buscarLibre(eEmpleado[], int);

int buscarEmpleado(eEmpleado[], int, int);

void altaEmpleado(eEmpleado[], int, eSector [], int);

void bajaEmpleado(eEmpleado [], int, eSector [], int);

void modificacionEmpleado(eEmpleado [], int, eSector [], int);

void ordenarEmpleados(eEmpleado [], int);

int totalSueldos(eEmpleado [], int);

void mayorSueldo(eEmpleado [], int, eSector [], int);

void empleadosPorSector(eEmpleado [], int, eSector [], int);

void cantidadDeEmpleadosPorSector(eEmpleado [], int, eSector [], int);

void totalSueldosPorSector(eEmpleado [], int, eSector []);

void empleadosQueMasGananPorSector(eEmpleado [], int, eSector [], int);

int mostrarSector(eSector [], int);

void mostarEmpleado(eEmpleado, eSector [], int);

void mostrarEmpleados(eEmpleado[], int, eSector [], int);

int menu();

void listar(EPersona [], int);

void grafico(EPersona [], int);

void mostrarPersona(EPersona);

void mostrarPersonas(EPersona [], int);

int numerico(char []);

int alfabetico(char []);

void mostrarMateriasPorAlumno(eAlumno [], int, eMateria [], int, eInscripcion [], int);

void mostrarAlumnosPorMateria(eAlumno [], int, eMateria [], int, eInscripcion [], int);

void cantidadAlumnosPorMateria(eMateria [], int, eInscripcion [], int);

int contadorAlumnos(int, eInscripcion [], int);

void materiasMasCursadas(eMateria [], int, eInscripcion [], int);