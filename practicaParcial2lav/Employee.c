
#include "Employee.h"

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
int employee_setId(Employee* listaEmployee,int id)
{
    int result=0;
    if(listaEmployee!=NULL && id >0)
    {
        listaEmployee->id = id;
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
int employee_getId(Employee* listaEmployee,int* id)
{
    int result=0;

    if(listaEmployee!=NULL && id!=NULL)
    {
        *id = listaEmployee->id;
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
int employee_setNombre(Employee* listaEmployee, char* nombre)
{
    int result=0;
    if( listaEmployee != NULL && nombre != NULL && strlen(nombre) >= 2 && strlen(nombre) <= 127)
    {
        strcpy(listaEmployee->nombre, nombre);
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
int employee_getNombre(Employee* listaEmployee,char* nombre){

    int result=0;
    if( listaEmployee != NULL && nombre != NULL)
    {
        strcpy( nombre,listaEmployee->nombre);
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
int employee_setHorasTrabajadas(Employee* listaEmployee,int horasTrabajadas){

    int result=0;
    if( listaEmployee != NULL && horasTrabajadas >= 0)
    {
        listaEmployee->horasTrabajadas = horasTrabajadas;
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
int employee_getHorasTrabajadas(Employee* listaEmployee,int* horasTrabajadas){

    int result=0;

    if(listaEmployee!=NULL && horasTrabajadas>0)
    {
        *horasTrabajadas=listaEmployee->horasTrabajadas;
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
int employee_setSueldo(Employee* listaEmployee,int sueldo){

    int result=0;
    if(listaEmployee!=NULL && sueldo >0)
    {
        listaEmployee->sueldo = sueldo;
        result=1;
    }

    return result;
}

/** \brief Toma valor de Sueldo de una estructura Employee.
 *
 * \param recibe puntero de estructura Employee.
 * \param Puntero a entero y que guardara el valor del sueldo.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int employee_getSueldo(Employee* listaEmployee,int* sueldo){

    int result=0;

    if(listaEmployee!=NULL && sueldo>0)
    {
        *sueldo=listaEmployee->sueldo;
        result = 1;
    }
    return result;
}


/** \brief Crea espacio en memoria y crea una nueva estructura del tipo Employee
 *
 * \return Devuelve la nueva estructura creada con los campos inicializados
 */
Employee* employee_new(){

    Employee* nuevo = (Employee*) malloc( sizeof(Employee));
    if( nuevo != NULL)
    {
        nuevo->id = 0;
        strcpy(nuevo->nombre, " ");
        nuevo->horasTrabajadas = 0;
        nuevo->sueldo = 0;
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
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr){
    Employee* nuevo = employee_new();
    if( nuevo != NULL)
    {
        if(idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
        {
            if(    !employee_setId(nuevo, atoi(idStr))
                || !employee_setNombre(nuevo,nombreStr)
                || !employee_setHorasTrabajadas(nuevo,atoi(horasTrabajadasStr))
                || !employee_setSueldo(nuevo,atoi(sueldoStr)) )
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
void showEmployee(Employee* emp){
    if(emp!=NULL){
       printf("%4d  %10s  %5d      %5d\n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);
    }
}

/** \brief Muestra los datos de un empleado
 *
 * \param Recibe un puntero a Employee
 */
void showEmployees(LinkedList* pArrayLinkedList){
    int tam;

    printf(" ID     Nombre     Horas    Sueldo\n");
    printf("------------------------------------\n");

    if(ll_len(pArrayLinkedList) == 0){
            printf("NO HAY EMPLEADOS QUE MOSTRAR\n\n");
    }

    if(pArrayLinkedList != NULL){
        tam = ll_len(pArrayLinkedList);
        for(int i=0; i<tam; i++){
            showEmployee((Employee*) ll_get(pArrayLinkedList, i));
        }

    }
}



/** \brief Busca empleado por ID
 *
 * \param pArrayListEmployee LinkedList*
 * \param int
 * \return int
 *
 */
int buscarPorId(LinkedList* pArrayListEmployee, int id){
    int index = -1;
    Employee* auxEmployee = NULL;
    int tam;

    if(pArrayListEmployee != NULL){

        tam = ll_len(pArrayListEmployee);

         for(int i=1;i<tam;i++)
        {
            auxEmployee = ((Employee*) ll_get(pArrayListEmployee,i));

            if(auxEmployee->id == id)
            {
                index = i;
                break;
            }
        }
    }

    return index;
}

/** \brief Ordena por Id
 *
 * \param Recibe primera estructura Employee
 * \param Recibe segunda estructura Employee
 * \return devuelve el tipo de ordenamiento
 */
int orderID(void* emp1, void* emp2)
{
    int result=0;
    Employee* p1 = NULL;
    Employee* p2 = NULL;

    if(emp1 != NULL && emp2 != NULL)
    {
        p1=(Employee*) emp1;
        p2=(Employee*) emp2;

        if(p1->id > p2->id)
            result = 1;
        else if(p1->id < p2->id)
            result=-1;
        else
            result=0;
    }
    return result;
}

/** \brief Ordena por Sueldo
 *
 * \param Recibe primera estructura Employee
 * \param Recibe segunda estructura Employee
 * \return devuelve el tipo de ordenamiento
 */
int orderSalary(void* emp1 , void* emp2)
{
    int result=0;
    Employee* p1 = NULL;
    Employee* p2 = NULL;

    if(emp1 != NULL && emp2 != NULL)
    {
        p1=(Employee*) emp1;
        p2=(Employee*) emp2;

        if(p1->sueldo > p2->sueldo)
        {
            result = 1;
        }
        else if(p1->sueldo < p2->sueldo)
        {
            result=-1;
        }
        else
        {
            result=0;
        }
    }
    return result;
}

/** \brief Ordena por Horas trabajadas
 *
 * \param Recibe primera estructura Employee
 * \param Recibe segunda estructura Employee
 * \return devuelve el tipo de ordenamiento
 */
int orderHours(void* emp1 , void* emp2)
{
    int result=0;
    Employee* p1 = NULL;
    Employee* p2 = NULL;

    if(emp1 != NULL && emp2 != NULL)
    {
        p1=(Employee*) emp1;
        p2=(Employee*) emp2;

        if(p1->horasTrabajadas > p2->horasTrabajadas)
        {
            result = 1;
        }
        else if(p1->horasTrabajadas < p2->horasTrabajadas)
        {
            result=-1;
        }
        else
        {
            result=0;
        }
    }
    return result;
}



/** \brief Ordena por Nombre.
 *
 * \param Recibe primera estructura Employee.
 * \param Recibe segunda estructura Employee.
 * \return devuelve el tipo de ordenamiento.
 */
int orderName(void* emp1, void* emp2)
{
    int result=0;
    Employee* p1 = NULL;
    Employee* p2 = NULL;

    if(emp1 != NULL && emp2 != NULL)
    {
        p1=(Employee*) emp1;
        p2=(Employee*) emp2;

        if(strcmp(p1->nombre,p2->nombre)>0)
            result = 1;
        else if(strcmp(p1->nombre,p2->nombre)<0)
            result=-1;
        else
            result=0;
    }
    return result;
}
