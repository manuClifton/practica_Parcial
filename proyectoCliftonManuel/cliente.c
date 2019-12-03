#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "cliente.h"
#include "biblioteca.h"


int inicializarClientes(eCliente clientes[], int tamCli){
    int rta = 0;
    for(int i=0; i<tamCli; i++){
        clientes[i].isEmpty = 1;
        if(i == tamCli -1){
            rta=1;
        }
    }
    return rta;
}

int isEmptyCliente(eCliente clientes[], int tamCli){
    int index = -1;
    for(int i=0; i<tamCli; i++){
        if(clientes[i].isEmpty == 1){
            index = i;
            break;
        }
    }
    return index;
}



int altaCliente(eCliente clientes[], int tamCli, int idCliente, eLocalidad localidades[], int tamLoc){
    int todoOk = 0;
    int indice;
    int idLocalidad;
    int esta;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono[21];
    char domicilio[51];

        system("cls");
        printf("******* ALTA *******\n\n");

        indice = isEmptyCliente(clientes, tamCli);

        if(indice == -1){
            printf("\nNO HAY LUGAR!! \n\n");
        }
        else{
            getString(nombre, "Ingrese Nombre: ", "Error. Reingrese nombre hasta 50 caracteres: ", 3, 50);

            getString(apellido, "Ingrese Apellido: ", "Error. Reingrese Apellido hasta 50 caracteres: ", 3, 50);

            getCharSex(&sexo, "Ingrese Sexo: ", "Error. Ingrese Sexo.  S o N: ", 'F', 'M');

            getString(telefono, "Ingrese Telefono: ", "Error. Reingrese Telefono (21 numeros): ", 10,21);
            //getIntRange(&telefono, "Ingrese Telefono: ", "Error. Reingrese Telefono (21 numeros): ", 10,21);

            getString(domicilio, "Ingrese Direccion: ", "Error. Reingrese Direccion: ", 10, 51);

            mostrarLocalidades(localidades, tamLoc);


            getInt(&idLocalidad, "\nIngrese ID: ", "Error. Reingrese ID: ");

            esta = buscarIdLocalidad(localidades, tamLoc, idLocalidad);

            while(esta == -1){
                getInt(&idLocalidad, "\nIngrese ID: ", "Error. Reingrese ID: ");
                esta = buscarIdLocalidad(localidades, tamLoc, idLocalidad);
            }


            clientes[indice] = newCliente(idCliente, nombre, apellido, sexo, telefono, domicilio, idLocalidad);
            todoOk = 1;
        }
        if(todoOk){
                printf("\n\nALTA EXITOSA !!! \n\n");
            }

    return todoOk;
}

eCliente newCliente(int idCliente, char nombre[], char apellido[], char sexo, char telefono[], char domicilio[], int idLocalidad){
    eCliente aux;

    aux.idCliente = idCliente + 1;
    strcpy(aux.nombre, nombre);
    strcpy(aux.apellido, apellido);
    aux.sexo = sexo;
    strcpy(aux.telefono, telefono);
    strcpy(aux.domicilio, domicilio);
    aux.idLocalidad = idLocalidad;

    aux.isEmpty = 0;

    return aux;
}



void mostrarCliente(eCliente cliente, eLocalidad localidades[], int tamLoc){
    char descLoc[51];
    cargarDescLocalidad(cliente.idLocalidad, localidades, tamLoc, descLoc);
    printf(" %2d  %10s    %10s     %4c     %10s      %14s       %10s  \n", cliente.idCliente, cliente.nombre, cliente.apellido, cliente.sexo, cliente.telefono, cliente.domicilio, descLoc);
}

void mostrarClientes(eCliente clientes[], int tamCli, eLocalidad localidades[], int tamLoc){
    int cont = 0;

    printf(" ID       NOMBRE      APELLIDO      SEXO    TELEFONO          DOMICILIO          LOCALIDAD \n");

    ordenarClientes(clientes, tamCli);

    for(int i=0; i<tamCli; i++){
        if(clientes[i].isEmpty == 0){
            mostrarCliente(clientes[i], localidades, tamLoc);
            cont++;
        }
    }
    if(!cont){
        printf("NO HAY CLIENTES QUE MOSTRAR\n\n");
    }
}



int bajaCliente(eCliente clientes[], int tamCli, eLocalidad localidades[], int tamLoc){
    int rta = 0;
    int idCliente;
    int esta;
    char confirma;

    getInt(&idCliente, "Ingrese ID del Cliente: ", "Error. Ingrese ID del cliente: ");

    esta = buscarIdCliente(clientes, tamCli, idCliente);

    if(esta != -1){

        mostrarCliente(clientes[esta], localidades, tamLoc);

        getChar(&confirma, "Confirma baja?  S o N: ", "Error. Reingrese S o N: ", 'S', 'N');

        if(confirma == 'S')
        {
            clientes[esta].isEmpty = 1;
            printf("BAJA EXITOSA!! \n\n");
            rta = 1;
        }
        else
        {
            printf("\nLA ELIMINACION HA SIDO CANCELADA\n");
        }

    }
    else{
        printf("NO EXISTE ESE CLIENTE!! \n\n");
        system("pause");
    }
    return rta;
}



