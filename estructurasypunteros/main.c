#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idTipo;
    char descripcion[20];
}eTipo;

typedef struct
{
    int id;
    char nombre[20];
    int edad;
    eTipo tipo;
    int estado;
}eMascota;

void modificarEdadYTipo(eMascota*, int);

void mostrarMascota(eMascota*);

void mostrarMascotas(eMascota*, int);

int cargarMascota(eMascota*);

int main()
{
    eMascota unaMascota;
    eMascota grupo[5] ={{2311, "Mauricio", 14, {3, "Gato"}, 1}, {2514, "Jorge", 7, {2, "Perro"}, 1}, {1145, "Roberto", 14, {1, "Reptil"}, 1}};
    int respuesta;


    (grupo + 3)->estado = 0;
    (*(grupo + 4)).estado = 0;

    unaMascota.edad = 5;
    unaMascota.id = 1234;
    strcpy(unaMascota.nombre, "Juan Carlos");
    unaMascota.estado = 1;

    modificarEdadYTipo(&unaMascota, 20);

    respuesta = cargarMascota(grupo);

    if(respuesta == 1)
    {
        printf("\n-----Se ha cargardo exitosamente-----\n");
    }
    else
    {
        printf("\n-------La mascota no se ha podido cargar-------\n");
    }

    mostrarMascotas(grupo, 5);



    printf("%d \n%s \n%d \n%s",unaMascota.id, unaMascota.nombre, unaMascota.edad, unaMascota.tipo.descripcion);

    return 0;
}

void modificarEdadYTipo(eMascota* x, int edad)
{

    x->edad = edad;

    strcpy(x->tipo.descripcion, "Ave");

}


void mostrarMascota(eMascota* mascota)
{
    printf("%d\n", mascota->id);
    printf("%s\n", mascota->nombre);
    printf("%d\n", mascota->edad);
    printf("%s\n", mascota->tipo.descripcion);
    printf("-------------------\n\n");
}


void mostrarMascotas(eMascota * vec, int tam)
{
    int i;
    if(vec != NULL)
    {
        for(i=0;i<tam;i++)
        {
            if((vec + i)->estado == 1)
            {
                mostrarMascota(vec + i);
            }
        }
    }
}

int cargarMascota(eMascota* mas)
{
    int ok = 0;

    if(mas != NULL)
    {
        printf("Ingrese el id de la mascota\n");
        scanf("%d", &mas->id);

        printf("Ingrese el nombre de la mascota\n");
        fflush(stdin);
        gets(mas->nombre);

        printf("Ingrese la edad de la mascota\n");
        scanf("%d", &mas->edad);

        printf("Ingrese el tipo de mascota\n");
        fflush(stdin);
        gets(mas->tipo.descripcion);

        mas->estado = 1;

        ok = 1;
    }

    return ok;
}


