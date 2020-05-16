#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arrayEmployees.h"

//#define TAM 1000//Este es el maximo de empleados que podra ser ingresado en el sistema.
#define TAM 14//Este TAM es para testear.

int main()
{
    int opcion;
    int bandera;
    int resultInitEmployees;
    int contador;
    int idIngresado;
    int opcionMenuCase4;

    bandera=0;
    contador=1;

    eEmployee employee[TAM];

    resultInitEmployees=initEmployees(employee,TAM);
    notifyErrorInitEmployees(resultInitEmployees);

    harcodear(employee,TAM);
    bandera=1;

    do
    {
        opcion=mostrarMenu();

        switch(opcion)
        {
            case 1:
                performEmployeeDataEntry(employee,TAM,contador);
                contador++;
                bandera=1;
                break;

            case 2:
                if(bandera==1)
                {
                    pedirIdModificar(employee,TAM);
                    //No se estarian realizando las modificaciones...
                }
                else
                {
                    printf("\nError! Se debe realizar la carga de algun empleado para poder usar esta opcion!\n\n");
                }
                break;

            case 3:
                hacerLaLogicaDelCase3(employee,TAM,idIngresado,bandera);
                break;

            case 4:
                if(bandera==1)
                {
                    opcionMenuCase4=mostrarMenuCase4Punto1();
                    sortEmployees(employee,TAM,opcionMenuCase4);
                    printEmployees(employee,TAM);

                    mostrarMenuCase4Punto2(employee,TAM);
                }
                else
                {
                    printf("\nError! Se debe realizar la carga de algun empleado para poder usar esta opcion!\n\n");
                }
                break;

            default:
                break;
        }
        system("pause");
        system("cls");

    }
    while(opcion>0 && opcion<5);

    return 0;
}

