#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    int opcion;
    int flag = 0;
    int flag2 = 0;
    int tamPro = 50;
    eProveedor proveedores[] = {{1, "Juan"}, {2, "Carlos"}, {3, "Manuel"}, {4,"Jose"}};
    eProducto productos[tamPro];

    inicializarProducto(productos, tamPro);

    while(flag == 0)
    {
        printf("1- Alta producto\n");
        printf("2- Modificar el producto\n");
        printf("3- Baja del producto\n");
        printf("4- Informar\n");
        printf("5- Listar\n");
        printf("6- Salir\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                altaProducto(productos, tamPro, 4);
                flag2 = 1;
                break;
            case 2:
                if(flag2 == 1)
                {
                    system("cls");
                    modificacionProducto(productos, tamPro);
                }
                else
                {
                    printf("Debe ingresar al menos un producto para utilizar esta opcion");
                }
                break;
            case 3:
                if(flag2 == 1)
                {
                    system("cls");
                    bajaProducto(productos, tamPro);
                }
                else
                {
                    printf("Debe ingresar al menos un producto para utilizar esta opcion");
                }
                break;
            case 4:
                if(flag2 == 1)
                {
                    system("cls");
                    informar(productos, tamPro);
                }
                else
                {
                    printf("Debe ingresar al menos un producto para utilizar esta opcion");
                }
                break;
            case 5:
                if(flag2 == 1)
                {
                    system("cls");
                    listar(proveedores, 4, productos, tamPro);
                }
                else
                {
                    printf("Debe ingresar al menos un producto para utilizar esta opcion");
                }
                break;
            case 7:
                flag = 1;
                break;
            default :
                printf("El numero ingresado no es valido");
        }
    }

    return 0;
}



