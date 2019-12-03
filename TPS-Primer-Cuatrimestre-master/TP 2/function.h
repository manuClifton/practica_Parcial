
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

/** \brief  Estructura Employee representa los datos de un empleado de la empresa.
 */
typedef struct {
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;

/** \brief Permite buscar un empleado por su numero de legajo.
 *\param Estructuta de empleado.
 *\param Tamaño de la estructura como entero.
 *\param Entero ingresado por el usuario.
 * \return Devuelve un número entero entre -1 y el tamaño de la estructura.
 */
int findEmployee(eEmployee list[], int len, int file);

/** \brief Despliega en pantalla un listado de empleados activos.
 *\param Estructuta de empleado.
 *\param Tamaño de la estructura como entero.
 * \return Retorna 0
 */
int printEmployees(eEmployee list[], int len);

/** \brief Busca en el Array de empleados un espacio libre o empleado inactivo.
 *\param Estructuta de empleado.
 *\param Tamaño de la estructura como entero.
 * \return Devuelve un número entero entre -1 y el tamaño de la estructura.
 */
int findFree(eEmployee list[], int len);

/** \brief Despliega menu principal de opciones en pantalla.
 * \return Retorna 0
 */
int menu();

/** \brief Despliega submenu menu de opciones en pantalla.
 * \return Retorna 0
 */
int menuAlphabet();

/** \brief Despliega submenu menu de opciones en pantalla.
 * \return Retorna 0
 */
int menuInfo();

/** \brief Despliega lista de empleados que superan el sueldo promedio.
 *\param Estructuta de empleado.
 *\param Tamaño de la estructura como entero.
 * \return
 */
void employeeExceedsAverage(eEmployee list[], int leng);

/** \brief Permite ingresar un numero de legajo y mostrar los datos del empleado en pantalla, si es que existe.
 *\param Estructuta de empleado.
 *\param Tamaño de la estructura como entero.
 *\param Entero ingresado por el usuario.
 * \return
 */
void findEmployeeById(eEmployee list[], int len);

/** \brief Genera un listado de empleados.
 * \return
 */
void generateEmployee(eEmployee list[], int len);

/** \brief Permite agregar un empleado nuevo al usuario, en caso que sea posible.
 *\param Estructuta de empleado.
 *\param Tamaño de la estructura como entero.
 * \return
 */
void highEmployee(eEmployee list[], int len);

/** \brief Inavilita a todos los empleados, realiza una baja logica general.
 *\param Estructuta de empleado.
 *\param Tamaño de la estructura como entero.
 * \return
 */
void initEmployees(eEmployee list[], int len);

/** \brief Permite modificar el sueldo de un empleado.
 *\param Estructuta de empleado.
 *\param Tamaño de la estructura como entero.
 * \return
 */
void modifyEmployee(eEmployee list[], int len);

/** \brief Realiza la baja logica de un empleado elegido por el usuario.
 *\param Estructuta de empleado.
 *\param Tamaño de la estructura como entero.
 * \return
 */
void removeEmployee(eEmployee list[], int len);

/** \brief Ordena de forma ascendente por apellido y muestra en pantalla el listado de empleados,
           Si el apellido es el mismo los ordena por sector.
 *\param Estructuta de empleado.
 *\param Tamaño de la estructura como entero.
 * \return
 */
void sortEmployeesUpward(eEmployee list[], int len);

/** \brief Ordena de forma decendente por apellido y muestra en pantalla el listado de empleados,
           Si el apellido es el mismo los ordena por sector.
 *\param Estructuta de empleado.
 *\param Tamaño de la estructura como entero.
 * \return
 */
void sortEmployeesDecendent(eEmployee list[], int len);

/** \brief Se utiliza en otras funcines, muestra un empleado de la nomina.
 * \return
 */
void printEmployee(eEmployee list);

/** \brief Indica en pantalla cuantos empleados activos existen y el promedio total de sueldos.
 *\param Estructuta de empleado.
 *\param Tamaño de la estructura como entero.
 * \return
 */
void totalEmployees(eEmployee list[], int len);


