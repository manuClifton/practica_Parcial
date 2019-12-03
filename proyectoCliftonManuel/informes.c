#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "informes.h"
#include "biblioteca.h"

int menuInformes(){
    int option;

    system("cls");
    printf("\n******************** INFORMES ******************\n\n");

        printf("1- Mostra Juegos de Catetgoria MESA\n");
        printf("2- Mostrar Alquileres por Cliente Seleccionado\n");
        printf("3- Mostrar total de importes por Cliente Seleccionado\n");
        printf("4- Listar Clientes que no Alquilaron juegos\n");
        printf("5- Listar los juegos que no han sido alquilados\n\n");

        printf("6- Listar Clientes de una Localidad Determinada\n");
        printf("7- Listar Juego preferidos de una Localidad\n");
        printf("8- Recaudacion por Localidad Determinada\n");
        printf("9- Informar Nombres de cliente y Fechas de alquiler por Juego seleccionado\n");
        printf("10- Categoria menos Alquilada\n");
        printf("11- Telefonos de Clientes por Fecha Seleccionada\n");
        printf("12- Listar Juegos Alquilados por Mujeres\n");
        printf("13- Juegos Preferido por Hombres\n");
        printf("14- Listar Clientes que alquilaron Juego Determinado\n");
        printf("15- Recaudacion por Fecha\n");


        printf("0- CANCELAR\n\n");
        getIntRange(&option, "Ingrese Opcion: ", "Error. Reingrese Opcion: ", 0, 100);

    return option;
}

void mostrarInformes(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq, eCategoria categorias[], int tamCat, eJuego juegos[], int tamJuego, eLocalidad localidades[], int tamLoc){
    char salir = 'N';

    system("cls");
    printf("*********** INFORMES ************\n\n");

    do{
             switch( menuInformes()){
                case 1:
                        mostrarJuegosCategoriaMesa(juegos, tamJuego, categorias, tamCat);
                    break;
                case 2:
                        alquileresPorCliente(alquileres, tamAlq, clientes, tamCli, juegos, tamJuego, localidades, tamLoc);
                    break;
                case 3:
                        deudaPorCliente(clientes, tamCli, alquileres, tamAlq, juegos, tamJuego, localidades, tamLoc);
                    break;
                case 4:
                        clientesQueNoAlquilaron(clientes, tamCli, alquileres, tamAlq, localidades, tamLoc);
                    break;
                case 5:
                        juegosQueNoAlquilaron(juegos, tamJuego, alquileres, tamAlq, categorias, tamCat);
                    break;
                case 6:
                        mostrarClientePorLocalidad(localidades, tamLoc, clientes, tamCli);
                    break;
                case 7:
                        juegoPreferidoPorLocalidad(juegos, tamJuego, alquileres, tamAlq, categorias, tamCat, localidades, tamLoc, clientes, tamCli);
                    break;
                case 8:
                    recaudacionPorLocalidad(clientes, tamCli, alquileres, tamAlq, juegos, tamJuego, localidades, tamLoc);
                    break;
                case 9:
                    nombresYfechasPorJuego(clientes, tamCli, alquileres, tamAlq, juegos, tamJuego, categorias, tamCat);
                    break;
                case 10:
                       categoriaMenosAlquilada(juegos, tamJuego, alquileres, tamAlq, categorias, tamCat);
                    break;
                case 11:
                        telefonoPorFecha(clientes, tamCli, alquileres, tamAlq);
                    break;
                case 12:
                        juegosAlquialdosPorMujeres(alquileres, tamAlq, juegos, tamJuego, clientes, tamCli, categorias, tamCat);
                    break;
                case 13:
                        juegoPreferidoPorHombres(alquileres, tamAlq, juegos, tamJuego, clientes, tamCli, categorias, tamCat);
                    break;
                case 14:
                        clientesPorJuegoDeterminado(alquileres, tamAlq, clientes, tamCli, juegos, tamJuego, localidades, tamLoc, categorias, tamCat);
                    break;
                case 15:
                        recaudacionPorFecha(clientes, tamCli, alquileres, tamAlq, juegos, tamJuego);
                    break;
                case 0:
                    //printf("Confirma salir?:");
                    //fflush(stdin);
                    //salir = getchar();
                    //printf("\n\n");
                    getChar(&salir, "Confirma Salir ?  S o N: ", "Error. Confirma Salir ?  S o N: ",'S','N');
                    break;
                default:
                    printf("\nOpcion Invalida!\n\n");
                    break;
             }
        system("pause");
    }while(salir == 'N');
}


