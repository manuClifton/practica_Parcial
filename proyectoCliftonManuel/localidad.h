#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED

typedef struct{
    int id;
    char nombre[31];
}eLocalidad;


int cargarDescLocalidad(int idLocalidad, eLocalidad localidades[], int tamLoc, char desc[]);
int buscarIdLocalidad(eLocalidad localidades[], int tamLoc, int idLocalidad);
void mostrarLocalidades(eLocalidad localidades[], int tamLoc);
void mostrarLocalidad(eLocalidad localidad);

#endif // LOCALIDAD_H_INCLUDED
