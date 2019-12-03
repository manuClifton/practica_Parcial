#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "biblioteca.h"

int menu(){
    int option;

    system("cls");
    printf("\n******************** PARCIAL ******************\n\n");

        printf("1- ALTA VUELO\n");
        printf("2- BAJA VUELO\n");
        printf("3- MODIFICAR VUELO\n");
        printf("4- LISTAR TODOS LOS VUELOS\n\n");
        printf("5- CONSULTAS\n\n");

        printf("0- CANCELAR\n\n");
        getIntRange(&option, "Ingrese Opcion: ", "Error. Reingrese Opcion: ", 1, 5);

    return option;
}


char menuInformes(){
    char option;

    system("cls");
    printf("*************   CONSULTAS   *************\n");
    printf("A- Vuelos de Piloto Seleccionado\n");
    printf("B- Todos los Pilotos que volaron a un destino espesifico\n");
    printf("C- Recaudacion por cada piloto\n");
    printf("D- Destino mas elegido\n");

    printf("E-  Salir\n\n");

    getCh(&option,"Ingrese Opcion: ", "Error. Ingrese Opcion: ");

    return option;
}
