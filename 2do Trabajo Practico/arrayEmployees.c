#include "arrayEmployees.h"
#define EMPTY 1
#define OCCUP 0

/** \brief para hacer pruebas en el programa, hard codeando el array.
 *
 * \param list[] eEmployee
 * \param tam int
 * \return void
 *
 */
void harcodear(eEmployee list[],int tam)
{
    int id[]={1,2,3,4,5,6,7,8,9,10};
    char nombres[][20]={"Juan","Alberto","Lucia","Martina","Jose","Pepe","Sofia","Miguel","Daniela","Luciana"};
    char apellidos[][20]={"Lopez","Fernandez","Pepita","Mandela","Andres","Leon","Montania","Garres","Planta","Zavala"};
    float salarios[]={250.5,277.5,4000.77,980.66,486.34,1234.56,98076.88,3456.78,1092.45,2956.1};
    int sectores[]={1,2,3,4,5,6,7,8,9,10};
    int isEmpty[]={0,1,0,0,0,0,0,0,0,0};

    printf("\nAdentro harcode\n");

    for(int i=0;i<tam;i++)
    {
        list[i].id=id[i];
        strcpy(list[i].name,nombres[i]);
        strcpy(list[i].lastName,apellidos[i]);
        list[i].salary=salarios[i];
        list[i].sector=sectores[i];
        list[i].isEmpty=isEmpty[i];
    }
}

/** \brief mostrar el menu del algoritmo, asi tambien capturando la opcion que eliga el usuario.
 *
 * \return el int a capturar, la opcion elegida del menu.
 *
 */
