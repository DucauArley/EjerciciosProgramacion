#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "string.h"
#include "Funciones.h"


eEmpleado* nuevoEmpleado()
{
    eEmpleado* returnAux;

    returnAux = (eEmpleado*) malloc(sizeof(eEmpleado));

    if(returnAux != NULL)
    {
        returnAux->id = -1;
        strcpy(returnAux->nombre, " ");
        strcpy(returnAux->direccion, " ");
        returnAux->hora = -1;
        returnAux->sueldo = -1;
    }
    else
    {
        printf("No se pudo conseguir espacio en memoria\n");
    }
    return returnAux;
}


int getId(eEmpleado* empleado)
{
    int retorno;

    if(empleado != NULL)
    {
        retorno = empleado->id;
    }

    return retorno;
}


int setId(eEmpleado* empleado, int id)
{
    int retorno = -1;

    if(empleado != NULL)
    {
        empleado->id = id;
        retorno = 0;
    }

    return retorno;
}

char* getNombre(eEmpleado* empleado)
{
    char* retorno;

    retorno = (char*) malloc(sizeof(char)* 20);

    if(empleado != NULL)
    {
        strcpy(retorno, empleado->nombre);
    }

    return retorno;
}


int setNombre(eEmpleado* empleado, char* nombre )
{
    int retorno = -1;

    if(empleado != NULL)
    {
        strcpy(empleado->nombre, nombre);
        retorno = 0;
    }

    return retorno;
}

char* getDireccion(eEmpleado* empleado)
{
    char* retorno;

    retorno = (char*) malloc(sizeof(char)* 20);


    if(empleado != NULL)
    {
        strcpy(retorno, empleado->direccion);
    }

    return retorno;
}


int setDireccion(eEmpleado* empleado, char* direccion)
{
    int retorno = -1;

    if(empleado != NULL)
    {
        strcpy(empleado->direccion, direccion);
        retorno = 0;
    }

    return retorno;
}

int getHoras(eEmpleado* empleado)
{
    int retorno;

    if(empleado != NULL)
    {
        retorno = empleado->hora;
    }

    return retorno;
}


int setHoras(eEmpleado* empleado, int hora)
{
    int retorno = -1;

    if(empleado != NULL)
    {
        empleado->hora = hora;
        retorno = 0;
    }

    return retorno;
}

int getSueldo(eEmpleado* empleado)
{
    int retorno;

    if(empleado != NULL)
    {
        retorno = empleado->sueldo;
    }

    return retorno;
}


int setSueldo(eEmpleado* empleado, int sueldo)
{
    int retorno = -1;

    if(empleado != NULL)
    {
        empleado->sueldo = sueldo;
        retorno = 0;
    }

    return retorno;
}



void printEmpleado(eEmpleado* empleado)
{
    if(empleado != NULL)
    {
        printf("%d      %s      %s        %d        %d\n", getId(empleado), getNombre(empleado), getDireccion(empleado), getHoras(empleado), getSueldo(empleado));
    }
    else
    {
        printf("No se pudo leer el empleado\n");
    }
}

int parserEmpleado(ArrayList* lista)
{
    char buffer[20];
    char buffer2[20];
    char id[20];
    char buffer3[20];
    eEmpleado* aux;
    FILE* pFile;
    int cant;

    pFile = fopen("Empleados.csv", "r");

    if(pFile == NULL || lista == NULL)
    {
        printf("No se ha podido abrir el archivo\n");
        exit(1);
    }

    while(!feof(pFile))
    {
        cant = fscanf(pFile, "%[^;];%[^;];%[^;];%[^\n]\n", id, buffer, buffer2, buffer3);
        aux = nuevoEmpleado();

         if(cant != 4)
        {

            if(feof(pFile))
            {
                break;
            }
            else
            {
                printf("Problema para leer el archivo\n");

                break;
            }
        }

        setId(aux, atoi(id));
        setNombre(aux, buffer);
        setDireccion(aux, buffer2);
        setHoras(aux, atoi(buffer3));

        al_add(lista, aux);
    }

    fclose(pFile);

    return 0;
}

int ordenar(void* empleado1, void* empleado2)
{
    int retorno = 0;

    if(strcmp(((eEmpleado*)empleado1)->nombre, ((eEmpleado*)empleado2)->nombre) < 0)
    {
        retorno = 1;
    }
    if(strcmp(((eEmpleado*)empleado1)->nombre, ((eEmpleado*)empleado2)->nombre) > 0)
    {
        retorno =  -1;
    }

    return retorno;
}

int calcularSueldo(void* empleado)
{
    int sueldo = -1;
    int sueldo2 = -1;
    int sueldo3 = -1;
    int retorno = -1;
    int hora = getHoras(empleado);

    if(((eEmpleado*)empleado)->hora<120 && ((eEmpleado*)empleado)->hora>=80)
    {
        sueldo = hora * 180;
        retorno = 0;
    }
    else
    {
        if(((eEmpleado*)empleado)->hora>120 && ((eEmpleado*)empleado)->hora<160)
        {
            hora = hora - 120;
            sueldo2 = 120 * 180;
            sueldo = sueldo2 + (hora * 240);
            retorno = 0;
        }
        else
        {
            if(((eEmpleado*)empleado)->hora>160 && ((eEmpleado*)empleado)->hora<=240)
            {
                hora = hora - 160;
                sueldo2 = 120 * 180;
                sueldo3 = sueldo2 + (40 * 240);
                sueldo = sueldo3 + (hora * 350);
                retorno = 0;
            }
        }
    }

    if(retorno == 0)
    {
        setSueldo(empleado, sueldo);
    }

    return retorno;
}

int guardarEnArchivo(ArrayList* lista, char* path)
{
    FILE* f;
    int retorno = -1;
    eEmpleado* aux;
    int i;
    int tam = al_len(lista);

    if(lista != NULL)
    {
        f = fopen(path, "w");

        if(f != NULL)
        {
            for(i=0;i<tam;i++)
            {
                aux = al_get(lista, i);
                fprintf(f,"%d;", getId(aux));
                fprintf(f,"%s;", getNombre(aux));
                fprintf(f,"%s;", getDireccion(aux));
                fprintf(f,"%d;", getHoras(aux));
                fprintf(f,"%d\n", getSueldo(aux));

            }

            retorno = 0;
        }
        fclose(f);
    }
    return retorno;
}




