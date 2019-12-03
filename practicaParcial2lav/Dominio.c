#include "Dominio.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "stdlib.h"


/** \brief Valida el valor de la ID y lo carga en estructura.
 *
 * \param recibe puntero de estructura Employee.
 * \param Toma el valor ID ingresado por el usuario.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int eDominio_setId(eDominio* listaDominio,int id)
{
    int result=0;
    if(listaDominio!=NULL && id >0)
    {
        listaDominio->id = id;
        result=1;
    }

    return result;
}

/** \brief Toma valor de ID de una estructura Employee.
 *
 * \param recibe puntero de estructura Employee.
 * \param puntero a entero y que guardara el valor del ID.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int eDominio_getId(eDominio* listaDominio,int* id)
{
    int result=0;

    if(listaDominio!=NULL && id!=NULL)
    {
        *id = listaDominio->id;
        result = 1;
    }


    return result;
}

/** \brief Valida la cadena y lo carga en estructura.
 *
 * \param Recibe puntero de estructura Employee.
 * \param Recibe cadena de caracteres.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int eDominio_setDominio(eDominio* listaDominio, char* dominio)
{
    int result=0;
    if( listaDominio != NULL && dominio != NULL && strlen(dominio) == 6 )
    {
        strcpy(listaDominio->dominio, dominio);
        result = 1;
    }
    return result;
}


/** \brief Toma la cadena de una estructura Employee.
 *
 * \param Recibe puntero de estructura Employee.
 * \param Puntero a char donde guardara la cadena de la estructura.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int eDominio_getDominio(eDominio* listaDominio,char* dominio){

    int result=0;
    if( listaDominio != NULL && dominio != NULL)
    {
        strcpy( dominio,listaDominio->dominio);
        result = 1;
    }
    return result;
}

/** \brief Valida el valor de las horas y lo carga en estructura.
 *
 * \param Recibe puntero de estructura Employee.
 * \param Toma el valor Horas ingresado por el usuario.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int eDominio_getAnio(eDominio* listaDominio,int* anio){

    int result=0;
    if( listaDominio != NULL && anio > 0)
    {
        *anio = listaDominio->anio;
        result = 1;
    }
    return result;
}


/** \brief Toma valor de Horas de una estructura Employee.
 *
 * \param recibe puntero de estructura Employee.
 * \param Puntero a entero y que guardara el valor de variable HorasTrabajadas.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int eDominio_setAnio(eDominio* listaDominio,int anio){

    int result=0;

    if(listaDominio!=NULL && anio>0)
    {
        listaDominio->anio = anio;
        result = 1;
    }
    return result;
}

/** \brief Valida el valor sueldo y lo carga en estructura
 *
 * \param Recibe puntero de estructura Employee
 * \param Toma el valor Sueldo ingresado por el usuario
 * \return Retorna 0 (cero) o 1 (uno).
 */


 int eDominio_getTipo(eDominio* listaDominio,char* tipo){

    int result=0;

    if(listaDominio!=NULL && tipo != NULL)
    {
        *tipo = listaDominio->tipo;
        result = 1;
    }
    return result;
}

/** \brief Toma valor de Sueldo de una estructura Employee.
 *
 * \param recibe puntero de estructura Employee.
 * \param Puntero a entero y que guardara el valor del sueldo.
 * \return Retorna 0 (cero) o 1 (uno).
 */


 int eDominio_setTipo(eDominio* listaDominio,char* tipo){

    int result=0;
    if(listaDominio!=NULL  )
    {
        listaDominio->tipo = *tipo;
        result=1;
    }

    return result;
}



/** \brief Crea espacio en memoria y crea una nueva estructura del tipo Employee
 *
 * \return Devuelve la nueva estructura creada con los campos inicializados
 */
eDominio* newDominio(){
    eDominio* nuevo = (eDominio*) malloc(sizeof(eDominio));
    if(nuevo != NULL){
        nuevo->id = 0;
        strcpy(nuevo->dominio, "");
        nuevo->anio = 0;
        nuevo->tipo = ' ';
    }
    return nuevo;
}


/** \brief Crea una nueva estructura de tipo Employee* y se cargan los campos con los parametros recibidos
 *
 * \param  Recibe cadena con los datos de la Id
 * \param  Recibe cadena de caracteres con los datos de Nombre
 * \param  Recibe cadena con el valor de las Horas trabajadas
 * \param  Recibe cadena con el valor del Sueldo
 *
 * \return Retorna la estructura Employee* con los datos cargados en sus campos
 */
eDominio* newDominio_Parametros(char* id,char* dominio,char* anio,char* tipo){
    eDominio* nuevo = newDominio();
    if( nuevo != NULL)
    {
        if(id!=NULL && dominio!=NULL && anio!=NULL && tipo!=NULL)
        {
            if(    !eDominio_setId(nuevo, atoi(id))
                || !eDominio_setDominio(nuevo,dominio)
                || !eDominio_setAnio(nuevo,atoi(anio))
                || !eDominio_setTipo(nuevo,tipo ))
            {
            free(nuevo);
            nuevo = NULL;
            }
        }
    }

    return nuevo;
}


/** \brief Muestra en pantalla, los datos de la linkedList
 *
 * \param Recibe LinkedList*
 */

void showDominio(eDominio* dominios){
    if(dominios!=NULL){
       printf("%4d  %10s  %5d    %5c\n",dominios->id,dominios->dominio,dominios->anio,dominios->tipo);
    }
}

/** \brief Muestra los datos de un empleado
 *
 * \param Recibe un puntero a Employee
 */

void showDominios(LinkedList* pArrayLinkedDominio){
    int tam;

    printf(" ID     Dominio     Anio    Tipo\n");
    printf("------------------------------------\n");

    if(ll_len(pArrayLinkedDominio) == 0){
            printf("NO HAY AUTOS O MOTOS QUE MOSTRAR\n\n");
    }

    if(pArrayLinkedDominio != NULL){
        tam = ll_len(pArrayLinkedDominio);
        for(int i=0; i<tam; i++){
            showDominio((eDominio*) ll_get(pArrayLinkedDominio, i));
        }
    }
}

//  PARA MAP
int setearTipo(void* e)
{
    int result = 0;
    eDominio* dom = NULL;

    if( e != NULL){
        dom = (eDominio*)e;
        if( *(dom->dominio) >= 65 && *(dom->dominio) <= 90  ){
            dom->tipo = 'A';
        }else{
            dom->tipo = 'M';
        }
        result = 1;
    }
    return result;
}

/*
void* seteaTipo(void* e)
{
    eDominio* dom = NULL;

    if(e != NULL){
         dom = (eDominio*)e;
        if( *(dom->dominio) >= 65 && *(dom->dominio) <= 90  ){
            dom->tipo = 'A';
        }else{
            dom->tipo = 'M';
        }
    }
    //return dom;
   // return (void*)dom;
}
*/




// PARA FILTER

int filterTipo(void* e)
{
    int todoOk = 0;
    eDominio* dom =NULL;
    if(e != NULL){
        dom = (eDominio*)e;
        if(dom->tipo != 'M'){
           todoOk = 1;
        }
    }
    return todoOk;
}




