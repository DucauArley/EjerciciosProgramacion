#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cuitCliente;
    int diasPublicacion;
    char video[20];
    int estado;
    int idPantalla;
}ePublicidad;

typedef struct
{
    char nombre[20];
    char direccion[20];
    int precioPublicidad;
    int idPantalla;
    int estado;
}ePantalla;


void inicializarPantallas(ePantalla [], int);

void inicializarPublicidades(ePublicidad [], int);

int buscarEspacioLibrePantalla(ePantalla [], int);

int buscarEspacioLibrePublicidad(ePublicidad [], int);

int buscarId(ePantalla [], int, int);

int buscarCuit(ePublicidad [], int , int );

void altaPantalla(ePantalla [], int);

void modificacionPantalla(ePantalla [], int);

void bajaPantalla(ePantalla [], int, ePublicidad [], int);

void contratarPublicidad(ePantalla [], int, ePublicidad [], int);

void modificarCondicionesDePublicacion(ePantalla [], int , ePublicidad [], int);

void cancelarContratacion(ePantalla [], int, ePublicidad [], int);

void consultaFacturacion(ePantalla [], int, ePublicidad [], int);

void listarContrataciones(ePantalla [], int, ePublicidad [], int);

void informar(ePantalla [], int, ePublicidad [], int);

void listaDeClientes(ePantalla [], int, ePublicidad [], int);

void clienteConImporteMasAlto(ePantalla [], int, ePublicidad [], int);

int pantallasPorCliente(ePantalla [], int , ePublicidad [], int, int);

int cantidadDePantallasPorCliente(ePantalla [], int, ePublicidad [], int, int);

void mostrarPantalla(ePantalla);

void mostrarPubicidad(ePublicidad publicidades);

void mostrarPubicidades(ePublicidad publicidades[], int);

void mostrarPantallas(ePantalla [], int);

int main()
{
    int opcion;
    int salir = 0;
    int tamPan = 100;
    int tamPub = 1000;
    ePantalla pantallas[tamPan];
    ePublicidad publicidades[tamPub];

    inicializarPantallas(pantallas, tamPan);
    inicializarPublicidades(publicidades, tamPub);

    while(salir == 0)
    {
        printf("1- Alta de pantalla\n");
        printf("2- Modificar datos de pantalla\n");
        printf("3- Baja de pantalla\n");
        printf("4- Contratar una publicidad\n");
        printf("5- Modificar condiciones de publicacion\n");
        printf("6- Cancelar contratacion\n");
        printf("7- Consultar facturacion\n");
        printf("8- Listar contratacion\n");
        printf("9- Listar pantallas\n");
        printf("10- Informar\n");
        printf("11- Salir\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                altaPantalla(pantallas, tamPan);
                break;
            case 2:
                system("cls");
                modificacionPantalla(pantallas, tamPan);
                break;
            case 3:
                system("cls");
                bajaPantalla(pantallas, tamPan, publicidades, tamPub);
                break;
            case 4:
                system("cls");
                contratarPublicidad(pantallas, tamPan, publicidades, tamPub);
                break;
            case 5:
                system("cls");
                modificarCondicionesDePublicacion(pantallas, tamPan, publicidades, tamPub);
                break;
            case 6:
                system("cls");
                cancelarContratacion(pantallas, tamPan, publicidades, tamPub);
                break;
            case 7:
                system("cls");
                consultaFacturacion(pantallas, tamPan, publicidades, tamPub);
                break;
            case 8:
                system("cls");
                listarContrataciones(pantallas, tamPan, publicidades, tamPub);
                break;
            case 9:
                system("cls");
                mostrarPantallas(pantallas, tamPan);
                break;
            case 10:
                system("cls");
                informar(pantallas, tamPan, publicidades, tamPub);
                break;
            case 11:
                system("cls");
                salir = 1;
                break;
            default:
                printf("el numero ingresado no es valido\n");
        }
    }



    return 0;
}

void inicializarPantallas(ePantalla pantallas[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        pantallas[i].estado = 0;
    }
}

void inicializarPublicidades(ePublicidad publicidades[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        publicidades[i].estado = 0;
    }
}

