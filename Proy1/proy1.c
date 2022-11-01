
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
	nodeMay *ap, *aux, *aux2, *aux3;
	unsigned char op;
	float val;
	int m, n, i, j, cant, cont, indice;
	char archivo[20];
	

	//interfaz
	while(1){	
		printf("\nElija una opcion: \n 1: Crear una matriz nueva \n 2: Obtener un elemento de una matriz \n 3: Leer una matriz de un archivo \n 4: Guardar una matriz en un archivo \n 5: Asignar un elemento a un espacio de la matriz \n 6: Sumar dos matrices\n 7: Multiplicar una matriz por un escalar\n 8: Realizar el producto de dos matrices (crea una nueva)\n 9: Trasponer una matriz\n 10: Imprimir una matriz 0: Salir\n");
		scanf("%c", &op);
		
		switch(op){
			case 0: return 0;
			case 1: 
				printf("\nIngrese las dimensiones de la matriz");
				scanf("%d", &m);
				scanf("%d", &n);
				aux = ap;

				while(aux && aux->next)
					aux = aux->next;

				if (aux = NULL )
					aux = ap = crearM(m, n);
				else
				    aux->next = crearM(m,n);
				printf("\nIngrese la cantidad de elementos no nulos de la matriz");
				scanf("%d", &cant);

				for(cont=0; cont <= cant; cont++){
				    printf("\nEscriba la posicion y valor del elemento: ");
				    scanf("%d", &m);
				    scanf("%d", &n);
				    scanf("%f", &val);

					if (!aux->next)
						asignarElemento(i,j,val,aux);
					else
						asignarElemento(i,j,val,aux->next);
				}
				break;

			case 2: 
				printf("\nEscriba la posicion del elemento y el numero de matriz: ");
				scanf("%d", &m);
				scanf("%d", &n);
				scanf("%d", &indice);
				
				for(i=1, aux = ap;i<indice; i++, aux=aux->next);

				printf("%d",obtenerElemento(m,n,aux));

		    	break;

			case 3:
				printf("Ingrese el nombre del archivo");
				scanf("%s",&archivo);
				aux = ap;
				cont=0;
				while(aux && aux->next){
					aux = aux->next;
					cont++;
				}
				aux->next = leerfile(archivo);

				printf("La matriz se guardo en la posicion %d ",cont)

				break;

			case 4:
				printf("Ingrese el nombre del archivo");
				scanf("%s",&archivo);

				printf("Ingrese el numero de la matriz");
				scanf("%d", &indice);
				for(i=1, aux = ap;i<indice; i++, aux=aux->next);
				crearFile(archivo, aux);


				break;

			case 5:
				printf("\nEscriba la posicion del elemento, el numero de matriz y su valor: ");
				scanf("%d", &m);
				scanf("%d", &n);
				scanf("%f", &val);
				scanf("%d", &indice);
				
				for(i=1, aux = ap;i<indice; i++, aux=aux->next);

				asignarElemento(m, n , val , aux);
				
				break;

			case 6: 
			    printf("\nIngrese el numero de las matrices a sumar");
				scanf("%d", &indice);
				
				for(i=1, aux = ap;i<indice; i++, aux=aux->next);

				scanf("%d", &indice);
				
				for(i=1, aux2 = ap;i<indice; i++, aux2=aux2->next);

				cont = 0;

				while(aux3 && aux3->next){
					aux3 = aux3->next;
					cont++;
				}

				aux3->next = suma(aux,aux2);

				printf("\nla nueva matriz se encuentra en el numero %d de la lista de matrices", cont);

				break;

			case 7: 
				int e;

			    printf("\nEscriba el valor del escalar y el numero de la matriz");
				scanf("%d", &e);
				scanf("%d", &indice);

				for(i=1, aux = ap;i<indice; i++, aux=aux->next);

				productoEsc(e, aux);

				printf("\nLa matriz se ha multiplicado por el escalar y ocupa la misma posicion");

				break;

			case 8: 
				printf("\nIngrese el numero de las matrices en el orden a multiplicar");
				scanf("%d", &indice);
				
				for(i=1, aux = ap;i<indice; i++, aux=aux->next);

				scanf("%d", &indice);
				
				for(i=1, aux2 = ap;i<indice; i++, aux2=aux2->next);

				cont = 0;

				while(aux3 && aux3->next){
					aux3 = aux3->next;
					cont++;
				}

				aux3->next = producto(aux,aux2);

				printf("\nla nueva matriz se encuentra en el numero %d de la lista de matrices", cont);

				break;

			case 9: 
				printf("\nIngrese el numero de la matriz a transponer");
				scanf("%d", &indice);
				
				for(i=1, aux = ap;i<indice; i++, aux=aux->next);

				trasponer(aux);

				printf("\nLa matriz se ha transpuesto y ocupa la misma posicion");

				break;

			case 10: 
				printf("\nIngrese el numero de la matriz a imprimir");
				scanf("%d", &indice);
				
				for(i=1, aux = ap;i<indice; i++, aux=aux->next);
				
				 imprimir(aux);
	
				break;

			default:
				printf("\nopcion invalida, vuelva a intentar\n");
				break;
		}
}
