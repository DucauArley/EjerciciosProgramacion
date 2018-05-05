#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre[20];
}eAlumno;

typedef struct
{
    int codigo;
    char descripcion[20];
}eMateria;

typedef struct
{
    int legAlumno;
    int codMateria;
}eInscripcion;

void mostrarMateriasPorAlumno(eAlumno [], int, eMateria [], int, eInscripcion [], int);

void mostrarAlumnosPorMateria(eAlumno [], int, eMateria [], int, eInscripcion [], int);

void cantidadAlumnosPorMateria(eMateria [], int, eInscripcion [], int);

int contadorAlumnos(int, eInscripcion [], int);

void materiasMasCursadas(eMateria [], int, eInscripcion [], int);

int main()
{
    eAlumno alumnos[] = {{1, "Juan"}, {2, "Carlos"}, {3, "Manuel"}, {4, "Ailin"}, {5, "Fiorela"}, {6, "Fabian"}, {7, "Micaela"}, {8, "Hernan"}, {9, "Matias"}, {10, "Luciana"}};
    eMateria materias[] = {{1, "Matematicas"}, {2, "Quimica"}, {3, "Programacion"}, {4, "Fisica"}, {5, "Literatura"}};
    eInscripcion inscripciones[] = {{1, 2}, {1, 3}, {2, 5}, {2, 3}, {3, 2}, {3, 4}, {3, 1}, {4, 2}, {5, 3}, {5, 4}, {6, 1}, {7, 3}, {7, 5}, {7, 1}, {8, 1}, {9, 5}, {9, 2}, {10, 2}, {10, 5}, {10,3}};

    mostrarAlumnosPorMateria(alumnos, 10, materias, 5, inscripciones, 20);
    cantidadAlumnosPorMateria(materias, 5, inscripciones, 20);

    materiasMasCursadas(materias, 5, inscripciones, 20);

    return 0;
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