int mostrarMenu()
{
    int opcion;

    printf("0. HARDCODEAR");
    printf("\n1. ALTAS\n");//Se debe permitir ingresar un empleado calculando automáticamente el número de Id. El resto de los campos se le pedirá al usuario.
    printf("2. MODIFICAR\n");//Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido o Salario o Sector
    printf("3. BAJA\n");//Se ingresará el Número de Id y se eliminará el empleado del sistema.
    printf("4. INFORMAR\n");//En esta opcion se debe mostrar la informacion de abajo.
    printf("  1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
    printf("  2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

/** \brief To indicate that all position in the array are empty,this function put the flag (isEmpty) in TRUE in all position of the array.
 *
 * \param list Employee* Pointer to array of employees.
 * \param len int Array length.
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
 *
 */
int initEmployees(eEmployee list[],int len)
{
    int resultado=-1;

    if(list!=NULL && len>0)
    {
        setAny(list,len);
        resultado=0;
    }
    return resultado;
}

/** \brief se encarga de avisar si hubo un error en la funcion "initEmployees".
 *
 * \param list[] eEmployee
 * \param len int
 * \param obtainedResult int
 * \return void
 *
 */
void notifyErrorInitEmployees(int obtainedResult)
{
    if(obtainedResult==-1)
    {
        printf("Error! No funciono ok initEmployee!\n");
    }
}

void performEmployeeDataEntry(eEmployee list[],int len,int contador)
{
    int resultAddEmployee;
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;

    id=contador;

    requestEmployeeName(name);
    printf("\nnombre: %s",name);

    requestEmployeeLastName(lastName);
    printf("\napellido: %s",lastName);

    salary=requestEmployeeSalary();
    printf("\nsalario: %.2f",salary);

    sector=requestEmployeeSector();
    printf("\nsector: %d",sector);

    resultAddEmployee=addEmployee(list,len,id,name,lastName,salary,sector);
    notifyErrorAddEmployee(resultAddEmployee);

}

void requestEmployeeName(char string[])
{
    char aux[51];

    printf("\nIngrese el nombre del empleado: ");
    fflush(stdin);
    gets(aux);
    strcpy(string,aux);

}

void requestEmployeeLastName(char string[])
{
    char aux[51];

    printf("\nIngrese el apellido del empleado: ");
    fflush(stdin);
    gets(aux);
    strcpy(string,aux);
    //printf("\napellido: %s",string);
}

float requestEmployeeSalary()
{
    float salary;

    do
    {
        printf("\nIngrese el salario del empleado: ");
        scanf("%f",&salary);

        if(salary<0)
        {
            printf("\nError! El salario ingresado es invalido!");
        }
    }
    while(salary<0);
    //printf("\nsalario: %.2f",salary);

    return salary;
}

int requestEmployeeSector()
{
    int sector;
    do
    {
        printf("\nIngrese el sector al que pertenece del empleado: ");
        scanf("%d",&sector);

        if(sector<0)
        {
            printf("\nError! El numero del sector ingresado es invalido!");
        }
    }
    while(sector<0);
    //printf("\nsector: %d",sector);

    return sector;
}

/** \brief add in a existing list of employees the values received as parameters in the first empty position.
 *
 * \param list eEmployee
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok.
 *
 */
int addEmployee(eEmployee list[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    int resultado=-1;
    int i;

    i=firstPositionEmpty(list,len);

    if(list!=NULL && (len>0 && len<1000) && salary>-1 && sector>0 && i!=-1)
    {
        list[i].id=id;
        strcpy(list[i].name,name);
        strcpy(list[i].lastName,lastName);
        list[i].salary=salary;
        list[i].sector=sector;
        list[i].isEmpty=OCCUP;

        resultado=0;
    }
    return resultado;
}

/** \brief buscar la primera posicion libre y dar su posicion en la que se encuentra,en el array
 *
 * \param list[] eEmployee
 * \param len int
 * \return la posicion libre en el array
 *
 */
int firstPositionEmpty(eEmployee list[],int len)
{
    int resultado=-1;

    if(list!=NULL && len<1001)
    {
        for(int i=0;i<len;i++)
        {
            if(list[i].isEmpty==EMPTY)
            {
                resultado=i;
                break;
            }
        }
    }

    return resultado;
}

/** \brief se encarga de avisar si hubo un error en la funcion "addEmployee".
 *
 * \param obtainedResult int
 * \return void
 *
 */
void notifyErrorAddEmployee(int obtainedResult)
{
    if(obtainedResult==-1)
    {
        printf("\nError! tiro -1 el addEmployee!");
    }
}

/** \brief validar la funcion "firstPositionEmpty"
 *
 * \param list[] eEmployee
 * \param len int
 * \param flag int
 * \return void
 *
 */
/*void corroborarPrimerIngreso(eEmployee list[],int len, int flag)
{
    if(flag==1)
    {
        initEmployees(list,len);
        flag=0;
    }
}*/

/** \brief find an Employee by Id and returns the index position in array.
 *
 * \param list[] Employee
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found].
 *
 */
int findEmployeeById(eEmployee list[], int len,int id)
{
    int idPosition=-1;

    if(list!=NULL && (len>0 && len<1001) && id>0)
    {
        for(int i=0;i<len;i++)
        {
            if(list[i].id==id)
            {
                idPosition=i;
            }
        }
    }
    return idPosition;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok.
 *
 */
int removeEmployee(eEmployee list[], int len, int id)
{
    int resultado=-1;
    int idPosition;

    if(list!=NULL && (len>0 && len<1000) && id>0)
    {
        idPosition=findEmployeeById(list,len,id);

        if(idPosition!=-1 && list[idPosition].isEmpty==OCCUP)
        {
            list[idPosition].isEmpty=EMPTY;
            resultado=0;
        }
    }
    return resultado;
}

/** \brief print the content of employees array
 *
 * \param list[] eEmployee
 * \param len int
 * \return int
 *
 */
int printEmployees(eEmployee list[], int len)
{
    int resultado=-1;

    if(list!=NULL && (len>0 && len<1000))
    {
        printf("\n      ***** Listado de Empleados *****\n\n");

        for(int i=0;i<len;i++)
        {
            if(list[i].isEmpty==OCCUP)
            {
                printf("      %d",list[i].id);
                printf("\t      %s",list[i].lastName);
                printf("\t      %s",list[i].name);
                printf("\t      %.2f",list[i].salary);
                printf("\t      %d\n",list[i].sector);
            }
        }
        resultado=0;
    }
    return resultado;
}

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order.
 *
 * \param list[] eEmployee
 * \param len int
 * \param order order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(eEmployee list[], int len, int order)
{
    int resultado=-1;

    printf("   1.");
    if(list!=NULL && (len>0 && len<1000) && (order>-1 && order<2))
    {
        switch(order)
        {
            case 0:
                resultado=ordenarAlfabeticamenteAaZ(list,len);
                break;

            case  1:
                resultado=ordenarAlfabeticamenteZaA(list,len);
                break;

            default:
                break;
        }
    }


    return resultado;
}

/** \brief ordenar un listado de elementos(nombre) alfabeticamente de la A a la Z y, como segundo criterio, por numero menor a mayor.
 *
 * \param list[] eEmployee
 * \param len int
 * \return int
 *
 */
int ordenarAlfabeticamenteAaZ(eEmployee list[],int len)
{
    int resultado=-1;

    eEmployee employeeAuxiliar;

    for(int i=0;i<len-1;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(stricmp(list[i].lastName,list[j].lastName)==1)
            {
                strcpy(employeeAuxiliar.lastName,list[i].lastName);
                strcpy(list[i].lastName,list[j].lastName);
                strcpy(list[j].lastName,employeeAuxiliar.lastName);

                resultado=0;
            }else
            {
                if(stricmp(list[i].lastName,list[j].lastName)==0)
                {
                    if(list[i].sector<list[j].sector)
                    {
                        employeeAuxiliar.sector=list[i].sector;
                        list[i].sector=list[j].sector;
                        list[j].sector=employeeAuxiliar.sector;

                        resultado=0;
                    }
                }
            }
        }
    }
    return resultado;
}

/** \brief ordenar un listado de elementos(nombre) alfabeticamente de la Z a la A y, como segundo criterio, por numero menor a mayor.
 *
 * \param list[] eEmployee
 * \param len int
 * \return int
 *
 */
int ordenarAlfabeticamenteZaA(eEmployee list[],int len)
{
    int resultado=-1;

    eEmployee employeeAuxiliar;

    for(int i=0;i<len-1;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(stricmp(list[i].lastName,list[j].lastName)==-1)
            {
                strcpy(employeeAuxiliar.lastName,list[i].lastName);
                strcpy(list[i].lastName,list[j].lastName);
                strcpy(list[j].lastName,employeeAuxiliar.lastName);

                resultado=0;
            }else
            {
                if(stricmp(list[i].lastName,list[j].lastName)==0)
                {
                    if(list[i].sector<list[j].sector)
                    {
                        employeeAuxiliar.sector=list[i].sector;
                        list[i].sector=list[j].sector;
                        list[j].sector=employeeAuxiliar.sector;

                        resultado=0;
                    }
                }
            }
        }
    }
    return resultado;
}

/**--------------------------------------------------------------------------------------*/

void setAny(eEmployee list[],int len)
{
    for(int i=0;i<len;i++)
    {
        list[i].id=0;
        strcpy(list[i].name,"");
        strcpy(list[i].lastName,"");
        list[i].salary=0;
        list[i].sector=0;
        list[i].isEmpty=EMPTY;
    }
}

void pedirIdModificar(eEmployee list[],int len)
{
    eEmployee aux;
    int id;
    int i;
    int opcion;
    char nombre[51];
    char lastName[51];
    float salary;
    int sector;
    char respuesta;

    printf("\nIngrese el ID del empleado que quierea modificar: ");
    scanf("%d",&id);

    i=findEmployeeById(list,len,id);

    opcion=mostrarMenuCase2();

    do
    {
        switch(opcion)
        {
            case 1:

                /*requestEmployeeName(name);
                strcpy(list[i].name,name);
                printf("name: %s\n",list[i].name);*/


                printf("ingrese nombre: ");
                scanf("%s",&aux.name);
                //strcpy(aux.name, nombre);
                break;

            case 2:
                editlastName(list,lastName,i);
                printf("last name: %s\n",list[i].lastName);
                break;

            case 3:
                salary = editSalary(salary);
                //list[i].salary = salary;
                printf("salary: %.2f\n",list[i].salary);
                break;

            case 4:
                list[i].sector=editSector(sector);
                printf("sector: %d\n",list[i].sector);
                break;

            default:
                break;
        }

        printf("\nIngrese 's' para seguir 'n' para salir: ");
        fflush(stdin);
        scanf("%c",&respuesta);

    }
    while(respuesta=='s');

    list[i] = aux;
    printf("hola");

}

int mostrarMenuCase2()
{
    int opcion;

    printf("\n1. Modificar nombre");
    printf("\n2. Modificar Apellido");
    printf("\n3. Modificar salario");
    printf("\n4. Modificar sector");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

void editName(eEmployee list[],char string[],int i)
{

    requestEmployeeName(string);
    strcpy(list[i].name,string);
}

void editlastName(eEmployee list[],char string[],int i)
{
    requestEmployeeLastName(string);
    strcpy(list[i].lastName,string);
}

float editSalary(float salary)
{
    salary=requestEmployeeSalary();

    return salary;
}

int editSector(int sector)
{
    sector=requestEmployeeSector();

    return sector;
}

/**-------------------------------------------------------------------------------------*/

int mostrarMenuCase3()
{
    int id;

    printf("Ingrese el ID del empleado que quiera eliminar del sistema: ");
    scanf("%d",&id);

    return id;
}

void hacerLaLogicaDelCase3(eEmployee list[],int len,int id,int flag)
{
    if(flag==1)
    {
        id=mostrarMenuCase3();
        removeEmployee(list,len,id);
    }
    else
    {
        printf("\nError! Se debe realizar la carga de algun empleado para poder usar esta opcion!\n\n");
    }
}

/**--------------------------------------------------------------------------------------------*/

int mostrarMenuCase4Punto1()
{
    int opcion;

    printf("\nIngrese cero(0), para que se ordene el enlistado alfabeticamente de la A a la Z");
    printf("\nIngrese uno(1), para que se ordene el enlistado alfabeticamente de la Z a la A");

    do
    {
        printf("\nIngrese aqui: ");
        scanf("%d",&opcion);

        if(opcion<0 || opcion>1)
        {
            printf("Error! Opcion invalida!");
        }
    }
    while(opcion<0 || opcion>1);

    return opcion;
}

void mostrarMenuCase4Punto2(eEmployee list[],int len)
{
    float totalSalarios;
    float promedioSalarios;
    int cantidadEmpleadosSuperiorSalario;

    totalSalarios=acumularLosSalarios(list,len);
    promedioSalarios=promediarLosSalarios(list,len,totalSalarios);
    cantidadEmpleadosSuperiorSalario=calcularLosSalariosSuperioresAlPromedio(list,len,promedioSalarios);

    printf("\nEl total de los salarios es: %.2f",totalSalarios);
    printf("\nEl promedio de los salarios es: %.2f",promedioSalarios);
    printf("\nLa cantidad de empleados que superan el promedio es: %d\n\n",cantidadEmpleadosSuperiorSalario);
}

float acumularLosSalarios(eEmployee list[],int len)
{
    float acumulador;
    int contador;

    acumulador=0;
    contador=0;

    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty==OCCUP)
        {
            acumulador=acumulador+list[i].salary;
            contador++;
            //printf("\nacumulador (%d) = %.2f",contador,acumulador);
        }
    }
    //printf("\ntotal acumulado: %.2f\n",acumulador);

    return acumulador;
}

float promediarLosSalarios(eEmployee list[],int len,float totalSalarios)
{
    int contador;
    float promedio;

    contador=0;

    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty==OCCUP)
        {
            contador++;
        }
    }

    promedio=totalSalarios/contador;

    return promedio;
}

int calcularLosSalariosSuperioresAlPromedio(eEmployee list[],int len,float promedio)
{
    int cantidadSalariosSuperiores;
    int contador;

    contador=0;

    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty==OCCUP && list[i].salary>promedio)
        {
            contador++;
        }
    }

    cantidadSalariosSuperiores=contador;

    return cantidadSalariosSuperiores;
}



