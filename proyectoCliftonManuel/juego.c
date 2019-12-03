#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "juego.h"


void mostrarJuego(eJuego juego, eCategoria categorias[], int tamCat){
    char desc[51];
    cargarDescCategoria(juego.idCategoria, categorias, tamCat, desc);
    printf(" %2d     %10s      %2.2f     %10s  \n", juego.idJuego, juego.descripcion, juego.importe, desc);
}

void mostrarJuegos(eJuego juegos[], int tamJuego, eCategoria categorias[], int tamCat){
    int cont = 0;
    printf("  ID     DESCRIPCION    IMPORTE     CATEGORIA \n");
    for(int i=0; i<tamJuego; i++){
            if(juegos[i].isEmpty == 0){
                mostrarJuego(juegos[i], categorias, tamCat);
                cont++;
            }
    }
    if(!cont){
        printf("NO HAY MARCAS QUE MOSTRAR\n\n");
    }
}

int cargarDescJuego(int idJuego, eJuego juegos[], int tamJuego, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tamJuego; i++){
        if( idJuego == juegos[i].idJuego){
            strcpy(desc, juegos[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

int buscarIdJuego(eJuego juegos[], int tamJuego, int idJuego){

    int indice = -1;

    for(int i=0; i<tamJuego; i++){
        if(juegos[i].idJuego == idJuego){
            indice = i;
            break;
        }
    }
    return indice;
}



int isEmptyJuego(eJuego juegos[], int tamJuego){
    int index = -1;
    for(int i=0; i<tamJuego; i++){
        if(juegos[i].isEmpty == 1){
            index = i;
            break;
        }
    }
    return index;
}





