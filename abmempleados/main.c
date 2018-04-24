#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;


typedef struct
{
    int legajo;
    char nombre[50];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
    int isEmpty;
}eEmpleado;

void inicializarEmpleados(eEmpleado[], int);

int buscarLibre(eEmpleado[], int);

int buscarEmpleado(eEmpleado[], int, int);

void altaEmpleado(eEmpleado[], int);

void mostarEmpleado(eEmpleado);

void mostrarEmpleados(eEmpleado[], int);

int menu();

int main()
{
    int TAM = 50;
    int salir = 0;
    eEmpleado gente[TAM];

    inicializarEmpleados(gente, TAM);

    do
    {
        switch(menu())
        {
            case 1:
                system("cls");
                altaEmpleado(gente, TAM);
                break;
            case 2:
                system("cls");

                break;
            case 3:
                system("cls");

                break;
            case 4:
                system("cls");
                mostrarEmpleados(gente, TAM);
                break;
            case 5:
                system("cls");

                break;
            case 6:
                system("cls");
                salir = 1;
                break;
            default:
                printf("Opcion incorecta\n");
                system("pause");
        }
    }
        while(salir != 1);


    return 0;
}

int menu()
{
    int opcion;

    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificacion\n");
    printf("4- Listar\n");
    printf("5- Ordenar\n");
    printf("6- Salir\n");

    scanf("%d", &opcion);

    return opcion;
}

void inicializarEmpleados(eEmpleado emp[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        emp[i].isEmpty = 1;
    }

}

int buscarLibre(eEmpleado emp[], int tam)
{
    int indice = -1;
    int i;

    for(i=0;i<tam;i++)
    {
        if(emp[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarEmpleado(eEmpleado emp[], int tam, int legajo)
{
    int i;
    int indice = -1;

    for(i=0;i<tam;i++)
    {
        if((legajo == emp[i].legajo) && emp[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void altaEmpleado(eEmpleado emp[], int tam)
{
    eEmpleado aux;
    int indice;
    int legajo;
    int esta;

    indice = buscarLibre(emp, tam);

    if(indice != -1)
    {
        printf("Ingrese el legajo\n");
        scanf("%d", &legajo);

        esta = buscarEmpleado(emp, tam, legajo);

        if(esta != -1)
        {
            printf("El empleado ya existe\n");
            mostarEmpleado(emp[esta]);
        }
        else
        {
            aux.legajo = legajo;

            aux.isEmpty = 0;

            printf("Ingrese el nombre\n");
            fflush(stdin);
            gets(aux.nombre);

            printf("Ingrese el sexo\n");
            fflush(stdin);
            scanf("%c", &aux.sexo);

            printf("Ingrese el sueldo\n");
            scanf("%f", &aux.sueldo);

            printf("Ingrese la fecha de ingreso d m a \n");
            scanf("%d %d %d", &aux.fechaIngreso.dia, &aux.fechaIngreso.mes, &aux.fechaIngreso.anio);


            emp[indice] = aux;

            printf("----------ALTA EXITOSA---------\n");

        }
    }
    else
    {
        printf("No se puede ingresar mas empleados\n");
    }
}

void mostarEmpleado(eEmpleado emp)
{
    printf("\nLegajo: %d\n", emp.legajo);
    printf("Nombre: %s\n", emp.nombre);
    printf("Sexo: %c\n", emp.sexo);
    printf("Sueldo: %.2f\n", emp.sueldo);
    printf("Fecha de ingreso %d/%d/%d\n", emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio);

}

void mostrarEmpleados(eEmpleado emp[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        if(emp[i].isEmpty == 0)
        {
            mostarEmpleado(emp[i]);
        }
    }

}
