
#include "localidad.h"

int cargarDescLocalidad(int idLocalidad, eLocalidad localidades[], int tamLoc, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tamLoc; i++){
        if( idLocalidad == localidades[i].id){
            strcpy(desc, localidades[i].nombre);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}



int buscarIdLocalidad(eLocalidad localidades[], int tamLoc, int idLocalidad){

    int indice = -1;

    for(int i=0; i<tamLoc; i++){
        if(localidades[i].id == idLocalidad){
            indice = i;
            break;
        }
    }
    return indice;
}




void mostrarLocalidad(eLocalidad localidad){
    printf("  %d     %10s  \n",  localidad.id,   localidad.nombre);
}

void mostrarLocalidades(eLocalidad localidades[], int tamLoc){
     int cont = 0;

    printf(" ID    LOCALIDAD \n");

    for(int i=0; i<tamLoc; i++){
        mostrarLocalidad(localidades[i]);
        cont++;

    }
    if(!cont){
        printf("NO HAY LOCALIDADES QUE MOSTRAR\n\n");
    }
}
