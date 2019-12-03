#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED

#include "fecha.h"
#include "juego.h"
#include "categoria.h"
#include "cliente.h"

typedef struct{
    int idAlquiler;
    int idJuego;
    int idCliente;
    eFecha fecha;
    int isEmpty;
}eAlquiler;

int inicializarAlquileres(eAlquiler alquileres[], int tamAlq);
int altaAlquileres(eAlquiler alquileres[], int tamAlq, int idAlquiler, eJuego juegos[], int tamJuego, eCategoria categorias[], int tamCat, eCliente clientes[], int tamCli, eLocalidad localidades[], int tamLoc);
eAlquiler newAlquiler(int idAlquiler, int idJuego, int idCliente, eFecha fecha);
void mostrarAlquileres(eAlquiler alquileres[], int tamAlq, eCliente clientes[], int tamCli, eJuego juegos[], int tamJuego);
void mostrarAlquiler(eAlquiler alquiler, eJuego juegos[], int tamJuego, eCliente clientes[], int tamCli);
int hardcodearAlquileres( eAlquiler alquileres[], int tamAlq, int cantidad);

#endif // ALQUILER_H_INCLUDED