void mostrarJuegosCategoriaMesa(eJuego juegos[], int tamJuego, eCategoria categorias[], int tamCat){

    system("cls");
    printf("***** JUEGOS CATEGORIA MESA ******** \n\n");

    for(int i=0; i<tamJuego; i++){
        if(juegos[i].idCategoria == 1000){
            mostrarJuego(juegos[i], categorias, tamCat);
        }
    }
}


void alquileresPorCliente(eAlquiler alquileres[], int tamAlq, eCliente clientes[], int tamCli, eJuego juegos[], int tamJuego, eLocalidad localidades[], int tamLoc){
    int idCliente;
    int esta;

    system("cls");
    printf("***** MOSTRAR ALQUILERES POR CLIENTE ******** \n\n");

    mostrarClientes(clientes, tamCli, localidades, tamLoc);

    getInt(&idCliente, "\nIngrese ID: ", "Error. Reingrese ID: ");

    esta = buscarIdCliente(clientes, tamCli, idCliente);

    while(esta == -1){
        printf("EROR. No se encontro al Cliente.");
        getInt(&idCliente, "\nIngrese ID: ", "Error. Reingrese ID: ");
        esta = buscarIdCliente(clientes, tamCli, idCliente);
    }

    printf("  ID        JUEGO           CLIENTE       FECHA \n");

    for(int i=0; i<tamAlq; i++){
        if(alquileres[i].idCliente == idCliente){
            mostrarAlquiler(alquileres[i], juegos, tamJuego, clientes, tamCli);
        }
    }
}

void deudaPorCliente(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq, eJuego juegos[], int tamJuego, eLocalidad localidades[], int tamLoc){
    float acumulador = 0;
    int idCliente;
    int esta;

    system("cls");
    printf("***** MOSTRAR DEUDA DE CLIENTE SELECCIONADO ******** \n\n");

    mostrarClientes(clientes, tamCli, localidades, tamLoc);

    getInt(&idCliente, "Ingrese ID: ", "Error, Reingrese ID: ");

    esta = buscarIdCliente(clientes, tamCli, idCliente);

    while(esta == -1){
        printf("EROR. No se encontro al Cliente.");
        getInt(&idCliente, "Ingrese ID: ", "Error, Reingrese ID: ");
        esta = buscarIdCliente(clientes, tamCli, idCliente);
    }
        for(int i=0; i<tamAlq; i++){
            if(alquileres[i].idCliente == idCliente){
                for(int j=0; j<tamJuego; j++){
                    if(juegos[j].idJuego == alquileres[i].idJuego){
                        acumulador+=juegos[j].importe;
                    }
                }
            }
        }
        printf("El Cliente debe: $%.2f ", acumulador );

}

int cantidadDeClietePorAlquiler( eAlquiler alquileres[], int tamAlq, int idCliente){
    int contador = 0;

                for(int j=0; j<tamAlq; j++){
                    if(  alquileres[j].idCliente == idCliente && alquileres[j].isEmpty == 0){
                        contador++;
                    }
                }
    return contador;
}

void clientesQueNoAlquilaron(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq, eLocalidad localidades[], int tamLoc){

    int cantidad[tamCli];

    system("cls");
    printf("***** CLIENTES QUE NO ALQUILARON NADA ******** \n\n");

    for(int i=0; i<tamCli; i++){
        if(clientes[i].isEmpty == 0){
            cantidad[i] = cantidadDeClietePorAlquiler(alquileres, tamAlq, clientes[i].idCliente);
        }

    }

    for(int i=0; i<tamCli; i++){
            if(cantidad[i] == 0){
               mostrarCliente(clientes[i], localidades, tamLoc);
            }
    }
}


