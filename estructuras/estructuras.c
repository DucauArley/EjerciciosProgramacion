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


void mostarEmpleado(eEmpleado emp)
{
    printf("\nLegajo: %d\n", emp.legajo);
    printf("Nombre: %s\n", emp.nombre);
    printf("Sexo: %c\n", emp.sexo);
    printf("Sueldo: %.2f\n", emp.sueldo);
    printf("Fecha de ingreso %d/%d/%d\n", emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio);

}

eEmpleado conseguirEmpleado()
{
    eEmpleado emp;

    printf("\nIngrese el legajo\n");
    scanf("%d", &emp.legajo);

    printf("Ingrese el nombre\n");
    fflush(stdin);
    gets(emp.nombre);

    printf("Ingrese el sexo\n");
    fflush(stdin);
    scanf("%c", &emp.sexo);

    printf("Ingrese el sueldo\n");
    scanf("%f", &emp.sueldo);

    printf("Ingrese la fecha de ingreso d m a \n");
    scanf("%d %d %d", &emp.fechaIngreso.dia, &emp.fechaIngreso.mes, &emp.fechaIngreso.anio);

    return emp;
}

void mostrarEmpleados(eEmpleado emp[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        mostarEmpleado(emp[i]);
    }

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
                    if(strcmp(emp[i].nombre, emp[j].nombre) > 0)
                    {
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
                    if(emp[i].legajo > emp[j].legajo)
                    {
                        aux = emp[i];
                        emp[i] = emp[j];
                        emp[j] = aux;
                    }
                }
            }
            break;
        case 3:
            for(i=0;i<tam-1;i++)
            {
                for(j=i+1;j<tam;j++)
                {
                    if(emp[i].sueldo > emp[j].sueldo)
                    {
                        aux = emp[i];
                        emp[i] = emp[j];
                        emp[j] = aux;
                    }
                }
            }
            break;
        case 4:
            for(i=0;i<tam-1;i++)
            {
                for(j=i+1;j<tam;j++)
                {
                    if(emp[i].sexo > emp[j].sexo)
                    {
                        aux = emp[i];
                        emp[i] = emp[j];
                        emp[j] = aux;
                    }
                    else
                    {
                        if(emp[i].legajo > emp[j].legajo)
                        {
                            aux = emp[i];
                            emp[i] = emp[j];
                            emp[j] = aux;
                        }
                    }
                }
            }
            break;
    }
}
