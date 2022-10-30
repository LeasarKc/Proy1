
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
	//node *listp = NULL;
	unsigned char op;
	int val;
	char name[20];
	//interfaz
	while(1){
		//printf("Su lista actual es: ");
		//print(listp);
		
		printf("\nElija una opcion: \n 1: Crear una matriz nueva \n 2: Obtener un elemento de una matriz \n 3: Asignar un elemento a un espacio de la matriz \n 4: Sumar dos matrices\n 5: Multiplicar una matriz por un escalar\n 6: Realizar el producto de dos matrices (crea una nueva)\n 7: Trasponer una matriz 0: Salir\n");
		scanf("%c", &op);
		
		switch(op){
			case 0: return 0;
			case 1: 
				printf("\nEscriba el nombre del elemento (20 caracteres maximo): ");
				scanf("%s", name);
				printf("\nEscriba el valor del elemento (entero): ");
				scanf("%d", &val);
				listp = add_front(listp, new_item(name, val));
				
				break;
			case 2: 
				printf("\nEscriba el nombre del elemento (20 caracteres maximo): ");
				scanf("%s", name);
				printf("\nEscriba el valor del elemento (entero): ");
				scanf("%d", &val);
				listp = add_end(listp, new_item(name, val));
				
				break;
			case 3:
				listp = reverse(listp);
				
				break;
			case 4: 
				listp = copy(listp);
				break;
			default:
				printf("\nopcion invalida, vuelva a intentar\n");
				break;
		}
}
