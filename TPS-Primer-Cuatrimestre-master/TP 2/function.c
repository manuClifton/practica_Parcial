
#include "function.h"



int menu(){
    int option;

    system("cls");
    printf("************* TRABAJO PRACTICO 2 *************\n");
    printf("*************        ABM         *************\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificacion\n");
    printf("4- Mostrar Empleados\n");
    printf("5- Buscar Empleado\n");
    printf("6- Informar\n");
    printf("7- Salir\n\n");
    printf("\nIngrese Opcion: ");
    scanf("\n%d", &option);

    return option;
}

int menuInfo(){
    int option;
    system("cls");
    printf("\n************* INFORMES *************\n\n");
    printf("1- Ordenar por Apellido y Sector: \n");
    printf("2- Mostrar cantidad de Empleados y promedio de sueldos: \n");
    printf("3- Mostrar por promedio de sueldo\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &option);

    return option;
}

int menuAlphabet(){
    int option;

    system("cls");
    printf("************* MOSTRAR EMPLEADOS POR APELLIDO Y SECTOR *************\n\n");
    printf("1- ASCENDENTE\n");
    printf("2- DESCENDENTE\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &option);

    return option;
}

void generateEmployee(eEmployee list[], int len){
    eEmployee auxEmp[]={
        {1, "Hernesto", "Guevara",  25000, 1, 1},
        {2,    "Pablo",  "Cepeda",  30000, 2, 1},
        {3,     "Luis",   "Lopez",  25000, 3, 1},
        {4,      "Ana",    "Soto",  37000, 4, 1},
        {5,    "Sofia", "Guevara",  20000, 5, 1},
        {6,    "Lucas",   "Elano",  40000, 1, 1},
        {7,    "Carla", "Pascual",  34000, 2, 1},
        {8,   "Andres", "Montiel",  37000, 3, 1},
        {9,   "Romina",   "Perez",  21000, 4, 1},
        {10, "Claudio",   "Gallo",  33000, 5, 1},
        {11,  "Karina",   "Perez",  45000, 1, 1},
        {12,    "Ayde",  "Chacon",  23000, 2, 1},
        {13, "Gustavo",   "Perez",  28000, 3, 1},
        {14, "Ezequiel",   "Posta", 35000, 4, 0},
        {15, "Liliana",  "Guerra",  34000, 5, 1}
    };
    for(int i=0; i<len; i++){
        list[i]=auxEmp[i];
    }
}


void initEmployees(eEmployee list[], int len){
    for(int i=0; i<len; i++){
        list[i].isEmpty = 0;
    }
}

int findFree(eEmployee list[], int len){
    int index = -1;

    for(int i=0; i<len; i++){
        if(list[i].isEmpty == 0){
            index = i;
            break;
        }
    }
    return index;
}

int findEmployee(eEmployee list[], int len, int file)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {
        if(list[i].isEmpty == 1 && list[i].id == file)
        {
            index = i;
            break;
        }
    }

    return index;
}

void highEmployee(eEmployee list[], int len)
{
    int index;
    int file;
    int is;

    index = findFree(list, len);

    if( index == -1)
    {
        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &file);
        while(file<1|| file>1000)
    {
        printf("Legajo incorrecto, reingrese valor entre 1 y 1000: ");
        scanf("%d",&file);
    }

        is = findEmployee(list, len, file);

        if( is != -1)
        {
            printf("Existe un empleado de legajo %d en el sistema\n", file);
            printEmployee(list[is]);
        }
        else
        {
            list[index].id = file;

            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(list[index].lastName);

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(list[index].name);

            printf("Ingrese sueldo: ");
            scanf("%f", &list[index].salary );

            printf("Ingrese sector del 1 al 5: ");
            scanf("%d", &list[index].sector);
              while(list[index].sector<1|| list[index].sector>5)
            {
            printf("Sector incorrecto, reingrese valor entre 1 y 5: ");
            scanf("%d",&list[index].sector);
            }

            list[index].isEmpty = 1;

            printf("Alta empleado exitosa!!!\n\n");
        }
    }
}


void removeEmployee(eEmployee list[], int len)
{
    int file;
    char confirm;
    int is;

    printf("Ingrese legajo: ");
    scanf("%d", &file);

    is = findEmployee(list, len, file);

    if( is == -1)
    {
        printf("\nEl legajo %d no esta registrado en el sistema\n", file);
    }
    else
    {
        printEmployee(list[is]);

        printf("\nConfirma la eliminacion? s/n");
        fflush(stdin);
        confirm = tolower(getche());

        if(confirm == 's')
        {
            list[is].isEmpty = 0;
        }
        else
        {
            printf("\nLa eliminacion ha sido cancelada\n");
        }
    }
}


