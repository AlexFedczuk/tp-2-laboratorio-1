#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arrayEmployees.h"

#define TAM 1000

int main()
{
    int opcion;
    int bandera;
    int resultInitEmployees;
    int contador;

    bandera=0;
    contador=1;

    eEmployee employee[TAM];

    resultInitEmployees=initEmployees(employee,TAM);
    notifyErrorInitEmployees(resultInitEmployees);

    //harcodear(employee,TAM);
    //bandera=1;

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
                hacerLaLogicaDelCase2(employee,TAM,bandera);
                break;

            case 3:
                hacerLaLogicaDelCase3(employee,TAM,bandera);
                break;

            case 4:
                hacerLaLogicaDelCase4(employee,TAM,bandera);
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

