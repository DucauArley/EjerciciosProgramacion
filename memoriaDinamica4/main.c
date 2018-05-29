#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;
    int estado;
}eEmpleado;

eEmpleado* new_Empleado();

eEmpleado* new_Empleado_Param(int, char*, float);

void inicializarEmpleados(eEmpleado* ,int);

eEmpleado* newArrayEmpleados(int);

void guardarEmpleados(eEmpleado*, int, char*);



void mostrarEmpleados(eEmpleado*, int);

void mostrarEmpleado(eEmpleado*);


int main()
{
    eEmpleado* emp1;
    eEmpleado* personal;
    int tam = 50;

    personal = newArrayEmpleados(tam);

    if(personal ==  NULL)
    {
        printf("No se pudo conseguir memoria\n");
        exit(1);
    }

    emp1 = new_Empleado_Param(230, "Juan carlos", 20000);

    *personal = *emp1;

    emp1 = new_Empleado_Param(546, "Julieta", 25000);

    *(personal + 1) = *emp1;

    emp1 = new_Empleado_Param(456, "Juan carlos", 30000);

    *(personal + 2) = *emp1;

    mostrarEmpleados(personal, 3);

    return 0;
}

eEmpleado* new_Empleado()
{
    eEmpleado* empleado;

    empleado = (eEmpleado*) malloc(sizeof(eEmpleado));

    if(empleado != NULL)
    {
        empleado->legajo = 0;
        strcpy(empleado->nombre, "");
        empleado->sueldo = 0;
        empleado->estado = 0;
    }

    return empleado;
}

eEmpleado* new_Empleado_Param(int legajo, char* nombre, float sueldo)
{
    eEmpleado* empleado;

    empleado = new_Empleado();

    if(empleado != NULL)
    {
        empleado->legajo = legajo;
        strcpy(empleado->nombre, nombre);
        empleado->sueldo = sueldo;
        empleado->estado = 1;
    }

    return empleado;
}

void inicializarEmpleados(eEmpleado* empleado, int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        (empleado + i)->estado == 0;
    }

}

eEmpleado* newArrayEmpleados(int tam)
{
    eEmpleado* array;

    if(tam>0)
    {
        array = (eEmpleado*) malloc(tam * sizeof(eEmpleado));

        if(array != NULL)
        {
            inicializarEmpleados(array, tam);
        }
    }

    return array;
}

int buscarLibre(eEmpleado* empleados, int tam)
{
    int indice = -1;
    int i;

    for(i=0;i<tam;i++)
    {
        if((empleados+i)->estado == 1)
        {
            indice = i;
        }
    }

    return indice;
}

void guardarEmpleados(eEmpleado* empleado, int tam, char* path)
{
    FILE* f;
    int i;

    f = fopen(path, "wb");

    if(f != NULL)
    {
        for(i=0;i<tam;i++)
        {
            if((empleado+i)->estado == 1)
            {
                fwrite((empleado + i), sizeof(eEmpleado), 1, f);
            }
        }

        fclose(f);
        printf("Empleados guardados con exito");
    }

}

int cargarEmpleados(eEmpleado* empleado, int tam, char*path)
{
    FILE* f;
    int indice;
    eEmpleado empleadoAuxiliar;
    int cant;
    int total = 0;

    //f = fopen();



    while(feof(f) == 0)
    {
        indice = buscarLibre(empleado, tam);

        if(indice == -1)
        {
            printf("");
            break;
        }
        else
        {
            cant = fread(&empleadoAuxiliar, sizeof(eEmpleado), 1, f);

            if(cant != 1)
            {
                if(feof(f) == 1)
                {
                    break;
                }
                else
                {
                    printf("No se pudo leer el ultimo registro\n");
                    break;
                }


            }

            *(empleado + indice) = empleadoAuxiliar;
            total ++;

        }

    }

    fclose(f);
    return total;
}



void mostrarEmpleado(eEmpleado* empleado)
{
    printf("Legajo: %d\n", empleado->legajo);
    printf("Nombre: %s\n", empleado->nombre);
    printf("Sueldo: %.2f\n", empleado->sueldo);
}

void mostrarEmpleados(eEmpleado* empleado, int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        if((empleado + i)->estado == 1)
        {
            mostrarEmpleado(empleado + i);
        }
    }
}



