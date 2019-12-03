#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#define TAMVUELO 15
#define TAMDES 4
#define TAMPILOTO 4

#include "biblioteca.h"
#include "menu.h"

///  ESTRUCTURAS
typedef struct{
    int idPiloto;
    char nombre[30];
}ePiloto;

typedef struct{
    int idVuelo;
    int idDestino;
    int idPiloto;
    int partida;
    int llegada;
    char estadoVuelo[30];
    int isEmpty;
}eVuelo;

typedef struct{
    int idDestino;
    char descripcion[30];
    float precio;
}eDestino;


/////// PROTOTIPO
// VUELOS
void mostrarVuelos(eVuelo vuelos[], int tamVuelo, ePiloto pilotos[], int tamPil, eDestino destinos[], int tamDes);
void mostrarVuelo(eVuelo vuelo, ePiloto pilotos[], int tamPil, eDestino destinos[], int tamDes);


int inicializarVuelos(eVuelo vuelos[], int tamVuelo);
int hardcodearVuelos( eVuelo vuelos[], int tamVuelo, int cantidad);
int altaVuelo(eVuelo vuelos[], int tamVuelo, int idVuelo, eDestino destinos[], int tamDes, ePiloto pilotos[], int tamPil);
eVuelo newVuelo(int idVuelo, int idDestino, int idPiloto, int partida, int llegada, char estado[]);
int isEmptyVuelo(eVuelo vuelos[], int tamVuelo);

int buscarVuelo(eVuelo vuelos[], int tamVuelo, int idVuelo);
int bajaVuelo(eVuelo vuelos[], int tamVuelo, ePiloto pilotos[], int tamPil, eDestino destinos[], int tamDes);

int modificarVuelo(eVuelo vuelos[], int tamVuelo, ePiloto pilotos[], int tamPil, eDestino destinos[], int tamDes);

void ordenarVuelos(eVuelo vue[], int tamVuelo);

// PILOTO
void mostrarPiloto(ePiloto piloto);
void mostrarPilotos(ePiloto pilotos[], int tamPil);
int cargarDescPiloto(int idPiloto, ePiloto pilotos[], int tamPil, char desc[]);
int buscarIdPiloto(ePiloto pilotos[], int tamPil, int idPiloto);
// DESTINO
void mostrarDestino(eDestino destino);
void mostrarDestinos(eDestino destinos[], int tamDes);
int cargarDescDestino(int idDestino, eDestino destinos[], int tamDes, char desc[]);
int buscarIdDestino(eDestino destinos[], int tamDes, int idDestino);


////////////////////////      INFORMES
void mostrarConsultas(eVuelo vuelos[], int tamVuelo, eDestino destinos[], int tamDes, ePiloto pilotos[], int tamPil);

void vuelosDePilotoSeleccionado(eVuelo vuelos[], int tamVuelo, ePiloto pilotos[], int tamPil, eDestino destinos[], int tamDes);


void pilotosDeDestinoSeleccionado(eVuelo vuelos[], int tamVuelo, ePiloto pilotos[], int tamPil, eDestino destinos[], int tamDes);

void recaudacionPorPiloto(ePiloto pilotos[], int tamPil, eVuelo vuelos[], int tamVuelo, eDestino destinos[], int tamDes);
float sumarCantidadDestino(int idPiloto, eVuelo vuelos[], int tamVuelo, eDestino destinos[], int tamDes);

void destinoMasElegido(eDestino destinos[], int tamDes, eVuelo vuelos[], int tamVuelo);
int cantidadDestinos(int idDestino, eVuelo vuelos[], int tamVuelo);

//////////////////////////////// MAIN

