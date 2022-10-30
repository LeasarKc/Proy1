
/**********************************************************************
Declaraciones de funciones para el primer proyecto de:
Algoritmos y Programacion II

Por: 
Diego Peña
Luis Enrique Salazar 
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

nodeF *nuevoElementoF(int i){
	nodeF *new;
	if ((new = (nodeF*)malloc(sizeof(nodeF)))== NULL){
		printf("\nERROR: Problema en malloc");
		exit(1);
		}
	new->fila = i;
	new->nextf = NULL;
	new->nextc = NULL;
	return new;
}

nodeC *nuevoElementoM(int val, int j){
	nodeC *new;
	if ((new = (nodeC*)malloc(sizeof(nodeC)))== NULL){
		printf("\nERROR: Problema en malloc");
		exit(1);
		}
	new->value = val;
	new->colm = j;
	new->nextc = NULL;
	return new;
}

nodeFst *crearM(int fil, int colm){
	nodeFst *new;
	
	if(fil == 0 || colm == 0)
		return NULL;
	
	if ((new = (nodeFst*)malloc(sizeof(nodeFst)))== NULL){
		printf("\nERROR: Problema en malloc");
		exit(1);
	}
	
	new->fil = fil;
	new->colm = colm;
	
	return new;
	
}

/*nodeFst *crearMAuto(int fil,int colm){
	nodeFst *new;
	nodeF *auxf = NULL;
	nodeC *auxc = NULL;
	
	int val = 0,i,j;
	
	if(fil == 0 || colm == 0)
		return NULL;
	
	new = crearM(fil, colm);
	
	for(auxf = new->nextf = nuevoElementoF(1), i = 2; i < fil; i++, auxf = auxf->nextf){
		auxf->nextf = nuevoElementoF(i);
		
		for(auxc = auxf->nextc = nuevoElementoM(val++, 1), j = 2; j < colm; j++, auxc = auxc-nextc){
			auxc->next = nuevoElementoM(val++, j);
		}
		free(auxc->next);
		val--;
	}
	free(auxf->next);
	return new;
}*/

int obtenerElemento(int fila, int colm, nodeFst *m){
	nodeF *auxf;
	nodeC *auxc;
	
	for(auxf = m->nextf; auxf; auxf=auxf->nextf){
	
		if (auxf->fila == fila){
			for(auxc = auxf->nextc; auxc; auxc=auxc->nextc){
				
				if (auxc->colm == colm)
					return auxc->value;
				else
					if (auxc->colm > colm)
						return 0;
			}
		}
		else 
			if (auxf->fila > fila)
				return 0;
	}
	return 0;
}

int asignarElemento(int fila, int colm, int val, nodeFst *m){
	nodeC *auxc, *auxantc = NULL, *newc;
	nodeF *auxf, *auxantf = NULL, *newf;
	
	for(auxf = m->nextf;; auxantf = auxf ,auxf=auxf->nextf){
		
		//Llega a la ultima fila sin encontrar a la que asignar
		if (!auxf){
			auxf = nuevoElementoF(fila);
			auxantf->nextf = auxf;
		}
		else{
			//Encuentra la fila
			if (auxf->fila == fila){
				for(auxc = auxf->nextc;; auxantc = auxc, auxc=auxc->nextc){
					
					//Llego al final de la fila sin encontrar la casilla, crea una
					if(!auxc){
						auxc = nuevoElementoM(val, colm);
						auxantc->nextc = auxc;
						return 1;
					}
					else{
						//Encuentra la casilla a la que va a asignar
						if (auxc->colm == colm){
							auxc->value = val;
							return 1;
						}
						else
							//Se paso la posicion que debia ocupar, crea una entre la actual y la anterior
							if (auxc->colm > colm){
								newc = nuevoElementoM(val, colm);
								newc->nextc = auxantc->nextc;
								auxantc->nextc = newc;
								return 1;
							}
					}
				}
			}
			else 
				//Se pasa de la fila
				if (auxf->fila > fila){
					newf = nuevoElementoF(fila);
					newf->nextf = auxantf->nextf;
					auxantf->nextf = newf;
					
					newf->nextc = nuevoElementoM(val, colm);
				}
					
		}
	}
	return 0;
}


void productoEsc(int e, nodeFst *m){
	nodeF *fil;
	nodeC *col;
	for(fil = m->nextf; fil; fil = fil->nextf)
		for (col = fil->nextc; col; col = col->nextc)
			col->value *= e; 
}

void imprimir(nodeFst *m){

}
