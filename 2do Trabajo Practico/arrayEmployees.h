#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"

//#define TAM 1000//Este es el maximo de empleados que podra ser ingresado en este sistema.

//#ifndef ARRAYEMPLOYEES_H_INCLUDED
//#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;

//#endif // ARRAYEMPLOYEES_H_INCLUDED

void harcodear(eEmployee list[],int tam);

int mostrarMenu();

int initEmployees(eEmployee list[],int len);
void notifyErrorInitEmployees(int obtainedResult);

void performEmployeeDataEntry(eEmployee list[],int len,int contador);
void requestEmployeeName(char string[]);
void requestEmployeeLastName(char string[]);
float requestEmployeeSalary();
int requestEmployeeSector();
int addEmployee(eEmployee list[], int len, int id, char name[],char lastName[],float salary,int sector);
int firstPositionEmpty(eEmployee list[],int len);
void notifyErrorAddEmployee(int obtainedResult);
//void corroborarPrimerIngreso(eEmployee list[],int len, int flag);

int findEmployeeById(eEmployee list[], int len,int id);

int removeEmployee(eEmployee list[], int len, int id);

int printEmployees(eEmployee list[], int length);

int sortEmployees(eEmployee list[], int len, int order);
int ordenarAlfabeticamenteAaZ(eEmployee list[],int len);
int ordenarAlfabeticamenteZaA(eEmployee list[],int len);

/**--------------------------------------------------------------------------------------*/

void setAny(eEmployee list[],int len);

void pedirIdModificar(eEmployee list[],int len);

int mostrarMenuCase2();

void editName(eEmployee list[],char string[],int i);

void editlastName(eEmployee list[],char string[],int i);

float editSalary(float salary);

int editSector(int sector);

/**-----------------------------------------------------------------------------------------*/

int mostrarMenuCase3();

void hacerLaLogicaDelCase3(eEmployee list[],int len,int id,int flag);

/**------------------------------------------------------------------------------------------*/

int mostrarMenuCase4Punto1();

void mostrarMenuCase4Punto2(eEmployee list[],int len);

float acumularLosSalarios(eEmployee list[],int len);

float promediarLosSalarios(eEmployee list[],int len,float totalSalarios);

int calcularLosSalariosSuperioresAlPromedio(eEmployee list[],int len,float promedio);