int main()
{
    char salir = 'N';
    int idVuelo = 1000;
    int flag = 0;
    eDestino destinos[TAMDES]= {
        {1, "Cancun", 25000},
        {2, "Miami", 150000},
        {3, "Rio", 72000},
        {4, "Dominicana", 85000}
    };

    ePiloto pilotos[TAMPILOTO]= {
        {200, "Juan"},
        {201, "Esteban"},
        {202, "Romina"},
        {203, "Federico"}
    };

    eVuelo vuelos[TAMVUELO];

    inicializarVuelos(vuelos, TAMVUELO);

    idVuelo = idVuelo + hardcodearVuelos(vuelos, TAMVUELO, 15);

    do{
             switch( menu()){
                case 1:
                        //ALTA
                        if(altaVuelo(vuelos, TAMVUELO, idVuelo, destinos, TAMDES, pilotos, TAMPILOTO)){
                            idVuelo++;
                            flag=1;
                        }

                    break;
                case 2:
                        //BAJA
                        if(flag){
                            bajaVuelo(vuelos, TAMVUELO, pilotos, TAMPILOTO, destinos, TAMDES);
                        }
                        else{
                            printf("\nDEBE DAR DE ALTA UN VUELO\n\n");
                        }
                    break;
                case 3:
                      //MODIFICAR
                      if(flag){
                        modificarVuelo(vuelos, TAMVUELO, pilotos, TAMPILOTO, destinos, TAMDES);
                      }
                      else{
                        printf("\nDEBE DAR DE ALTA UN VUELO\n\n");
                      }
                    break;
                case 4:
                      //LISTAR VUELOS
                      if(flag){
                        mostrarVuelos(vuelos, TAMVUELO, pilotos, TAMPILOTO, destinos, TAMDES);
                      }
                      else{
                        printf("\nDEBE DAR DE ALTA UN VUELO\n\n");
                      }
                    break;
                case 5:
                    if(flag){
                        mostrarConsultas(vuelos, TAMVUELO, destinos, TAMDES, pilotos, TAMPILOTO);
                    }
                    else{
                        printf("\nDEBE DAR DE ALTA UN VUELO\n\n");
                      }
                    break;
                case 0:

                    getChar(&salir, "Confirma Salir ?  S o N: ", "Error. Confirma Salir ?  S o N: ",'S','N');
                    break;
                default:
                    printf("\nOpcion Invalida!\n\n");
                    break;
             }
        system("pause");
    }while(salir == 'N');


    return 0;
}// FIN MAIN


// DESARROLLO


int inicializarVuelos(eVuelo vuelos[], int tamVuelo){
    int rta = 0;
    for(int i=0; i<tamVuelo; i++){
        strcpy(vuelos[i].estadoVuelo, "Activo");
        if(i == tamVuelo -1){
            rta=1;
        }
    }
    return rta;
}


void mostrarVuelo(eVuelo vuelo, ePiloto pilotos[], int tamPil, eDestino destinos[], int tamDes){
    char descDes[51];
    char descPil[51];
    cargarDescDestino(vuelo.idDestino, destinos, tamDes, descDes);
    cargarDescPiloto(vuelo.idPiloto, pilotos, tamPil, descPil);
    printf(" %2d  %10s    %10s     %4d     %10d      %14s   \n", vuelo.idVuelo, descDes, descPil, vuelo.partida, vuelo.llegada, vuelo.estadoVuelo);
}

void mostrarVuelos(eVuelo vuelos[], int tamVuelo, ePiloto pilotos[], int tamPil, eDestino destinos[], int tamDes){
    int cont = 0;

    printf(" ID       DESTINO      PILOTO      PARTIDA      LLEGADA        ESTADO \n");

    ordenarVuelos(vuelos, tamVuelo);

    for(int i=0; i<tamVuelo; i++){
        if(vuelos[i].isEmpty == 0){
            mostrarVuelo(vuelos[i], pilotos, tamPil, destinos, tamDes);
            cont++;
        }
    }
    if(!cont){
        printf("NO HAY VUELOS QUE MOSTRAR\n\n");
    }
}

