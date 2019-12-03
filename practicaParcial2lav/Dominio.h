#include "LinkedList.h"

#ifndef DOMINIO_H_INCLUDED
#define DOMINIO_H_INCLUDED

typedef struct{
    int id;
    char dominio[7];
    int anio;
    char tipo;
}eDominio;

eDominio* newDominio();
eDominio* newDominio_Parametros(char* id,char* dominio,char* anio,char* tipo);


void showDominio(eDominio* dom);
void showDominios(LinkedList* pArrayLinkedDominio);

int eDominio_setId(eDominio* listaDominio,int id);
int eDominio_getId(eDominio* listaDominio,int* id);

int eDominio_setDominio(eDominio* listaDominio, char* dominio);
int eDominio_getDominio(eDominio* listaDominio,char* dominio);

int eDominio_getAnio(eDominio* listaDominio,int* anio);
int eDominio_setAnio(eDominio* listaDominio,int anio);

int eDominio_setTipo(eDominio* listaDominio,char* tipo);
int eDominio_getTipo(eDominio* listaDominio,char* tipo);

int setearTipo(void* dom);
//void* seteaTipo(void* e);

int filterTipo(void* e);

#endif // DOMINIO_H_INCLUDED
