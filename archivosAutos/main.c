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
void guardarAutos(eAuto*, int);
int buscarLibre(eAuto*, int);
eAuto* cargarAutos(eAuto*, int*);
void inicializarAutos(eAuto*, int);
eAuto* newArrayAutos(int);
eAuto* agrandarArray(eAuto* autos, int* tam);

int main()
{
    eAuto* flota;
    int tam = 20;


    flota = newArrayAutos(tam);

    if(flota == NULL)
    {
        printf("No se pudo conseguir memoria\n");
        exit(1);
    }


    flota = cargarAutos(flota, &tam);

    printf("tamanio del array %d\n", tam);

    mostrarAutos(flota, tam);

    guardarAutos(flota, tam);


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

void inicializarAutos(eAuto* autos, int tam)
{
    int i;

    if(autos != NULL && tam > 0)
    {
        for(i=0;i<tam;i++)
        {
            (autos + i)->estado = 0;
        }
    }

}

eAuto* newArrayAutos(int tam)
{
    eAuto* autos;

    if(tam > 0)
    {
        autos = (eAuto*) malloc(sizeof(eAuto) * tam);

        if(autos != NULL)
        {
            inicializarAutos(autos, tam);
        }
    }

    return autos;
}

int buscarLibre(eAuto* autos, int tam)
{
    int i;
    int indice = -1;

    for(i=0;i<tam;i++)
    {
        if((autos + i)->estado == 0)
            {
                indice = i;
                break;
            }
    }

    return indice;
}

eAuto* agrandarArray(eAuto* autos, int* tam)
{
    int tamAux = (*tam) + 20;
    eAuto* aux;
    int i;

    aux = (eAuto*) realloc(autos, sizeof(eAuto) * tamAux);

    if(aux != NULL)
    {
        autos = aux;
        for(i=*tam;i<tamAux;i++)
        {
            (autos + i)->estado = 0;
        }
        *tam = tamAux;
        free(aux);
    }
    return autos;
}

eAuto* cargarAutos(eAuto* autos, int* tam)
{
    FILE* archivo;
    int indice;
    int total = 0;
    int cantidad;
    char id[50];
    char modelo[50];
    char marca[50];
    char color[50];
    char anio[50];
    eAuto aux;

    archivo = fopen("autos.csv", "r");

    if(archivo == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }

    while(!feof(archivo))
    {
        indice = buscarLibre(autos, *tam);

        if(indice == -1)
        {
            agrandarArray(autos, tam);
            fflush(stdin);
            indice = buscarLibre(autos, *tam);
        }


        cantidad = fscanf(archivo, "%[^,] , %[^,], %[^,] , %[^,], %[^\n] \n", id, marca, color, anio, modelo);

         if(cantidad != 5)
        {
            if(feof(archivo))
            {
                break;
            }
            else
            {
                printf("No se pudo leer el ultimo registro\n");
                break;
            }
        }

        aux.id = atoi(id);
        strcpy(aux.marca,marca);
        strcpy(aux.modelo,modelo);
        strcpy(aux.color,color);
        aux.anio = atoi(anio);
        aux.estado = 1;

        *(autos + indice) = aux;

        total ++;
    }

    fclose(archivo);
    printf("Se guardaron %d autos\n", total);

    return autos;
}

void guardarAutos(eAuto* autos, int tam)
{
    FILE* archivo;
    int i;

    archivo = fopen("autos.txt", "w");

    if(archivo != NULL)
    {
        for(i=0; i<tam; i++)
        {
            if( (autos + i)->estado)
            {
                fprintf(archivo,"%d,%s,%s,%s,%d\n",(autos+i)->id, (autos+i)->marca, (autos+i)->modelo, (autos+i)->color, (autos+i)->anio);
            }
        }
        fclose(archivo);
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }

}



