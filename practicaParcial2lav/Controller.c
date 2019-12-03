#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "stdlib.h"

#include "LinkedList.h"
#include "parser.h"
#include "Dominio.h"
#include "biblioteca.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayLinkedDominio)
{
     FILE* pFile = NULL;
    int result=0;

    if(path != NULL && pArrayLinkedDominio != NULL){
        pFile= fopen(path,"r");
        if(pFile==NULL)
        {
            result=0;
        }
        else
        {
          result = parser_DominioFromText(pFile, pArrayLinkedDominio);
        }
    }
    fclose(pFile);

    return result;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayLinkedDominio)
{
    FILE* pFile = NULL;
    int result=0;

    if(path != NULL && pArrayLinkedDominio != NULL){
        pFile = fopen(path,"rb");
        if(pFile==NULL)
        {
            result=0;
        }
        else
        {
          result = parser_DominioFromBinary(pFile, pArrayLinkedDominio);
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
int controller_saveAsText(char* path , LinkedList* pArrayLinkedDominio)
{
    FILE* pFile = NULL;
    eDominio* auxDom = NULL;
    int size=ll_len(pArrayLinkedDominio);
    int result=-1;

    int id;
    int anio;
    char tipo;
    char dominio[130];

    if(pArrayLinkedDominio!=NULL && path!=NULL)
    {
        if(size>0)
        {
            pFile=fopen(path,"w");

            if(pFile!=NULL)
            {
                 for(int i=0;i<size;i++)
                {
                    auxDom=(eDominio*)ll_get(pArrayLinkedDominio,i);
                    eDominio_getId(auxDom, &id);
                    eDominio_getDominio(auxDom,dominio);
                    eDominio_getAnio(auxDom,&anio);
                    eDominio_getTipo(auxDom,&tipo);
                    fprintf(pFile,"%d,%s,%d,%c\n",id,dominio,anio,tipo);
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

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayLinkedDominio)
{
    FILE* pFile = NULL;
    eDominio* auxDom = NULL;
    int size = ll_len(pArrayLinkedDominio);
    int result = -1;

    if(pArrayLinkedDominio!=NULL && path!=NULL)
    {
        if(size>0)
        {
            pFile=fopen(path,"wb");

            if(pFile!=NULL)
            {
                for(int i=0; i<size;i++)
                {
                    auxDom=ll_get(pArrayLinkedDominio,i);
                    if(auxDom!=NULL)
                    {
                        fwrite(auxDom,sizeof(eDominio),1,pFile);
                    }
                }
            result=1;
            fclose(pFile);
            }
            else{
            result=0;
            }
        }
    }
    else{
        result=0;
    }

    return result;
}



