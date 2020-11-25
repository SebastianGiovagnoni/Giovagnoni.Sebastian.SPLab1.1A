int controller_loadFromText(char* path , LinkedList* pArrayListeBicicleta);
int controller_loadFromBinary(char* path , LinkedList* pArrayListeBicicleta, int* idMax, char* pId);
int controller_addeBicicleta(LinkedList* pArrayListeBicicleta, int* idMax);
int controller_editeBicicleta(LinkedList* pArrayListeBicicleta);
int controller_removeeBicicleta(LinkedList* pArrayListeBicicleta);
int controller_ListeBicicleta(LinkedList* pArrayListeBicicleta);
int controller_sorteBicicleta(LinkedList* pArrayListeBicicleta);
int controller_saveAsText(char* path, LinkedList* pArrayListeBicicleta);
int controller_saveAsBinary(char* path,char* pathIdMax, LinkedList* pArrayListeBicicleta ,int* idMax);
void controller_map(LinkedList* bici);
void controller_filter(LinkedList* bici);


