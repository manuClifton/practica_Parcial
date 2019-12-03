#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "biblioteca.h"
#include "alquiler.h"
#include "categoria.h"
#include "cliente.h"
#include "juego.h"
#include "fecha.h"
#include "localidad.h"
#include "informes.h"


#define TAMCAT 5
#define TAMJUEGO 10
#define TAMCLI  12
#define TAMALQ 12
#define TAMLOC 5




////////////////////  INFORMES






///////////////////////// LOCALIDAD



//////////////////////
char menu();


///////////////////////  MAIN
int main()
{
    char salir = 'N';
    int idAlquiler = 399;
    int idCliente = 0;
    int flag = 0;

    eCategoria categorias[TAMCAT]= {
        {1000, "Mesa"},
        {1001, "Azar"},
        {1002, "Estrategia"},
        {1003, "Salon"},
        {1004, "Magia"}

    };

    eJuego juegos[TAMJUEGO]=  {
        {2000, "MONOPOLI", 200, 1000, 0},
        {2001, "POKER", 250, 1001, 0},
        {2002, "TEG", 300, 1002, 0},
        {2003, "BOCHAS", 150, 1003, 0},
        {2004, "LOL", 500, 1004, 0},
        {2005, "LIFE", 200, 1000, 0},
        {2006, "TRUCO", 250, 1001, 0},
        {2007, "ARGENTUM", 300, 1002, 0},
        {2008, "PING-PONG", 150, 1003, 0},
        {2009, "MAGIC HAT", 500, 1004, 0}
    };

    eLocalidad localidades[TAMLOC]= {
        {200, "Matanza"},
        {201, "Lanus"},
        {202, "Congreso"},
        {203, "Palermo"},
        {204, "Boca"},
    };

    eCliente clientes[TAMCLI];
    eAlquiler alquileres[TAMALQ];

    inicializarClientes(clientes, TAMCLI);
    inicializarAlquileres(alquileres, TAMALQ);
    idCliente = idCliente + hardcodearClientes(clientes, TAMCLI, 10);
    idAlquiler = idAlquiler + hardcodearAlquileres(alquileres, TAMALQ, 10);

     do{
        switch(menu()){
        case 'A':
            if(altaCliente(clientes, TAMCLI, idCliente, localidades, TAMLOC)){
                idCliente++;
                flag++;
            }
            break;
        case 'B':
                // MODIFICAR
                modificarCliente(clientes, TAMCLI, localidades, TAMLOC);
            break;
        case 'C':
                 // BAJA CLIENTE
                 if(bajaCliente(clientes, TAMCLI, localidades, TAMLOC)){
                    flag--;
                 }

            break;
        case 'D':
                // LISTAR CLIENTES
                    mostrarClientes(clientes, TAMCLI, localidades, TAMLOC);
            break;
        case 'E':
                // LISTAR JUEGOS
                mostrarJuegos(juegos, TAMJUEGO, categorias, TAMCAT);
            break;
        case 'F':
                mostrarCategorias(categorias, TAMCAT);
            break;
        case 'G':
                if(flag != 0){
                    if(altaAlquileres(alquileres, TAMALQ, idAlquiler, juegos, TAMJUEGO, categorias, TAMCAT, clientes, TAMCLI, localidades, TAMLOC)){
                        idAlquiler++;
                    }
                }else{
                    printf("PRIMERO DEBE DAR DE ALA UN CLIENTE!! \n\n");
                }
            break;
        case 'H':
                mostrarAlquileres(alquileres, TAMALQ, clientes, TAMCLI, juegos, TAMJUEGO);
            break;
        case 'I':
               // INFORMES
               mostrarInformes(clientes, TAMCLI, alquileres, TAMALQ, categorias, TAMCAT, juegos, TAMJUEGO, localidades, TAMLOC);
            break;
        case 'J':
              getChar(&salir,"Desea Salir?  S o N: ","Error. Ingrese si S o N: ", 'S', 'N');
                    printf("\n\n");
            break;
        default:
            printf("\n\nOPCION INVALIDA!! \n\n");
            break;
        }
        system("pause");
     }while(salir == 'N');


    return 0;
}

///////////////////////////// DESARROLLO


char menu(){
    char option;

    system("cls");
    printf("************* PARCIAL *************\n");
    printf("*************   ABM   *************\n");
    printf("A- Alta Cliente\n");
    printf("B- Modificacion Cliente\n");
    printf("C- Baja Cliente\n");
    printf("D- Listar Clientes\n");
    printf("E- Listar Juegos\n");
    printf("F- Listar Categoria\n");
    printf("G- Alta Alquiler\n");
    printf("H- Listar Alquileres\n");
    printf("I- INFORMES\n");
    printf("J-  Salir\n\n");

    getCh(&option,"Ingrese Opcion: ", "Error. Ingrese Opcion: ");

    return option;
}



//////////////////////////////// LOCALIDADES









/////////////////////////////// INFORMES















