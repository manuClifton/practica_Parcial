#include <stdio.h>
#include <stdlib.h>
#include "stdlib.h"
#include "LinkedList.h"
#include "Cachorro.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_CachorroFromText(FILE* pFile, LinkedList* pArrayLinkedCachorros)
{
    int result = 0;
    char buffer[6][30];
    int cant;

    eCachorro* perro = NULL;

    if(pFile != NULL && pArrayLinkedCachorros != NULL)
    {

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2],buffer[3],buffer[4],buffer[5]);

        while(!feof(pFile))
        {
            cant =  fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2],buffer[3],buffer[4],buffer[5]);

            if(cant == 6)
            {


                perro = newCachorro_Parametros(buffer[0], buffer[1], buffer[2],buffer[3],buffer[4],buffer[5]);

                if(perro != NULL)
                {
                    ll_add(pArrayLinkedCachorros,perro );
                    result = 1;
                }
            }
            else
            {
                if(feof(pFile))
                {
                    break;
                }
                else
                {
                    result = 0;
                    break;
                }
            }
        }
    }
    return result;
}
