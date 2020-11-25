#include <stdio.h>
#include <stdlib.h>
//#define <time.h>
#include <ctype.h>
#include "string.h"
#include "Employee.h"

eBicicleta* eBicicleta_new(){
    eBicicleta* auxeBicicleta;
    auxeBicicleta= (eBicicleta*) malloc(sizeof(eBicicleta));
    return auxeBicicleta;
}
eBicicleta* eBicicleta_newParametros(char* idStr,char* nombreStr,char* tipoStr,char* tiempoStr){
    eBicicleta* auxeBicicleta=eBicicleta_new();

    eBicicleta_setId(auxeBicicleta,atoi(idStr));
    eBicicleta_setNombre(auxeBicicleta,nombreStr);
    eBicicleta_setTipo(auxeBicicleta,tipoStr);
    eBicicleta_setTiempo(auxeBicicleta,atoi(tiempoStr));

    return auxeBicicleta;
}
int eBicicleta_setId(eBicicleta* this,int id){
    int verificacion= -1;
    if(this!=NULL){
        this->id=id;
        verificacion=1;
    }
    return verificacion;
}
int eBicicleta_getId(eBicicleta* this,int* id){
    int verificacion= -1;
    if(this!=NULL){
        *id=this->id;
        verificacion=1;
    }
    return verificacion;
}
int eBicicleta_setNombre(eBicicleta* this,char* nombre){
    int verificacion= -1;
    if(this!=NULL){
        strcpy(this->nombre,nombre);
        verificacion=1;
    }
    return verificacion;
}
int eBicicleta_getNombre(eBicicleta* this,char* nombre){
    int verificacion= -1;
    if(this!=NULL){
         strcpy(nombre,this->nombre);
        verificacion=1;
    }
    return verificacion;
}
int eBicicleta_setTipo(eBicicleta* this,char* tipo)
{
    int verificacion= -1;
        if(this!=NULL){
        strcpy(this->tipo,tipo);
        verificacion=1;
    }
    return verificacion;
}
int eBicicleta_getTipo(eBicicleta* this,char* tipo){
    int verificacion= -1;
        if(this!=NULL){
        strcpy(tipo,this->tipo);
        verificacion=1;
    }
    return verificacion;
}
int eBicicleta_setTiempo(eBicicleta* this,int tiempo){
    int verificacion= -1;
    if(this!=NULL){
        this->tiempo=tiempo;
        verificacion=1;
    }
    return verificacion;
}
int eBicicleta_getTiempo(eBicicleta* this,int* tiempo){
    int verificacion= -1;
    if(this!=NULL){
        *tiempo=this->tiempo;
        verificacion=1;
    }
    return verificacion;
}

    int eBicicleta_checkStr(char* ingreso)
{
    int i;
    int flag=1;
    int len;
    len=strlen(ingreso);
    for(i=0;i<len;i++)
    {
        if(ingreso[i]=='\0')
        {

            break;

        }
        else
        {
            if(isdigit(ingreso[i])==0)
            {
                //printf("%d",flag);
                flag=isdigit(ingreso[i]);
                break;
            }
        }

    }
    return flag;
}

/*int eBicicleta_IngresarDatos(eBicicleta* this,int opcion,char* mensaje)
{
    char ingreso[128];

    puts(mensaje);
    fflush(stdin);
    switch(opcion)
    {
    case 1:
        scanf("%s",ingreso);

        ingreso[0]=toupper(ingreso[0]);

        eBicicleta_setNombre(this, ingreso);

        break;
    case 2:
        scanf("%s",ingreso);
        while(eBicicleta_checkStr(ingreso)==0)
        {
            printf("ERROR:");
            scanf("%s",ingreso);
        }
        eBicicleta_setHorasTrabajadas(this,atoi(ingreso));
        break;
    case 3:
        scanf("%s",ingreso);
        while(eBicicleta_checkStr(ingreso)==0)
        {
            printf("ERROR:");
            scanf("%s",ingreso);
        }
        eBicicleta_setSueldo(this,atoi(ingreso));
        break;
    default:
        printf("\n\nError modificacion\n");
        system("pause");

        break;
    }
    return 0;
}*/
int eBicicleta_list(eBicicleta* this)
{

    printf("%5d %20s %20s            %10d\n",this->id,this->nombre,this->tipo,this->tiempo);

    return 1;
}

