#include "menu.h"
#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
/** \brief Menu principal del programa.
 * \return Retorna entero seleccionado por el usuario.
 */
int menu(void)
{
    int option;

        system("cls");
        printf("***************** PARCIAL 2  *****************\n");
        printf("*********    Biblioteca LinkedList    ***********\n\n");

        printf("1. Cargar los datos de los cachorros desde el archivo cachorro.csv (modo texto)\n");
        printf("2. Imprimir la lista\n");
        printf("3. Filtrar menores de 45 dias\n");
        printf("4. Filtras Machos\n");
        printf("5. Generar listado de callejeros\n");

        printf("6. Salir\n");

        getIntRange(&option, "Ingrese Opcion: ", "Error. Reingrese Opcion: ", 1, 6);

    return option;
}
