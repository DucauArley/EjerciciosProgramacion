#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char marca[50];
    char modelo[50];
    char color[50];
    int anio;
    int estado;
} eAuto;

void mostrarAutos(eAuto*, int);
void mostrarAuto(eAuto*);
eAuto* new_Auto();
eAuto* new_Auto_Param(int, char*, char*, char*, int);
int buscarLibre(eAuto*, int);
int cargarAutos(eAuto*, int, char*);
void inicializarAutos(eAuto*, int);
eAuto* agrandarArrayAutos(eAuto*, int);
void parseAutos(eAuto*);

int main()
{
    eAuto* autos;
    int tam = 20;

    autos = (eAuto*) malloc(sizeof(eAuto) * 20);

    inicializarAutos(autos, &tam);

    mostrarAutos(autos, tam);

    return 0;
}

void mostrarAuto(eAuto* autos)
{
    if(autos!= NULL)
    {
        printf("%d %s %s %d %s\n", autos->id, autos->marca, autos->color, autos->anio, autos->modelo);
    }
}

void mostrarAutos(eAuto* autos, int tam)
{
    int i;

    if(autos != NULL && tam > 0)
    {
        for(i=0; i< tam; i++)
        {

            if((autos + i)->estado == 1)
            {
                mostrarAuto(autos+i);
            }
        }
    }
    else
    {
        printf("\nNo se pueden mostrar los autos\n");
    }

}

eAuto* new_Auto()
{

    eAuto* nuevoAuto;

    nuevoAuto = (eAuto*)malloc(sizeof(eAuto));
    if(nuevoAuto != NULL)
    {
        nuevoAuto->anio = 0;
        strcpy(nuevoAuto->modelo, "");
        strcpy(nuevoAuto->color, "");
        strcpy(nuevoAuto->marca, "");
        nuevoAuto->id = 0;
        nuevoAuto->estado = 0;
    }
    return nuevoAuto;

}



eAuto* new_Auto_Param(int id, char* modelo, char* marca, char* color, int anio)
{

    eAuto* nuevoAuto;

    nuevoAuto = new_Auto();

    if(nuevoAuto != NULL)
    {
        nuevoAuto->id = id;
        strcpy(nuevoAuto->modelo, modelo);
        strcpy(nuevoAuto->color, color);
        strcpy(nuevoAuto->marca, marca);
        nuevoAuto->anio = anio;
        nuevoAuto->estado = 1;
    }
    return nuevoAuto;

}

int cargarAutos(eAuto* autos, int tam, char* path)
{
    int indice;
    eAuto Auxiliar;
    int cant;
    int total = 0;


    indice = buscarLibre(autos, tam);

    while(indice == -1)
    {
        autos = agrandarArrayAutos(autos, tam);
        indice = buscarLibre(autos, tam);
    }

    parseAutos(Auxiliar);

    *(autos+indice) = Auxiliar;
    total++;

    fclose(f);
    return total;
}

int buscarLibre(eAuto* autos, int tam)
{
    int i;
    int indice = -1;

    for(i=0; i<tam; i++)
    {
        if((autos+i)->estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void inicializarAutos(eAuto* autos, int tam)
{
    int i;

    if(autos != NULL && tam > 0)
    {
        for( i=0; i<tam; i++)
        {
            (autos+i)->estado = 0;
        }
    }
}

eAuto* agrandarArrayAutos(eAuto* array, int* tam)
{
    int tamAux;
    int indice;
    int i;

    indice = buscarLibre(array, *tam);

    while(indice == -1)
    {
        indice = buscarLibre(array, *tam);
        tamAux = *(tam + 20);
        array = (eAuto*) realloc(array, tamAux * sizeof(eAuto));
        for(i=tam;i<tamAux;i++)
        {
            inicializarAutos(array, tamAux);
        }
    }
    return array;
}

void parseAutos(eAuto* auto1)
{

    int cant;
    int id;
    char marca[50];
    char modelo[50];
    char color[50];
    char idCad[20];
    char anioCad[20];
    int anio;

    FILE* f;

    f = fopen("autos.csv", "r");

    if(f == NULL)
    {
        printf("Error al abrir el fichero\n");
        exit(1);
    }
    else
    {
        //cant = fscanf(f, "%d , %s , %s , %d, %s \n", &id, marca, color, &anio, modelo);
        // cant = fscanf(f, "%d , %[0-z], %[0-z] , %d, %[0-z]\n", &id, marca, color, &anio, modelo);
        cant = fscanf(f, "%[^,] , %[^,], %[^,] , %[^,], %[^\n] \n", idCad, marca, color, anioCad, modelo);

        if( cant != 5)
        {

            if(feof(f))
            {
                break;
            }
            else
            {
                printf("Problema para leer el archivo\n");

                break;
            }
        }

        auto1->estado = 1;

        id = atoi(idCad);
        anio = atoi(anioCad);

        auto1->id = id;
        auto1->anio = anio;
        strcpy(auto1->marca, marca);
        strcpy(auto1->modelo, modelo);
        strcpy(auto1->color, color);
    }



    fclose(f);
}