int cantidadDeJuegosPorAlquiler( eAlquiler alquileres[], int tamAlq, int idJuego){
    int contador = 0;

                for(int j=0; j<tamAlq; j++){
                    if(  alquileres[j].idJuego == idJuego && alquileres[j].isEmpty == 0){
                        contador++;
                    }
                }
    return contador;
}

void juegosQueNoAlquilaron(eJuego juegos[], int tamJuego, eAlquiler alquileres[], int tamAlq, eCategoria categorias[], int tamCat){

    int cantidad[tamJuego];

    system("cls");
    printf("***** JUEGOS QUE NO SE ALQUILARON ******** \n\n");

    for(int i=0; i<tamJuego; i++){
        if(juegos[i].isEmpty == 0){
            cantidad[i] = cantidadDeJuegosPorAlquiler(alquileres, tamAlq, juegos[i].idJuego);
        }
    }

    for(int i=0; i<tamJuego; i++){
            if(cantidad[i] == 0){
               mostrarJuego(juegos[i], categorias, tamCat);
            }
    }
}


void mostrarClientePorLocalidad(eLocalidad localidades[], int tamLoc, eCliente clientes[], int tamCli){
    int idLocalidad;
    int esta;

    system("cls");
    printf("***** MOSTRAR CLIENTES POR LOCALIDAD ******** \n\n");

    mostrarLocalidades(localidades, tamLoc);

    getInt(&idLocalidad, "\nIngrese ID: ", "Error. Reingrese ID: ");

    esta = buscarIdLocalidad(localidades, tamLoc, idLocalidad);

    while(esta == -1){
        printf("EROR. No se encontro la Localidad.");
        getInt(&idLocalidad, "\nIngrese ID: ", "Error. Reingrese ID: ");
        esta = buscarIdLocalidad(localidades, tamLoc, idLocalidad);
    }

    printf(" ID    NOMBRE     APELLIDO   SEXO    TELEFONO    DOMICILIO       LOCALIDAD \n");

    for(int i=0; i<tamCli; i++){
        if(clientes[i].idLocalidad == idLocalidad){
            mostrarCliente(clientes[i], localidades, tamLoc);
        }
    }
}





int cantidadJuegosPorLocalidad(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq, int idJuego, int idLocalidad){

    int contador = 0;

        for(int j=0; j<tamCli; j++){
            if(clientes[j].idLocalidad == idLocalidad && clientes[j].isEmpty == 0){
                for(int i=0; i<tamAlq; i++){
                    if(alquileres[i].idCliente == clientes[j].idCliente && alquileres[i].idJuego == idJuego && alquileres[i].isEmpty == 0){
                                contador++;
                    }
                }
            }
        }

    return contador;
}


void juegoPreferidoPorLocalidad(eJuego juegos[], int tamJuego, eAlquiler alquileres[], int tamAlq, eCategoria categorias[], int tamCat, eLocalidad localidades[], int tamLoc, eCliente clientes[], int tamCli){

    int idLocalidad;
    int esta;
    int cantidad[tamJuego];
    int mayor=0;
    int flag=0;

    system("cls");
    printf("***** JUEGOS PREFERIDO POR LOCALIDAD ******** \n\n");

    mostrarLocalidades(localidades, tamLoc);

    getInt(&idLocalidad, "\nIngrese ID: ", "Error. Reingrese ID: ");

    esta = buscarIdLocalidad(localidades, tamLoc, idLocalidad);

    while(esta == -1){
        printf("EROR. No se encontro la Localidad.");
        getInt(&idLocalidad, "\nIngrese ID: ", "Error. Reingrese ID: ");
        esta = buscarIdLocalidad(localidades, tamLoc, idLocalidad);
    }


    for(int j=0; j<tamJuego; j++){
        cantidad[j] = cantidadJuegosPorLocalidad(clientes, tamCli, alquileres, tamAlq, juegos[j].idJuego, idLocalidad);
        printf("%d\n\n", cantidad[j]);
    }


    for(int i=0; i<tamJuego; i++){
            if(cantidad[i] > mayor || flag == 0){
                mayor = cantidad[i];
                flag = 1;
            }
    }

    if(mayor > 0){
        printf("Juego preferido fue elegido %d veces. \n\n", mayor);

        for(int i=0; i<tamJuego; i++){
            if(cantidad[i] == mayor){
                mostrarJuego(juegos[i], categorias, tamCat);
            }
        }
    }
    else{
        printf("La Localidad no alquilo ningun juego\n\n");
    }
}