void findEmployeeById(eEmployee list[], int len){
    int file;
    int is=0;

    printf("Ingrese numero de legajo que desea encontrar: ");
    scanf("%d", &file);

    for(int i=0; i<len; i++){
        if(list[i].id == file && list[i].isEmpty == 1){
            printf(" Legajo      Apellido    Nombre       Sueldo        Sector\n");
            printf("--------    ----------  --------     --------      --------\n");
            printEmployee(list[i]);
            is = 1;
            break;
        }
    }
    if(is == 0){
        printf("\nNo hay empleado registrado con ese numero de legajo.\n\n");
    }
}


void modifyEmployee(eEmployee list[], int len)
{
    int file;
    char confirm;
    float nowSalary;
    int is;

    printf("Ingrese legajo: ");
    scanf("%d", &file);

    is = findEmployee(list, len, file);

    if( is == -1)
    {

        printf("\nEl legajo %d no esta registrado en el sistema\n", file);
    }
    else
    {
        findEmployee(list, len, file);

        printf("\nQuiere cambiar el sueldo? s/n:  ");
        fflush(stdin);
        confirm = tolower(getche());

        if(confirm == 's')
        {
            printf("\n\nIngrese nuevo sueldo: ");
            scanf("%f", &nowSalary);
            //valido sueldo
            list[is].salary = nowSalary;
        }
        else
        {
            printf("\n\nNo se ha modificado el sueldo\n\n");
        }
    }
}

void sortEmployeesUpward(eEmployee list[], int len)
{
        eEmployee auxChar;
        system("cls");
        printf(" Legajo      Apellido    Nombre       Sueldo        Sector\n");
        printf("--------    ----------  --------     --------      --------\n");

            for(int i=0; i<len-1; i++){
                for(int j=i+1; j<len; j++){
                    if(strcmp(list[i].lastName,list[j].lastName)>0 && list[i].isEmpty == 1){
                        auxChar = list[i];
                        list[i] = list[j];
                        list[j] = auxChar;
                    }
                    if(strcmp(list[i].lastName,list[j].lastName) == 0 && list[i].sector > list[j].sector && list[i].isEmpty == 1){
                               auxChar = list[i];
                               list[i] = list[j];
                               list[j] = auxChar;
                            }
                }
            }
            printEmployees(list, len);
            system("pause");
}

void sortEmployeesDecendent(eEmployee list[], int len)
{
        eEmployee auxChar;
        system("cls");

        printf(" Legajo      Apellido    Nombre       Sueldo        Sector\n");
        printf("--------    ----------  --------     --------      --------\n");

            for(int i=0; i<len-1; i++){
                for(int j=i+1; j<len; j++){
                    if(strcmp(list[i].lastName,list[j].lastName)<0 && list[i].isEmpty == 1){
                        auxChar = list[i];
                        list[i] = list[j];
                        list[j] = auxChar;
                    }
                    if(strcmp(list[i].lastName,list[j].lastName) == 0 && list[i].sector < list[j].sector && list[i].isEmpty == 1){
                               auxChar = list[i];
                               list[i] = list[j];
                               list[j] = auxChar;
                            }
                }
            }
            printEmployees(list, len);
            system("pause");
}

void printEmployee(eEmployee list){

    if(list.isEmpty == 1){
         printf("%5d       %7s     %8s     %7.2f         %d\n", list.id, list.lastName, list.name, list.salary, list.sector);
    }
}

int printEmployees(eEmployee list[], int len){

    int contador = 0;

    system("cls");


    printf(" Legajo      Apellido    Nombre       Sueldo        Sector\n");
    printf("--------    ----------  --------     --------      --------\n");

    for(int i=0; i < len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            printEmployee(list[i]);
            contador++;
        }
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNO HAY EMPLEADOS QUE MOSTRAR.\n\n");
    }
    return 0;
}



void totalEmployees(eEmployee list[], int len)
{
    int counterEmployee = 0;
    int counterSalary = 0;
    float average;

    for(int i=0; i < len; i++)
    {
        if(list[i].isEmpty == 1){
            counterEmployee = counterEmployee + 1;
        counterSalary = counterSalary + list[i].salary;
        }
    }

    average = (float) counterSalary / counterEmployee;
        printf("\nCantidad: %d\n\n", counterEmployee);
        printf("Promedio de sueldos: %.2f\n\n", average);


}



void employeeExceedsAverage(eEmployee list[], int leng)
{
    int counterEmployee = 0;
    int counterSalary = 0;
    float average;


    printf(" Legajo      Apellido    Nombre       Sueldo        Sector\n");
    printf("--------    ----------  --------     --------      --------\n");

    for(int i=0; i < leng; i++)
    {
        if(list[i].isEmpty == 1){
            counterEmployee = counterEmployee + 1;
        counterSalary = counterSalary + list[i].salary;
        }
    }

    average = (float) counterSalary / counterEmployee;

    for(int i=0; i<leng; i++)
    {
        if(list[i].salary > average){
            printEmployee(list[i]);
        }
    }
}

