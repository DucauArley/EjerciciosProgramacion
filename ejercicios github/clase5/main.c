#include <stdio.h>
#include <stdlib.h>

void mostrarNumeros(int[], int);

int main()
{
    int numeros[5];
    int i;
    int maximo;
    int minimo;
    int promedio;
    int sumaNumero = 0;
    char respuesta;
    int indice;

    for(i=0;i<5;i++)
    {
        printf("Ingrese un numero\n");
        scanf("%d", &numeros[i]);

        sumaNumero = numeros[i] + sumaNumero;

        if(i == 0)
        {
            maximo = numeros[0];
            minimo = numeros[0];
        }
        else
        {
            if(numeros[i] > maximo)
            {
                maximo = numeros[i];
            }
            else
            {
                if(numeros[i] < minimo)
                {
                    minimo = numeros[i];
                }

            }

        }


    }

    promedio = sumaNumero / i;

    mostrarNumeros(numeros, 5);

    printf("\nEl numero maximo es: %d\nEl numero minimo es: %d\nEl promedio es: %d\n", maximo, minimo, promedio);

    printf("Desea cambiar un numero s/n");
    fflush(stdin);
    scanf("%c", &respuesta);

    while(respuesta != 'n')
    {
        printf("Indique la posicion del numero que quiera cambiar \n");
        scanf("%d", &indice);
        indice = indice - 1;

        printf("Ingrese un numero \n");
        scanf("%d", &numeros[indice]);

        printf("Desea cambiar otro numero? \n");
        fflush(stdin);
        scanf("%c", &respuesta);

    }

    mostrarNumeros(numeros, 5);

    return 0;
}

void mostrarNumeros(int numeros[], int tam)
{
    int i;

     for(i=0;i<tam;i++)
    {
        printf("%d  ", numeros[i]);
    }
}