int cantidadDeJuegosPorMujeres(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq, int idJuego){
    int contador = 0;

        for(int k=0; k<tamCli; k++){
            if(clientes[k].sexo == 'F' && clientes[k].isEmpty == 0){
                for(int j=0; j<tamAlq; j++){
                    if( alquileres[j].idCliente == clientes[k].idCliente &&  alquileres[j].idJuego == idJuego && alquileres[j].isEmpty == 0){
                        contador++;
                    }
                }
            }
        }
    return contador;
}

void juegosAlquialdosPorMujeres(eAlquiler alquileres[], int tamAlq, eJuego juegos[], int tamJuego, eCliente clientes[], int tamCli, eCategoria categorias[], int tamCat){

    int cantidad[tamJuego];

        for(int j=0; j<tamJuego; j++){
            cantidad[j] = cantidadDeJuegosPorMujeres(clientes, tamCli, alquileres,tamAlq, juegos[j].idJuego);
        }

        for(int i=0; i<tamJuego; i++){
            if(cantidad[i] > 0){
                mostrarJuego(juegos[i], categorias, tamCat);
            }
        }
}




int cantidadDeJuegosPorHombres(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq, int idJuego){
    int contador = 0;

        for(int k=0; k<tamCli; k++){
            if(clientes[k].sexo == 'M' && clientes[k].isEmpty == 0){
                for(int j=0; j<tamAlq; j++){
                    if( alquileres[j].idCliente == clientes[k].idCliente &&  alquileres[j].idJuego == idJuego && alquileres[j].isEmpty == 0){
                        contador++;
                    }
                }
            }
        }
    return contador;
}

void juegoPreferidoPorHombres(eAlquiler alquileres[], int tamAlq, eJuego juegos[], int tamJuego, eCliente clientes[], int tamCli, eCategoria categorias[], int tamCat){

    int cantidad[tamJuego];
    int mayor;
    int flag = 0;

        for(int j=0; j<tamJuego; j++){
            cantidad[j] = cantidadDeJuegosPorMujeres(clientes, tamCli, alquileres,tamAlq, juegos[j].idJuego);
        }

        for(int i=0; i<tamJuego; i++){
            if(cantidad[i] > mayor || flag == 0){
                mayor = cantidad[i];
                flag = 1;
            }
        }

        if(mayor > 0){
            printf("Juego preferido por Hombres fue elegido %d veces. \n\n", mayor);

            for(int i=0; i<tamJuego; i++){
                if(cantidad[i] == mayor){
                    mostrarJuego(juegos[i], categorias, tamCat);
                }
            }
        }
}




void recaudacionPorLocalidad(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq, eJuego juegos[], int tamJuego, eLocalidad localidades[], int tamLoc){
    float acumulador = 0;
    int idLocalidad;
    int esta;

    system("cls");
    printf("***** MOSTRAR RECAUDACION POR LOCALIDAD SELECCIONADA ******** \n\n");

    mostrarLocalidades(localidades, tamLoc);

    getInt(&idLocalidad, "Ingrese ID: ", "Error, Reingrese ID: ");

    esta = buscarIdLocalidad(localidades, tamLoc, idLocalidad);

    while(esta == -1){
            printf("EROR. No se encontro la Localidad.");
        getInt(&idLocalidad, "\nIngrese ID: ", "Error. Reingrese ID: ");
        esta = buscarIdLocalidad(localidades, tamLoc, idLocalidad);
    }

    for(int i=0; i<tamCli; i++){
        if(clientes[i].idLocalidad == idLocalidad && clientes[i].isEmpty == 0){
            for(int j=0; j<tamAlq; j++){
                if(alquileres[j].idCliente == clientes[i].idCliente && alquileres[j].isEmpty == 0){
                    for(int k=0; k<tamJuego; k++){
                        if(juegos[k].idJuego == alquileres[j].idJuego){
                            acumulador+=juegos[k].importe;
                        }
                    }
                }
            }
        }
    }

    printf("La Localidad Recaudo: $%.2f ", acumulador );

}


