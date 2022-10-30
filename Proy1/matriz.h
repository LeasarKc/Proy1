
/**********************************************************************
.h de funciones para el primer proyecto de:
Algoritmos y Programacion II

Por: 
Diego Peña
Luis Enrique Salazar
***********************************************************************/

//       Struct del nodo de las listas de las matrices

typedef struct nodeMay{
    struct nodeFst *fst;
    struct nodeMay *nextmay;
} nodeMay;

//       Struct del nodo que almacena las dimensiones de la matriz
typedef struct nodeFst {
    int fil,colm;   //Dimensiones de la matriz entera.
    struct nodeF *nextf; //Apuntador: primera fila
} nodeFst;

//      Struct de los nodos de las  filas de la matriz
typedef struct nodeF {
    int fila;  //indice de la fila
    struct nodeF *nextf; //Apuntador: siguiente fila
    struct nodeC *nextc; // Apuntador: siguiente columna
} nodeF;

//      Struct de los nodos de las columnas de la matriz
typedef struct nodeC {
    int value;
    int colm;   //indice de la columna
    struct nodeC *nextc; // Apuntador: siguiente columna
} nodeC;


//       Prototipos de las funciones

nodeF *nuevoElementoF(int); //Crear una fila nueva

nodeC *nuevoElementoM(int, int); //Crear una casilla de la matriz

nodeFst *crearM(int,int); //crear por primera vez una matriz vacia

int llenarManual(nodeFst*); //Funcion llenar matriz con valores dados

int obtenerElemento(int,int,nodeFst*); // devuelve el elemento en una posicion de la matrz

int asignarElemento(int,int,int,nodeFst*); //asigna un valor a una posicion de la matriz

nodeFst *suma(nodeFst*,nodeFst*); //devuelve una nueva matriz que resulta de la suma de las matrices que tiene por parametros

void productoEsc(int, nodeFst*); // multiplica una matriz por un escalar

nodeFst *producto(nodeFst*, nodeFst*); //devuelve la matriz producto de dos matrices

void trasponer(nodeFst*); //traspone una matriz

void imprimir(nodeFst*); //muestra los valores de una matriz
