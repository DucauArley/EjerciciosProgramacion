#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

typedef struct
{
    int idMensaje;
    char mensaje[50];
    int popularidad;
    int idUsuario;
}eMensaje;

typedef struct
{
    int idUsuario;
    char nick[30];
    int popularidad;
}eUsuario;

eMensaje* nuevoMensaje();
eUsuario* nuevoUsuario();
int getIdMensaje(eMensaje*);
char* getMensaje(eMensaje*);
int getPopularidadMensaje(eMensaje*);
int getIdUsuarioMensaje(eMensaje*);
int getIdUsuario(eUsuario*);
char* getNick(eUsuario*);
int getPopularidadUsuario(eUsuario*);
int setIdMensaje(eMensaje*, int);
int setMensaje(eMensaje*, char*);
int setPopularidadMensaje(eMensaje*, int);
int setIdUsuarioMensaje(eMensaje*, int);
int setIdUsuario(eUsuario*, int);
int setNick(eUsuario*, char*);
int setPopularidadUsuario(eUsuario*, int);
int parserMensaje(ArrayList*, char*);
int parserUsuario(ArrayList*, char*);
