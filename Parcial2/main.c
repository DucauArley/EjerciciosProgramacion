#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

typedef struct
{
    int dni;
    int turno;
}eTramite;

int turnoUrgente = 0;
int turnoRegular = 0;

void agregarUrgente(ArrayList*);

void agregarRegular(ArrayList*);

void proximoCliente(ArrayList*, ArrayList*, ArrayList*, ArrayList*);

void listar(ArrayList*, ArrayList*);

void informar(ArrayList*, ArrayList*);

int ordenar(void*, void*);

int Esta(ArrayList*, eTramite*);

void mostrarTramite(eTramite*);


int main()
{
    int opcion;
    int salir = 0;
    ArrayList* alUrgente;
    ArrayList* alRegular;
    ArrayList* alAtendidoUrgente;
    ArrayList* alAtendidoRegular;

    alUrgente = al_newArrayList();
    alRegular = al_newArrayList();
    alAtendidoUrgente = al_newArrayList();
    alAtendidoRegular = al_newArrayList();

    while(salir != 1)
    {
        printf("1- Tramite urgente\n");
        printf("2- Tramite regular\n");
        printf("3- Proximo cliente\n");
        printf("4- Listar personas a ser atendidas\n");
        printf("5- Informar clientes atendidos\n");
        printf("6- Salir\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarUrgente(alUrgente);
                break;
            case 2:
                system("cls");
                agregarRegular(alRegular);
                break;
            case 3:
                system("cls");
                proximoCliente(alUrgente, alRegular, alAtendidoUrgente, alAtendidoRegular);
                break;
            case 4:
                system("cls");
                listar(alUrgente, alRegular);
                break;
            case 5:
                system("cls");
                informar(alAtendidoUrgente, alAtendidoRegular);
                break;
            case 6:
                system("cls");
                salir = 1;
                break;
            default:
                system("cls");
                printf("El numero ingresado no es valido\n");
        }

    }

    return 0;
}

void agregarUrgente(ArrayList* urgente)
{
    eTramite* tramite;
    int esta;

    tramite = (eTramite*) malloc(sizeof(eTramite));

    if(urgente != NULL && tramite != NULL)
    {
        printf("Ingrese su dni\n");
        scanf("%d", &(tramite->dni));

        esta = Esta(urgente, tramite);

        if(esta != -1)
        {
            while(tramite->dni<0)
            {
                printf("Reingrese su dni\n");
                scanf("%d", &(tramite->dni));
            }

            turnoUrgente ++;

            tramite->turno = turnoUrgente;
            al_add(urgente, tramite);
        }
        else
        {
            printf("Ya tiene turno\n");
        }
    }

}

void agregarRegular(ArrayList* regular)
{
    eTramite* tramite;
    int esta;

    tramite = (eTramite*) malloc(sizeof(eTramite));

    if(regular != NULL && tramite != NULL)
    {
        printf("Ingrese su dni\n");
        scanf("%d", &(tramite->dni));

        esta = Esta(regular, tramite);

        if(esta != -1)
        {
            while(tramite->dni<0)
            {
                printf("Reingrese su dni\n");
                scanf("%d", &(tramite->dni));
            }

            turnoRegular ++;

            tramite->turno = turnoRegular;
            al_add(regular, tramite);
        }
        else
        {
            printf("Ya tiene turno \n");
        }
    }

}

void proximoCliente(ArrayList* urgente, ArrayList* regular, ArrayList* atendidoUrgente, ArrayList* atendidoRegular)
{
    eTramite* tramite;
    tramite = (eTramite*) malloc(sizeof(eTramite));

    if(urgente != NULL && regular != NULL && atendidoUrgente != NULL && atendidoRegular != NULL && tramite != NULL)
    {
        if(al_isEmpty(regular) == 0 || al_isEmpty(urgente) == 0)
        {
            if(al_isEmpty(urgente) == 1)
            {
                printf("Tramite Regular\n");
                tramite = (eTramite*) al_pop(regular, 0);
                mostrarTramite(tramite);
                al_add(atendidoRegular, tramite);
            }
            else
            {
                printf("Tramite Urgente\n");
                tramite = (eTramite*) al_pop(urgente, 0);
                mostrarTramite(tramite);
                al_add(atendidoUrgente, tramite);
            }
        }
        else
        {
            printf("No queda nadie mas por ser atendido\n");
        }
    }
}

void listar(ArrayList* urgente, ArrayList* regular)
{
    eTramite* tramite;
    int tamUrg;
    int tamReg;
    int i;

    tramite = (eTramite*) malloc(sizeof(eTramite));

    if(urgente != NULL && regular != NULL && tramite != NULL)
    {
        tamReg = al_len(regular);
        tamUrg = al_len(urgente);

        printf("Tramites Urgentes\n");

        for(i=0;i<tamUrg;i++)
        {
            tramite = (eTramite*) al_get(urgente, i);
            printf("\n");
            mostrarTramite(tramite);
        }

        printf("\nTramites Regulares\n");

        for(i=0;i<tamReg;i++)
        {
            tramite = (eTramite*) al_get(regular, i);
            printf("\n");
            mostrarTramite(tramite);
        }

        printf("\n");

    }
}

void informar(ArrayList* urgente, ArrayList* regular)
{
    //Mayor a menor
    eTramite* tramite;
    int tamUrg;
    int tamReg;
    int i;

    tramite = (eTramite*) malloc(sizeof(eTramite));

    if(urgente != NULL && regular != NULL && tramite != NULL)
    {
        tamUrg = al_len(urgente);
        tamReg = al_len(regular);

        al_sort(urgente, ordenar, 0);
        al_sort(regular, ordenar, 0);

        printf("Tramites Urgentes Atendidos\n");
        for(i=0;i<tamUrg;i++)
        {
            tramite = (eTramite*) al_get(urgente, i);
            printf("\n");
            mostrarTramite(tramite);
        }


        printf("\nTramites Regulares Atendidos\n");
        for(i=0;i<tamReg;i++)
        {
            tramite = (eTramite*) al_get(regular, i);
            printf("\n");
            mostrarTramite(tramite);
        }

        printf("\n");

    }

}

int ordenar(void* tramite1, void* tramite2)
{
    if(((eTramite*)tramite1)->dni > ((eTramite*)tramite2)->dni)
    {
        return 1;
    }
    if(((eTramite*)tramite1)->dni < ((eTramite*)tramite2)->dni)
    {
        return -1;
    }
    return 0;


}

void mostrarTramite(eTramite* tramite)
{
    if(tramite != NULL)
    {
        printf("DNI: %d\n", tramite->dni);
        printf("Turno: %d\n", tramite->turno);
    }
}

int Esta(ArrayList* array, eTramite* tramite)
{
    eTramite* tramite2;
    int j;
    int tam = al_len(array);
    int retorno = 0;

    tramite2 = (eTramite*) malloc(sizeof(eTramite));

    if(tramite != NULL && tramite2 != NULL)
    {
        for(j=0;j<tam;j++)
        {
            tramite2 = al_get(array, j);

            if(tramite->dni == tramite2->dni)
            {
                retorno = -1;
                break;
            }
        }
    }

    return retorno;
}