int cargarDescDestino(int idDestino, eDestino destinos[], int tamDes, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tamDes; i++){
        if( idDestino == destinos[i].idDestino){
            strcpy(desc, destinos[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

int cargarDescPiloto(int idPiloto, ePiloto pilotos[], int tamPil, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tamPil; i++){
        if( idPiloto == pilotos[i].idPiloto){
            strcpy(desc, pilotos[i].nombre);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}


///////////////// HARDCODEAR VUELO

int hardcodearVuelos( eVuelo vuelos[], int tamVuelo, int cantidad){
    int cont = 0;

    eVuelo aux[]=
    {
       {1000,   1,200, 22,  7,    "ACTIVO", 0},
       {1001,   2,201, 15, 12,  "CANCELADO",0},
       {1002,   3,203,  7, 16, "SUSPENDIDO",0},
       {1003,   4,202, 18, 20,     "ACTIVO",0},
       {1004,   1,200, 13, 17,   "DEMORADO",0},
       {1005,   2,201, 14, 13,     "ACTIVO",0},
       {1006,   3,201, 21,  1,   "DEMORADO",0},
       {1007,   4,203, 18,  2,     "ACTIVO",0},
       {1008,   1,202, 12,  6,     "ACTIVO",0},
       {1009,   2,201, 23, 18,  "CANCELADO",1},
       {1010,   2,202, 23, 13,  "CANCELADO",1},
       {1011,   2,203, 23, 11,  "CANCELADO",1},
       {1012,   2,202, 23,  2,  "CANCELADO",1},
       {1013,   2,201, 23,  8,  "CANCELADO",1},
       {1014,   2,200, 23,  9,  "CANCELADO",1},
    };

    if( cantidad <= 15 && tamVuelo >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            vuelos[i] = aux[i];
            cont++;
        }
    }

    return cont;
}


///////////////////////////////////////////////// ALTA

int altaVuelo(eVuelo vuelos[], int tamVuelo, int idVuelo, eDestino destinos[], int tamDes, ePiloto pilotos[], int tamPil){
    int todoOk = 0;
    int indice;
    int esta;

    int idDestino;
    int idPiloto;
    int partida;
    int llegada;


        system("cls");
        printf("******* ALTA VUELO *******\n\n");

        indice = isEmptyVuelo(vuelos, tamVuelo);

        if(indice == -1){
            printf("\nNO HAY LUGAR!! \n\n");
        }
        else{

        mostrarDestinos(destinos, tamDes);

        getInt(&idDestino, "\nIngrese ID: ", "Error. Reingrese ID: ");

        esta = buscarIdDestino(destinos, tamDes, idDestino);

        while(esta == -1){
            printf("EROR. No se encontro el Destino.");
            getInt(&idDestino, "\nIngrese ID: ", "Error. Reingrese ID: ");
            esta = buscarIdDestino(destinos, tamDes, idDestino);
        }

        mostrarPilotos(pilotos, tamPil);

        getInt(&idPiloto, "\nIngrese ID: ", "Error. Reingrese ID: ");

        esta = buscarIdPiloto(pilotos, tamPil, idPiloto);

        while(esta == -1){
            printf("EROR. No se encontro el Piloto.");
            getInt(&idPiloto, "\nIngrese ID: ", "Error. Reingrese ID: ");
            esta = buscarIdPiloto(pilotos, tamPil, idPiloto);
        }

        getIntRange(&partida, "Ingrese Hora de partida: ", "Error. Reingrese Hora entre 0 y 24:", 0, 24);

        getIntRange(&llegada, "Ingrese Hora de llegada: ", "Error. Reingrese Hora llegada 0 y 24:", 0, 24);


            vuelos[indice] = newVuelo(idVuelo, idDestino, idPiloto, partida, llegada, "ACTIVO");
            todoOk = 1;
        }

        if(todoOk){
                printf("\n\nALTA EXITOSA !!! \n\n");
            }

    return todoOk;
}

eVuelo newVuelo(int idVuelo, int idDestino, int idPiloto, int partida, int llegada, char estado[]){
    eVuelo aux;

    aux.idVuelo = idVuelo + 1;
    aux.idDestino = idDestino;
    aux.idPiloto = idPiloto;
    aux.partida = partida;
    aux.llegada = llegada;
    strcpy(aux.estadoVuelo, estado);
    aux.isEmpty = 0;

    return aux;
}

int isEmptyVuelo(eVuelo vuelos[], int tamVuelo){
    int index = -1;
    for(int i=0; i<tamVuelo; i++){
        if(vuelos[i].isEmpty == 1 ){
            index = i;
            break;
        }
    }
    return index;
}



/////////////////////////////////////////////// BAJA VUELO
int bajaVuelo(eVuelo vuelos[], int tamVuelo, ePiloto pilotos[], int tamPil, eDestino destinos[], int tamDes){
    int rta = 0;
    int idVuelo;
    int esta;
    char confirma;

    mostrarVuelos(vuelos, tamVuelo, pilotos, tamPil, destinos, tamDes);

    getInt(&idVuelo, "Ingrese ID: ", "Error. Ingrese ID: ");

    esta = buscarVuelo(vuelos, tamVuelo, idVuelo);

    if(esta != -1){

        mostrarVuelo(vuelos[esta], pilotos, tamPil, destinos, tamDes);

        getChar(&confirma, "Confirma baja?  S o N: ", "Error. Reingrese S o N: ", 'S', 'N');

        if(confirma == 'S')
        {
            strcpy(vuelos[esta].estadoVuelo, "CANCELADO");
            printf("\n BAJA EXITOSA!! \n\n");
            rta = 1;
        }
        else
        {
            printf("\nLA BAJA HA SIDO CANCELADA\n");
        }

    }
    else{
        printf("NO EXISTE ESE VUELO!! \n\n");
        system("pause");
    }
    return rta;
}

int buscarVuelo(eVuelo vuelos[], int tamVuelo, int idVuelo){

    int indice = -1;

    for(int i=0; i<tamVuelo; i++){
        if(vuelos[i].idVuelo == idVuelo){
            indice = i;
            break;
        }
    }
    return indice;
}

///////////////////////////////////////MODIFICAR
int modificarVuelo(eVuelo vuelos[], int tamVuelo, ePiloto pilotos[], int tamPil, eDestino destinos[], int tamDes){
    int todoOk = 0;
    int esta;
    int idVuelo;
    int flag = 0;
    char nuevoEstado[30];

    system("cls");
    printf("************* MODIFICACION ESTADO DE VUELO *************\n");

    mostrarVuelos(vuelos, tamVuelo, pilotos, tamPil, destinos, tamDes);

    getInt(&idVuelo, "Ingrese ID del Vuelo: ", "Error. Ingrese ID: ");

    esta = buscarVuelo(vuelos, tamVuelo, idVuelo);

    if(esta != -1){

        mostrarVuelo(vuelos[esta], pilotos, tamPil, destinos, tamDes);

        getString(nuevoEstado, "Ingrese Nuevo de Estado: ", "Error. Reingrese Nuevo Estado: ", 5, 11);

        strcpy(vuelos[esta].estadoVuelo, nuevoEstado);
        todoOk = 1;
        flag = 1;
    }
    else{
        printf("NO EXISTE VUELO CON ESE ID\n\n");
    }

    if(flag == 1){
        printf("\nSE MODIFICO ESTADO CON EXITO !! \n\n");
    }

    return todoOk;
}

//////////////////////////////////////////// MOSTRAR DESINOS

void mostrarDestino(eDestino destino){

    printf(" %d     %s     %.2f\n",destino.idDestino, destino.descripcion, destino.precio);
}

void mostrarDestinos(eDestino destinos[], int tamDes){
    int cont = 0;
    printf("  ID       DESTINO        PRECIO\n");
    for(int i=0; i<tamDes; i++){
        mostrarDestino(destinos[i]);
        cont++;
    }
    if(!cont){
        printf("NO HAY DESTINOS QUE MOSTRAR\n\n");
    }
}

int buscarIdDestino(eDestino destinos[], int tamDes, int idDestino){

    int indice = -1;

    for(int i=0; i<tamDes; i++){
        if(destinos[i].idDestino == idDestino){
            indice = i;
            break;
        }
    }
    return indice;
}


void ordenarVuelos(eVuelo vue[], int tamVuelo){
    eVuelo aux;

        for(int i=0; i<tamVuelo-1; i++){
            for(int j=i+1; j<tamVuelo; j++){
                if(vue[i].idVuelo > vue[j].idVuelo){
                    aux = vue[i];
                    vue[i] = vue[j];
                    vue[j] = aux;
                }
            }
        }
}

//////////////////////////////////////////// MOSTRAR PILOTOS


void mostrarPiloto(ePiloto piloto){

    printf(" %d     %s \n", piloto.idPiloto, piloto.nombre);
}

void mostrarPilotos(ePiloto pilotos[], int tamPil){
    int cont = 0;
    printf("  ID       PILOTO\n");
    for(int i=0; i<tamPil; i++){
        mostrarPiloto(pilotos[i]);
        cont++;
    }
    if(!cont){
        printf("NO HAY PILOTOS QUE MOSTRAR\n\n");
    }
}



int buscarIdPiloto(ePiloto pilotos[], int tamPil, int idPiloto){

    int indice = -1;

    for(int i=0; i<tamPil; i++){
        if(pilotos[i].idPiloto == idPiloto){
            indice = i;
            break;
        }
    }
    return indice;
}


/////////////////////////////////////// INFORMES

void mostrarConsultas(eVuelo vuelos[], int tamVuelo, eDestino destinos[], int tamDes, ePiloto pilotos[], int tamPil){
      char salir = 'N';

      do{
             switch( menuInformes()){
           case 'A':
                //vuelos de piloto seleccionado
                vuelosDePilotoSeleccionado(vuelos, tamVuelo, pilotos, tamPil, destinos, tamDes);
            break;
        case 'B':
                pilotosDeDestinoSeleccionado(vuelos, tamVuelo, pilotos, tamPil, destinos, tamDes);
            break;
        case 'C':
                 recaudacionPorPiloto(pilotos, tamPil, vuelos, tamVuelo, destinos, tamDes);
            break;
        case 'D':
                destinoMasElegido(destinos, tamDes, vuelos, tamVuelo);
            break;

        case 'E':
              getChar(&salir,"Desea Salir?  S o N: ","Error. Ingrese si S o N: ", 'S', 'N');
                    printf("\n\n");
            break;
        default:
            printf("\n\nOPCION INVALIDA!! \n\n");
            break;
        }
        system("pause");
    }while(salir == 'N');
}









void vuelosDePilotoSeleccionado(eVuelo vuelos[], int tamVuelo, ePiloto pilotos[], int tamPil, eDestino destinos[], int tamDes){
    int idPiloto;
    int esta;
    int flag=0;

    system("cls");
    printf("***** MOSTRAR VUELO POR PILOTO ******** \n\n");

    mostrarPilotos(pilotos, tamPil);
    getInt(&idPiloto, "\nIngrese ID: ", "Error. Reingrese ID: ");

    esta =  buscarIdPiloto(pilotos, tamPil, idPiloto);

    while(esta == -1){
        printf("EROR. No se encontro Piloto.");
        getInt(&idPiloto, "\nIngrese ID: ", "Error. Reingrese ID: ");
        esta =  buscarIdPiloto(pilotos, tamPil, idPiloto);
    }

    printf(" ID       DESTINO      PILOTO      PARTIDA      LLEGADA        ESTADO \n");

    for(int i=0; i<tamVuelo; i++){
        if(vuelos[i].idPiloto == idPiloto && vuelos[i].isEmpty == 0){
            mostrarVuelo(vuelos[i], pilotos, tamPil, destinos, tamDes);
            flag=1;
        }
    }
    if(!flag){
        printf("\nEL PILOTO NO TIENE VUELOS SELECCIONADOS\n\n");
    }
}


void pilotosDeDestinoSeleccionado(eVuelo vuelos[], int tamVuelo, ePiloto pilotos[], int tamPil, eDestino destinos[], int tamDes){
    int idDestino;
    int esta;
    int flag=0;

    system("cls");
    printf("***** MOSTRAR PILOTO POR DESTINO ******** \n\n");

    mostrarDestinos(destinos, tamDes);

    getInt(&idDestino, "\nIngrese ID: ", "Error. Reingrese ID: ");

    esta =  buscarIdDestino(destinos, tamDes, idDestino);

    while(esta == -1){
        printf("EROR. No se encontro Destino.");
        getInt(&idDestino, "\nIngrese ID: ", "Error. Reingrese ID: ");
        esta =  buscarIdDestino(destinos, tamDes, idDestino);
    }

    printf("  ID       PILOTO\n");

    for(int i=0; i<tamVuelo; i++){
        if(vuelos[i].idDestino == idDestino && vuelos[i].isEmpty == 0){
            for(int j=0; j<tamPil; j++){
                if(pilotos[j].idPiloto == vuelos[i].idPiloto){
                    mostrarPiloto(pilotos[j]);
                    flag = 1;
                }
            }
        }
    }
    if(!flag){
        printf("\nNINGUN PILOTO VOLO A ESE DESTINO\n\n");
    }
}


float sumarCantidadDestino(int idPiloto, eVuelo vuelos[], int tamVuelo, eDestino destinos[], int tamDes){
    float acumulador = 0;

    for(int i=0; i<tamVuelo; i++){
        if(vuelos[i].idPiloto == idPiloto && vuelos[i].isEmpty == 0){
            for(int j=0; j<tamDes; j++){
                if(vuelos[i].idDestino == destinos[j].idDestino){
                    acumulador = acumulador + destinos[j].precio;
                }
            }
        }
    }
    return acumulador;
}


void recaudacionPorPiloto(ePiloto pilotos[], int tamPil, eVuelo vuelos[], int tamVuelo, eDestino destinos[], int tamDes){

    float cantidad[tamPil];

    system("cls");
    printf("***** MOSTRAR RECAUDACION POR CADA PILOTO ******** \n\n");

    for(int i=0; i<tamPil; i++){
       cantidad[i] = sumarCantidadDestino(pilotos[i].idPiloto, vuelos, tamVuelo, destinos, tamDes);
    }

    for(int i=0; i<tamPil; i++){
        printf("Piloto: %s,  Recaudacion: %.2f\n\n", pilotos[i].nombre, cantidad[i]);
    }
}






int cantidadDestinos(int idDestino, eVuelo vuelos[], int tamVuelo){

    int contador = 0;

        for(int j=0; j<tamVuelo; j++){
            if(vuelos[j].idDestino == idDestino && vuelos[j].isEmpty == 0){
                contador++;
            }
        }

    return contador;
}


void destinoMasElegido(eDestino destinos[], int tamDes, eVuelo vuelos[], int tamVuelo){


    int cantidad[tamDes];
    int mayor=0;
    int flag=0;

    system("cls");
    printf("***** DESTINO PREFERIDO ******** \n\n");

    for(int i=0; i<tamDes; i++){
        cantidad[i] = cantidadDestinos(destinos[i].idDestino, vuelos, tamVuelo);
    }

    for(int i=0; i<tamDes; i++){
            if(cantidad[i] > mayor || flag == 0){
                mayor = cantidad[i];
                flag = 1;
            }
    }

        printf("Destino preferido fue elegido %d veces. \n\n", mayor);

        for(int i=0; i<tamDes; i++){
            if(cantidad[i] == mayor){
                mostrarDestino(destinos[i]);
            }
        }
}


