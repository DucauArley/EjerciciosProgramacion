#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5


int main()
{

    int vectorInt[TAM] = {25, 10, 34, 90, 5};
    char vectorString[TAM][20]= {"aaa","bbb","aaa","bbb","aaa"};

    int i;
    int j;
    int auxInt;
    char auxString[20];


    for(i=0; i<TAM-1; i++)
    {
        for(j=i+1; j<TAM; j++)
        {
            if(strcmp(vectorString[i], vectorString[j])>0)
            {
                auxInt = vectorInt[i];
                vectorInt[i] = vectorInt[j];
                vectorInt[j] = auxInt;

                strcpy(auxString, vectorString[i]);
                strcpy(vectorString[i],vectorString[j]);
                strcpy(vectorString[j],auxString);

            }
            else
            {
                if(strcmp(vectorString[i], vectorString[j])==0)
                {
                    if(vectorInt[i]>vectorInt[j])
                    {
                        auxInt = vectorInt[i];
                        vectorInt[i] = vectorInt[j];
                        vectorInt[j] = auxInt;
                    }
                }
            }
        }
    }

    for(i=0; i<TAM; i++)
    {
        printf("%s -- %d\n", vectorString[i], vectorInt[i]);
    }




    return 0;
}
