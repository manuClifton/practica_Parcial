#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "Dominio.h"
#include "validaciones.h"


int main()
{
    int flag=0;


    FILE *pArchivo;
    LinkedList* listaDominios = ll_newLinkedList();
    LinkedList* listaMapeada = NULL;
    LinkedList* listaFilterA = NULL;
    LinkedList* listaFilterM = NULL;
    /* LinkedList* listaDominio=ll_newLinkedList();
     LinkedList* listaAutos;
     LinkedList* listaMotos;
     */
    char salir = 'n';

    if(listaDominios!=NULL)
    {
        do
        {
            switch(menu())
            {
            case 1:
                if((pArchivo=fopen( "datos.csv","r"))==NULL)
                {
                    printf("\nNO SE PUDO ABRIR EL ARCHIVO\n");

                }
                else if (controller_loadFromText("datos.csv", listaDominios))
                {
                    system("cls");
                    printf("\nEL ARCHIVO ESTA CARGADO CORRECTAMENTE\n");
                    flag=1;
                }

                fclose(pArchivo);
                break;

            case 2:  ///LISTAR ORIGINAL, SIN TIPO MAPEADO

                if (flag)
                {
                    showDominios(listaDominios);
                }
                else
                {
                    printf("\nERROR, TAL VEZ AUN NO SE CARGARON ARCHIVOS.\n");
                }
                break;

            case 3: ///MAPEAR Y CARGAR, CON TIPO DE VEHICULO

                if (flag)
                {
                    listaMapeada = ll_map(listaDominios, seteaTipo);
                    printf("\nSE HA MAPEADO LA LISTA ORIGINAL Y AGREGADO EL TIPO\n");

                }else{
                    printf("\n ERROR!! ");
                }
                break;

            case 4: ///Listar vehiculos con tipo

                if(listaMapeada != NULL)
                {
                    showDominios(listaMapeada);
                }
                else
                {
                    printf("\nERROR, TAL VEZ NO HAY ARCHIVOS CARGADOS.\n");
                }

                break;

            case 5:///Listar vehiculos separados por tipo

                listaFilterA = ll_filter(listaMapeada, filterTipo, 'A');
                listaFilterM = ll_filter(listaMapeada, filterTipo, 'M');

                if(listaFilterA != NULL && listaFilterM != NULL)
                {
                    showDominios(listaFilterA);
                    printf("\n");
                    showDominios(listaFilterM);
                }

                /*if(!flag)///hacer flag de seteo motos y seteo autos
                {
                    printf("\nSe debe cargar un archivo previamente.\n");
                }
                else
                {
                   controller_removeEmployee(listaEmpleados);
                }
                */
                break;

            case 6:///generar archivo de salida Autos Y MOTOS

                if (flag)
                {
                    if(controller_saveAsText("auto.csv", listaFilterA)){
                        printf("Se guardo el Archivo ");
                    }



                }
                break;

            case 7: ///generar archivo de salida Motos
                 if(flag)
                {
                    if(controller_saveAsText("moto.csv", listaFilterM)){
                        printf("Se guardo el Archivo ");
                    }

                }

                break;


            case 8: ///SALIR
                printf("\nConfirma la salida del sistema? (s/n): ");
                fflush(stdin);
                scanf("%c",&salir);
                break;

            default:
                printf("\nOPCION INVALIDA\n");

            }
            system("\n\npause\n");
        }
        while(salir == 'n');
    }
    {
        printf("\nERROR. No se consiguio espacio en memoria para el LinkedList");
    }

    system("\n\npause");
    return 0;
}

