#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "categoria.h"

void mostrarCategoria(eCategoria categoria){

    printf(" %d     %s  \n", categoria.idCategoria, categoria.descripcion);
}

void mostrarCategorias(eCategoria categorias[], int tamCat){
    int cont = 0;
    printf("  ID     DESCRIPCION\n");
    for(int i=0; i<tamCat; i++){
        mostrarCategoria(categorias[i]);
        cont++;
    }
    if(!cont){
        printf("NO HAY CATEGORIAS QUE MOSTRAR\n\n");
    }
}

int cargarDescCategoria(int idCategoria, eCategoria categorias[], int tamCat, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tamCat; i++){
        if( idCategoria == categorias[i].idCategoria){
            strcpy(desc, categorias[i].descripcion);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}







