#ifndef eBicicleta_H_INCLUDED
#define eBicicleta_H_INCLUDED
typedef struct
{
    int id;
    char nombre[50];
    char tipo[20];
    int tiempo;
}eBicicleta;

eBicicleta* eBicicleta_new();
eBicicleta* eBicicleta_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void eBicicleta_delete();

int eBicicleta_setId(eBicicleta* this,int id);
int eBicicleta_getId(eBicicleta* this,int* id);

int eBicicleta_setNombre(eBicicleta* this,char* nombre);
int eBicicleta_getNombre(eBicicleta* this,char* nombre);

int eBicicleta_setTipo(eBicicleta* this,char* tipo);
int eBicicleta_getTipo(eBicicleta* this,char* tipo);

int eBicicleta_setTiempo(eBicicleta* this,int tiempo);
int eBicicleta_getTiempo(eBicicleta* this,int* tiempo);

int eBicicleta_IngresarDatos(eBicicleta* this,int opcion,char* mensaje);
int eBicicleta_checkStr(char* ingreso);

int eBicicleta_list(eBicicleta* this);
int eBicicleta_chooseMod(eBicicleta* this, char* mensaje);

void eBicicleta_delete(eBicicleta* this);
int eBicicleta_compareById(void* empleadoUno, void* empleadoDos);

int eBicicleta_compareByName(void* empleadoUno, void* empleadoDos);
int eBicicleta_compareByHorasTrabajadas(void* empleadoUno, void* empleadoDos);

int eBicicleta_compareBySueldo(void* empleadoUno, void* empleadoDos);
int laQueMapea(void* aux);

int filtroBmx(void* aux);
int filtroPlayera(void* aux);

int filtroMtb(void* aux);
int filtroPaseo(void* aux);

int eBicicleta_compareByTipo(void* empleadoUno, void* empleadoDos);
#endif // eBicicleta_H_INCLUDED
