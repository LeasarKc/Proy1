
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
					return 1;
				}
					
		}
	}
	return 0;
}

nodeFst *suma(nodeFst *m1, nodeFst *m2){
	nodeFst *new;
	nodeC *auxc1, *auxc2, *auxc3;
	nodeF *auxf1, *auxf2, *auxf3;
	
	if (m1->colm != m2->colm || m1->fil != m2-> fil)
		return NULL;
	
	auxf1 = m1->nextf;
	auxf2 = m2->nextf;
	
	//Crea la nueva matriz vacia
	new = crearM(m1->fil, m1->colm); 
	
	//Primer elemento de las filas para no perder el apuntador
	if (auxf1 && (!auxf2 || auxf1->fila <= auxf2->fila))
		new->nextf = nuevoElementoF(auxf1->fila);
	else if(auxf2)
		new->nextf = nuevoElementoF(auxf2->fila);
	
	for (auxf3 = new->nextf; auxf1 || auxf2; auxf3 = auxf3->nextf){
		
		//Si para ambas matrices hay elementos en la misma fila
		if (auxf1 == auxf2){
			
			auxc1 = auxf1->nextc;
			auxc2 = auxf2->nextc;
			//primer elemento para no perder el apuntador
			if(auxc1->colm < auxc2->colm)
				auxc3 = auxf3->nextc = nuevoElementoM(auxc1->value, auxc1->colm);
			else if(auxc1->colm > auxc2->colm)
					auxc3 = auxf3->nextc = nuevoElementoM(auxc2->value, auxc2->colm);
				else
					auxc3 = auxf3->nextc = nuevoElementoM(auxc1->value + auxc2->value, auxc1->colm);
					
			for(auxc1 = auxc1->nextc, auxc2 = auxc2->nextc; auxc1 || auxc2;){
				
				
				if(!auxc2 || auxc1->colm < auxc2->colm){
					auxc3 = auxf3->nextc = nuevoElementoM(auxc1->value, auxc1->colm);
					auxc1 = auxc1->nextc;
				}
				else if(auxc1->colm > auxc2->colm){
						auxc3 = auxf3->nextc = nuevoElementoM(auxc2->value, auxc2->colm);
						auxc2 = auxc2->nextc;
					}
					else{
						auxc3 = auxf3->nextc = nuevoElementoM(auxc1->value + auxc2->value, auxc1->colm);
						auxc1 = auxc1->nextc;
						auxc2 = auxc2->nextc;
					}
			}
			
			//Continuar con el ciclo de filas
			auxf1 = auxf1->nextf;
			auxf2 = auxf2->nextf;
		}
		else{
			//Si existen elementos para la fila 1
			if(auxf1 && (!auxf2 || auxf1->fila < auxf2->fila)){
				
				//crea el primer elemento por separado para no perder el apuntador
				auxc3 = auxf3->nextc = nuevoElementoM(auxf1->nextc->value, auxf1->nextc->colm);
				
				for(auxc1 = auxf1->nextc->nextc; auxc1; auxc1=auxc1->nextc, auxc3 = auxc3->nextc)
					auxc3->nextc = nuevoElementoM(auxc1->value,auxc1->colm);
				
				//instruccion para continuar el ciclo de filas
				auxf1=auxf1->nextf;
			}
			
			else{
				//Si existen elementos para la fila 2
				
				//crea el primer elemento por separado
				auxc3 = auxf3->nextc = nuevoElementoM(auxf2->nextc->value, auxf2->nextc->colm);
				
				for(auxc2 = auxf2->nextc->nextc; auxc2; auxc2=auxc2->nextc, auxc3 = auxc3->nextc)
					auxc3->nextc = nuevoElementoM(auxc2->value,auxc2->colm);
					
				//Para continuar el ciclo de filas
				auxf2 = auxf2->nextf;
			}
		}
		
		
		//Crear el siguiente elemento de m3
		if (auxf2 && auxf1 && auxf1->fila <= auxf2->fila)
			auxf3->nextf = nuevoElementoF(auxf1->fila);
		else if(auxf1 && auxf2)
			auxf3->nextf = nuevoElementoF(auxf2->fila);
			
	}
	
	return new;
}

void productoEsc(int e, nodeFst *m){
	nodeF *fil;
	nodeC *col;
	for(fil = m->nextf; fil; fil = fil->nextf)
		for (col = fil->nextc; col; col = col->nextc)
			col->value *= e; 
}

nodeFst *producto(nodeFst*m1, nodeFst*m2){
	nodeFst *new;
	nodeF *auxf1, *auxf2, *auxf3;
	nodeC *auxc1, *auxc2, *auxc3;
	int val;
	register int i, j;
	
	if (m1->colm != m2->fil) return NULL;
	
	new = crearM(m1->fil, m2->colm);
	
	if (!m1->nextf || !m2->nextf) return new;
	
	auxf3 = new->nextf = nuevoElementoF(m1->nextf->fila);
	
	for(auxf1 = m1->nextf; auxf1;){
		
		for(i = 1, auxf2= m2->nextf; i <= new->colm; i++){
			
			//Si la fila corresponde con lo guardado en la casilla
			if (auxf2 && auxf2->fila == i){
				//multiplicar y sumar columnas y filas
				for(val = 0, auxc1 = auxf1->nextc, auxc2 = auxf2->nextc, j = 1; j <= m1-> colm; j++){
				
					if (auxc1 && auxc2 && auxc1->colm == j && auxc2->colm ==j){
						val += auxc1->value * auxc2->value;
						auxc1=auxc1->nextc;
						auxc2=auxc2->nextc;
					}
					else if(auxc1 && auxc1->colm == j)
						auxc1=auxc1->nextc;
					else if (auxc2)
						auxc2=auxc2->nextc;
			}
			
				if (val){
					//Si es el riemr elemento de la fila
					if(!auxf3->nextc)
						auxc3 = auxf3->nextc = nuevoElementoM(val,i);
					
					auxc3->nextc = nuevoElementoM(val, i);
					auxc3 = auxc3->nextc;
				}
			
				auxf2 = auxf2->nextf;
			}
		}
		
		if(auxf3->nextc && auxf1->nextf){
			auxf3->nextf = nuevoElementoF(auxf1->fila);
			auxf3 = auxf3->nextf;
		}
		
	}
	if (!new->nextf->nextf && !new->nextf->nextc)
		free(new->nextf);
	
	return new;
}

void imprimir(nodeFst *m){

}