int buscarEspacioLibrePantalla(ePantalla pantallas[], int tam)
{
    int i;
    int indice = -1;

    for(i=0;i<tam;i++)
    {
        if(pantallas[i].estado == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarEspacioLibrePublicidad(ePublicidad publicidades[], int tam)
{
    int i;
    int indice = -1;

    for(i=0;i<tam;i++)
    {
        if(publicidades[i].estado == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarId(ePantalla pantallas[], int tam, int id)
{
    int i;
    int indice = -1;

    for(i=0;i<tam;i++)
    {
        if(pantallas[i].idPantalla == id && pantallas[i].estado == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarCuit(ePublicidad publicidades[], int tam, int cuit)
{
    int i;
    int indice = -1;

    for(i=0;i<tam;i++)
    {
        if(publicidades[i].cuitCliente == cuit && publicidades[i].estado == 1)
        {
            indice = i;
            break;
        }

    }

    return indice;
}

void altaPantalla(ePantalla pantallas[], int tam)
{
    int indice;
    int esta;
    ePantalla aux;

    indice = buscarEspacioLibrePantalla(pantallas, tam);

    if(indice == -1)
    {
        printf("No se pueden ingresar mas pantallas\n");
    }
    else
    {
        printf("Ingrese el id de la pantalla\n");
        scanf("%d", &aux.idPantalla);

        esta = buscarId(pantallas, tam, aux.idPantalla);

        if(esta != -1)
        {
            printf("La pantalla ya existe\n");
            mostrarPantalla(pantallas[esta]);
        }
        else
        {
            printf("Ingrese el nombre\n");
            fflush(stdin);
            gets(aux.nombre);

            printf("Ingrese la direccion\n");
            fflush(stdin);
            gets(aux.direccion);

            printf("ingrese el precio de la publicidad por cada dia de publicacion\n");
            scanf("%d", &aux.precioPublicidad);

            aux.estado = 1;

            pantallas[indice] = aux;

            printf("--------ALTA EXITOSA-------\n");

        }
    }
}

void modificacionPantalla(ePantalla pantallas[], int tam)
{
    int esta;
    int flag = 0;
    int opcion;
    char respuesta;
    ePantalla aux;

    printf("Ingrese el id de la pantalla\n");
    scanf("%d", &aux.idPantalla);

    esta = buscarId(pantallas, tam, aux.idPantalla);

    if(esta == -1)
    {
        printf("La pantalla no existe\n");
    }
    else
    {
        mostrarPantalla(pantallas[esta]);

        printf("Que desea modificar?\n");
        printf("1- Nombre\n");
        printf("2- Direccion\n");
        printf("3- Precio de la publicidad por cada dia de publicacion\n");
        scanf("%d", &opcion);

        aux = pantallas[esta];

        while(flag == 0)
        {
            switch(opcion)
            {
                case 1:
                    printf("Ingrese el nombre\n");
                    fflush(stdin);
                    gets(aux.nombre);
                    flag = 1;
                    break;
                case 2:
                    printf("Ingrese la direccion\n");
                    fflush(stdin);
                    gets(aux.direccion);
                    flag = 1;
                    break;
                case 3:
                    printf("Ingrese el precio de la publicidad por cada día de publicación\n");
                    scanf("%d", &aux.precioPublicidad);
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
            pantallas[esta] = aux;
            printf("---------MODIFICACION EXITOSA------\n");
        }
        else
        {
            printf("Se ha cancelado la modificacion\n");
        }

    }

}

void bajaPantalla(ePantalla pantallas[], int tamPan, ePublicidad publicidades[], int tamPub)
{
    int esta;
    char respuesta;
    int id;
    int i;

    printf("Ingrese el id de la pantalla que desea dar de baja\n");
    scanf("%d", &id);

    esta = buscarId(pantallas, tamPan, id);

    if(esta == -1)
    {
        printf("La pantalla que desea dar de baja no existe\n");
    }
    else
    {
        mostrarPantalla(pantallas[esta]);

        printf("Seguro que desea darla de baja\n");
        fflush(stdin);
        scanf("%c", &respuesta);

        if(respuesta == 's')
        {
            pantallas[esta].estado = 0;

            for(i=0;i<tamPub;i++)
            {
                if(publicidades[i].idPantalla == pantallas[esta].idPantalla)
                {
                    publicidades[i].estado = 0;
                }
            }

            printf("-------BAJA EXITOSA------\n");
        }
        else
        {
            printf("Se ha cancelado la operacion\n");
        }
    }

}

void contratarPublicidad(ePantalla pantallas[], int tamPan, ePublicidad publicidades[], int tamPub)
{
    int id;
    int indicePub;
    int esta;
    ePublicidad aux;

    indicePub = buscarEspacioLibrePublicidad(publicidades, tamPub);

    if(indicePub == -1)
    {
        printf("No se pueden realizar mas contrataciones\n");
    }
    else
    {
        mostrarPantallas(pantallas, tamPan);

        printf("Ingrese el id de la pantalla que quiera contratar\n");
        scanf("%d", &id);

        esta = buscarId(pantallas, tamPub, id);

        if(esta == -1)
        {
            printf("Esa pantalla no existe\n");
        }
        else
        {
            aux.estado = 1;
            aux.idPantalla = id;

            printf("Ingrese su cuit\n");
            scanf("%d", &aux.cuitCliente);

            printf("Ingrese la cantidad de dias que dura la publicacion\n");
            scanf("%d", &aux.diasPublicacion);

            printf("Ingrese el nombre del video\n");
            fflush(stdin);
            gets(aux.video);

            publicidades[indicePub] = aux;

            printf("--------CONTRATACION EXITOSA-------\n");
        }
    }
}

void modificarCondicionesDePublicacion(ePantalla pantallas[], int tamPan, ePublicidad publicidades[], int tamPub)
{
    int cuit;
    int indice;
    int esta;
    int estaCuit;
    int id;
    ePublicidad aux;
    char respuesta;

    printf("Ingrese su cuit\n");
    scanf("%d", &cuit);

    estaCuit = buscarCuit(publicidades, tamPub, cuit);

    if(estaCuit == -1)
    {
        printf("El cliente no existe");
    }
    else
    {
        esta = pantallasPorCliente(pantallas, tamPan, publicidades, tamPub, cuit);

        if(esta == 0)
        {
            printf("El cliente no contrato ninguna pantalla\n");
        }
        else
        {
            printf("Ingrese el id de la pantalla que desea modificar\n");
            scanf("%d", &id);

            indice = buscarId(pantallas, tamPan, id);

            if(indice == -1)
            {
                printf("La pantalla no existe\n");
            }
            else
            {
                printf("Ingrese la cantidad de dias a contratar\n");
                scanf("%d", &aux.diasPublicacion);

                printf("Desea realizar los cambios?\n");
                fflush(stdin);
                scanf("%c", &respuesta);

                if(respuesta == 's')
                {
                    publicidades[estaCuit].diasPublicacion = aux.diasPublicacion;
                    printf("-------MODIFICACION EXITOSA-------\n");
                }
                else
                {
                    printf("Se ha cancelado la operacion\n");
                }
            }
        }
    }

}

void cancelarContratacion(ePantalla pantallas[], int tamPan, ePublicidad publicidades[], int tamPub)
{
    int i;
    int cuit;
    int indice;
    int esta;
    int estaCuit;
    int id;

    printf("Ingrese su cuit\n");
    scanf("%d", &cuit);

    estaCuit = buscarCuit(publicidades, tamPub, cuit);

    if(estaCuit == -1)
    {
        printf("El cliente no existe");
    }
    else
    {
        esta = pantallasPorCliente(pantallas, tamPan, publicidades, tamPub, cuit);

        if(esta == 0)
        {
            printf("El cliente no contrato ninguna pantalla\n");
        }
        else
        {
            printf("Ingrese el id de la pantalla que desea cancelar\n");
            scanf("%d", &id);

            indice = buscarId(pantallas, tamPan, id);

            if(indice == -1)
            {
                printf("La pantalla no existe\n");
            }
            else
            {
                for(i=0;i<tamPub;i++)
                {
                    if(publicidades[i].idPantalla == id)
                    {
                        publicidades[i].estado = 0;
                    }
                }
                printf("----------CANCELACION EXITOSA-----------\n");
            }
        }
    }
}

void consultaFacturacion(ePantalla pantallas[], int tamPan, ePublicidad publicidades[], int tamPub)
{
    int cuit;
    int esta;
    int i;
    int acumuladorImporte;

    printf("Ingrese su cuit\n");
    scanf("%d", &cuit);

    esta = buscarCuit(publicidades, tamPub, cuit);

    if(esta == -1)
    {
        printf("El cuit ingresado no existe\n");
    }
    else
    {
        for(i=0;i<tamPub;i++)
        {
            if(publicidades[i].cuitCliente == cuit && publicidades[i].estado == 1)
            {
                mostrarPubicidad(publicidades[i]);
                acumuladorImporte = publicidades[i].diasPublicacion * pantallas[i].precioPublicidad;
                printf("El importe a abonar es: %d\n", acumuladorImporte);
            }
        }
    }
}

void listarContrataciones(ePantalla pantallas[], int tamPan, ePublicidad publicidades[], int tamPub)
{
    int i;
    int j;

    for(i=0;i<tamPan;i++)
    {
        for(j=0;j<tamPub;j++)
        {
            if(pantallas[i].idPantalla == publicidades[j].idPantalla && pantallas[i].estado == 1 && publicidades[j].estado == 1)
            {
                printf("Nombre: %s\n", pantallas[i].nombre);
                printf("Video: %s\n", publicidades[j].video);
                printf("Cantidad de dias: %d\n", publicidades[j].diasPublicacion);
                printf("Cuit: %d\n", publicidades[j].cuitCliente);
            }
        }
    }

}

void informar(ePantalla pantallas[], int tamPan, ePublicidad publicidades[], int tamPub)
{
    int opcion;

    printf("1- Lista de cada cliente con cantidad de contrataciones e importe a pagar por cada una\n");
    printf("2- Cliente con importe mas alto a facturar\n");
    scanf("%d", &opcion);

    switch(opcion)
    {
        case 1:
            system("cls");
            listaDeClientes(pantallas, tamPan, publicidades, tamPub);
            break;
        case 2:
            system("cls");
            clienteConImporteMasAlto(pantallas, tamPan, publicidades, tamPub);
            break;
        default:
            printf("El numero ingresado es incorrecto\n");
    }


}

void listaDeClientes(ePantalla pantallas[], int tamPan, ePublicidad publicidades[], int tamPub)
{
    int cantidad;
    int i;
    int acumuladorImporte;

    for(i=0;i<tamPub;i++)
    {
        cantidad = cantidadDePantallasPorCliente(pantallas, tamPan, publicidades, tamPub, publicidades[i].cuitCliente);
    }

     for(i=0;i<tamPub;i++)
        {
            if(publicidades[i].estado == 1)
            {
                acumuladorImporte = publicidades[i].diasPublicacion * pantallas[i].precioPublicidad;
                printf("El importe a abonar es: %d\n", acumuladorImporte);
            }
        }


}

void clienteConImporteMasAlto(ePantalla pantallas[], int tamPan, ePublicidad publicidades[], int tamPub)
{
    int i;
    int j;
    int maximo;
    int flag = 0;
    int acumuladorImporte;

    for(i=0;i<tamPub;i++)
    {

        for(j=0;j<tamPub;i++)
        {
            if(publicidades[j].estado == 1)
            {
                acumuladorImporte = publicidades[j].diasPublicacion * pantallas[j].precioPublicidad;

                if(flag == 0)
                {
                    maximo = acumuladorImporte;
                    flag = 1;
                }
                else
                {
                    if(acumuladorImporte > maximo)
                    {
                        maximo = acumuladorImporte;
                    }
                }
            }
        }
    }

    printf("El o los clientes con importe más alto a facturar, son: \n");

    for(i=0;i<tamPub;i++)
    {
          for(j=0;j<tamPub;i++)
        {
            if(publicidades[j].estado == 1)
            {
                acumuladorImporte = publicidades[j].diasPublicacion * pantallas[j].precioPublicidad;

                if(acumuladorImporte == maximo)
                {
                    printf("%d\n", publicidades[j].cuitCliente);
                }
            }
        }
    }

}

int pantallasPorCliente(ePantalla pantallas[], int tamPan, ePublicidad publicidades[], int tamPub, int cuit)
{
    int i;
    int j;
    int flag = 0;

    for(i=0;i<tamPub;i++)
    {
        if(publicidades[i].cuitCliente == cuit && publicidades[i].estado == 1)
        {
            for(j=i+1;j<tamPan;j++)
            {
                if(publicidades[i].idPantalla == pantallas[j].idPantalla && pantallas[j].estado == 1)
                {
                    mostrarPantalla(pantallas[i]);
                    flag = 1;
                }
            }
        }
    }

    return flag;
}

int cantidadDePantallasPorCliente(ePantalla pantallas[], int tamPan, ePublicidad publicidades[], int tamPub, int cuit)
{
    int i;
    int j;
    int flag = 0;

    for(i=0;i<tamPub;i++)
    {
        if(publicidades[i].cuitCliente == cuit && publicidades[i].estado == 1)
        {
            for(j=i+1;j<tamPan;j++)
            {
                if(publicidades[i].idPantalla == pantallas[j].idPantalla && pantallas[j].estado == 1)
                {
                    flag ++;
                }
            }
        }
    }

    return flag;
}


void mostrarPantalla(ePantalla pantalla)
{
    printf("Nombre: %s\n", pantalla.nombre);
    printf("ID: %d\n", pantalla.idPantalla);
    printf("Direccion: %s\n", pantalla.direccion);
    printf("Precio de la publicidad: %d\n\n", pantalla.precioPublicidad);
}

void mostrarPubicidad(ePublicidad publicidades)
{
    printf("Cuit: %d\n", publicidades.cuitCliente);
    printf("Dias de publicacion: %d\n", publicidades.diasPublicacion);
    printf("Video: %s\n", publicidades.video);

}

void mostrarPublicidades(ePublicidad publicidades[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        if(publicidades[i].estado == 1)
        {
            mostrarPubicidad(publicidades[i]);
        }
    }

}

void mostrarPantallas(ePantalla pantallas[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        if(pantallas[i].estado == 1)
        {
            mostrarPantalla(pantallas[i]);
        }
    }

}


