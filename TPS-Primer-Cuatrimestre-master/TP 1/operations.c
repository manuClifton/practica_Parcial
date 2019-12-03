#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int showMenu(int flagA,int a,int b,int flagB){
    system("cls"); // limpiar pantalla

    int opcion;
            printf("*** Menu de Opciones ***\n\n");
        if(flagA == 0){
            printf("1. Ingresar 1er operando (A=x)\n");
        }else{
            printf("1. 1er operando (A=%d)\n", a);
        }
        if(flagB == 0){
            printf("2. Ingresar 2do operando (B=y)\n");
        }else{
            printf("2.  2do operando (B=%d)\n", b);
        }

            printf("3. Calcular todas las operaciones\n");
            printf("3. Calcular todas las operaciones\n");
            printf("4. Informar resultados\n");
            printf("5-Salir\n");
            printf("\n Ingrese opcion: ");
        scanf("%d", &opcion);
    return opcion;
}

int sumOperation(int num1, int num2){
    int res;
        res = num1 + num2;
    return res;
}

int subtractionOperation(int num1, int num2){
    int res;
        res = num1 - num2;
    return res;
}

float divideOperation(int num1, int num2){
    float res;
        res = (float) num1/num2;
    return res;
}

int multipliOperation(int num1, int num2){
    int res;
        res = num1 * num2;
    return res;
}

long factorialOperationA(int num){
    long rta;
        if(num <= 1){
            rta=1;
        }else{
            rta = num * factorialOperationA(num -1);
        }
        return rta;
}

long factorialOperationB(int num){
    long rta;
        if(num <= 1){
            rta = 1;
        }else{
            rta = num * factorialOperationB(num -1);
        }
        return rta;
}
