#include "localidad.h"

#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED



typedef struct{
    int idCliente;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono[21];
    char domicilio[51];
    int idLocalidad;
    int isEmpty;
}eCliente;



int altaCliente(eCliente clientes[], int tamCli, int idCliente, eLocalidad localidades[], int tamLoc);
int isEmptyCliente(eCliente clientes[], int tamCli);
int inicializarClientes(eCliente clientes[], int tamCli);
eCliente newCliente(int idCliente, char nombre[], char apellido[], char sexo, char telefono[], char domicilio[], int idLocalidad);
void ordenarClientes(eCliente cli[], int tamCli);
void mostrarClientes(eCliente clientes[], int tamCli, eLocalidad localidades[], int tamLoc);
void mostrarCliente(eCliente cliente, eLocalidad localidades[], int tamLoc);
int hardcodearClientes( eCliente clientes[], int tamCli, int cantidad);
int bajaCliente(eCliente clientes[], int tamCli, eLocalidad localidades[], int tamLoc);
int buscarIdCliente(eCliente clientes[], int tamCli, int idCliente);
int modificarCliente(eCliente clientes[], int tamCli, eLocalidad localidades[], int tamLoc);
int cargarDescCliente(int idCliente, eCliente clientess[], int tamCli, char desc[]);
int subMenu();
#endif // CLIENTE_H_INCLUDED