/*int eBicicleta_chooseMod(eBicicleta* this, char* mensaje)
{
    char mensajeMod[3][30]={"\nIngrese nombre:","\nIngrese Horas trabajadas:","\nIngrese salario:"};
    int opcion;

    puts(mensaje);
    scanf("%d",&opcion);

    system("cls");
    if(opcion>0&&opcion<=3)
    {
        eBicicleta_IngresarDatos(this,opcion,mensajeMod[opcion-1]);
    }else
    {
        eBicicleta_IngresarDatos(this,-1," ");
    }


    return 1;
}*/

void eBicicleta_delete(eBicicleta* this)
{
    free(this);

}

int eBicicleta_compareByTipo(void* empleadoUno, void* empleadoDos)
{
    int estado;

    eBicicleta* emp1=(eBicicleta*)empleadoUno;
    eBicicleta* emp2=(eBicicleta*)empleadoDos;

    estado=stricmp(emp1->tipo, emp2->tipo);

   if(estado==0)
   {
       if(emp1->tiempo > emp2->tiempo )
        {
            estado=1;
        }
        else if(emp1->tiempo < emp2->tiempo)
        {
            estado=-1;
        }
        else
        {
            estado= 0;
        }
   }

    return estado;
}

/*int eBicicleta_compareByName(void* empleadoUno, void* empleadoDos)
{
    int estado;

    eBicicleta* emp1=(eBicicleta*)empleadoUno;
    eBicicleta* emp2=(eBicicleta*)empleadoDos;

    estado=stricmp(emp1->nombre,emp2->nombre);

    return estado;
}*/

/*int eBicicleta_compareBySueldo(void* empleadoUno, void* empleadoDos)
{
    int estado;

    eBicicleta* emp1=(eBicicleta*)empleadoUno;
    eBicicleta* emp2=(eBicicleta*)empleadoDos;

    if(emp1->sueldo>emp2->sueldo)
    {
        estado=1;
    }
    else if(emp1->sueldo<emp2->sueldo)
    {
        estado=-1;
    }
    else
    {
        estado=0;
    }
    return estado;
}*/

/*int eBicicleta_compareByHorasTrabajadas(void* empleadoUno, void* empleadoDos)
{
    int estado;

    eBicicleta* emp1=(eBicicleta*)empleadoUno;
    eBicicleta* emp2=(eBicicleta*)empleadoDos;

    if(emp1->horasTrabajadas>emp2->horasTrabajadas)
    {
        estado=1;
    }
    else if(emp1->horasTrabajadas < emp2->horasTrabajadas )
    {
        estado=-1;
    }
    else
    {
        estado=0;
    }
    return estado;
}*/
int laQueMapea(void* aux)
{
    int retorno=0;
    int aleatorio;
    eBicicleta* bici=aux;

    if(bici!=NULL)
    {
        retorno=1;
        aleatorio=rand()%(71)+50;
        eBicicleta_setTiempo(bici, aleatorio);
    }

    return retorno;
}

int filtroBmx(void* aux)
{
    int retorno=0;
    char aleatorio[10];
    eBicicleta* bici=aux;

    if(bici!=NULL)
    {
        eBicicleta_getTipo(bici,aleatorio);
        retorno=stricmp(aleatorio,"bmx");
    }

    return retorno;
}

int filtroPlayera(void* aux)
{
    int retorno=0;
    char aleatorio[10];
    eBicicleta* bici=aux;

    if(bici!=NULL)
    {
        eBicicleta_getTipo(bici,aleatorio);
        retorno=stricmp(aleatorio,"playera");
    }

    return retorno;
}

int filtroMtb(void* aux)
{
    int retorno=0;
    char aleatorio[10];
    eBicicleta* bici=aux;

    if(bici!=NULL)
    {
        eBicicleta_getTipo(bici,aleatorio);
        retorno=stricmp(aleatorio,"mtb");
    }

    return retorno;
}

int filtroPaseo(void* aux)
{
    int retorno=0;
    char aleatorio[10];
    eBicicleta* bici=aux;

    if(bici!=NULL)
    {
        eBicicleta_getTipo(bici,aleatorio);
        retorno=stricmp(aleatorio,"paseo");
    }

    return retorno;
}
