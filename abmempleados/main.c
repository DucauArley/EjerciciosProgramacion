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

void bajaEmpleado(eEmpleado [], int);

void modificacionEmpleado(eEmpleado [], int);

void ordenarEmpleados(eEmpleado [], int);

int totalSueldos(eEmpleado [], int);

void mayorSueldo(eEmpleado [], int);

void mostarEmpleado(eEmpleado);

void mostrarEmpleados(eEmpleado[], int);

int menu();

int main()
{
    int TAM = 50;
    int salir = 0;
    int sueldosNetos;
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
                bajaEmpleado(gente, TAM);
                break;
            case 3:
                system("cls");
                modificacionEmpleado(gente, TAM);
                break;
            case 4:
                system("cls");
                mostrarEmpleados(gente, TAM);
                break;
            case 5:
                system("cls");
                ordenarEmpleados(gente, TAM);
                break;
            case 6:
                system("cls");
                salir = 1;
                break;
            case 7:
                system("cls");
                sueldosNetos = totalSueldos(gente, TAM);
                printf("La suma de los sueldos es: %d\n", sueldosNetos);
                break;
            case 8:
                system("cls");
                mayorSueldo(gente, TAM);
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
    printf("7- total sueldos\n");
    printf("8- Empleados que mas ganan\n");

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

void bajaEmpleado(eEmpleado emp[], int tam)
{
    int legajo;
    int esta;
    char respuesta;

    printf("ingrese el legajo\n");
    scanf("%d", &legajo);

    esta = buscarEmpleado(emp, tam, legajo);

    if(esta != -1)
    {
        mostarEmpleado(emp[esta]);

        printf("Desea eliminar a el empleado? s/n \n");
        fflush(stdin);
        scanf("%c", &respuesta);

        if(respuesta == 's')
        {
            emp[esta].isEmpty = 1;
            printf("----------BAJA EXITOSA---------\n");
        }
        else
        {
            printf("Se cancelo la operacion\n");
        }


    }
    else
    {
        printf("El empleado no existe\n");
    }
}

void modificacionEmpleado(eEmpleado emp[], int tam)
{
    int esta;
    int opcion;
    char respuesta;
    int flag = 0;
    eEmpleado aux;

    printf("Ingrese el legajo\n");
    scanf("%d", &aux.legajo);

    esta = buscarEmpleado(emp, tam, aux.legajo);

    if(esta != -1)
    {
        mostarEmpleado(emp[esta]);

        printf("Que desea modificar?\n");
        printf("1- Nombre\n");
        printf("2- Sexo\n");
        printf("3- Sueldo\n");
        printf("4- Fecha de ingreso\n");
        scanf("%d", &opcion);

        while(flag == 0)
        {
            switch(opcion)
            {
                case 1:
                    printf("Ingrese el nombre\n");
                    fflush(stdin);
                    gets(aux.nombre);
                    aux.sexo = emp[esta].sexo;
                    aux.sueldo = emp[esta].sueldo;
                    aux.fechaIngreso = emp[esta].fechaIngreso;
                    aux.isEmpty = emp[esta].isEmpty;
                    flag = 1;
                    break;
                case 2:
                    printf("Ingrese el sexo\n");
                    fflush(stdin);
                    scanf("%c", &aux.sexo);
                    strcpy(aux.nombre, emp[esta].nombre);
                    aux.sueldo = emp[esta].sueldo;
                    aux.fechaIngreso = emp[esta].fechaIngreso;
                    aux.isEmpty = emp[esta].isEmpty;
                    flag = 1;
                    break;
                case 3:
                    printf("Ingrese el sueldo\n");
                    scanf("%f", &aux.sueldo);
                    aux.sexo = emp[esta].sexo;
                    strcpy(aux.nombre, emp[esta].nombre);
                    aux.fechaIngreso = emp[esta].fechaIngreso;
                    aux.isEmpty = emp[esta].isEmpty;
                    flag = 1;
                    break;
                case 4:
                    printf("Ingrese la fecha de ingreso d m a \n");
                    scanf("%d %d %d", &aux.fechaIngreso.dia, &aux.fechaIngreso.mes, &aux.fechaIngreso.anio);
                    aux.sexo = emp[esta].sexo;
                    aux.sueldo = emp[esta].sueldo;
                    strcpy(aux.nombre, emp[esta].nombre);
                    aux.isEmpty = emp[esta].isEmpty;
                    flag = 1;
                    break;
                default:
                    printf("El numero ingresado no es valido\n");
                    scanf("%d", &opcion);
            }
        }

        printf("Desea realizar los cambios?\n");
        fflush(stdin);
        scanf("%c", &respuesta);

        if(respuesta == 's')
        {
            emp[esta] = aux;
            printf("---------MODIFICACION EXITOSA------\n");
        }
        else
        {
            printf("Se ha cancelado la modificacion\n");
        }
    }
    else
    {
        printf("El empleado no existe\n");
    }
}

void ordenarEmpleados(eEmpleado emp[], int tam)
{
    int i;
    int j;
    eEmpleado aux;

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
                if(emp[i].sexo == emp[j].sexo)
                {
                    if(emp[i].sueldo > emp[j].sueldo)
                    {
                        aux = emp[i];
                        emp[i] = emp[j];
                        emp[j] = aux;
                    }
                }
            }
        }
    }

    printf("---------ORDENAMIENTO EXITOSO--------\n");
}

int totalSueldos(eEmpleado emp[], int tam)
{
    int acumuladorSueldos = 0;
    int i;

    for(i=0;i<tam;i++)
    {
        if(emp[i].isEmpty == 0)
        {
            acumuladorSueldos = emp[i].sueldo + acumuladorSueldos;
        }
    }

    return acumuladorSueldos;
}

void mayorSueldo(eEmpleado emp[], int tam)
{
    int i;
    int j;
    int contadorSueldo = 1;
    eEmpleado aux;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(emp[i].isEmpty == 0 && emp[j].isEmpty == 0)
            {
                if(emp[i].sueldo < emp[j].sueldo)
                {
                    aux = emp[i];
                    emp[i] = emp[j];
                    emp[j] = aux;
                }
            }
        }
    }

    for(i=1;i<tam;i++)
    {
        if(emp[0].sueldo == emp[i].sueldo)
        {
            contadorSueldo ++;
        }
    }

    mostrarEmpleados(emp,contadorSueldo);

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
    int flag = 0;

    for(i=0;i<tam;i++)
    {
        if(emp[i].isEmpty == 0)
        {
            mostarEmpleado(emp[i]);
            flag = 1;
        }

    }

    if(flag == 0)
    {
        printf("No hay empleados\n");
    }

}
