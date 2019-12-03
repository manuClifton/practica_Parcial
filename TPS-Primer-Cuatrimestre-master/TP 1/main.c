#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int main(){
    int a;
    int b;
    int sum;
    int subtraction;
    int flagA = 0;
    int flagB = 0;
    int flagDivide = 0;
    int flagOperation = 0;
    int multiplication;
    float divide;
    long factorialA;
    long factorialB;
    char seguir = 's';

    do{
        switch(showMenu(flagA, a, b, flagB)){

        case 1:
            printf("Ingrese el valor de A:\n\n");
            scanf("%d", &a);
            flagA = 1;
            break;
        case 2:
            printf("Ingrese el valor de B:\n\n");
            scanf("%d", &b);
            flagB = 1;
            break;
        case 3:
                if(flagA && flagB){

                    sum = sumOperation(a,b);
                    subtraction = subtractionOperation(a,b);

                    if(!b==0){
                        divide = divideOperation(a,b);
                        flagDivide = 1;
                    }else{
                        flagDivide = 0;
                    }

                    multiplication = multipliOperation(a,b);

                    factorialA = factorialOperationA(a);

                    factorialB = factorialOperationB(b);

                    flagOperation = 1;

                    printf("Operaciones realizadas\n\n");
                }else{
                    printf("Se debe ingresar los operandos A y B para realizar las operaciones.\n\n");
                }
            break;
        case 4:
            if(flagOperation==1){


                    printf("a) El resultado de A+B es: %d\n", sum);
                    printf("b) El resultado de A-B es: %d\n", subtraction);

                if(flagDivide==1){
                    printf("c) El resultado de A/B es: %.2f.\n", divide);
                }else{
                    printf("c) No es posible dividir por cero \n");
                }
                    printf("d) El resultado de A*B es: %d\n", multiplication);
                    printf("e) El factorial de A es: %ld y El factorial de B es: %ld \n", factorialA, factorialB);
            }else{
                printf("Aun no se realizaron las operaciones\n\n.");
            }

                flagOperation=0;
            break;
        case 5:
            printf("Opcion Salir\n\n");
            seguir = 'n';
            break;
        default:
            printf("Opcion Invalida\n\n");
            break;
        }

        system("pause");

    }while(seguir=='s');

    return 0;
}





























