#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
int parser_eBicicletaFromText(FILE* pFile , LinkedList* pArrayListeBicicleta)
{
    eBicicleta* aux;

    int x;
    char id[20], nombre[50], horasTrabajadas[20], sueldo[20];

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",id,nombre,horasTrabajadas,sueldo);

     do{
        x=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",id,nombre,horasTrabajadas,sueldo);
        if(x==4)
        {
            aux=eBicicleta_newParametros(id,nombre,horasTrabajadas,sueldo);
            ll_add(pArrayListeBicicleta,aux);
        }

    }while(!feof(pFile));

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
int parser_eBicicletaFromBinary(FILE* pFile , LinkedList* pArrayListeBicicleta)
{
    eBicicleta* aux;

    int x;
    char id[20], nombre[50], horasTrabajadas[20], sueldo[20];

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",id,nombre,horasTrabajadas,sueldo);

    do{
        x=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",id,nombre,horasTrabajadas,sueldo);
        if(x==4)
        {
            aux=eBicicleta_newParametros(id,nombre,horasTrabajadas,sueldo);
            ll_add(pArrayListeBicicleta,aux);
        }
    }while(!feof(pFile));

    return 1;
}


