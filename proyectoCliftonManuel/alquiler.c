#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "alquiler.h"
#include "biblioteca.h"



int isEmptyAlquiler(eAlquiler alquiler[], int tamAlq){
    int index = -1;
    for(int i=0; i<tamAlq; i++){
        if(alquiler[i].isEmpty == 1){
            index = i;
            break;
        }
    }
    return index;
}

int inicializarAlquileres(eAlquiler alquileres[], int tamAlq){
    int rta = 0;
    for(int i=0; i<tamAlq; i++){
        alquileres[i].isEmpty = 1;
        if(i == tamAlq -1){
            rta=1;
        }
    }
    return rta;
}

int altaAlquileres(eAlquiler alquileres[], int tamAlq, int idAlquiler, eJuego juegos[], int tamJuego, eCategoria categorias[], int tamCat, eCliente clientes[], int tamCli, eLocalidad localidades[], int tamLoc){
    int todoOk = 0;
    int indice;
    int indiceJuego;
    int indiceCli;
    int idJuego;
    int idCliente;
    eFecha fecha;

        system("cls");
        printf("******* ALTA ALQUILER *******\n\n");

        indice = isEmptyAlquiler(alquileres, tamAlq);

        if(indice == -1){
            printf("\nNO HAY LUGAR!! \n\n");
        }
        else{
            mostrarJuegos(juegos, tamJuego, categorias, tamCat);

            getInt(&idJuego, "Ingrese ID: ", "Error. Reingrese ID: ");
            indiceJuego = buscarIdJuego(juegos, tamJuego, idJuego);
            while(indiceJuego == -1){
                printf("No existe ese juego!!");
                getInt(&idJuego, "Ingrese ID: ", "Error. Reingrese ID: ");
                indiceJuego = buscarIdJuego(juegos, tamJuego, idJuego);
            }
                mostrarClientes(clientes, tamCli, localidades, tamLoc);
                printf("\n");
                getInt(&idCliente, "Ingrese ID cliente: ", "Error. Reingrese ID Cliente: ");
                indiceCli = buscarIdCliente(clientes, tamCli, idCliente);

                while(indiceCli == -1){
                    printf("No existe ese Cliente!!");
                    getInt(&idCliente, "Ingrese ID cliente: ", "Error. Reingrese ID Cliente: ");
                    indiceCli = buscarIdCliente(clientes, tamCli, idCliente);
                }

                printf("Ingrese Fecha dd/mm/aaaa: ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

                alquileres[indice] = newAlquiler(idAlquiler, idJuego, idCliente, fecha);
                todoOk = 1;


        }
        if(todoOk){
                printf("\n\nALTA EXITOSA !!! \n\n");
            }

    return todoOk;
}

eAlquiler newAlquiler(int idAlquiler, int idJuego, int idCliente, eFecha fecha){
    eAlquiler aux;

    aux.idAlquiler = idAlquiler + 1;

    aux.idJuego = idJuego;
    aux.idCliente = idCliente;
    aux.fecha.dia = fecha.dia;
    aux.fecha.mes = fecha.mes;
    aux.fecha.anio = fecha.anio;
    aux.isEmpty = 0;

    return aux;
}

void mostrarAlquiler(eAlquiler alquiler, eJuego juegos[], int tamJuego, eCliente clientes[], int tamCli){
    char descJuego[51];
    char descCli[51];
    cargarDescJuego(alquiler.idJuego, juegos, tamJuego, descJuego);
    cargarDescCliente(alquiler.idCliente, clientes, tamCli, descCli);
    printf(" %2d     %10s      %10s     %02d/%02d/%d  \n", alquiler.idAlquiler, descJuego, descCli, alquiler.fecha.dia, alquiler.fecha.mes, alquiler.fecha.anio);
}

void mostrarAlquileres(eAlquiler alquileres[], int tamAlq, eCliente clientes[], int tamCli, eJuego juegos[], int tamJuego){
    int cont = 0;
    printf("  ID        JUEGO           CLIENTE       FECHA \n");
    for(int i=0; i<tamAlq; i++){
        if(alquileres[i].isEmpty == 0){
            mostrarAlquiler(alquileres[i], juegos, tamJuego, clientes, tamCli);
        cont++;
        }

    }
    if(!cont){
        printf("NO HAY ALQUILERES QUE MOSTRAR\n\n");
    }
}


int hardcodearAlquileres( eAlquiler alquileres[], int tamAlq, int cantidad){
    int cont = 0;

    eAlquiler aux[]=
    {
       {400,   2000,10,{12,10,2019},0},
       {401,   2001, 3,{21,10,2019},0},
       {402,   2008, 8,{6,10,2019}, 0},
       {403,   2003,10,{4,10,2019}, 0},
       {404,   2004, 6,{3,10,2019}, 0},
       {405,   2000, 5,{21,10,2019},0},
       {406,   2003, 2,{16,10,2019},0},
       {407,   2005, 3,{19,10,2019},0},
       {408,   2009, 4,{24,10,2019},0},
       {409,   2004, 1,{25,10,2019},0}
    };

    if( cantidad <= 10 && tamAlq >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            alquileres[i] = aux[i];
            cont++;
        }
    }

    return cont;
}
