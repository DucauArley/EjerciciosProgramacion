#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Funciones.h"
#include "string.h"

eMensaje* nuevoMensaje()
{
    eMensaje* returnAux;

    returnAux = (eMensaje*) malloc(sizeof(eMensaje));

    if(returnAux != NULL)
    {
        returnAux->idMensaje = -1;
        strcpy(returnAux->mensaje, " ");
        returnAux->popularidad = -1;
        returnAux->idUsuario = -1;
    }
    else
    {
        printf("No se pudo conseguir espacio en memoria\n");
    }
    return returnAux;
}

eUsuario* nuevoUsuario()
{
    eUsuario* returnAux;

    returnAux = (eUsuario*) malloc(sizeof(eUsuario));

    if(returnAux != NULL)
    {
        returnAux->idUsuario = -1;
        strcpy(returnAux->nick, " ");
        returnAux->popularidad = -1;
    }
    else
    {
        printf("No se pudo conseguir espacio en memoria\n");
    }
    return returnAux;
}

int getIdMensaje(eMensaje* mensaje)
{
    int retorno = -1;

    if(mensaje != NULL)
    {
        retorno = mensaje->idMensaje;
    }

    return retorno;
}

char* getMensaje(eMensaje* mensaje)
{
    char* retorno;

    retorno = (char*) malloc(sizeof(char) * 50);

    if(mensaje != NULL && retorno != NULL)
    {
        strcpy(retorno, mensaje->mensaje);
    }

    return retorno;
}

int getPopularidadMensaje(eMensaje* mensaje)
{
    int retorno = -1;

    if(mensaje != NULL)
    {
        retorno = mensaje->popularidad;
    }

    return retorno;
}

int getIdUsuarioMensaje(eMensaje* mensaje)
{
    int retorno = -1;

    if(mensaje != NULL)
    {
        retorno = mensaje->idUsuario;
    }

    return retorno;
}

int getIdUsuario(eUsuario* usuario)
{
    int retorno = -1;

    if(usuario != NULL)
    {
        retorno = usuario->idUsuario;
    }

    return retorno;
}

char* getNick(eUsuario* usuario)
{
    char* retorno;

    retorno = (char*) malloc(sizeof(char) * 30);

    if(usuario != NULL && retorno != NULL)
    {
        strcpy(retorno, usuario->nick);
    }

    return retorno;
}

int getPopularidadUsuario(eUsuario* usuario)
{
    int retorno = -1;

    if(usuario != NULL)
    {
        retorno = usuario->popularidad;
    }

    return retorno;
}

int setIdMensaje(eMensaje* mensaje, int id)
{
    int retorno = -1;

    if(mensaje != NULL)
    {
        mensaje->idMensaje = id;
        retorno = 0;
    }

    return retorno;
}

int setMensaje(eMensaje* mensaje, char* texto)
{
    int retorno = -1;

    if(mensaje != NULL)
    {
        strcpy(mensaje->mensaje, texto);
        retorno = 0;
    }

    return retorno;
}

int setPopularidadMensaje(eMensaje* mensaje, int popularidad)
{
    int retorno = -1;

    if(mensaje != NULL)
    {
        mensaje->popularidad = popularidad;
        retorno = 0;
    }

    return retorno;
}

int setIdUsuarioMensaje(eMensaje* mensaje, int id)
{
    int retorno = -1;

    if(mensaje != NULL)
    {
        mensaje->idUsuario = id;
        retorno = 0;
    }

    return retorno;
}

int setIdUsuario(eUsuario* usuario, int id)
{
    int retorno = -1;

    if(usuario != NULL)
    {
        usuario->idUsuario = id;
        retorno = 0;
    }

    return retorno;
}

int setNick(eUsuario* usuario, char* texto)
{
    int retorno = -1;

    if(usuario != NULL)
    {
        strcpy(usuario->nick, texto);
        retorno = 0;
    }

    return retorno;
}

int setPopularidadUsuario(eUsuario* usuario, int popularidad)
{
    int retorno = -1;

    if(usuario != NULL)
    {
        usuario->popularidad = popularidad;
        retorno = 0;
    }

    return retorno;
}

int parserMensaje(ArrayList* lista, char* path)
{
    char buffer[20];
    char buffer2[20];
    char id[20];
    char buffer3[20];
    eMensaje* aux;
    FILE* pFile;
    int cant;

    pFile = fopen(path, "r");

    if(pFile == NULL || lista == NULL)
    {
        printf("No se ha podido abrir el archivo\n");
        exit(1);
    }

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, buffer, buffer2, buffer3);

    while(!feof(pFile))
    {
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, buffer, buffer2, buffer3);
        aux = nuevoMensaje();

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

        setIdMensaje(aux, atoi(id));
        setMensaje(aux, buffer3);
        setPopularidadMensaje(aux, atoi(buffer2));
        setIdUsuarioMensaje(aux, atoi(buffer));

        al_add(lista, aux);
    }

    fclose(pFile);

    return 0;
}

int parserUsuario(ArrayList* lista, char* path)
{
    char buffer[20];
    char buffer2[20];
    char id[20];
    eUsuario* aux;
    FILE* pFile;
    int cant;

    pFile = fopen(path, "r");

    if(pFile == NULL || lista == NULL)
    {
        printf("No se ha podido abrir el archivo\n");
        exit(1);
    }

    fscanf(pFile, "%[^,],%[^,],%[^\n]\n", id, buffer, buffer2);

    while(!feof(pFile))
    {
        cant = fscanf(pFile, "%[^,],%[^,],%[^\n]\n", id, buffer, buffer2);
        aux = nuevoUsuario();

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

        setIdUsuario(aux, atoi(id));
        setNick(aux, buffer);
        setPopularidadUsuario(aux, atoi(buffer2));

        al_add(lista, aux);
    }

    fclose(pFile);

    return 0;
}
