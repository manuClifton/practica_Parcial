#include "LinkedList.h"

#ifndef CACHORRO_H_INCLUDED
#define CACHORRO_H_INCLUDED

typedef struct{
    int id;
    char nombre[30];
    int dias;
    char raza[30];
    char reservado[30];
    char genero;
}eCachorro;

   int eCachorro_setId(eCachorro* listaCachorros,int id);
int eCachorro_getId(eCachorro* listaCachorros,int* id);
int eCachorro_setNombre(eCachorro* listaCachorros, char* nombre);
int eCachorro_getNombre(eCachorro* listaCachorros,char* nombre);
int eCachorro_getDias(eCachorro* listaCachorros,int* dias);
int eCachorro_setDias(eCachorro* listaCachorros,int dias);
 int eCachorro_setRaza(eCachorro* listaCachorros,char* raza);
 int eCachorro_getRaza(eCachorro* listaCachorros,char* raza);
 int eCachorro_setReservado(eCachorro* listaCachorros,char* reservado);
 int eCachorro_getReservado(eCachorro* listaCachorros,char* reservado);
 int eCachorro_getGenero(eCachorro* listaCachorros,char* genero);
 int eCachorro_setGenero(eCachorro* listaCachorros,char* genero);

 int filterMayor45(void* e);
 int filterMacho(void* e);
 int filterCallejeros(void* e);

 int eCachorro_getIdMayor(eCachorro* listaCachorros,int* id);

eCachorro* newCachorro();
eCachorro* newCachorro_Parametros(char* id,char* nombre,char* dias,char* raza, char* reservado, char* genero);
void showCachorro(eCachorro* perro);
void showCachorros(LinkedList* pArrayLinkedCachorros);


#endif // CACHORRO_H_INCLUDED
