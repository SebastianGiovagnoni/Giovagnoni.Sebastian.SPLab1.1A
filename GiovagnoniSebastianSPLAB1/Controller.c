#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListeBicicleta)
{
    FILE* archivo;
    archivo=fopen(path, "r");

    if(archivo!=NULL)
    {
        parser_eBicicletaFromText(archivo, pArrayListeBicicleta);
        printf("total %d",ll_len(pArrayListeBicicleta));
    }
    else
    {
        printf("el archivo no existe\n");
    }
    system("pause");
    fclose(archivo);
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListeBicicleta, int* idMax, char* pId)
{
    FILE* pIdMax;
    FILE* archivo;
    archivo=fopen(path, "rb");
    pIdMax=fopen(pId,"rb");

    if(archivo!=NULL)
    {
        parser_eBicicletaFromBinary(archivo, pArrayListeBicicleta);
        fscanf(pIdMax,"%d",idMax);
    }
    else
    {
        printf("el archivo no existe\n");
    }
    fclose(archivo);

    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
/*int controller_addeBicicleta(LinkedList* pArrayListeBicicleta, int* idMax)
{
    eBicicleta* auxeBicicleta=eBicicleta_new();

    *idMax=*idMax+1;
    if(pArrayListeBicicleta!=NULL){
        eBicicleta_setId(auxeBicicleta,*idMax);
        eBicicleta_IngresarDatos(auxeBicicleta,1,"Ingrese Nombre:");
        eBicicleta_IngresarDatos(auxeBicicleta,2,"Ingrese Horas Trabajadas:");
        eBicicleta_IngresarDatos(auxeBicicleta,3,"Ingrese Salario:");
        ll_add(pArrayListeBicicleta,auxeBicicleta);
    }
    return 1;
}*/
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
/*int controller_editeBicicleta(LinkedList* pArrayListeBicicleta)
{
    int i;
    int id;
    int auxId;
    int flag=0;
    eBicicleta* empleado;


    for(i=0;i<ll_len(pArrayListeBicicleta);i++)
    {
        empleado= (eBicicleta*)  ll_get(pArrayListeBicicleta, i);
        eBicicleta_list(empleado);
    }

    printf("Ingrese id: ");
    scanf("%d",&id);

    for(i=0;i<ll_len(pArrayListeBicicleta);i++)
    {
        empleado=(eBicicleta*) ll_get(pArrayListeBicicleta,i);
        eBicicleta_getId(empleado, &auxId);
        if(id==auxId)
        {
            flag=1;
            break;
        }

    }
    system("cls");
    if(flag==1)
    {
        eBicicleta_chooseMod(empleado, "\n\nModificar\n\n1.Nombre\n2.Horas trabajadas\n3.Salario\n\nSelecion: ");
        ll_set(pArrayListeBicicleta,i,(eBicicleta*)empleado);
    }else
    {
        printf("id inexistente");
        system("pause");
    }
    return 1;
}*/

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
/*int controller_removeeBicicleta(LinkedList* pArrayListeBicicleta)
{
    int i;
    int id;
    int auxId;
    int flag=0;
    eBicicleta* empleado;


    for(i=0;i<ll_len(pArrayListeBicicleta);i++)
    {
        empleado= (eBicicleta*)  ll_get(pArrayListeBicicleta, i);
        eBicicleta_list(empleado);

    }

    printf("Ingrese id: ");
    scanf("%d",&id);

    for(i=0;i<ll_len(pArrayListeBicicleta);i++)
    {
        empleado=(eBicicleta*) ll_get(pArrayListeBicicleta,i);
        eBicicleta_getId(empleado, &auxId);
        if(id==auxId)
        {
            eBicicleta_delete(empleado);
            ll_remove(pArrayListeBicicleta, i);
            flag=1;
            break;
        }

    }
    if(flag==0)
    {
        printf("No existe id");
        system("pause");
    }


    return 1;
}*/

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
int controller_ListeBicicleta(LinkedList* pArrayListeBicicleta)
{
    eBicicleta* empleado;
    int i;

    if(pArrayListeBicicleta!=NULL)
    {
        for(i=0; i<ll_len(pArrayListeBicicleta); i++)
        {
            empleado=(eBicicleta*)ll_get(pArrayListeBicicleta,i);
            eBicicleta_list(empleado);
        }
        system("pause");
    }

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */

int controller_sorteBicicleta(LinkedList* pArrayListeBicicleta)
{

    if(pArrayListeBicicleta != NULL)
    {
        ll_sort(pArrayListeBicicleta, eBicicleta_compareByTipo, 1);
        controller_ListeBicicleta(pArrayListeBicicleta);
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListeBicicleta)
{
    int i;
    char auxS[20];
    int auxId;
    int auxH;
    char auxN[50];
    eBicicleta* aux;
    FILE* pData;

    pData=fopen(path,"w");


    if(pData!=NULL)
    {

        for(i=0;i<ll_len(pArrayListeBicicleta);i++)
        {
            aux= (eBicicleta*)  ll_get(pArrayListeBicicleta, i);

            eBicicleta_getId(aux, &auxId);
            eBicicleta_getTipo(aux, auxS);
            eBicicleta_getTiempo(aux, &auxH);
            eBicicleta_getNombre(aux, auxN);

            fprintf(pData,"%d,%s,%s,%d\n",auxId,auxN,auxS,auxH);
        }

        fclose(pData);

    }else
    {
        printf("\n\nERROR\n");

        system("pause");
    }


    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
/*int controller_saveAsBinary(char* path,char* pathIdMax, LinkedList* pArrayListeBicicleta ,int* idMax)
{
    int i;
    int auxS;
    int auxId;
    int auxH;
    char auxN[50];
    eBicicleta* aux;
    FILE* pData;
    FILE* pIdMax;

    pIdMax=fopen(pathIdMax,"wb");
    pData=fopen(path,"wb");

    if(pIdMax!=NULL&&pData!=NULL)
    {

        fprintf(pIdMax,"%d",*idMax);
        for(i=0;i<ll_len(pArrayListeBicicleta);i++)
        {
            aux= (eBicicleta*)  ll_get(pArrayListeBicicleta, i);

            eBicicleta_getId(aux, &auxId);
            eBicicleta_getTipo(aux, auxS);
            eBicicleta_getTiempo(aux, &auxH);
            eBicicleta_getNombre(aux, auxN);

            fprintf(pData,"%d,%s,%d,%s\n",auxId,auxN,auxH,auxS);
        }

        fclose(pData);
        fclose(pIdMax);

    }else
    {
        printf("\n\nERROR MEMORIA\n");

        system("pause");
    }

    return 1;
}*/
void controller_map(LinkedList* bici)
{
    ll_map(bici, laQueMapea);
}

void controller_filter(LinkedList* bici)
{
    int opcion;

    printf("1. bmx\n 2. playera\n 3. mtb\n 4. paseo\n");
    scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            controller_saveAsText("bmx.txt",ll_filter(bici,filtroBmx));
            break;
        case 2:
            controller_saveAsText("playera.txt",ll_filter(bici,filtroPlayera));
            break;
        case 3:
            controller_saveAsText("mtb.txt",ll_filter(bici,filtroMtb));
            break;
        case 4:
            controller_saveAsText("paseo.txt",ll_filter(bici,filtroPaseo));
            break;
        default:
            break;
        }


}
