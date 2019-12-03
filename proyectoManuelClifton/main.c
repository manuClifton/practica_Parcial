#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "stdlib.h"

#include "LinkedList.h"
#include "biblioteca.h"
#include "Controller.h"
#include "Cachorro.h"
#include "menu.h"


int main()
{

    char salir = 'N';
    int flag = 0;
    int flagCarga1 = 0;
    int flagCarga2 = 0;
    char path[50];

   LinkedList* listaCachorros = ll_newLinkedList();
   LinkedList* listaFiltrarMayor = NULL;
   LinkedList* listaFiltrarMacho = NULL;
   LinkedList* listaFiltrarCallejero = NULL;

   if(listaCachorros != NULL)
    {
    do{
        switch(menu())
        {
        case 1:
            if(!flag){
                    printf("Ingresa el archivo: ");
                    scanf("%s", path);
                    strcat(path, ".csv");
                    if(controller_loadFromText(path, listaCachorros)){
                        printf("\n   **********************\n");
                        printf("   * Cargo Exitosamente *\n");
                        printf("   **********************\n\n");
                        flag=1;
                    }else{
                        printf("\n   *******************\n");
                        printf("   * Error al cargar *\n");
                        printf("   *******************\n\n");
                    }
            }else if(flag){
                        printf("\n   *******************\n");
                        printf("   * YA esta cargado *\n");
                        printf("   *******************\n\n");
            }
            else{
                        printf("\n   *******************\n");
                        printf("   * Error al cargar *\n");
                        printf("   *******************\n\n");
            }
            break;
        case 2:
            if(flag){
                showCachorros(listaCachorros);
            }
            else{
                        printf("\n   *******************\n");
                        printf("   * Primero debe cargar *\n");
                        printf("   *******************\n\n");
            }
            break;

        case 3:
            if(flag && flagCarga1 == 0){
                       listaFiltrarMayor = ll_filter(listaCachorros, filterMayor45);

                       if(controller_saveAsText("mayores.csv", listaFiltrarMayor)){
                            printf("\n   **********************\n");
                            printf("   * Cargo Exitosamente *\n");
                            printf("   **********************\n\n");
                        flagCarga1 = 1;
                       }
                       else{
                            printf("\n   *******************\n");
                            printf("   * Error al cargar *\n");
                            printf("   *******************\n\n");
                       }
            }
            else{
                        printf("\n   *******************\n");
                        printf("   * Primero debe cargar *\n");
                        printf("   *******************\n\n");
            }
            break;
        case 4:
            if(flag && flagCarga2 == 0){
                       listaFiltrarMacho = ll_filter(listaCachorros, filterMacho);
                       if(controller_saveAsText("hembras.csv", listaFiltrarMacho)){
                            printf("\n   **********************\n");
                            printf("   * Cargo Exitosamente *\n");
                            printf("   **********************\n\n");
                        flagCarga1 = 1;
                       }
                       else{
                            printf("\n   *******************\n");
                            printf("   * Error al cargar *\n");
                            printf("   *******************\n\n");
                       }
            }
            else{
                        printf("\n   *******************\n");
                        printf("   * Primero debe cargar *\n");
                        printf("   *******************\n\n");
            }
            break;
        case 5:
            if(flag){
                listaFiltrarCallejero = ll_filter(listaCachorros, filterCallejeros);
                showCachorros(listaFiltrarCallejero);
                 if(controller_saveAsText("callejeros.csv", listaFiltrarCallejero)){
                            printf("\n   **********************\n");
                            printf("   * Cargo Exitosamente *\n");
                            printf("   **********************\n\n");
                        flagCarga1 = 1;
                       }
                       else{
                            printf("\n   *******************\n");
                            printf("   * Error al cargar *\n");
                            printf("   *******************\n\n");
                       }
            }
            else{
                        printf("\n   *******************\n");
                        printf("   * Primero debe cargar *\n");
                        printf("   *******************\n\n");
            }
            break;
        case 6:
                getChar(&salir,"Desea Salir?  S o N: ","Error. Ingrese S o N: ", 'S', 'N');
                printf("\n\n");
        }
        system("pause");
        }while(salir == 'N');

    if(salir == 'S'){
                printf("\n ******************************\n");
                printf("   **********  ADIOS  ***********\n");
                printf("   ******************************\n\n");
                 system("pause");
    }
   }
   else{
            printf("\n   *******************\n");
            printf("   * Error al cargar *\n");
            printf("   *******************\n\n");
   }



    return 0;
}
