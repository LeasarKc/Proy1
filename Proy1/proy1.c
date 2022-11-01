
/**********************************************************************
main del primer proyecto de:
Algoritmos y Programacion II

Por: 
Diego Peña
Luis Enrique Salazar
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"

int main(){
	nodeMay *ap;
	unsigned char op;
	float val;
	int m, n, i, j, cant, cont;
	

	//interfaz
	while(1){	
		printf("\nElija una opcion: \n 1: Crear una matriz nueva \n 2: Obtener un elemento de una matriz \n 3: Asignar un elemento a un espacio de la matriz \n 4: Sumar dos matrices\n 5: Multiplicar una matriz por un escalar\n 6: Realizar el producto de dos matrices (crea una nueva)\n 7: Trasponer una matriz\n 8: Imprimir una matriz 0: Salir\n");
		scanf("%c", &op);
		
		switch(op){
			case 0: return 0;
			case 1: 
				printf("\nIngrese las dimensiones de la matriz");
				scanf("%d", &m);
				scanf("%d", &n);
				
				fst = crearM(m, n);
				printf("\nIngrese la cantidad de elementos no nulos de la matriz");
				scanf("%d", &cant);
				for(cont=0; cont <= cant; cont++){
				    printf("\nEscriba la posicion y valor del elemento: ");
				    scanf("%d", &i);
				    scanf("%d", &j);
				    scanf("%f", &val);
				    nodeF->nextf = nuevoElementoF(i);

				}
				break;
			case 2: 
				printf("\nEscriba la posicion del elemento y el numero de matriz: ");
				scanf("%d", &i);
				scanf("%d", &j);
				//scanf(matriz¿)//
				printf("%d",obtenerElemento(i, j, nodeFst *m) );
		    	break;
			case 3:
				printf("\nEscriba la posicion del elemento, el numero de matriz y su valor: ");
				scanf("%d", &i);
				scanf("%d", &j);
				scanf("%f", &val);
				//scanf(matriz¿)//
				asignarElemento(i, j , val , nodeFst *m);
				
				break;
			case 4: 
			    printf("Ingrese el numero de las matrices a sumar");
				//scanf(matriz¿)//
				//crearM(m, n)//
				nuevasuma = suma(nodeFst*,nodeFst*);
				break;
			case 5: 
				int e;
			    printf("Escriba el valor del escalar y el numero de la matriz");
                //scanf(matriz¿)//
				scanf("%d", &e);
				productoEsc(e, nodeFst*);
				break;
			case 6: 
				printf("Ingrese el numero de las matrices en el orden a multiplicar");
				//scanf(matriz¿)//
				nuevaproduct = producto(nodeFst*, nodeFst*)
				break;
			case 7: 
				printf("Ingrese el numero de la matriz a transponer");
				//scanf(matriz¿)//
				trasponer(nodeFst*);
				break;
			case 8: 
				printf("Ingrese el numero de la matriz a imprimir");
				//scanf(matriz¿)//
				void imprimir(nodeFst *m)
				break;
			default:
				printf("\nopcion invalida, vuelva a intentar\n");
				break;
		}
}
