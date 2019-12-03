#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include "categoria.h"

typedef struct{
    int idJuego;
    char descripcion[51];
    float importe;
    int idCategoria;
    int isEmpty;
}eJuego;

void mostrarJuego(eJuego juego, eCategoria categorias[], int tamCat);
void mostrarJuegos(eJuego juegos[], int tamJuego, eCategoria categorias[], int tamCat);
int cargarDescJuego(int idJuego, eJuego juegos[], int tamJuego, char desc[]);
int buscarIdJuego(eJuego juegos[], int tamJuego, int idJuego);
int isEmptyJuego(eJuego juegos[], int tamJuego);

#endif // JUEGO_H_INCLUDED
