#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "stdlib.h"

#include "LinkedList.h"
#include "biblioteca.h"
#include "Controller.h"
#include "Dominio.h"


int main()
{

    LinkedList* listaDominios = ll_newLinkedList();
    LinkedList* listaMapeada = NULL;
    LinkedList* listaFilterA = NULL;
    LinkedList* listaFilterM = NULL;

    controller_loadFromText("datos.csv", listaDominios);

        showDominios(listaDominios);


    listaMapeada = ll_Map(listaDominios, setearTipo);

    if(listaMapeada != NULL){
         showDominios(listaMapeada);
    }
    //showDominios(listaDominios);

    listaFilterA = ll_filter(listaMapeada, filterTipo, 'A');

    if(listaFilterA != NULL){
        showDominios(listaFilterA);
    }

    listaFilterM = ll_filter(listaMapeada, filterTipo, 'M');

    if(listaFilterM != NULL){
        showDominios(listaFilterM);
    }

        controller_saveAsText("auto.csv", listaFilterA);
        controller_saveAsText("moto.csv", listaFilterM);
/**/
    return 0;
}



