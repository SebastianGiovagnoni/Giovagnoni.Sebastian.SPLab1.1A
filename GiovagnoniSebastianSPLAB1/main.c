#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int main()
{
    int option = 1;
    srand (time(NULL));
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        printf("\n\n1. Cargar los datos de las Bicicletas desde el archivo bicicletas.csv (modo texto)\n2. Listar\n3. Asignar tiempos\n4. filtrar por tipo\n5. Mostrar posiciones\n6. guardar posiciones\n7. Salir\nSelecion:");
        scanf("%d",&option);
        system("cls");
        switch(option)
        {
            case 1:
                controller_loadFromText("bicicletas.csv",listaEmpleados);
                break;
            case 2:
                controller_ListeBicicleta(listaEmpleados);
                break;
            case 3:
                controller_map(listaEmpleados);
                break;
            case 4:
                controller_filter(listaEmpleados);
                break;
            case 5:
                controller_sorteBicicleta(listaEmpleados);
                break;
            case 6:
                controller_saveAsText("bicicletasPosiciones.csv",listaEmpleados);
                break;
            default:
                break;
        }
        system("cls");
    }while(option != 7);
    return 0;
}