void nombresYfechasPorJuego(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq, eJuego juegos[], int tamJuego, eCategoria categoria[], int tamCat){
    int idJuego;
    int esta;
    int contador=0;

    system("cls");
    printf("***** MOSTRAR NOMBRES Y FECHAS POR JEUGO SELECCIONADO ******** \n\n");

    mostrarJuegos(juegos, tamJuego, categoria, tamCat);

    getInt(&idJuego, "Ingrese ID: ", "Error, Reingrese ID: ");

    esta = buscarIdJuego(juegos, tamJuego, idJuego);
    while(esta == -1){
        printf("EROR. No se encontro el Juego.");
        getInt(&idJuego, "\nIngrese ID: ", "Error. Reingrese ID: ");
        esta = buscarIdJuego(juegos, tamJuego, idJuego);
    }

        for(int i=0; i<tamAlq; i++){
            if(alquileres[i].idJuego == idJuego){
                for(int j=0; j<tamCli; j++){
                    if(clientes[j].idCliente == alquileres[i].idCliente){
                        printf(" %10s   %02d/%02d/%d \n", clientes[j].nombre, alquileres[i].fecha.dia, alquileres[i].fecha.mes,alquileres[i].fecha.anio);
                        contador++;
                    }
                }
            }
        }

        if(contador == 0){
            printf("EL JUEGO NO SE ALQUILO. \n\n");
        }

}





int cantidadDeJuegosPorCategoria( eCategoria categoria[], int tamCat, eAlquiler alquileres[], int tamAlq, eJuego juegos[], int tamJuego,int idCategoria){
    int contador = 0;


                for(int i=0; i<tamAlq; i++){
                    if(alquileres[i].isEmpty == 0){
                        for(int k=0; k<tamJuego; k++){
                            if(juegos[k].idCategoria == idCategoria && juegos[k].idJuego == alquileres[i].idJuego){
                                for(int j=0; j<tamCat; j++){
                                    if(categoria[j].idCategoria == juegos[k].idCategoria){
                                        contador++;
                                    }
                                }
                            }
                        }
                    }
                }
    return contador;
}

void categoriaMenosAlquilada(eJuego juegos[], int tamJuego, eAlquiler alquileres[], int tamAlq, eCategoria categorias[], int tamCat){

    int cantidad[tamCat];
    int menor;
    int flag = 0;

    system("cls");
    printf("***** JUEGOS QUE NO SE ALQUILARON ******** \n\n");



    for(int j=0; j<tamJuego; j++){
        for(int i=0; i<tamCat; i++){
            if(juegos[j].idCategoria == categorias[i].idCategoria){
                cantidad[i] = cantidadDeJuegosPorCategoria(categorias, tamCat,alquileres, tamAlq, juegos, tamJuego, categorias[i].idCategoria);
            }
        }
    }

    for(int i=0; i<tamCat; i++){
            if(cantidad[i] < menor || flag == 0){
                menor = cantidad[i];
                flag = 1;
            }
    }

    printf("LA CATEGORIA MENOS ALQUILADA ES: \n");

    for(int i=0; i<tamCat; i++){
            if(cantidad[i] == menor){
                mostrarCategoria(categorias[i]);
            }
    }

    if(menor == 0){
        printf("LA CATEGORIA NO SE ALQUILO NUNCA \n");
    }
    else if(menor == 1){
        printf("SE ALQUILO 1 SOLA VEZ\n");
    }else{
        printf("SE ALQUILO %d VECES\n", menor);
    }

}


