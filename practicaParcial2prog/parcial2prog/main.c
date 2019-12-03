#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// punto 1
typedef struct{
    int codigo;
    char marca[20];
    char modelo[20];
    int capacidad;
}ePendrive;



///////////////////////////// PROTOTIPOS

ePendrive* newPendrive();
ePendrive* newPendriveParam(int codigo, char* marca, char* modelo, int capacidad);

int main()
{

    // punto 2
/*
    int* aux;
    int* enteros = (int*) malloc(sizeof(int)*5);

    for(int i=0; i<5; i++){
        *(enteros + i) = 10;
    }

    for(int i=0; i<5; i++){
        printf(" %d ", *(enteros +i));
    }
    printf("\n\n");


    aux = (int*) realloc(enteros, sizeof(int)*10);
    if(aux != NULL){
        enteros = aux;

    }

    for(int i=5; i<10; i++){
        *(enteros +i) = 9;
    }

    for(int i=0; i<10; i++){
        printf(" %d ", *(enteros +i));
    }
    printf("\n\n");
    free(enteros);
    free(aux);
*/
////////////////////////   BINARIO
    FILE* archivo;
    ePendrive* p1;
    int cant;
    // CARGO EL PUNTERO A ESTRUCTURA PEDRIVE
    p1 = newPendriveParam(03, "HP", "JHQ-4", 250);
    // ABRO EL ARCHUVO
    archivo = fopen("archivo.bin","wb");
    // ESCRIBO EN EL ARCHIVO BINARIO
    if(archivo != NULL){
        while(!feof(archivo)){
            cant = fwrite(p1, sizeof(ePendrive), 1, archivo);
            if(cant < 1){
                    if(feof(archivo)){
                    break;
                }
            }
        }
    }
    fclose(archivo);// CIERRO EL ARCHUVO

    // LEEO DE EL ARCHIVO BINARIO
    archivo = fopen("archivo.bin", "rw");
    if(archivo != NULL){
        while(!feof(archivo)){
            fread(p1, sizeof(ePendrive), 1, archivo);
            printf(" %d  %10s    %10s    %d \n\n", p1->codigo, p1->marca, p1->modelo, p1->capacidad);
        }
    }
    fclose(archivo);







    //////////////////7 TEXTO
    FILE* archivoTXT;
    ePendrive* p2 = NULL;
    int cantidad;
    // ABRO EL ARCHIVO Y GUARDO EN EL ARCHIVO
    archivoTXT = fopen("archivoTXT.txt","w");
    if(archivoTXT != NULL){
        fprintf(archivoTXT, " %d, %s, %s, %d ", p1->codigo,p1->marca, p1->modelo, p1->capacidad);
    }
    fclose(archivoTXT);

    // ABRO EL ARCHIVO Y LEO DE EL
    char buffer[4][20];

    archivoTXT = fopen("archivoTXT.txt","r");
    if(archivoTXT != NULL){
            while(!feof(archivoTXT)){
                cantidad = fscanf(archivoTXT, "%[^,], %[^,], %[^,], %[^\n], \n", buffer[0], buffer[1], buffer[2], buffer[3]);
                if(cantidad < 4){
                        if(feof(archivoTXT)){
                            break;
                        }
                    }
                p2 = newPendriveParam(atoi(buffer[0]), buffer[1], buffer[2], atoi(buffer[3]));
                printf(" %d  %s  %s   %d  \n",p2->codigo, p2->marca, p2->modelo, p2->capacidad);
            }


    }
    fclose(archivoTXT);







    /////////////////////////
    int num;
    int* puntero;
    puntero = &num;

    *puntero = 5;
    printf(" %d \n", num);


    return 0;
}





// punto 1
ePendrive* newPendrive(){
    ePendrive* pen;

    pen = (ePendrive*) malloc(sizeof(ePendrive));

    if(pen != NULL){
        pen->codigo = 0;
        strcpy( pen->marca, "");
        strcpy( pen->modelo, "");
        pen->capacidad = 0;
    }
    return pen;
}

ePendrive* newPendriveParam(int codigo, char* marca, char* modelo, int capacidad){
    ePendrive* nuevoPen = newPendrive();

    if(nuevoPen != NULL){
        nuevoPen->codigo = codigo;
        strcpy(nuevoPen->marca, marca);
        strcpy(nuevoPen->modelo, modelo);
        nuevoPen->capacidad = capacidad;
    }
    return nuevoPen;
}
