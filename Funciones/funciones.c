#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int menu()
{
    int opcion;

    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificacion\n");
    printf("4- Listar\n");
    printf("5- Ordenar\n");
    printf("6- total sueldos\n");
    printf("7- Empleados que mas ganan\n");
    printf("8- Empleados por sector\n");
    printf("9- Cantidad de empleados por sector\n");
    printf("10- Total sueldos por sector\n");
    printf("11- Empleados que mas ganan por sector\n");
    printf("12- Salir\n");


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

void altaEmpleado(eEmpleado emp[], int tam, eSector sector[], int tamsec)
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
            mostarEmpleado(emp[esta], sector, tamsec);
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

            aux.idSector = mostrarSector(sector, tamsec);

            emp[indice] = aux;

            printf("----------ALTA EXITOSA---------\n");

        }
    }
    else
    {
        printf("No se puede ingresar mas empleados\n");
    }
}

void bajaEmpleado(eEmpleado emp[], int tam, eSector sector[], int tamsec)
{
    int legajo;
    int esta;
    char respuesta;

    printf("ingrese el legajo\n");
    scanf("%d", &legajo);

    esta = buscarEmpleado(emp, tam, legajo);

    if(esta != -1)
    {
        mostarEmpleado(emp[esta], sector, tamsec);

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

void modificacionEmpleado(eEmpleado emp[], int tam, eSector sector[], int tamsec)
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
        mostarEmpleado(emp[esta], sector, tamsec);

        printf("Que desea modificar?\n");
        printf("1- Nombre\n");
        printf("2- Sexo\n");
        printf("3- Sueldo\n");
        printf("4- Fecha de ingreso\n");
        printf("5- Sector\n");
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
                    aux.idSector = emp[esta].idSector;
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
                    aux.idSector = emp[esta].idSector;
                    flag = 1;
                    break;
                case 3:
                    printf("Ingrese el sueldo\n");
                    scanf("%f", &aux.sueldo);
                    aux.sexo = emp[esta].sexo;
                    strcpy(aux.nombre, emp[esta].nombre);
                    aux.fechaIngreso = emp[esta].fechaIngreso;
                    aux.isEmpty = emp[esta].isEmpty;
                    aux.idSector = emp[esta].idSector;
                    flag = 1;
                    break;
                case 4:
                    printf("Ingrese la fecha de ingreso d m a \n");
                    scanf("%d %d %d", &aux.fechaIngreso.dia, &aux.fechaIngreso.mes, &aux.fechaIngreso.anio);
                    aux.sexo = emp[esta].sexo;
                    aux.sueldo = emp[esta].sueldo;
                    strcpy(aux.nombre, emp[esta].nombre);
                    aux.isEmpty = emp[esta].isEmpty;
                    aux.idSector = emp[esta].idSector;
                    flag = 1;
                    break;
                case 5:
                    fflush(stdin);
                    aux.idSector = mostrarSector(sector, tamsec);
                    fflush(stdin);
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

void mayorSueldo(eEmpleado emp[], int tam, eSector sector[], int tamsec)
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

    mostrarEmpleados(emp,contadorSueldo, sector, tamsec);

}

void empleadosPorSector(eEmpleado emp[], int tam, eSector sector[], int tamsec)
{
    int idSector;
    int i;
    int flag = 0;

    printf("Ingrese el sector en el que desea buscar empleados\n");
    scanf("%d", &idSector);

    for(i=0;i<tam;i++)
    {
        if(emp[i].idSector == idSector)
        {
            mostrarEmpleados(emp, tam, sector, tamsec);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay empleados en ese sector\n");
    }
}

void cantidadDeEmpleadosPorSector(eEmpleado emp[], int tam, eSector sector[], int tamsec)
{
    int i;
    int contadorEmpleados;
    int j;

    for(i=0;i<tamsec;i++)
    {
        printf("La cantidad de empleados de %s es: ", sector[i].nombre);
        contadorEmpleados = 0;

        for(j=0;j<tam;j++)
        {
            if(emp[j].idSector == sector[i].id)
            {
                contadorEmpleados ++;
            }
        }

        printf("%d\n", contadorEmpleados);
    }
}

void totalSueldosPorSector(eEmpleado emp[], int tam, eSector sector[])
{
    int idSector;
    int i;
    int flag = 0;
    int acumuladorSueldo = 0;

    printf("Ingrese el sector en el que desea calcular el total de sueldos\n");
    scanf("%d", &idSector);

    for(i=0;i<tam;i++)
    {
        if(emp[i].idSector == idSector)
        {
            acumuladorSueldo = acumuladorSueldo + emp[i].sueldo;
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay empleados en ese sector\n");
    }
    else
    {
        printf("EL total de sueldos es: %d\n", acumuladorSueldo);
    }

}

void empleadosQueMasGananPorSector(eEmpleado emp[], int tam, eSector sector[], int tamsec)
{
    int i;
    int j;
    int h;
    eEmpleado aux;
    int contadorSueldo[] = {1, 1, 1, 1, 1};

    for(j=0;j<tam-1;j++)
    {
        for(h=j+1;h<tam;h++)
        {
            if(emp[j].isEmpty == 0 && emp[h].isEmpty == 0)
            {
                if(emp[j].sueldo < emp[h].sueldo)
                {
                    aux = emp[j];
                    emp[j] = emp[h];
                    emp[h] = aux;
                }
            }
        }
    }

    for(i=0;i<tamsec;i++)
    {
        printf("\nEl o los empleados que mas ganan en el sector %s es o son:\n", sector[i].nombre);
        for(j=1;j<tam;j++)
        {
            if(emp[0].sueldo == emp[j].sueldo && emp[j].idSector == sector[i].id)
            {
                contadorSueldo[i] ++;
            }
        }

        for(h=0;h<tam;h++)
        {
            if(emp[h].idSector == sector[i].id && emp[h].isEmpty == 0)
            {
                mostarEmpleado(emp[h], sector, tamsec);
            }
        }
    }
}


int mostrarSector(eSector sector[], int tamsec)
{
    int idSector;
    int i;

    printf("Ingrese un sector \n");

    for(i=0;i<tamsec;i++)
    {
        printf("%d- %s\n", i + 1, sector[i].nombre);
    }

    scanf("%d", &idSector);

    while(idSector < 1 || idSector > tamsec)
    {
        printf("Reingrese el sector\n");
        scanf("%d", &idSector);
    }

    return idSector;
}

void mostarEmpleado(eEmpleado emp, eSector sector[], int tamsec)
{
    int i;
    char nombre[20];

    printf("\nLegajo: %d\n", emp.legajo);
    printf("Nombre: %s\n", emp.nombre);
    printf("Sexo: %c\n", emp.sexo);
    printf("Sueldo: %.2f\n", emp.sueldo);
    printf("Fecha de ingreso %d/%d/%d\n", emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio);

    for(i=0;i<tamsec;i++)
    {
        if(sector[i].id == emp.idSector)
        {
            strcpy(nombre, sector[i].nombre);
            break;
        }
    }

    printf("Sector %s\n", nombre);
}

void mostrarEmpleados(eEmpleado emp[], int tam, eSector sector[], int tamsec)
{
    int i;
    int flag = 0;

    for(i=0;i<tam;i++)
    {
        if(emp[i].isEmpty == 0)
        {
            mostarEmpleado(emp[i], sector, tamsec);
            flag = 1;
        }

    }

    if(flag == 0)
    {
        printf("No hay empleados\n");
    }

}

void listar(EPersona lista[], int tam)
{
    EPersona aux;
    int i;
    int j;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(lista[i].estado == 1 && lista[j].estado == 1)
            {
                if(strcmp(lista[i].nombre, lista[j].nombre) == 1)
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
            }
        }
    }

    mostrarPersonas(lista, tam);
}

void grafico(EPersona lista[], int tam)
{
    int edades[] = {0, 0, 0};
    int i;
    int j;
    int mayor = 0;

    for(i=0;i<tam;i++)
    {
        if(lista[i].estado == 1)
        {
            if(lista[i].edad <= 18)
            {
                edades[0] ++;
            }
            else
            {
                if(lista[i].edad > 18 && lista[i].edad <= 35)
                {
                    edades[1] ++;
                }
                else
                {
                    if(lista[i].edad > 35)
                    {
                        edades[2] ++;
                    }
                }
            }
        }
    }

    for(i=0;i<3;i++)
    {
        if(mayor < edades[i])
        {
            mayor = edades[i];
        }

    }

    for(i=mayor;i>0;i--)
    {
        for(j=0;j<3;j++)
        {
            if(i <= edades[j])
            {
                printf(" *   ");
            }
            else
            {
                printf("     ");
            }
        }
        printf("\n");

    }


    printf("<18 19-35 >35\n");
}


int numerico(char texto[])
{
    int i = 0;

    while(texto[i] != '\0')
    {
        if(texto[i] < 0 || texto[i] > 9)
        {
            return 0;
        }

        i ++;
    }

    return 1;
}

int alfabetico(char texto[])
{
    int i = 0;

    while(texto[i] != '\0')
    {
        if((texto[i] != ' ') && (texto[i] < 'a' || texto[i] > 'z') && (texto[i] < 'A' || texto[i] > 'Z'))
        {
            return 0;
        }

        i++;
    }

    return 1;
}

void mostrarMateriasPorAlumno(eAlumno alumno[], int tamAlu, eMateria materia[], int tamMat, eInscripcion inscripcion[], int tamIns)
{
    int i;
    int j;
    int k;

    for(i=0;i<tamAlu;i++)
    {
        printf("%s\n", alumno[i].nombre);

        for(j=0;j<tamIns;j++)
        {
            if(alumno[i].legajo == inscripcion[j].legAlumno)
            {
                //printf("%s\n", materia[inscripcion[j].codMateria - 1].descripcion);

                for(k=0;k<tamMat;k++)
                {
                    if(inscripcion[j].codMateria == materia[k].codigo)
                    {
                        printf("%s\n", materia[k].descripcion);
                    }
                }

            }
        }

        printf("-----------------------------------------\n");
    }
}

void mostrarAlumnosPorMateria(eAlumno alumno[], int tamAlu, eMateria materia[], int tamMat, eInscripcion inscripcion[], int tamIns)
{
    int i;
    int j;
    int k;

    for(i=0;i<tamMat;i++)
    {
        printf("%s\n", materia[i].descripcion);

        for(j=0;j<tamIns;j++)
        {
            if(materia[i].codigo == inscripcion[j].codMateria)
            {
                for(k=0;k<tamAlu;k++)
                {
                    if(inscripcion[j].legAlumno == alumno[k].legajo)
                    {
                        printf("%s\n", alumno[k].nombre);
                    }
                }

            }
        }

        printf("-----------------------------------------\n");
    }

}

void cantidadAlumnosPorMateria(eMateria materia[], int tamMat, eInscripcion inscripcion[], int tamIns)
{
    int i;
    int contador;

    for(i=0;i<tamMat;i++)
    {
        printf("%s\n", materia[i].descripcion);
        contador = 0;

        contador = contadorAlumnos(materia[i].codigo, inscripcion, tamIns);

        printf("%d\n", contador);
    }

}

int contadorAlumnos(int materia, eInscripcion inscripcion[], int tamIns)
{
    int j;
    int contador = 0;

    for(j=0;j<tamIns;j++)
    {
        if(inscripcion[j].codMateria == materia)
        {
            contador ++;
        }
    }

    return contador;
}


void materiasMasCursadas(eMateria materia[], int tamMat, eInscripcion inscripcion[], int tamIns)
{
    int i;
    int contador;
    int maximo;
    int flag = 0;

    for(i=0;i<tamMat;i++)
    {
        contador = 0;
        contador = contadorAlumnos(materia[i].codigo, inscripcion, tamIns);

        if(flag == 0)
        {
            maximo = contador;
            flag = 1;
        }
        else
        {
            if(contador > maximo)
            {
                maximo = contador;
            }
        }
    }

    printf("La o las materias que mas alumnos tienen, son: \n");

    for(i=0;i<tamMat;i++)
    {
        contador = 0;
        contador = contadorAlumnos(materia[i].codigo, inscripcion, tamIns);

        if(contador == maximo)
        {
            printf("%s\n", materia[i].descripcion);
        }
    }



}