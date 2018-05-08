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


void inicializarProveedor(eProveedor [], int);

void inicializarProducto(eProducto [], int);

int buscarLibreProveedor(eProveedor [], int);

int buscarLibreProducto(eProducto [], int);

int buscarProveedor(eProveedor [], int, int);

int buscarProducto(eProducto [], int, int);

void altaProducto(eProducto [], int, int);

void modificacionProducto(eProducto [], int);

void bajaProducto(eProducto [], int);

void informar(eProducto [], int);

void listar(eProveedor [], int, eProducto [], int);

void ordenar(eProducto [], int);

void productosPromedios(eProducto [], int);

void cantidadProductos(eProducto [], int);

void totalYPromedioImportes(eProducto [], int);

void stockDelProducto(eProducto [], int);

void mostrarProducto(eProducto pro);

void mostrarProveedores(eProveedor prov[], int tam);

void mostrarProveedor(eProveedor prov);

void mostrarProductos(eProducto pro[], int tam);
