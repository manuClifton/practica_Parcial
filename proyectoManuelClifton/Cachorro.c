#include "Cachorro.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "stdlib.h"

/** \brief Valida el valor de la ID y lo carga en estructura.
 *
 * \param recibe puntero de estructura eCachorro.
 * \param Toma el valor ID ingresado por el usuario.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int eCachorro_setId(eCachorro* listaCachorros,int id)
{
    int result=0;
    if(listaCachorros!=NULL && id >0)
    {
        listaCachorros->id = id;
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

int eCachorro_getId(eCachorro* listaCachorros,int* id)
{
    int result=0;

    if(listaCachorros!=NULL && id!=NULL)
    {
        *id = listaCachorros->id;
        result = 1;
    }


    return result;
}

/*
int eCachorro_getIdMayor(eCachorro* listaCachorros,int* id)
{
    int result=0;

    if(listaCachorros!=NULL && id!=NULL && *id >= 45)
    {
        *id = listaCachorros->id;
        result = 1;
    }


    return result;
}
*/

/** \brief Valida la cadena y lo carga en estructura.
 *
 * \param Recibe puntero de estructura Employee.
 * \param Recibe cadena de caracteres.
 * \return Retorna 0 (cero) o 1 (uno).
 */

int eCachorro_setNombre(eCachorro* listaCachorros, char* nombre)
{
    int result=0;
    if( listaCachorros != NULL && nombre != NULL)
    {
        strcpy(listaCachorros->nombre, nombre);
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

int eCachorro_getNombre(eCachorro* listaCachorros,char* nombre){

    int result=0;
    if( listaCachorros != NULL && nombre != NULL)
    {
        strcpy( nombre,listaCachorros->nombre);
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

int eCachorro_getDias(eCachorro* listaCachorros,int* dias){

    int result=0;
    if( listaCachorros != NULL && dias > 0)
    {
        *dias = listaCachorros->dias;
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

int eCachorro_setDias(eCachorro* listaCachorros,int dias){

    int result=0;

    if(listaCachorros!=NULL && dias>0)
    {
        listaCachorros->dias = dias;
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


 int eCachorro_setRaza(eCachorro* listaCachorros,char* raza){

    int result=0;

    if(listaCachorros!=NULL && raza != NULL)
    {
         strcpy(listaCachorros->raza, raza);
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


 int eCachorro_getRaza(eCachorro* listaCachorros,char* raza){

    int result=0;
    if(listaCachorros!=NULL && raza != NULL )
    {
        strcpy( raza,listaCachorros->raza);
        result=1;
    }

    return result;
}


/** \brief Valida el valor sueldo y lo carga en estructura
 *
 * \param Recibe puntero de estructura Employee
 * \param Toma el valor Sueldo ingresado por el usuario
 * \return Retorna 0 (cero) o 1 (uno).
 */


 int eCachorro_setReservado(eCachorro* listaCachorros,char* reservado){

    int result=0;

    if(listaCachorros!=NULL && reservado != NULL)
    {
         strcpy(listaCachorros->reservado, reservado);
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


 int eCachorro_getReservado(eCachorro* listaCachorros,char* reservado){

    int result=0;
    if(listaCachorros!=NULL && reservado != NULL )
    {
        strcpy( reservado,listaCachorros->reservado);
        result=1;
    }

    return result;
}

/** \brief Valida el valor sueldo y lo carga en estructura
 *
 * \param Recibe puntero de estructura Employee
 * \param Toma el valor Sueldo ingresado por el usuario
 * \return Retorna 0 (cero) o 1 (uno).
 */


 int eCachorro_getGenero(eCachorro* listaCachorros,char* genero){

    int result=0;

    if(listaCachorros!=NULL && genero != NULL)
    {
        *genero = listaCachorros->genero;
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


 int eCachorro_setGenero(eCachorro* listaCachorros,char* genero){

    int result=0;
    if(listaCachorros!=NULL  )
    {
        listaCachorros->genero = *genero;
        result=1;
    }

    return result;
}


/** \brief Crea espacio en memoria y crea una nueva estructura del tipo Employee
 *
 * \return Devuelve la nueva estructura creada con los campos inicializados
 */

eCachorro* newCachorro()
{
    eCachorro* nuevo = (eCachorro*) malloc(sizeof(eCachorro));
    if(nuevo != NULL){
        nuevo->id = 0;
        strcpy(nuevo->nombre, "");
        nuevo->dias = 0;
        strcpy(nuevo->raza, "");
        strcpy(nuevo->reservado, "");
        nuevo->genero = ' ';
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

eCachorro* newCachorro_Parametros(char* id,char* nombre,char* dias,char* raza, char* reservado, char* genero){
    eCachorro* nuevo = newCachorro();
    if( nuevo != NULL)
    {
        if(id!=NULL && nombre!=NULL && dias!=NULL && raza!=NULL && reservado!=NULL && genero!=NULL)
        {
            if(    !eCachorro_setId(nuevo, atoi(id))
                || !eCachorro_setNombre(nuevo,nombre)
                || !eCachorro_setDias(nuevo,atoi(dias))
                || !eCachorro_setRaza(nuevo,raza )
                || !eCachorro_setReservado(nuevo, reservado)
                || !eCachorro_setGenero(nuevo, genero))
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


void showCachorro(eCachorro* perro){
    if(perro!=NULL){
       printf("%4d  %10s  %2d    %10s    %10s   %5c\n",perro->id, perro->nombre, perro->dias, perro->raza, perro->reservado, perro->genero);
    }
}

/** \brief Muestra los datos de un empleado
 *
 * \param Recibe un puntero a Employee
 */

void showCachorros(LinkedList* pArrayLinkedCachorros){
    int tam;

    printf("\n ID     Nombre     Dias    Raza          Reservado     Genero\n");
    printf("------------------------------------------------------------\n");

    if(ll_len(pArrayLinkedCachorros) == 0){
            printf("NO HAY PERROS QUE MOSTRAR\n\n");
    }

    if(pArrayLinkedCachorros != NULL){
        tam = ll_len(pArrayLinkedCachorros);
        for(int i=0; i<tam; i++){
            showCachorro((eCachorro*) ll_get(pArrayLinkedCachorros, i));
        }
    }
}




// PARA FILTER

int filterMayor45(void* e)
{
    int todoOk = 0;
    int dias;

    eCachorro* perro =NULL;
    if(e != NULL){
        if(eCachorro_getDias(perro, &dias)){
                if(dias >= 45){
                    todoOk = 1;
                }
        }
    }
    return todoOk;
}





int filterMacho(void* e)
{
    int todoOk = 0;
    char genero;
    eCachorro* perro =NULL;
    if(e != NULL){
        if(eCachorro_getGenero(perro, &genero)){
             if(genero != 'M'){
                todoOk = 1;
             }
        }
    }
    return todoOk;
}

int filterCallejeros(void* e)
{
    int todoOk = 0;
    char raza[20];
    eCachorro* perro =NULL;
    if(e != NULL){
        if(eCachorro_getRaza(perro, raza)){
            if(strcmpi(raza, "Callejero") == 0 ){
                todoOk = 1;
            }
        }
    }
    return todoOk;
}


