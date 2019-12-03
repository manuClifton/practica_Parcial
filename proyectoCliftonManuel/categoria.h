#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED


typedef struct{
    int idCategoria;
    char descripcion[51];
}eCategoria;

int cargarDescCategoria(int idCategoria, eCategoria categorias[], int tamCat, char desc[]);
void mostrarCategorias(eCategoria categorias[], int tamCat);
void mostrarCategoria(eCategoria categoria);


#endif // CATEGORIA_H_INCLUDED