void telefonoPorFecha(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq){
    eFecha fecha;
    int dia;
    int mes;
    int anio;
    int contador=0;

    system("cls");
    printf("***** TELEFONOS POR FECHA SELECCIONADA ******** \n\n");

    getIntRange(&dia, "Ingrese Dia: ", "Error, Ingrese Dia: ", 1, 31);
    getIntRange(&mes, "Ingrese Mes: ", "Error, Ingrese Mes: ", 1, 12);
    getIntRange(&anio, "Ingrese Anio: ", "Error, Ingrese Anio: ", 1990, 2019);
    fecha.dia = dia;
    fecha.mes = mes;
    fecha.anio = anio;

        for(int i=0; i<tamAlq; i++){
            if( comparaFecha(fecha, alquileres[i].fecha) == 0 && alquileres[i].isEmpty == 0){
               for(int j=0; j<tamCli; j++){
                    if(clientes[j].idCliente == alquileres[i].idCliente){
                        printf(" %10s   %10s \n", clientes[j].nombre, clientes[j].telefono);
                        contador++;
                    }
               }
            }
        }
        if(contador == 0){
            printf("NO HAY TELEFONOS PARA LA FECHA INDICADA\n\n");
        }
}




void clientesPorJuegoDeterminado(eAlquiler alquileres[], int tamAlq, eCliente clientes[], int tamCli, eJuego juegos[], int tamJuego, eLocalidad localidades[], int tamLoc, eCategoria categorias[], int tamCat){
    int idJuego;
    int esta;
    int flag=0;

    system("cls");
    printf("***** MOSTRAR CLIENTES POR JUEGO DETERMINADO ******** \n\n");

    mostrarJuegos(juegos, tamJuego, categorias, tamCat);

    getInt(&idJuego, "\nIngrese ID: ", "Error. Reingrese ID: ");

    esta = buscarIdJuego(juegos, tamJuego, idJuego);

    while(esta == -1){
        printf("EROR. No se encontro el Juego.");
        getInt(&idJuego, "\nIngrese ID: ", "Error. Reingrese ID: ");
        esta = buscarIdJuego(juegos, tamJuego, idJuego);
    }

    printf(" ID       NOMBRE      APELLIDO      SEXO    TELEFONO          DOMICILIO          LOCALIDAD \n");

    for(int i=0; i<tamAlq; i++){
        if(alquileres[i].idJuego == idJuego){
            for(int j=0; j<tamCli; j++){
                if(clientes[j].idCliente == alquileres[i].idCliente){
                    mostrarCliente(clientes[j], localidades, tamLoc);
                    flag=1;
                }
            }
        }
    }
    if(!flag){
        printf("\n\nNINGUN CLIENTE ALQUILO EL JUEGO SELECCIONADO\n\n");
    }
}


void recaudacionPorFecha(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq, eJuego juegos[], int tamJuego){
    float acumulador = 0;
    eFecha fecha;
    int dia;
    int mes;
    int anio;

    system("cls");
    printf("***** RECAUDACION DE FECHA DETERMINADA ******** \n\n");

    getIntRange(&dia, "Ingrese Dia: ", "Error, Ingrese Dia: ", 1, 31);
    getIntRange(&mes, "Ingrese Mes: ", "Error, Ingrese Mes: ", 1, 12);
    getIntRange(&anio, "Ingrese Anio: ", "Error, Ingrese Anio: ", 1990, 2019);
    fecha.dia = dia;
    fecha.mes = mes;
    fecha.anio = anio;

        for(int i=0; i<tamAlq; i++){
            if( comparaFecha(alquileres[i].fecha, fecha) == 0 ){
                for(int j=0; j<tamJuego; j++){
                    if(juegos[j].idJuego == alquileres[i].idJuego){
                        acumulador+=juegos[j].importe;
                    }
                }
            }
        }
        printf("\n LA RECAUDACION DEL DIA SELECCIONADO ES: $%.2f \n\n", acumulador );

}



