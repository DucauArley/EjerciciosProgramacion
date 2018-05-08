#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigoProveedor;
    char descripcion[50];
    int estado;
}eProveedor;

typedef struct
{
    int codigoProducto;
    char descripcion[50];
    int importe;
    int cantidad;
    int codigoProveedor;
    int estado;
}eProducto;

void inicializarProveedor(eProveedor prov[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        prov[i].estado = 0;
    }

}

void inicializarProducto(eProducto pro[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        pro[i].estado = 0;
    }

}

int buscarLibreProveedor(eProveedor prov[], int tam)
{
    int indice = -1;
    int i;

    for(i=0;i<tam;i++)
    {
        if(prov[i].estado == 0)

        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarLibreProducto(eProducto pro[], int tam)
{
    int indice = -1;
    int i;

    for(i=0;i<tam;i++)
    {
        if(pro[i].estado == 0)

        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarProveedor(eProveedor prov[], int tam, int codigoProv)
{
    int i;
    int indice = -1;

    for(i=0;i<tam;i++)
    {
        if((codigoProv == prov[i].codigoProveedor) && prov[i].estado == 1)
        {
            indice = i;
            break;

        }
    }

    return indice;
}

int buscarProducto(eProducto pro[], int tam, int codigoPro)
{
    int i;
    int indice = -1;

    for(i=0;i<tam;i++)
    {
        if((codigoPro == pro[i].codigoProducto) && pro[i].estado == 1)
        {
            indice = i;
            break;

        }
    }

    return indice;
}

void altaProducto(eProducto pro[], int tam, int tamProv)
{
    eProducto aux;
    int indice;
    int codigo;

    indice = buscarLibreProducto(pro, tam);

    if(indice != -1)
    {
        codigo = indice + 1;

        aux.codigoProducto = codigo;

        aux.estado = 1;

        printf("Ingrese la descripcion\n");
        fflush(stdin);
        gets(aux.descripcion);

        printf("Ingrese el codigo de proveedor\n");
        scanf("%d", &aux.codigoProveedor);

        while(aux.codigoProveedor > tamProv || aux.codigoProveedor < 0)
        {
            printf("Reingrese el codigo de proveedor\n");
            scanf("%d", &aux.codigoProveedor);
        }

        printf("Ingrese el importe de producto\n");
        scanf("%d", &aux.importe);

        printf("Ingrese la cantidad de producto\n");
        scanf("%d", &aux.cantidad);
        pro[indice] = aux;

        printf("----------ALTA EXITOSA---------\n");

    }
    else
    {
        printf("No se puede ingresar mas productos\n");
    }
}

void modificacionProducto(eProducto pro[], int tam)
{
    int esta;
    int flag = 0;
    int opcion;
    int codigo;
    char respuesta;
    eProducto aux;

    printf("Ingrese el codigo de producto\n");
    scanf("%d", &codigo);

    esta = buscarProducto(pro, tam, codigo);

    if(esta == -1)
    {
        printf("El producto no existe\n");
    }
    else
    {
        mostrarProducto(pro[esta]);

        printf("Que desea modificar?\n");
        printf("1- Descripcion\n");
        printf("2- Importe\n");
        printf("3- Cantidad\n");
        scanf("%d", &opcion);

        aux = pro[esta];

        while(flag == 0)
        {
            switch(opcion)
            {
                case 1:
                    printf("Ingrese la descripcion\n");
                    fflush(stdin);
                    gets(aux.descripcion);
                    flag = 1;
                    break;
                case 2:
                    printf("Ingrese el importe\n");
                    fflush(stdin);
                    scanf("%d", &aux.importe);
                    flag = 1;
                    break;
                case 3:
                    printf("Ingrese la cantidad\n");
                    scanf("%d", &aux.cantidad);
                    flag = 1;
                    break;
                default:
                    printf("La opcion ingresada no existe\n");
            }
        }

        printf("Desea realizar los cambios?\n");
        fflush(stdin);
        scanf("%c", &respuesta);

        if(respuesta == 's')
        {
            pro[esta] = aux;
            printf("---------MODIFICACION EXITOSA------\n");
        }
        else
        {
            printf("Se ha cancelado la modificacion\n");
        }

    }

}

void bajaProducto(eProducto pro[], int tam)
{
    int codigo;
    int esta;
    char respuesta;

    printf("ingrese el codigo de producto\n");
    scanf("%d", &codigo);

    esta = buscarProducto(pro, tam, codigo);

    if(esta != -1)
    {
        mostrarProducto(pro[esta]);

        printf("Desea eliminar a el empleado? s/n \n");
        fflush(stdin);
        scanf("%c", &respuesta);

        if(respuesta == 's')
        {
            pro[esta].estado = 0;
            printf("----------BAJA EXITOSA---------\n");
        }
        else
        {
            printf("Se cancelo la operacion\n");
        }


    }
    else
    {
        printf("El producto no existe\n");
    }
}

void informar(eProducto pro[], int tam)
{
    totalYPromedioImportes(pro,tam);
    stockDelProducto(pro, tam);

}

void totalYPromedioImportes(eProducto pro[], int tam)
{
    int i;
    int total = 0;
    int promedio;
    int sumaImportes = 0;
    int contadorImportes = 0;
    int contadorImportesSuperioresPromedio = 0;
    int contadorImportesInferioresPromedio = 0;


    for(i=0;i<tam;i++)
    {
        if(pro[i].estado == 1)
        {
            sumaImportes = pro[i].importe * pro[i].cantidad;
            total = sumaImportes + total;
            contadorImportes = contadorImportes + pro[i].cantidad;
        }
    }
    promedio = total / contadorImportes;


    for(i=0;i<tam;i++)
    {
        if(pro[i].estado == 1)
        {
            if(pro[i].importe < promedio)
            {
                contadorImportesInferioresPromedio ++;
            }
            if(pro[i].importe > promedio)
            {
                contadorImportesSuperioresPromedio ++;
            }

        }
    }

     printf("INFORME A\n");
    printf("El total es: %d\n", total);
    printf("El promedio es: %d\n", promedio);
    printf("La cantidad de productos que superan el promedio es: %d\n", contadorImportesSuperioresPromedio);

    printf("-----------------\n");

    printf("INFORME B\n");
    printf("El total es: %d\n", total);
    printf("El promedio es: %d\n", promedio);
    printf("La cantidad de productos que no superan el promedio es: %d\n", contadorImportesInferioresPromedio);

    printf("-----------------\n");

}

void listar(eProveedor prov[], int tamProv, eProducto pro[], int tamPro)
{

    printf("LISTA A\n");
    ordenar(pro, tamPro);
    printf("----------\n");
    cantidadProductos(pro, tamPro);
    printf("----------\n");
    productosPromedios(pro, tamPro);
    printf("----------\n");
    productosPorProveedor(prov, tamProv, pro, tamPro);
    printf("----------\n");
    //productosPrecio(prov, tamProv, pro, tamPro);


}

/*void productosPrecio(eProveedor prov[], int tamProv, eProducto pro[], int tamPro)
{
    int i;
    eProducto maximo;
    eProducto minimo;
    int flag = 0;

    for(i=0;i<tamProv;i++)
    {

        if(flag=0)
        {
            maximo = pro[i];
            flag = 1;
        }
        else
        {
            if(pro[i].importe > maximo.importe)
            {
                maximo = pro[i];
            }
        }
    }

    printf("LISTA K\n");
    for(i=0;i<tamProv;i++)
    {
        if(maximo.codigoProveedor == prov[i].codigoProveedor)
        {
            mostrarProveedor(prov[i]);
            mostrarProducto(maximo);
        }
    }

    for(i=0;i<tamPro;i++)
    {
        if(flag=0)
        {
            minimo = pro[i];
            flag = 1;
        }
        else
        {
            if(pro[i].importe < minimo.importe)
            {
                minimo = pro[i];
            }
        }
    }

    printf("----------------\n");
    printf("LISTA L\n");

    for(i=0;i<tamProv;i++)
    {
        if(minimo.codigoProveedor == prov[i].codigoProveedor)
        {
            mostrarProveedor(prov[i]);
            mostrarProducto(minimo);
        }
    }



}*/


void productosPorProveedor(eProveedor prov[], int tamProv, eProducto pro[], int tamPro)
{
    int i;
    int j;

    printf("LISTAR G\n");
    for(i=0;i<tamProv;i++)
    {
        mostrarProveedor(prov[i]);
        for(j=0;j<tamPro;j++)
        {
            if((prov[i].codigoProveedor == pro[j].codigoProveedor) && (prov[i].estado == 1) && (pro[j].estado == 1))
            {
                mostrarProducto(pro[j]);
            }
        }
    }


}



void ordenar(eProducto pro[], int tam)
{
    int i;
    int j;
    eProducto aux;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(pro[i].estado == 1 && pro[j].estado == 1)
            {
                if(pro[i].importe > pro[j].importe)
                {
                    aux = pro[i];
                    pro[i] = pro[j];
                    pro[j] = aux;
                }
                else
                {
                    if(pro[i].importe == pro[j].importe)
                    {
                        if(strcmp(pro[i].descripcion, pro[j].descripcion) >0)
                        {
                            aux = pro[i];
                            pro[i] = pro[j];
                            pro[j] = aux;
                        }
                    }
                }
            }

        }
    }
    mostrarProductos(pro, tam);
}

void cantidadProductos(eProducto pro[], int tam)
{
    int i;

    printf("LISTA B\n");
    for(i=0;i<tam;i++)
    {
        if(pro[i].estado == 1)
        {
            if(pro[i].cantidad <= 10)
            {
                mostrarProducto(pro[i]);

            }
        }
    }

    printf("----------\n");
    printf("LISTA C \n");
    for(i=0;i<tam;i++)
    {
        if(pro[i].estado == 1)
        {
             if(pro[i].cantidad > 10)
            {
                mostrarProducto(pro[i]);
            }
        }
    }
}

void productosPromedios(eProducto pro[], int tam)
{
    int i;
    int total = 0;
    int contadorImportes = 0;
    int sumaImportes = 0;
    int promedio;

    for(i=0;i<tam;i++)
    {
        if(pro[i].estado == 1)
        {
            sumaImportes = pro[i].importe * pro[i].cantidad;
            total = sumaImportes + total;
            contadorImportes = pro[i].cantidad + contadorImportes;
        }
    }
    promedio = total / contadorImportes;

    printf("LISTA D\n");

    for(i=0;i<tam;i++)
    {
        if(pro[i].estado == 1)
        {
            if(pro[i].importe > promedio)
            {
                mostrarProducto(pro[i]);
            }
        }
    }

    printf("----------\n");

    printf("LISTA E\n");


    for(i=0;i<tam;i++)
    {
        if(pro[i].estado == 1)
        {
            if(pro[i].importe < promedio)
            {
                mostrarProducto(pro[i]);
            }
        }
    }

}




void stockDelProducto(eProducto pro[], int tam)
{
    int i;
    int cantidadMayor = 0;
    int cantidadMenor = 0;

    for(i=0;i<tam;i++)
    {
        if(pro[i].estado == 1)
        {
            if(pro[i].cantidad <= 10)
            {
                cantidadMenor ++;
            }
            else
            {
                if(pro[i].cantidad > 10)
                {
                    cantidadMayor ++;
                }
            }

        }
    }
    printf("INFORME C\n");
    printf("La cantidad de productos cuyo stock es menor o igual a 10 es: %d\n", cantidadMenor);
    printf("----------------\n");

    printf("INFORME D\n");
    printf("La cantidad de productos cuyo stock es mayor a 10 es: %d\n", cantidadMayor);
    printf("----------------\n");

}

void mostrarProveedor(eProveedor prov)
{
    printf("\nCodigo: %d\n", prov.codigoProveedor);
    printf("Descripcion: %s\n", prov.descripcion);
}

void mostrarProveedores(eProveedor prov[], int tam)
{
    int i;
    int flag = 0;

    for(i=0;i<tam;i++)
    {
        if(prov[i].estado == 1)
        {
            mostrarProveedor(prov[i]);
            flag = 1;
        }

    }

    if(flag == 0)
    {
        printf("No hay proveedores\n");
    }

}


void mostrarProducto(eProducto pro)
{
    printf("\nCodigo de producto: %d\n", pro.codigoProducto);
    printf("Descripcion: %s\n", pro.descripcion);
    printf("Importe %d\n", pro.importe);
    printf("Cantidad: %d\n", pro.cantidad);
}

void mostrarProductos(eProducto pro[], int tam)
{
    int i;
    int flag = 0;

    for(i=0;i<tam;i++)
    {
        if(pro[i].estado == 1)
        {
            mostrarProducto(pro[i]);
            flag = 1;
        }

    }

    if(flag == 0)
    {
        printf("No hay productos\n");
    }

}
