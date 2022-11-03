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
	nodeFst *temp;
	int op;
	int val, e;
	int m, n, i, cont, indice;


	//interfaz
	while(1){
		printf("\n\nElija una opcion: \n 1: Crear una matriz nueva \n 2: Obtener un elemento de una matriz  \n 3: Asignar un elemento a un espacio de la matriz \n 4: Sumar dos matrices\n 5: Multiplicar una matriz por un escalar\n 6: Realizar el producto de dos matrices\n 7: Trasponer una matriz\n 8: Imprimir una matriz \n 0: Salir\n");
		scanf("%d", &op);

		switch(op){
			case 0: return 0;
			case 1:
				printf("\nIngrese las dimensiones de la matriz ");
				scanf("%d", &m);
				scanf("%d", &n);

				if(m <=0 || n<=0)
					printf("Dimensiones invalidas");
				else{


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
				}}
				break;

			case 2:
				printf("\nEscriba la posicion del elemento");
				printf("\nFila: ");
				scanf("%d", &m);
				printf("\nColumna: ");
				scanf("%d", &n);
				printf("\nNumero de la matriz: ");
				scanf("%d", &indice);

				for(i=1, aux = ap;i<indice && aux; i++, aux=aux->nextmay);

				if (i<indice || !aux)
                    printf("Matriz inexistente, intente de nuevo");
                else
                    printf("%d",obtenerElemento(m,n,aux->fst));

		    	break;

			case 3:
				printf("\nEscriba los datos del elemento ");
				printf("\nFila: ");
				scanf("%d", &m);
				printf("\nColumna: ");
				scanf("%d", &n);
				printf("\nValor del elemento: ");
				scanf("%d", &val);
				printf("\nNumero de la matriz: ");
				scanf("%d", &indice);

				for(i=1, aux = ap;i<indice && aux; i++, aux=aux->nextmay);

				if (i<indice || !aux)
                    printf("Matriz inexistente, intente de nuevo");
				else
                    asignarElemento(m, n , val , aux->fst);

				break;

			case 4:
			    printf("\nIngrese el numero de las matrices a sumar ");
				scanf("%d", &indice);

				for(i=1, aux = ap;i<indice && aux; i++, aux=aux->nextmay);

				if (i<indice || !aux)
                    printf("Matriz inexistente, intente de nuevo");
				else{

				scanf("%d", &indice);

				for(i=1, aux2 = ap;i<indice && aux2; i++, aux2=aux2->nextmay);

				if (i<indice || !aux)
                    printf("Matriz inexistente, intente de nuevo");
				else{

				cont = 2;

				aux3 = ap;
				while(aux3->nextmay){
					aux3 = aux3->nextmay;
					cont++;
				}

                if (temp = suma(aux->fst,aux2->fst)){
                    aux3->nextmay = nuevoMay();
                    aux3 = aux3->nextmay;
                    aux3->fst = temp;
                    printf("\nla nueva matriz se encuentra en el numero %d de la lista de matrices ", cont);
                }else
                    printf("Hubo un error, intentelo de nuevo");

                }}

				break;

			case 5:
			    printf("\nEscriba los datos ");
				printf("\nValor del escalar ");
				scanf("%d", &e);
				printf("\nNumero de la matriz ");
				scanf("%d", &indice);

				for(i=1, aux = ap;i<indice && aux; i++, aux=aux->nextmay);

				if (i<indice || !aux){
                    printf("Matriz inexistente, intente de nuevo");
				}else{
                    productoEsc(e, aux->fst);
                    printf("\nLa matriz se ha multiplicado por el escalar y ocupa la misma posicion ");
                }

				break;

			case 6:
				printf("\nIngrese el numero de las matrices en el orden a multiplicar ");
				scanf("%d", &indice);
				for(i=1, aux = ap;i<indice && aux; i++, aux=aux->nextmay);

				if (i<indice || !aux)
                    printf("Matriz inexistente, intente de nuevo");
				else{

				scanf("%d", &indice);

				for(i=1, aux2 = ap;i<indice && aux2; i++, aux2=aux2->nextmay);

				if (i<indice || !aux)
                    printf("Matriz inexistente, intente de nuevo");
				else{

				cont = 2;

				while(aux3->nextmay){
					aux3 = aux3->nextmay;
					cont++;
				}
				if (temp = producto(aux->fst,aux2->fst)){
                    aux->nextmay = nuevoMay();
                    aux = aux->nextmay;
                    aux3->fst = temp;

                    printf("\nla nueva matriz se encuentra en el numero %d de la lista de matrices ", cont);
                }else
                    printf("Hubo un error, intentelo de nuevo");

                }}

				break;

			case 7:
				printf("\nIngrese el numero de la matriz a transponer ");
				scanf("%d", &indice);

				for(i=1, aux = ap;i<indice && aux; i++, aux=aux->nextmay);

				if (i<indice || !aux){
                    printf("Matriz inexistente, intente de nuevo");
				}
				else{
                    trasponer(aux->fst);
                    printf("\nLa matriz se ha transpuesto y ocupa la misma posicion ");
                }

				break;

			case 8:
				printf("\nIngrese el numero de la matriz a imprimir ");
				scanf("%d", &indice);

				for(i=1, aux = ap;i<indice && aux; i++, aux=aux->nextmay);

				if (i<indice || !aux)
                    printf("Matriz inexistente, intente de nuevo");
                else
                    imprimir(aux->fst);

				break;

			default:
				printf("\nopcion invalida, vuelva a intentar\n");
				break;
		}
	}
}
