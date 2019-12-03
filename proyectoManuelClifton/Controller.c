#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "stdlib.h"

#include "LinkedList.h"
#include "parser.h"
#include "Cachorro.h"
#include "biblioteca.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayLinkedCachorros)
{
     FILE* pFile = NULL;
    int result=0;

    if(path != NULL && pArrayLinkedCachorros != NULL){
        pFile= fopen(path,"r");
        if(pFile==NULL)
        {
            result=0;
        }
        else
        {
          result = parser_CachorroFromText(pFile, pArrayLinkedCachorros);
        }
    }
    fclose(pFile);

    return result;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayLinkedCachorros)
{
    FILE* pFile = NULL;
    eCachorro* auxPerro = NULL;
    int size=ll_len(pArrayLinkedCachorros);
    int result=-1;


    int id;
    int dias;
    char genero;
    char nombre[130];
    char raza[130];
    char reservado[130];

    if(pArrayLinkedCachorros!=NULL && path!=NULL)
    {
        {
            pFile=fopen(path,"w");

            if(pFile!=NULL)
            {
                 for(int i=0;i<size;i++)
                {
                    auxPerro=(eCachorro*)ll_get(pArrayLinkedCachorros,i);
                    eCachorro_getId(auxPerro, &id);
                    eCachorro_getNombre(auxPerro, nombre);
                    eCachorro_getDias(auxPerro,&dias);
                    eCachorro_getRaza(auxPerro,raza);
                    eCachorro_getReservado(auxPerro, reservado);
                    eCachorro_getGenero(auxPerro, &genero);
                    fprintf(pFile,"%d,%s,%d,%s,%s,%c\n",id,nombre,dias,raza,reservado,genero);
                }
                fclose(pFile);
                result=1;
            }
            else{
                result=0;
            }
        }
    }
    return result;
}



