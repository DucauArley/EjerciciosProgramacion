#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    int opcion;
    int salir = 0;
    ArrayList* lista;
    int ok;
    int desde;
    int hasta;

    lista = al_newArrayList();

    while(salir == 0)
    {
        printf("1- Parsear el archivo\n");
        printf("2- Listar empleados\n");
        printf("3- Ordenar por nombre\n");
        printf("4- Agregar un elemento\n");
        printf("5- Eliminar un elemento\n");
        printf("6- Listar empleados (Desde/ hasta)\n");
        printf("7- Salir\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                ok = parserEmployee(lista, "data.csv");

                if(ok == 0)
                {
                    printf("Parseado exitoso\n");
                }
                break;
            case 2:
                system("cls");
                employee_printAll(lista);
                break;
            case 3:
                system("cls");
                ok = al_sort(lista, employee_compare, 0);

                if(ok == 0)
                {
                    printf("Ordenado exitosamente\n");
                }
                else
                {
                    printf("No se pudo ordenar\n");
                }
                break;
            case 4:
                system("cls");
                employee_add(lista);
                break;
            case 5:
                system("cls");
                employee_delete(lista);
                break;
            case 6:
                system("cls");
                printf("Ingrese la posicion desde la que quiere imprimir\n");
                scanf("%d", &desde);
                printf("Ingrese la posicion hasta la que quiere imprimir\n");
                scanf("%d", &hasta);
                employee_printLots(lista,desde, hasta);
                break;
            case 7:
                system("cls");
                salir = 1;
                break;
            default:
                printf("El numero ingresado es incorrecto\n");
        }


    }



    return 0;
}
