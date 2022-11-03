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
	nodeMay *ap=NULL, *aux, *aux2, *aux3;
	int op;
	int val, e;
	int m, n, i, cont, indice;
	char archivo[20];


	//interfaz
	while(1){
		printf("\nElija una opcion: \n 1: Crear una matriz nueva \n 2: Obtener un elemento de una matriz \n 3: Leer una matriz de un archivo \n 4: Guardar una matriz en un archivo \n 5: Asignar un elemento a un espacio de la matriz \n 6: Sumar dos matrices\n 7: Multiplicar una matriz por un escalar\n 8: Realizar el producto de dos matrices\n 9: Trasponer una matriz\n 10: Imprimir una matriz \n 0: Salir\n");
		scanf("%d", &op);

		switch(op){
			case 0: return 0;
			case 1:
				printf("\nIngrese las dimensiones de la matriz ");
				scanf("%d", &m);
				scanf("%d", &n);

				if(m <=0 || n<=0){
					printf("Dimensiones invalidas");
					break;
				}


				aux = ap;
				while(aux && aux->nextmay)
					aux = aux->nextmay;


				if(!aux){
					aux = ap = nuevoMay();
					aux->fst = crearM(m, n);
				}
				else{
				    aux->nextmay = nuevoMay();
				    aux = aux->nextmay;
				   aux->fst = crearM(m,n);
				}

				int cant;

				printf("\nIngrese la cantidad de elementos no nulos de la matriz ");
				scanf("%d", &cant);

				for(cont=1; cont <= cant; cont++){
				    printf("\nEscriba los datos del elemento %d: ", cont);
					printf("\nFila:");
				    scanf("%d", &m);
					printf("\nColumna: ");
				    scanf("%d", &n);
					printf("\nValor del elemento: ");
				    scanf("%d", &val);

					asignarElemento(m,n,val,aux->fst);
				}
				break;

			case 2:
				printf("\nEscriba la posicion del elemento");
				printf("\nFila: ");
				scanf("%d", &m);
				printf("\nColumna: ");
				scanf("%d", &n);
				printf("\nNumero de la matriz: ");
				scanf("%d", &indice);

				for(i=1, aux = ap;i<indice; i++, aux=aux->nextmay);

				printf("%d",obtenerElemento(m,n,aux->fst));

		    	break;

			case 3:
				printf("Ingrese el nombre del archivo ");
				scanf("%s",archivo);

				aux = ap;
				cont = 1;
				while(aux && aux->nextmay){
					aux = aux->nextmay;
					cont++;
				}


				if(!aux){
					aux = ap = nuevoMay();
					aux->fst = leerFile(archivo);
				}
				else{
				    aux->nextmay = nuevoMay();
				    aux = aux->nextmay;
					aux->fst = leerFile(archivo);
				}

				printf("La matriz se guardo en la posicion %d ",cont);

				break;

			case 4:
				printf("Ingrese el nombre del archivo ");
				scanf("%s",archivo);

				printf("Ingrese el numero de la matriz ");
				scanf("%d", &indice);
				for(i=1, aux=ap ;i<indice; i++, aux=aux->nextmay);

				if(!crearFile(archivo, aux->fst))
					printf("Error al crear el archivo");


				break;

			case 5:
				printf("\nEscriba los datos del elemento ");
				printf("\nFila: ");
				scanf("%d", &m);
				printf("\nColumna: ");
				scanf("%d", &n);
				printf("\nValor del elemento");
				scanf("%d", &val);
				printf("\nNumero de la matriz: ");
				scanf("%d", &indice);

				for(i=1, aux = ap;i<indice; i++, aux=aux->nextmay);

				asignarElemento(m, n , val , aux->fst);

				break;

			case 6:
			    printf("\nIngrese el numero de las matrices a sumar ");
				scanf("%d", &indice);

				for(i=1, aux = ap;i<indice; i++, aux=aux->nextmay);

				scanf("%d", &indice);

				for(i=1, aux2 = ap;i<indice; i++, aux2=aux2->nextmay);

				cont = 2;

				aux3 = ap;
				while(aux3->nextmay){
					aux3 = aux3->nextmay;
					cont++;
				}

				aux3->nextmay = nuevoMay();
				aux3 = aux3->nextmay;
				aux3->fst = suma(aux->fst,aux2->fst);

				printf("\nla nueva matriz se encuentra en el numero %d de la lista de matrices ", cont);

				break;

			case 7:
			    printf("\nEscriba los datos ");
				printf("\nValor del escalar ");
				scanf("%d", &e);
				printf("\nNumero de la matriz ");
				scanf("%d", &indice);

				for(i=1, aux = ap;i<indice; i++, aux=aux->nextmay);

				productoEsc(e, aux->fst);

				printf("\nLa matriz se ha multiplicado por el escalar y ocupa la misma posicion ");

				break;

			case 8:
				printf("\nIngrese el numero de las matrices en el orden a multiplicar ");
				scanf("%d", &indice);
				for(i=1, aux = ap;i<indice; i++, aux=aux->nextmay);

				scanf("%d", &indice);

				for(i=1, aux2 = ap;i<indice; i++, aux2=aux2->nextmay);

				cont = 2;

				while(aux3->nextmay){
					aux3 = aux3->nextmay;
					cont++;
				}
				aux->nextmay = nuevoMay();
				aux = aux->nextmay;
				aux3->fst = producto(aux->fst,aux2->fst);

				printf("\nla nueva matriz se encuentra en el numero %d de la lista de matrices ", cont);

				break;

			case 9:
				printf("\nIngrese el numero de la matriz a transponer ");
				scanf("%d", &indice);

				for(i=1, aux = ap;i<indice; i++, aux=aux->nextmay);

				trasponer(aux->fst);

				printf("\nLa matriz se ha transpuesto y ocupa la misma posicion ");

				break;

			case 10:
				printf("\nIngrese el numero de la matriz a imprimir ");
				scanf("%d", &indice);

				for(i=1, aux = ap;i<indice; i++, aux=aux->nextmay);

				imprimir(aux->fst);

				break;

			default:
				printf("\nopcion invalida, vuelva a intentar\n");
				break;
		}
	}
}