int buscarIdCliente(eCliente clientes[], int tamCli, int idCliente){

    int indice = -1;

    for(int i=0; i<tamCli; i++){
        if(clientes[i].idCliente == idCliente){
            indice = i;
            break;
        }
    }
    return indice;
}

int modificarCliente(eCliente clientes[], int tamCli, eLocalidad localidades[], int tamLoc){
    int todoOk = 0;
    int esta;
    int idCliente;
    int flag = 0;

    system("cls");
    printf("************* MODIFICACION *************\n");

    getInt(&idCliente, "Ingrese ID del Cliente: ", "Error. Ingrese ID cliente: ");


    esta = buscarIdCliente(clientes, tamCli, idCliente);

    if(esta != -1){

        mostrarCliente(clientes[esta], localidades, tamLoc);

        switch(subMenu()){
        case 1:
            getString(clientes[esta].nombre, "Ingrese Nuevo de Nombre: ", "Error. Reingrese Nuevo nombre: ", 3, 51);
            todoOk = 1;
            flag = 1;
            break;
        case 2:
            getString(clientes[esta].apellido, "Ingrese Nuevo de Apellido: ", "Error. Reingrese Nuevo Apellido: ", 3, 51);
            todoOk = 1;
            flag = 2;
            break;
        case 3:
            // TELEGONO
            getString(clientes[esta].telefono, "Ingrese Telefono: ", "Error. Reingrese Telefono (21 numeros): ", 10,21);
            //getIntRange(&clientes[esta].telefono,"Ingrese Nuevo de Telefono: ", "Error. Reingrese Nuevo Telefono: ", 10, 21);
            todoOk = 1;
            flag = 3;
            break;
        case 4:
            printf("\nSE CANCELO MODIFICAION\n\n");
            break;
        default:
            printf("\nOPCION INVALIDA !! \n\n");
            break;
        }
    }
    else{
        printf("NO EXISTE CLIENTE CON ESE ID\n\n");
    }

    if(flag == 1){
            printf("\nSE MODIFICO NOMBRRE CON EXITO !! \n\n");

        }else if(flag == 2){
            printf("\nSE MODIFICO APELLIDO CON EXITO !!\n\n");
        }
        else if(flag == 3){
            printf("\nSE MODIFICO TELEFONO CON EXITO !!\n\n");
        }
    return todoOk;
}

int cargarDescCliente(int idCliente, eCliente clientes[], int tamCli, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tamCli; i++){
        if( idCliente == clientes[i].idCliente){
            strcpy(desc, clientes[i].nombre);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

void ordenarClientes(eCliente cli[], int tamCli){
    eCliente aux;

        for(int i=0; i<tamCli-1; i++){
            for(int j=i+1; j<tamCli; j++){
                if(stricmp(cli[i].apellido, cli[j].apellido) > 0){
                    aux = cli[i];
                    cli[i] = cli[j];
                    cli[j] = aux;
                }
                else if( stricmp(cli[i].apellido, cli[j].apellido) == 0 && stricmp(cli[i].nombre, cli[j].nombre) > 0 ){
                    aux = cli[i];
                    cli[i] = cli[j];
                    cli[j] = aux;
                }
            }
        }
}

int subMenu(){
    int option;

        printf("1- NOMBRE\n");
        printf("2- APELLIDO\n");
        printf("3- TELEFONO\n");
        printf("4- CANCELAR\n");
        getIntRange(&option, "Ingrese Opcion: ", "Error. Reingrese Opcion: ", 1, 4);

    return option;
}


int hardcodearClientes( eCliente clientes[], int tamCli, int cantidad){
    int cont = 0;

    eCliente aux[]=
    {
       {1,   "PABLO",    "LESCANO",   'M', "1160313333", "San Juan 284",     201, 0},
       {2,   "LUCAS",    "LUGUERZIO", 'M', "1150315433", "Lorenzo 351",      202, 0},
       {3,   "ROMINA",   "LEDESMA",   'F', "1167413333", "San Jose 3617",    203, 0},
       {4,   "EZEQUIEL", "PEREZ",     'M', "1140313953", "Corrientes 450",   204, 0},
       {5,   "ANA",      "LOPEZ",     'F', "1174314125", "Julio 5000",       200, 0},
       {6,   "RAQUEL",   "GONZALES",  'F', "1161314569", "Santa 3500",       201, 0},
       {7,   "MIGUEL",   "GOMEZ",     'M', "1165213458", "Medrano 2105",     203, 0},
       {8,   "CRISTINA", "MONTANIA",  'F', "1152313336", "San Juan 865",     204, 0},
       {9,   "PEDRO",    "MONTANIA",  'M', "1160357896", "Libertad 65",      200, 0},
       {10,  "SABRINA",  "ESCOBAR",   'F', "1121513612", "Av Brazil 444",    202, 0}
    };

    if( cantidad <= 10 && tamCli >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            clientes[i] = aux[i];
            cont++;
        }
    }

    return cont;
}
